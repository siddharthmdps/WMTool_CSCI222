

class Stock{
     
	public: 
	
		string itemID, itemDes, MainCategory,
     		 SubCategory,   
	  		 TransactionID, TransactionDate;
	  	int Threshold, price, qty, IncomingStock, OutgoingStock;  
	  
	  	Stock();
		~Stock();
	  	bool addStock(fstream&, char []);
	  	bool removeStock(fstream&, char []);
	  	bool editStock(fstream&,char []);
	  	void searchStock(fstream&,char []);
	  	void stockMenu();
	  	void summaryReport(fstream&,char [], int);
	  	void displayOutput();
	  	
	  
	  
};

