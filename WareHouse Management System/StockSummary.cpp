#include "StockSummary.h"

StockSummary::StockSummary()
{

}

StockSummary::~StockSummary()
{
}
string StockSummary::Int2String(int& integer)
{
	bool negative=false;
	int temp=integer;
	string tempresult,result;
	if(integer<0){
		negative = true;
		temp=0-temp;
	}
	while(temp>0){
		tempresult+=((temp%10)+48);
		temp=temp/10;
	}
	if(negative)result+="-";
	for(int i=tempresult.length()-1;i>=0;i--){
		result+=tempresult[i];
	}
	return result;
}

void StockSummary::dailyReport(fstream& afile,char filename[])
{
	
	stockrecord s;
	string monthnum, date, month, year, record;
	vector<stockrecord> stockvector;
	vector<string> dates;
	ostringstream convert;
	bool found = false;

	afile.open(filename, ios::in);
	if(!afile){
		cout << "File reading failed to open! Exiting..";
	}	 
	else{
        while(getline(afile,record))
		{
			istringstream ss(record);
			getline(ss,s.id,':');
			getline(ss,s.desc,':');
			getline(ss,s.maincat,':');
			getline(ss,s.subcat,':');
			getline(ss,s.price,':');
			getline(ss,s.qty,':');
			getline(ss,date,'-');
			getline(ss,month,'-');
			getline(ss,year,'\n');
			s.compdate=date+"-"+month+"-"+year;
			if(month=="Jan")monthnum="01";
			if(month=="Feb")monthnum="02";
			if(month=="Mar")monthnum="03";
			if(month=="Apr")monthnum="04";
			if(month=="May")monthnum="05";
			if(month=="Jun")monthnum="06";
			if(month=="Jul")monthnum="07";
			if(month=="Aug")monthnum="08";
			if(month=="Sep")monthnum="09";
			if(month=="Oct")monthnum="10";
			if(month=="Nov")monthnum="11";
			if(month=="Dec")monthnum="12";
			
			if(dates.empty())
				dates.push_back("20"+year+monthnum+date);
			else{
				found = false;
				for(int i=0;i<dates.size();i++){
					if(dates[i] == ("20"+year+monthnum+date))
					found = true;	 
				}
				if(found == false)
					dates.push_back("20"+year+monthnum+date);
			}	 
		}
	
	}
	afile.close();
	sort(dates.begin(), dates.end());
	for(int i=0;i<dates.size();i++){
		cout <<dates[i]<<endl;
	}
	afile.open(filename, ios::in);
	if(!afile){
		cout << "File reading failed to open! Exiting..";
	}	 
	else{
		cout << left << setw (10)  << "Item ID" 
			 << left << setw (30) << "Item Description"
			 << left << setw (15) << "Main Cat" 
			 << left << setw (15) << "Sub Cat"
			 << left << setw (15) << "Price" 
			 << left << setw (12) << "Quantity"
			 << left << setw (10) << "Date" << endl;
			 
		for(int i=0;i<dates.size();i++){
			afile.clear();
			afile.seekg(0,ios::beg);
			while(getline(afile,record))
			{
				istringstream ss(record);
				getline(ss,s.id,':');
				getline(ss,s.desc,':');
				getline(ss,s.maincat,':');
				getline(ss,s.subcat,':');
				getline(ss,s.price,':');
				getline(ss,s.qty,':');
				getline(ss,date,'-');
				getline(ss,month,'-');
				getline(ss,year,'\n');
				s.compdate=date+"-"+month+"-"+year;
				if(month=="Jan")monthnum="01";
				if(month=="Feb")monthnum="02";
				if(month=="Mar")monthnum="03";
				if(month=="Apr")monthnum="04";
				if(month=="May")monthnum="05";
				if(month=="Jun")monthnum="06";
				if(month=="Jul")monthnum="07";
				if(month=="Aug")monthnum="08";
				if(month=="Sep")monthnum="09";
				if(month=="Oct")monthnum="10";
				if(month=="Nov")monthnum="11";
				if(month=="Dec")monthnum="12";
				if(dates[i] == ("20"+year+monthnum+date)){
					if(stockvector.empty()){
					//s.quantity = String2Int(s.qty);
						stockvector.push_back(s);
					}
					else{
						bool foundrecord=false;
						for(int j=0;j<stockvector.size();j++){
							if(stockvector[j].id == s.id){
								foundrecord=true;
								int quantity = atoi(stockvector[j].qty.c_str())+atoi(s.qty.c_str()); 
								stockvector[j].qty=Int2String(quantity);
							}
						}
						if(foundrecord==false){
						stockvector.push_back(s);	    						
						}
					}
					
				}	
				 
			}
			for(int i=0;i<stockvector.size();i++){
			cout << left << setw (10)  << stockvector[i].id;
					cout << left << setw (30) << stockvector[i].desc ;
					cout << left << setw (15) << stockvector[i].maincat;
					cout << left << setw (15) << stockvector[i].subcat;
					cout << left << setw (15) << stockvector[i].price;
					cout << left << setw (12) << stockvector[i].qty;
					cout << left << setw (10) << stockvector[i].compdate;
					cout << endl;
					
			} 
			stockvector.clear();
		}
	}
	afile.close();
}

