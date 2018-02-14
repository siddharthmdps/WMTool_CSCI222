#include <iostream>
#include <cstdlib>
using namespace std;

class Details{

    public:
	  Details();	   
	  ~Details();
	  void getDetails();
	  
	  char FirstName[100]; char LastName[100]; char MiddleName[100];
      char Email[100]; int Phone;
};

