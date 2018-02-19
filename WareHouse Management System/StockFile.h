
class StockFile{

    public:
		char filename[15];
	  StockFile();	  
	  ~StockFile();
	  bool addToStockFile(fstream&, char [], string, string, string, string, int, int, string);
	  
};

