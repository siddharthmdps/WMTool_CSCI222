#include "Stock.h"
#include "StockFile.cpp"

Stock::Stock()
{
}

void Stock::addStock(fstream& afile,char filename[])
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
		exit(-1);
	}	 
	else{
        while(getline(afile,record)){
			istringstream ss(record);
			getline(ss,id,':');
			getline(ss,desc,':');
			cout <<"ID"<< id << "Desc"<< desc << "\n";
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
		sf.addToStockFile(afile, filename, itemID, itemDes, MainCategory, SubCategory, price,qty,TransactionDate);
	}
	
}

void Stock::removeStock()
{
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
	while(toupper(selection)!= 'I'){
		cout << "Your selection: ";
		cin >> selection;
		switch(selection){
			case 'a':
			case 'A':
				addStock(afile, "StockFile.txt");
				break;
			case 'b':
			case 'B':
				removeStock();
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
	} 
	

}

void Stock::displayOutput()
{
}

Stock::~Stock()
{
}

