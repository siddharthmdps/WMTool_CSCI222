#include <iostream>
#include <cstdlib>
using namespace std;

class Account{

    public:
		bool AccountStatus; //Never include user yet from user class
			
		Account();	        
		~Account();
		void Register();
		void Login();
	  	void Logout();
	  	void Stock();	
	  	void Authentication();
	  	void LockAccount();
	  	void addWarningMessage();
	  	void displayWarningMessage();
	  	void ManageUser();
	  
	  	
};

