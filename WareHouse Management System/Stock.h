#include <iostream>
#include <cstdlib>
using namespace std;

class Stock{
     
	public: 
	  Stock();
	  void addStock();
	  void removeStock();
	  void editStock();
	  void searchStock();
	  void stockMenu();
	  void summaryReport();
	  void displayOutput();
	  ~Stock();
	  
	  char itemID[100]; char itemDes[200]; char MainCategory[100];
      char SubCategory[100];char IncomingStock[100]; char Outgoing Stock[100];	  
	  char TransactionID[100]; char TransactionDate[100];
	  int Treshold; int price;  
};

