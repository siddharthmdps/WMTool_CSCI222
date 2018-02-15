#include "Account.h"



Account::Account()
{
}

void Account::Register()
{	   
}


void Account::Login()
{
	static bool AccountStatus = 0;

	cout    << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
		<< "~~~~~~~~~~Welcome to C-4's Warehouse Management Tool~~~~~~~~~~\n"
	        << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";

	while(1)	//Program will loop here Acting as the first screen for the user
	{

	AccountStatus = 0;

	cout	<< "Welcome to the system, please Login to access stock!\n\n";
	cout	<< "Username: ";
	getline(cin, username);

	cout	<< "Passowrd: ";
	getline(cin, password);

	searchvar = username + ";" + password + ";";

	cout	<< "\nPlease wait while system verifies user... \n\n";

	Authentication();

	}
	
			   
}


void Account::Logout()
{	   
}

void Account::Stock()
{	   
}

void Account::Authentication()
{	
	string line;
	int currentLine = 0, userNotFound = 1;
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
	    	currentLine++;
	    	if (line.find(searchvar, 0) != string::npos) 
		{
			//cout << "found: " << searchvar << "line: " << currentLine << endl; //Test if line found
			cout << "User found! Logging in...  Welcome "
			     << username
			     << "!\n\n";
			//Once 
			FailedAttemptCount = 0;
			userNotFound = 0;
			AccountStatus = 1;
	    	}
		
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
		//Go to next screen after user login.
		cout << "User has logged in ";
		exit(0);	

	}
	
}

void Account::LockAccount()
{	   
	//Do some account locking here
	cout << "Account is now locked.\n\n";
	AccountStatus = 0;
}

void Account::addWarningMessage()
{	   
}

void Account::displayWarningMessage()
{	   
}

void Account::ManageUser()
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





