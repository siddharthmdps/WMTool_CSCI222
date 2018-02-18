#include "Stock.h"
#include "StockFile.cpp"
#include "StockSummary.cpp"

Stock::Stock()
{
}

bool Stock::addStock(fstream& afile,char filename[])
{
	string record, id, desc;
	bool found = false;
	cout << "Enter Item ID:";
	cin >> itemID;
	cout << "Enter Item Description:";
	cin >> itemDes;
	afile.open(filename, ios::in);
	if(!afile){
		cout << "File reading failed to open! Exiting..";
		return false;
	}	 
	else{
        while(getline(afile,record)){
			istringstream ss(record);
			getline(ss,id,':');
			getline(ss,desc,':');
			if((id==itemID) && (desc==itemDes)){
				found = true;
			}
		}
	
	}
	afile.close();
	if(found == true){
		cout << "Invalid Input. Duplicate already exist!" << endl;
	}
	else{
		StockFile sf;
		cout << "Enter Item Category: ";
		cin >> MainCategory;
		cout << "Enter Item Sub-Category: ";
		cin >> SubCategory;
		cout << "Enter Price:";
		cin >> price;
		cout << "Enter Item Quantity: ";
		cin >> qty;
		cout << "Enter Transaction Date(DD-MMM-YY): ";
		cin >> TransactionDate;
		if(sf.addToStockFile(afile, filename, itemID, itemDes, MainCategory, SubCategory, price,qty,TransactionDate)){
				cout << "Record with Item ID: " << itemID << " and Item Description: " << itemDes << " is added to the file!"<< endl;
				return true;
		}
		else{
			cout << "Adding record to the file failed!"<< endl;
			return false;
			}
	}
	
}

bool Stock::removeStock(fstream& afile,char filename[])
{

	string record, id, desc;
	fstream bfile;
	bool found = false;
	cout << "Enter Item ID:";
	cin >> itemID;
	cout << "Enter Item Description:";
	cin >> itemDes;
	afile.open(filename, ios::in);
	bfile.open("temp.txt", ios::out);
	if(!afile || !bfile){
		cout << "File reading failed to open! Exiting..";
		return(false);
	}	 
	else{
        while(getline(afile,record)){
			istringstream ss(record);
			getline(ss,id,':');
			getline(ss,desc,':');
			if((id==itemID) && (desc==itemDes)){
				found = true;
			}
			else{
				bfile << record << endl;
			}
		}
	
	}
	afile.close();
	bfile.close();
	remove(filename);
	rename("temp.txt", filename);
	if(found == true){
		cout << "Record with Item ID: " << itemID << " and Item Description: " << itemDes << " is removed!"<< endl;
		return true;
	}
	else{
		cout << "Record Not Found! Please Try Again!" << endl;
		return false;
	}
	

}

bool Stock::editStock(fstream& afile,char filename[])
{
	string id, des, record, price, qty;
	int subChoice;
	bool found = false;
	fstream bfile;
	afile.open(filename, ios::in);
	bfile.open("temp.txt", ios::out);
	
	cout << "\nWelcome to Edit Stock" << endl;
	cout << "______________________"  << endl;
	cout << "\nPlease enter Item ID that you want to edit: ";
	cin  >> id;
		
	if(!afile)
	{
		cout << "File reading failed to open! Exiting..";
		return(false);
	}
	else
	{
        while(getline(afile,record))
		{
			istringstream ss(record);
			getline(ss,itemID,':');
			getline(ss,itemDes,':');
			getline(ss,MainCategory,':');
			getline(ss,SubCategory,':');
			getline(ss,price,':');
			getline(ss,qty,':');
			getline(ss,TransactionDate,'\n');
			
			if(id == itemID){
				found = true;
				cout << "Record with Item ID: " << id << " and Item Description: " << itemDes << " is found!"<< endl;
				cout << "\nPlease select what would you like to Edit (Any other input will return to main screen!)"<< endl;
				cout << "-----------------------------------------" << endl;
				cout << "1) Description " << endl;
				cout << "2) Category " << endl;
				cout << "3) Sub Category " << endl;
				cout << "4) Price " << endl;
				cout << "5) Quantity " << endl;
				cout << "6) Transacted Date" << endl;
				cout << "-----------------------------------------" << endl;
				cout << "Your choice: ";
				cin  >> subChoice;
				if (subChoice == 1)
				{
					do{	    
						cout << "Enter new Description: ";
						cin.ignore();
						getline(cin, itemDes);
					}while(itemDes=="");
					
				}
				if (subChoice == 2)
				{	  
					cout << "Enter new Category: ";
					getline(cin,MainCategory);
					
				}
				if (subChoice == 3)
				{	  
					cout << "Enter new Sub-Category: ";
					getline(cin, SubCategory);
					
				}
				if (subChoice == 4)
				{	  
					cout << "Enter new Price: ";
					getline(cin, price);
					
				}
				if (subChoice == 5)
				{	  
					cout << "Enter new Quantity: ";
					getline(cin, qty);
					
				}
				if (subChoice == 6)
				{	  
					cout << "Enter new Transacted-Date: ";
					getline(cin, TransactionDate);
					
				}
				cout << "Item is now changed to:\nID:"<< itemID<<"\nDescription:"
			 <<itemDes<<"\nMain-Category:"<<MainCategory<<"\nSub-Category:"<<SubCategory
			 <<"\nPrice:"<<price<<"\nQuantity:"<<qty<<"\nTrans-Date:"<<TransactionDate<<"\n";	
			}
			bfile<<itemID<<":"<<itemDes<<":"<<MainCategory<<":"<<SubCategory<<":"<<price<<":"<<qty<<":"<<TransactionDate<<"\n";
		}
	}
	afile.close();
	bfile.close();
	remove(filename);
	rename("temp.txt", filename);  
	if (found == true)
	{	
		return true;
	}
	else{
		cout << "Item with id - " << id << " could not be found! " << endl;
		cout << "Please try again" << endl;
		return false;
	}

}

