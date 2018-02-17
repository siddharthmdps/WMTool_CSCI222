#include "Account.h"



Account::Account()
{
}

void Account::setUserLocation(int UL)
{

	UserLocation = UL;

}

string Account::getcurrentpassword()
{

	return currentpassword;

}

void Account::setcurrentpassword(string CP)
{

	currentpassword = CP;

}

int  Account::getUserLocation()
{

	return UserLocation;

}

void Account::setaccStatus(string AC)
{

	accStatus = AC;

}

string Account::getaccStatus()
{

	return accStatus;
	
}


void Account::Register()
{
	string line, newusername, newpassword;
	int UserLocation = 0, userNotFound = 1;
	fstream userfile;

	cout    << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
		<< "~~~~~~~~~~~~~~~~~~~~~~~~~Registration~~~~~~~~~~~~~~~~~~~~~~~~~\n"
	        << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

								//UserLocation = getUserLocation();	//Current Users Location in file. Maybe use for tracking.
								//cout << UserLocation;
	cout << "\nTo register new user, key your password to authenticate\n\n";
	
	verifyUser();
	
	cout << "\nPlease fill in details of user to be registered\n\n";

	cout << "Username: ";
	getline(cin, newusername);

	cout << "Password: ";
	getline(cin, newpassword);
								//cout << newusername << newpassword;		//input test
	userfile.open("userFile.txt", ios::out | ios::app);

	if(!userfile)	
	{
		cout  << " Error Has occured while decrypting userFile, program shutting down.";
		exit(-1);
	}

	userfile << newusername + ";" + newpassword + ";\n";

	cout << "\n\nNew User "
	     << newusername
	     << " registered!\n\n";   
	 	
	userfile.close();   
}

void Account::ManageUser()
{	
	string line;
	int UserLocation = 0, userNotFound = 1,choice = 0;

	cout    << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
		<< "~~~~~~~~~~~~~~~~~~~~~~~~~Manage User~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
	        << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

	while(1)
	{
		cout << "\nPlease select an option!\n"
		     << "1. View Account Info\n"
		     << "2. Edit Account Info\n"
		     << "3. Change Password\n"
		     << "4. Back\n\n";

		cout << "Your Choice: ";

		cin  >> choice;

		switch(choice)
		{
			case 1: //View Account Info
				break;
			
			case 2: //Edit Account Info
				break;
			
			case 3: changePassword();
				break;

			case 4: LoginMenu();
				break;

			default: cout << "\nInvalid option selected, try again.\n\n";
		}

	}

}

void Account::verifyUser()
{
	int valid = 0, firstpass = 0, passInvalid = 0;

	string passcheck;

	while(valid != 1)
	{
		if(firstpass == 0)
		{
			cin.clear();
			cin.ignore(100,'\n');
			firstpass = 1;
		}

		cout << "Enter password: ";

		getline(cin, passcheck);

		if(password == passcheck)
		{
			cout << "\nUser verified\n\n";

			valid = 1;
			passInvalid = 0;
		}
		if(password != passcheck)
		{	
			passInvalid++;	
		}
		if(passInvalid == 1)
		{
			cout << "\nInvalid password, 2 attempts remaining\n\n";
		}
		if(passInvalid == 2)
		{
			cout << "\nInvalid password, 1 attempts remaining\n\n";
		}
		if(passInvalid == 3)
		{
			cout << "\nMax attempts exceeded, locking account\n\n";
			LockAccount();
		}	
		
	}	

}

void Account::changePassword()
{
	int Location = getUserLocation();

	string OldPassword = getcurrentpassword();

	verifyUser();

	cout  << "\nPlease enter current password to continue\n\n";
}

void Account::LoginMenu()
{
	int choice = 0;
	
	cout    << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
		<< "~~~~~~~~~~~~~~~~~~~~~~~~~~Login Menu~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
	        << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	
	while(1)
	{
		cout << "\nPlease select an option!\n"
		     << "1. Register New User\n"
		     << "2. Manage Account\n"
		     << "3. View Stock Information\n"
		     << "4. Logout\n\n";

		cout << "Your Choice: ";

		cin  >> choice;

		switch(choice)
		
			case 1: Register();			//Register done
				break;
			
			case 2: ManageUser();
				break;
			
			case 3: Stock();
				break;

			case 4: cin.clear();			//Clearing buffer for new login
				cin.ignore(100,'\n');
				Logout();						
				break;

			default: cout << "\nInvalid option selected, try again.\n\n";
		}

	}

}

