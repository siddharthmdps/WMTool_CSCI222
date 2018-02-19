#include "Encryption.h"

Encryption::Encryption()
{

}

Encryption::~Encryption()
{

}

void Encryption::encryptUserFile()
{

	ifstream userfile("userFile.txt"); 		//File to read from
	ofstream fileout("usertmp.txt");	 	//Temporary file

	EncryptionKey = 5;
	//DecryptionKey = -1;
	//outfile.open (outfileloc.c_str()); //opens the output file

	while (!userfile.eof())	//while not the end of the file
	{
			//cout << "HI";
			char name;	//character from file to be encrypted
			userfile.get(name);	//gets character from the file
			name = name + EncryptionKey;	//adds the part of the password array
			//name = name + DecryptionKey;
			fileout << name;	//prints that character to the output file
	}

	    userfile.close();
	    fileout.close();
		
		remove( "userFile.txt" );

	    rename( "usertmp.txt" , "xxxxxxxx.txt" );	//refresh userFile
	
	    EncryptionStatus = 1;

	    cout << "\nEncryption successful\n\n";
		
	
}

void Encryption::decryptUserFile()
{
	DecryptionKey = -5;

	ifstream userfile("xxxxxxxx.txt"); 		//File to read from
	ofstream fileout("usertmp.txt");	 	//Temporary file

	//outfile.open (outfileloc.c_str()); //opens the output file

	while (!userfile.eof())	//while not the end of the file
	{
			//cout << "HI";
			char name;	//character from file to be encrypted
			userfile.get(name);	//gets character from the file
			//name = name + EncryptionKey;	//adds the part of the password array
			name = name + DecryptionKey;
			fileout << name;	//prints that character to the output file
	}

	    userfile.close();
	    fileout.close();
		
		remove( "xxxxxxxx.txt");

	    rename( "usertmp.txt" , "userFile.txt" );	//refresh userFile
	
	    EncryptionStatus = 1;

	    cout << "\nDencryption successful\n\n";
}

void Encryption::encryptStockFile()
{

	ifstream userfile("userFile.txt"); 		//File to read from
	ofstream fileout("usertmp.txt");	 	//Temporary file

	EncryptionKey = 5;
	//DecryptionKey = -1;
	//outfile.open (outfileloc.c_str()); //opens the output file

	while (!userfile.eof())	//while not the end of the file
	{
			//cout << "HI";
			char name;	//character from file to be encrypted
			userfile.get(name);	//gets character from the file
			name = name + EncryptionKey;	//adds the part of the password array
			//name = name + DecryptionKey;
			fileout << name;	//prints that character to the output file
	}

	    userfile.close();
	    fileout.close();
		
		remove( "userFile.txt" );

	    rename( "usertmp.txt" , "xxxxxxxx.txt" );	//refresh userFile
	
	    EncryptionStatus = 1;

	    cout << "\nEncryption successful\n\n";
		
	
}

void Encryption::decryptStockFile()
{
	DecryptionKey = -5;

	ifstream userfile("xxxxxxxx.txt"); 		//File to read from
	ofstream fileout("usertmp.txt");	 	//Temporary file

	//outfile.open (outfileloc.c_str()); //opens the output file

	while (!userfile.eof())	//while not the end of the file
	{
			//cout << "HI";
			char name;	//character from file to be encrypted
			userfile.get(name);	//gets character from the file
			//name = name + EncryptionKey;	//adds the part of the password array
			name = name + DecryptionKey;
			fileout << name;	//prints that character to the output file
	}

	    userfile.close();
	    fileout.close();
		
		remove( "xxxxxxxx.txt");

	    rename( "usertmp.txt" , "userFile.txt" );	//refresh userFile
	
	    EncryptionStatus = 1;

	    cout << "\nEncryption successful\n\n";
}

//int main()
//{

//Encryption E;

//E.encryptUserFile();	  //testing
//E.decryptUserFile();

//}

