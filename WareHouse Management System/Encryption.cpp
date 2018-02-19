#include "Encryption.h"

Encryption::Encryption()
{

}

Encryption::~Encryption()
{

}

void Encryption::encryptUserFile()
{
	string reading;
	char character;
	ifstream userfile("userFile.txt"); 	    //File to read from
	ofstream fileout("xxxxxxxx.txt");	 	//Temporary file

	EncryptionKey = 5;
	
		while(getline(userfile,reading)){
			for(int i=0;i<reading.size();i++){
				character=reading.at(i);
				character+=EncryptionKey;
				reading.at(i)=character;
			}
			fileout<<reading<<endl;	   
		}

	    userfile.close();
	    fileout.close();
		
		remove( "userFile.txt" );
		rename("xxxxxxxx.txt", "xxxxxxxx.o");

	    cout << "\nEncryption successful\n\n";
	
}

void Encryption::decryptUserFile()
{
	string reading;
	char character;
	rename("xxxxxxxx.o", "xxxxxxxx.txt");
	ifstream userfile("xxxxxxxx.txt"); 	//File to read from
	ofstream fileout("userFile.txt");	   	  //Temporary file

	EncryptionKey = 5;
	
		while(getline(userfile,reading)){
			for(int i=0;i<reading.size();i++){
				character=reading.at(i);
				character-=EncryptionKey;
				reading.at(i)=character;
			}
			fileout<<reading<<endl;	   
		}

	    userfile.close();
	    fileout.close();
		
		remove( "xxxxxxxx.txt" );

	    cout << "\nEncryption successful\n\n";
}

void Encryption::encryptStockFile()
{

	string reading;
	char character;
	ifstream stockfile("StockFile.txt"); 	  //File to read from
	ofstream fileout("yyyyyyyy.txt");	 	//Temporary file

	EncryptionKey = 5;
	
		while(getline(stockfile,reading)){
			for(int i=0;i<reading.size();i++){
				character=reading.at(i);
				character+=EncryptionKey;
				reading.at(i)=character;
			}
			fileout<<reading<<endl;	   
		}

	    stockfile.close();
	    fileout.close();
		
		remove( "StockFile.txt" );
		rename("yyyyyyyy.txt", "yyyyyyyy.o");

	    cout << "\nEncryption successful\n\n";
		
	
}

void Encryption::decryptStockFile()
{

	string reading;
	char character;
	rename("yyyyyyyy.o", "yyyyyyyy.txt");
	ifstream stockfile("yyyyyyyy.txt"); 	  //File to read from
	ofstream fileout("StockFile.txt");	   	  //Temporary file

	EncryptionKey = 5;
	
		while(getline(stockfile,reading)){
			for(int i=0;i<reading.size();i++){
				character=reading.at(i);
				character-=EncryptionKey;
				reading.at(i)=character;
			}
			fileout<<reading<<endl;	   
		}

	    stockfile.close();
	    fileout.close();
		
		remove( "yyyyyyyy.txt" );

	    cout << "\nDecryption successful\n\n";
}

