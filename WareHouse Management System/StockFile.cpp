#include "StockFile.h"


StockFile::StockFile()
{
}

bool StockFile::addToStockFile(fstream& afile, char filename[], string id, string desc, string maincat, string subcat, int price, int qty, string trans)
{
	afile.open(filename, ios::out| ios::app);
	if(!afile){
		cout << "File writing failed to open! Exiting..";
		return false;
	}	 
	else{
	afile<<id<<":"<<desc<<":"<<maincat<<":"<<subcat<<":"<<price<<":"<<qty<<":"<<trans<<"\n";
	}
	afile.close();
	return true;  
}


void StockFile::updateToStockFile()
{	   
}


void StockFile::processStockFile()
{	   
}


void StockFile::removeFromStockFile()
{	   
}

void StockFile::searchInStockFile()
{	   
}

StockFile::~StockFile()
{
}

