
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <sstream>


using namespace std;

class Account{

   	 public:
		
	
		int FailedAttemptCount;	 //Track Failed Login
		bool AccountStatus;	 //Track login
		

		std::string username;
		std::string password;
		std::string searchvar;
	
		Account();	        
		~Account();

		void setUserLocation(int UL);
		int  getUserLocation();

		void setaccStatus(string AC);
		string getaccStatus();

		void setcurrentpassword(string CP);
		string getcurrentpassword();

		void Register();
		void LoginMenu();
		void Login();			//File is delimited by ;
	  	void Logout();	
	  	void Stock();	
	  	void Authentication();
	  	void LockAccount();
	  	void addWarningMessage();
	  	void displayWarningMessage();
	  	void ManageUser();
		void changePassword();
		void verifyUser();		//Called when user needs to be verified while doing certain tasks
		
	
	private:
	  	std::string currentpassword;	//For Authentication purposes
		int UserLocation;	 	//Track which user is using program
		std::string accStatus;
	  	
};

#endif // ACCOUNT_H