void Stock::searchStock(fstream& afile,char filename[])
{
	string keyword, record, qty, price;
	bool found = false;
	cout << "Enter any keyword to search(ID or Name or Main/Sub-Category):";
	cin >> keyword;

	afile.open(filename, ios::in);
	if(!afile){
		cout << "File reading failed to open! Exiting..";
		return ;
	}	 
	else{
		cout << left << setw (10) << "Item ID" 
					 << left << setw (30) << "Item Description"
					 << left << setw (15) << "Main Cat" 
					 << left << setw (15) << "Sub Cat"
					 << left << setw (15) << "Price" 
					 << left << setw (12) << "Quantity"
					 << left << setw (10) << "Date" << endl;
        while(getline(afile,record)){
			istringstream ss(record);
			getline(ss,itemID,':');
			getline(ss,itemDes,':');
			getline(ss,MainCategory,':');
			getline(ss,SubCategory,':');
			getline(ss,price,':');
			getline(ss,qty,':');
			getline(ss,TransactionDate,'\n');
			if((keyword==itemID) || (keyword==MainCategory) || (keyword==itemDes) || (keyword==SubCategory) || (keyword==price) || (keyword==qty) || (keyword==TransactionDate)){
				found = true;
				cout << left << setw (10)  << itemID;
				cout << left << setw (30) << itemDes;
				cout << left << setw (15) << MainCategory;
				cout << left << setw (15) << SubCategory;
				cout << left << setw (15) << price;
				cout << left << setw (12) << qty;
				cout << left << setw (10) << TransactionDate;
				cout << endl;	 
			}
		}
		cout << endl << endl << endl;
		}
	if (found == false){	
		cout << "No Item with '" << keyword << "' is found! " << endl;
		cout << "Please try again" << endl;
	}
	afile.close();
}

void Stock::summaryReport(fstream& afile,char filename[], int option)
{

	StockSummary ss;
	if(option == 0)ss.dailyReport(afile, filename);
	if(option == 1)ss.weeklyReport(afile, filename);
	if(option == 2)ss.monthlyReport(afile, filename);	  
	if(option == 3)ss.yearlyReport(afile, filename);
/*
	fstream afile;	  
	string id, desc, record, maincat, subcat, qty, transdate, price;
	bool found = false;

	afile.open("StockFile.txt", ios::in);
	if(!afile){
		cout << "File reading failed to open! Exiting..";
	}	 
	else{
		cout << left << setw (10)  << "Item ID" 
			 << left << setw (30) << "Item Description"
			 << left << setw (15) << "Main Cat" 
			 << left << setw (15) << "Sub Cat"
			 << left << setw (15) << "Price" 
			 << left << setw (12) << "Quantity"
			 << left << setw (10) << "Date" << endl;
        while(getline(afile,record))
		{
			istringstream ss(record);
			getline(ss,id,':');
			getline(ss,desc,':');
			getline(ss,maincat,':');
			getline(ss,subcat,':');
			getline(ss,price,':');
			getline(ss,qty,':');
			getline(ss,transdate,'\n');
 	//	 if(id==itemID)
	   		{
				cout << left << setw (10)  << id;
				cout << left << setw (30) << desc ;
				cout << left << setw (15) << maincat;
				cout << left << setw (15) << subcat;
				cout << left << setw (15) << price;
				cout << left << setw (12) << qty;
				cout << left << setw (10) << transdate;
				cout << endl;
			}
			
		}
	
	}
	afile.close();
*/
}

void Stock::stockMenu()
{
	char selection;
	fstream afile;
	selection = 'Z';
	while(toupper(selection)!= 'I'){
	cout << "-------------------------------------------" << endl;
	cout << "Welcome to the WareHouse Management System" << endl
		 << "-------------------------------------------" << endl << endl;
	
	cout << "Please select an Option:" << endl << endl;
	cout << "\ta) Add new stock" << endl;
	cout << "\tb) Remove stock" << endl;
	cout << "\tc) Edit stock item" << endl;
	cout << "\td) Search stock item" << endl;
	cout << "\te) Daily stock summary report" << endl;
	cout << "\tf) Weekly stock summary report" << endl;
	cout << "\tg) Monthly stock summary report" << endl;
	cout << "\th) Yearly stock summary report" << endl;
	cout << "\ti) Quit" << endl << endl;
	
	cout << "-------------------------------------------" << endl;
	
		cout << "Your selection: ";
		cin >> selection;
		switch(selection){
			case 'a':
			case 'A':
				addStock(afile, "StockFile.txt");
				break;
			case 'b':
			case 'B':
				removeStock(afile, "StockFile.txt");
				break;
			case 'c':
			case 'C':
				editStock(afile, "StockFile.txt");
				break;
			case 'd':
			case 'D':
				searchStock(afile, "StockFile.txt");
				break;
			case 'e':
			case 'E':
				summaryReport(afile, "StockFile.txt", 0);
				break;
			case 'f':
			case 'F':
				summaryReport(afile, "StockFile.txt", 1);
				break;
			case 'g':
			case 'G':
				summaryReport(afile, "StockFile.txt", 2);
				break;
			case 'h':
			case 'H':
				summaryReport(afile, "StockFile.txt", 3);
				break;
			case 'i':
			case 'I':
				break;
			default:
				cout << "Please select an Option given above!!..:)" << endl;
				break;
			
		}
		system("PAUSE");
		system("CLS");
	} 
	

}

void Stock::displayOutput()
{
}

Stock::~Stock()
{
}