void StockSummary::weeklyReport(fstream& afile,char filename[])
{
}

void StockSummary::monthlyReport(fstream& afile,char filename[])
{

	
	stockrecord s;
	string monthnum, date, month, year, record;
	vector<stockrecord> stockvector;
	vector<string> dates;
	ostringstream convert;
	bool found = false;

	afile.open(filename, ios::in);
	if(!afile){
		cout << "File reading failed to open! Exiting..";
	}	 
	else{
        while(getline(afile,record))
		{
			istringstream ss(record);
			getline(ss,s.id,':');
			getline(ss,s.desc,':');
			getline(ss,s.maincat,':');
			getline(ss,s.subcat,':');
			getline(ss,s.price,':');
			getline(ss,s.qty,':');
			getline(ss,date,'-');
			getline(ss,month,'-');
			getline(ss,year,'\n');
			s.compdate=date+"-"+month+"-"+year;
			if(month=="Jan")monthnum="01";
			if(month=="Feb")monthnum="02";
			if(month=="Mar")monthnum="03";
			if(month=="Apr")monthnum="04";
			if(month=="May")monthnum="05";
			if(month=="Jun")monthnum="06";
			if(month=="Jul")monthnum="07";
			if(month=="Aug")monthnum="08";
			if(month=="Sep")monthnum="09";
			if(month=="Oct")monthnum="10";
			if(month=="Nov")monthnum="11";
			if(month=="Dec")monthnum="12";
			
			if(dates.empty())
				dates.push_back("20"+year+monthnum);
			else{
				found = false;
				for(int i=0;i<dates.size();i++){
					if(dates[i] == ("20"+year+monthnum))
					found = true;	 
				}
				if(found == false)
					dates.push_back("20"+year+monthnum);
			}	 
		}
	
	}
	afile.close();
	sort(dates.begin(), dates.end());
	for(int i=0;i<dates.size();i++){
		cout <<dates[i]<<endl;
	}
	afile.open(filename, ios::in);
	if(!afile){
		cout << "File reading failed to open! Exiting..";
	}	 
	else{
		cout << left << setw (10)  << "Item ID" 
			 << left << setw (30) << "Item Description"
			 << left << setw (15) << "Main Cat" 
			 << left << setw (15) << "Sub Cat"
			 << left << setw (15) << "Price" 
			 << left << setw (12) << "Quantity"
			 << left << setw (10) << "Date" << endl;
			 
		for(int i=0;i<dates.size();i++){
			afile.clear();
			afile.seekg(0,ios::beg);
			while(getline(afile,record))
			{
				istringstream ss(record);
				getline(ss,s.id,':');
				getline(ss,s.desc,':');
				getline(ss,s.maincat,':');
				getline(ss,s.subcat,':');
				getline(ss,s.price,':');
				getline(ss,s.qty,':');
				getline(ss,date,'-');
				getline(ss,month,'-');
				getline(ss,year,'\n');
				s.compdate=date+"-"+month+"-"+year;
				if(month=="Jan")monthnum="01";
				if(month=="Feb")monthnum="02";
				if(month=="Mar")monthnum="03";
				if(month=="Apr")monthnum="04";
				if(month=="May")monthnum="05";
				if(month=="Jun")monthnum="06";
				if(month=="Jul")monthnum="07";
				if(month=="Aug")monthnum="08";
				if(month=="Sep")monthnum="09";
				if(month=="Oct")monthnum="10";
				if(month=="Nov")monthnum="11";
				if(month=="Dec")monthnum="12";
				if(dates[i] == ("20"+year+monthnum)){
					if(stockvector.empty()){
					//s.quantity = String2Int(s.qty);
						stockvector.push_back(s);
					}
					else{
						bool foundrecord=false;
						for(int j=0;j<stockvector.size();j++){
							if(stockvector[j].id == s.id){
								foundrecord=true;
								int quantity = atoi(stockvector[j].qty.c_str())+atoi(s.qty.c_str()); 
								stockvector[j].qty=Int2String(quantity);
							}
						}
						if(foundrecord==false){
						stockvector.push_back(s);	    						
						}
					}
					
				}	
				 
			}
			for(int i=0;i<stockvector.size();i++){
			cout << left << setw (10)  << stockvector[i].id;
					cout << left << setw (30) << stockvector[i].desc ;
					cout << left << setw (15) << stockvector[i].maincat;
					cout << left << setw (15) << stockvector[i].subcat;
					cout << left << setw (15) << stockvector[i].price;
					cout << left << setw (12) << stockvector[i].qty;
					cout << left << setw (10) << stockvector[i].compdate;
					cout << endl;
					
			} 
			stockvector.clear();
		}
	}
	afile.close();

}