void Account::Login()
{
	static bool AccountStatus = 0;

	cout    << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
		<< "~~~~~~~~~~Welcome to C-4's Warehouse Management Tool~~~~~~~~~~\n"
	        << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";

	while(1)						//Program will loop here Acting as the first screen for the user
	{

	AccountStatus = 0;

	cout	<< "Welcome to the system, please Login to access stock!\n\n";
	cout	<< "Username: ";
	getline(cin, username);

	cout	<< "Password: ";
	getline(cin, password);

	searchvar = username + ";" + password + ";";		//1; is a check for locked or non-locked account

	cout	<< "\nPlease wait while system verifies user... \n\n";

	Authentication();

	}
	
			   
}


void Account::Logout()
{
	cout <<	"\nThank you for using C-4's WMT "
	     << username
	     << ".\n\n"
	     << "Now logging out....\n\n";
								//cout << username << password << "HI";			//Testing erase

	username.erase  (username.begin(), username.end()); 	//Reset username and password
	password.erase  (password.begin(), password.end()); 
	searchvar.erase (searchvar.begin(), searchvar.end());	//Reset search variable

	Login();
								//cout << username << password << "HI";			//Testing erase		   
}

void Account::Stock()
{	   

	//Sid add your StockMenu calling function here.	

}

void Account::Authentication()
{	
	string line;
	int currentLine = 0, userNotFound = 1;
	string status;
	int statuscheck;						//Test variable
	int count = 0;

	static int FailedAttemptCount =0;
	ifstream userfile;

	userfile.open("userFile.txt", ios::in);

	if(!userfile)	
	{
		cout  << " Error Has occured while decrypting userFile, program shutting down.";
		exit(-1);
	}  
	
	while(getline(userfile, line)) 
	{ 
	    	
	    	if (line.find(searchvar, 0) != string::npos) 
		{
									//cout << "found: " << searchvar << "line: " << currentLine << endl; //Test if line found
			cout << "User found!\n\n";
			    
									//cout << line;

			istringstream iss(line);
  			string s;
			
			while(getline(iss, s, ';'))			//Go to a specific area of userFile
			{	
				count++;
				if(count == 3)
				{
									//status = s;
					statuscheck = s.at(0);		//if '49' means not locked.
									//cout << "\n\n" << status << "\n\n";
					
				}
			}
			
			FailedAttemptCount = 0;
			userNotFound = 0;
			AccountStatus = 1;
			
									//setaccStatus(status);
			setUserLocation(currentLine);			//Saves location of user in UserFile for other functions reference
			setcurrentpassword(password);			//Saves password in private for authentication
									//statuscheck = getaccStatus();
									//cout << statuscheck << "HERE";
	    	}
		currentLine++;						//cout << currentLine;				//Check which line
	}
	if(statuscheck == 48)
	{
		cout    << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
			<< "~~ALERT, YOUR ACCOUNT IS LOCKED PLEASE SEEK ADMIN TO UNLOCK.~~\n"
	        	<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
		Logout();
	}

	if(userNotFound == 1)
	{
		FailedAttemptCount++;
	}

	if(userNotFound == 1 && FailedAttemptCount == 1)
	{
		cout << "\nInvalid username or password entered please retry, 2 attempts remain!\n\n";
		AccountStatus = 0;
	}
	
	if(userNotFound == 1 && FailedAttemptCount == 2)
	{
		cout << "\nInvalid username or password entered please retry, 1 attempts remain!\n\n";
		AccountStatus = 0;
	}

	if(userNotFound == 1 && FailedAttemptCount >= 3)
	{
		cout << "\nYou have exceed the maximum attempts, your account is now locked\n\n";
		FailedAttemptCount = 0;
		AccountStatus = 0;
		LockAccount();
	}
	
	userfile.close(); 
	
	if(AccountStatus == 1)
	{
		if(statuscheck == 49)
		{
		
			cout << "Logging in...  Welcome "		//Goes to loginmenu
			     << username
			     << "\n\n";

			cout << "User has logged in!\n\n";

			LoginMenu();
			exit(0);
		}
									//exit(0);	//Test exit	
	}
	
}

void Account::LockAccount()
{	   
	//Do some account locking here
	cout << "Account is now locked.\n\n";
	AccountStatus = 0;
	Logout();
}

void Account::addWarningMessage()
{	   
}

void Account::displayWarningMessage()
{	   
}




Account::~Account()
{
}

int main()
{
    Account A;
    A.Login();	//Test operations

}




