#include "Stock.h"
#include "StockFile.cpp"
#include "StockSummary.cpp"

Stock::Stock()
{
}

void Stock::addStock(fstream& afile,char filename[])
{
	cout << "\n Add Stock Menu: \n";
	string record, id, desc;
	bool found = false;
	cout << "Enter Item ID:";
	cin >> itemID;
	cout << "Enter Item Description:";
	cin.ignore();
	getline(cin, itemDes);
		StockFile sf;
		cout << "Enter Item Category: ";
		getline(cin, MainCategory);
		cout << "Enter Item Sub-Category: ";
		getline(cin, SubCategory);
		cout << "Enter Price:";
		cin >> price;
		cout << "Enter Item Quantity: ";
		cin >> qty;
		cout << "Enter Transaction Date(DD-MMM-YY): ";
		cin >> TransactionDate;
		if(sf.addToStockFile(afile, filename, itemID, itemDes, MainCategory, SubCategory, price,qty,TransactionDate)){
				cout << "\nRecord with Item ID: " << itemID << " and Item Description: " << itemDes << " is added to the file!"<< endl;
				return ;
		}
		else{
			cout << "\nAdding record to the file failed!"<< endl;
			return ; 
			}
	
}

void Stock::removeStock(fstream& afile,char filename[])
{
	cout << "\nRemove Stock Menu: \n";
	string record, id, desc;
	fstream bfile;
	bool found = false;
	cout << "Enter Item ID:";
	cin >> itemID;
	cout << "Enter Item Description:";
	cin.ignore();
	getline(cin, itemDes);
	afile.open(filename, ios::in);
	bfile.open("temp.txt", ios::out);
	if(!afile || !bfile){
		cout << "\nFile reading failed to open! Exiting..";
		return;
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
		cout << "\nRecord with Item ID: " << itemID << " and Item Description: " << itemDes << " is removed!"<< endl;
		return;
	}
	else{
		cout << "\nRecord Not Found! Please Try Again!" << endl;
		return;
	}
	

}

void Stock::editStock(fstream& afile,char filename[])
{
	string id, des, record, price, qty, tempdes,tempmaincat,tempsubcat,tempprice;
	int subChoice;
	bool found = false;
	fstream bfile;
	afile.open(filename, ios::in);
	bfile.open("temp.txt", ios::out);
	
	cout << "\nEdit Stock Menu: \n" << endl;
	cout << "______________________"  << endl;
	cout << "\nEnter Item ID: ";
	cin  >> id;
		
	if(!afile)
	{
		cout << "File reading failed to open! Exiting..";
		return;
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
				if(!found){
				cout << "\nRecord with Item ID: " << id << " and Item Description: " << itemDes << " is found!"<< endl;
				cout << "\nPlease select what would you like to Edit (Any other input will return to main screen!)"<< endl;
				cout << "-----------------------------------------" << endl;
				cout << "1) Description " << endl;
				cout << "2) Category " << endl;
				cout << "3) Sub Category " << endl;
				cout << "4) Price " << endl;
				cout << "-----------------------------------------" << endl;
				cout << "Your choice: ";
				cin  >> subChoice;
				cout << endl;
				}
				
				if (subChoice == 1)
				{	
					if(!found){
						cout << "Enter new Description: ";
						cin.ignore();
						getline(cin, tempdes);
					}
					itemDes=tempdes;
					
				}
				if (subChoice == 2)
				{	
					if(!found){  
						cout << "Enter new Category: ";
						cin.ignore();
						getline(cin,tempmaincat);
					}
					MainCategory=tempmaincat;
					
				}
				if (subChoice == 3)
				{	
					if(!found){  
					cout << "Enter new Sub-Category: ";
					cin.ignore();
					getline(cin, tempsubcat);
					}
					SubCategory=tempsubcat;
				}
				if (subChoice == 4)
				{	 
					if(!found){ 
					cout << "Enter new Price: ";
					cin.ignore();
					getline(cin, price);
					}
					price=tempprice;
					
				}
				if(!found){
				cout << "\nItem is now changed to:\nID:"<< itemID<<"\nDescription:"
			 <<itemDes<<"\nMain-Category:"<<MainCategory<<"\nSub-Category:"<<SubCategory
			 <<"\nPrice:"<<price << endl;
			 }
			 found = true;	
			 
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
		return ;
	}
	else{
		cout << "Item with id - " << id << " could not be found! " << endl;
		cout << "Please try again" << endl;
		return ;
	}

}

void Stock::searchStock(fstream& afile,char filename[])
{
	cout << "\nSearch Stock Menu: \n";
	string keyword, record, qty, price;
	bool found = false;
	cout << "Enter any keyword to search:";
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
	cout << "\n Summary Report Menu: \n";
	StockSummary ss;
	if(option == 0)ss.dailyReport(afile, filename);
	if(option == 1)ss.weeklyReport(afile, filename);
	if(option == 2)ss.monthlyReport(afile, filename);	  
	if(option == 3)ss.yearlyReport(afile, filename);
}

void Stock::stockMenu()
{
	StockFile sf;
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
				addStock(afile, sf.filename);
				break;
			case 'b':
			case 'B':
				removeStock(afile,  sf.filename);
				break;
			case 'c':
			case 'C':
				editStock(afile,  sf.filename);
				break;
			case 'd':
			case 'D':
				searchStock(afile,  sf.filename);
				break;
			case 'e':
			case 'E':
				summaryReport(afile,  sf.filename, 0);
				break;
			case 'f':
			case 'F':
				summaryReport(afile,  sf.filename, 1);
				break;
			case 'g':
			case 'G':
				summaryReport(afile,  sf.filename, 2);
				break;
			case 'h':
			case 'H':
				summaryReport(afile,  sf.filename, 3);
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

Stock::~Stock()
{
}

