
class StockFile{

    public:
	  StockFile();	  
	  ~StockFile();
	  bool addToStockFile(fstream&, char [], string, string, string, string, int, int, string);
	  void removeFromStockFile();
	  void updateToStockFile();
	  void processStockFile();
	  void searchInStockFile();
	  
};

