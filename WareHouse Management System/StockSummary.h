#include <iostream>
#include <cstdlib>

struct stockrecord{
		string id, desc, maincat, subcat, qty, price, compdate;
		//int quantity;
		
	};

class StockSummary{

      public:
	     StockSummary();
		 ~StockSummary();
		 int String2Int(string&);
		 string Int2String(int&);
		 void dailyReport(fstream&,char []);
		 void weeklyReport(fstream&,char []);
		 void monthlyReport(fstream&,char []);
		 void yearlyReport(fstream&,char []);
};

