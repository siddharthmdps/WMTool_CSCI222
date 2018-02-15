
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <cctype>


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

		void Register();
		void Login();		//File is delimited by ;
	  	void Logout();
	  	void Stock();	
	  	void Authentication();
	  	void LockAccount();
	  	void addWarningMessage();
	  	void displayWarningMessage();
	  	void ManageUser();
	  
	  	
};

#endif // ACCOUNT_H
