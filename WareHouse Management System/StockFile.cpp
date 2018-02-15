#include "StockFile.h"


StockFile::StockFile()
{
}

void StockFile::addToStockFile(fstream& afile, char filename[], string id, string desc, string maincat, string subcat, int price, int qty, string trans)
{
	afile.open(filename, ios::out| ios::app);
	if(!afile){
		cout << "File writing failed to open! Exiting..";
		exit(-1);
	}	 
	else{
	afile<<id<<":"<<desc<<":"<<maincat<<":"<<subcat<<":"<<price<<":"<<qty<<":"<<trans<<"\n";
	}
	afile.close();  
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

