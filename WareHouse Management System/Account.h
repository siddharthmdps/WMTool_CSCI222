

class Account{

   	 public:
		
		Encryption e;
		
		int FailedAttemptCount;	 	//Track Failed Login
		int Linenumber, encryptcheck;
		bool AccountStatus;	 	//Track login
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

		void viewInfo();				//ManageUser options
		void editInfo();
		void changePassword();		
	  	
	  	void addWarningMessage();	//Stock related features
	  	void displayWarningMessage();
	  	
		
		
	
	private:
	  	std::string currentpassword;	//For Authentication purposes
		int UserLocation;	 	//Track which user is using program
		std::string accStatus;
	  	
};


