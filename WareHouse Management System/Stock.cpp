#include "Stock.h"
#include "StockFile.cpp"

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

void Stock::editStock()
{
}

void Stock::searchStock()
{
}

void Stock::summaryReport(int option)
{
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
				editStock();
				break;
			case 'd':
			case 'D':
				searchStock();
				break;
			case 'e':
			case 'E':
				summaryReport(0);
				break;
			case 'f':
			case 'F':
				summaryReport(1);
				break;
			case 'g':
			case 'G':
				summaryReport(2);
				break;
			case 'h':
			case 'H':
				summaryReport(3);
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