void StockSummary::yearlyReport(fstream& afile,char filename[])
{
	
	stockrecord s;
	string monthnum, date, month, year, record;
	vector<stockrecord> stockvector;
	vector<string> dates;
	ostringstream convert;
	bool found = false;

	afile.open(filename, ios::in);
	if(!afile){
		cout << "File reading failed to open! Exiting..";
	}	 
	else{
        while(getline(afile,record))
		{
			istringstream ss(record);
			getline(ss,s.id,':');
			getline(ss,s.desc,':');
			getline(ss,s.maincat,':');
			getline(ss,s.subcat,':');
			getline(ss,s.price,':');
			getline(ss,s.qty,':');
			getline(ss,date,'-');
			getline(ss,month,'-');
			getline(ss,year,'\n');
			s.compdate=date+"-"+month+"-"+year;
			if(month=="Jan")monthnum="01";
			if(month=="Feb")monthnum="02";
			if(month=="Mar")monthnum="03";
			if(month=="Apr")monthnum="04";
			if(month=="May")monthnum="05";
			if(month=="Jun")monthnum="06";
			if(month=="Jul")monthnum="07";
			if(month=="Aug")monthnum="08";
			if(month=="Sep")monthnum="09";
			if(month=="Oct")monthnum="10";
			if(month=="Nov")monthnum="11";
			if(month=="Dec")monthnum="12";
			
			if(dates.empty())
				dates.push_back("20"+year);
			else{
				found = false;
				for(int i=0;i<dates.size();i++){
					if(dates[i] == ("20"+year))
					found = true;	 
				}
				if(found == false)
					dates.push_back("20"+year);
			}	 
		}
	
	}
	afile.close();
	sort(dates.begin(), dates.end());
	for(int i=0;i<dates.size();i++){
		cout <<dates[i]<<endl;
	}
	afile.open(filename, ios::in);
	if(!afile){
		cout << "File reading failed to open! Exiting..";
	}	 
	else{
		cout << left << setw (10)  << "Item ID" 
			 << left << setw (30) << "Item Description"
			 << left << setw (15) << "Main Cat" 
			 << left << setw (15) << "Sub Cat"
			 << left << setw (15) << "Price" 
			 << left << setw (12) << "Quantity"
			 << left << setw (10) << "Date" << endl;
			 
		for(int i=0;i<dates.size();i++){
			afile.clear();
			afile.seekg(0,ios::beg);
			while(getline(afile,record))
			{
				istringstream ss(record);
				getline(ss,s.id,':');
				getline(ss,s.desc,':');
				getline(ss,s.maincat,':');
				getline(ss,s.subcat,':');
				getline(ss,s.price,':');
				getline(ss,s.qty,':');
				getline(ss,date,'-');
				getline(ss,month,'-');
				getline(ss,year,'\n');
				s.compdate=date+"-"+month+"-"+year;
				if(month=="Jan")monthnum="01";
				if(month=="Feb")monthnum="02";
				if(month=="Mar")monthnum="03";
				if(month=="Apr")monthnum="04";
				if(month=="May")monthnum="05";
				if(month=="Jun")monthnum="06";
				if(month=="Jul")monthnum="07";
				if(month=="Aug")monthnum="08";
				if(month=="Sep")monthnum="09";
				if(month=="Oct")monthnum="10";
				if(month=="Nov")monthnum="11";
				if(month=="Dec")monthnum="12";
				if(dates[i] == ("20"+year)){
					if(stockvector.empty()){
					//s.quantity = String2Int(s.qty);
						stockvector.push_back(s);
					}
					else{
						bool foundrecord=false;
						for(int j=0;j<stockvector.size();j++){
							if(stockvector[j].id == s.id){
								foundrecord=true;
								int quantity = atoi(stockvector[j].qty.c_str())+atoi(s.qty.c_str()); 
								stockvector[j].qty=Int2String(quantity);
							}
						}
						if(foundrecord==false){
						stockvector.push_back(s);	    						
						}
					}
					
				}	
				 
			}
			for(int i=0;i<stockvector.size();i++){
			cout << left << setw (10)  << stockvector[i].id;
					cout << left << setw (30) << stockvector[i].desc ;
					cout << left << setw (15) << stockvector[i].maincat;
					cout << left << setw (15) << stockvector[i].subcat;
					cout << left << setw (15) << stockvector[i].price;
					cout << left << setw (12) << stockvector[i].qty;
					cout << left << setw (10) << stockvector[i].compdate;
					cout << endl;
					
			} 
			stockvector.clear();
		}
	}
	afile.close();

}

