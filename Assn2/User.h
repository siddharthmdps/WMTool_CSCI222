#include <iostream>
#include <cstdlib>
using namespace std;

class User{

    public:
	  User();	 
	  ~User();
	  void addUser();
	  void updateUser();
	  void verifyUser();
	  
	  char Password[100]; 
      char UserID[100];
};

