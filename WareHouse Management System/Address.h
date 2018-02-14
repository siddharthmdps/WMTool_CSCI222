#include <iostream>
#include <cstdlib>
using namespace std;

class Address{

    public:
	  Address();	   
	  ~Address();
	  void AddAddress();
	  void DeleteAddress();
	  void UpdateAddress();
	  void getAddress();
	  
	  char Street[100]; char City[100]; int PostalCode; 
      char State[100]; char Country[100];
};

