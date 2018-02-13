#include <iostream>
#include <cstdlib>
using namespace std;

class Encryption{

    public:
	  Encryption();	   
	  ~Encryption();
	  void EncryptUserFile();
	  void DecryptUserFile();
	  void EncryptStockFile();
	  void DecryptStockFile();
	  
	  
	  bool EncryptionStatus;
	  char EncryptionKey[100]; 
      char DecryptionKey[100];
};

