//#include <iostream>
//#include <cstdlib>

struct stockrecord{
		string id, desc, maincat, subcat, qty, price, compdate, in, out, endDate;
		
	};
	
class StockSummary{

      public:
	     StockSummary();
		 ~StockSummary();
		 string incrementDate(string);
		 string incrementMonth(string);
		 string incrementYear(string);
		 string Int2String(int&);
		 void dailyReport(fstream&,char []);
		 void weeklyReport(fstream&,char []);
		 void monthlyReport(fstream&,char []);
		 void yearlyReport(fstream&,char []);
};

