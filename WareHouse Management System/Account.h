
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
#include <stdlib.h>


using namespace std;

class Account{

   	 public:
		
	
		int FailedAttemptCount;	 	//Track Failed Login
		bool AccountStatus;	 	//Track login
		int Linenumber;
		
		//user input and search vars
		std::string username;		
		std::string password;		
		std::string searchvar;		
		//user input and search vars

		//Construct and Destruct
		Account();	        	
		~Account();		
		//Construct and Destruct

		//mutators and accessors
		void setUserLocation(int UL);	
		int  getUserLocation();

		void setaccStatus(string AC);
		string getaccStatus();

		void setcurrentpassword(string CP);
		string getcurrentpassword();
		//mutators and accessors
		void login();			
		
		void loginMenu();		//LoginMenu and its options
		void registerUser();		//1.
		void manageUser();		//2.
		void stock();			//3.
		void logout();			//4.
					
		void lockAccount();		//when system needs to lock account
		void verifyUser();		//used when needed to verify user
	  	void authentication();

						//ManageUser options
		void changePassword();		
	  	
	  	void addWarningMessage();	//Stock related features
	  	void displayWarningMessage();
	  	
		
		
	
	private:
	  	std::string currentpassword;	//For Authentication purposes
		int UserLocation;	 	//Track which user is using program
		std::string accStatus;
	  	
};

#endif // ACCOUNT_H
