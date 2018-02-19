

class Stock{
     
	public: 
	
		string itemID, itemDes, MainCategory,
     		 SubCategory,   
	  		 TransactionID, TransactionDate;
	  	int Threshold, price, qty, IncomingStock, OutgoingStock;  
	  
	  	Stock();
		~Stock();
	  	void addStock(fstream&, char []);
	  	void removeStock(fstream&, char []);
	  	void editStock(fstream&,char []);
	  	void searchStock(fstream&,char []);
	  	void stockMenu();
	  	void summaryReport(fstream&,char [], int);
	  	
	  
	  
};

