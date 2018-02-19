#include "StockSummary.h"

StockSummary::StockSummary()
{

}

StockSummary::~StockSummary()
{
}

string StockSummary::incrementDate(string dated){
	string tempdate, tempmonth, tempyear;
	int tempDate, tempMonth, tempYear;
	tempdate = dated.at(6);
	tempdate+=dated.at(7);
	tempmonth = dated.at(4);
	tempmonth+=dated.at(5);
	tempyear =  dated.at(0);
	tempyear+=dated.at(1);
	tempyear+=dated.at(2);
	tempyear+=dated.at(3);
	tempDate=atoi(tempdate.c_str());
	tempMonth=atoi(tempmonth.c_str());
	tempYear=atoi(tempyear.c_str());
	tempDate++;
	if(tempMonth == 1 || tempMonth == 3 || tempMonth == 5 || tempMonth == 7 || tempMonth == 8 || tempMonth == 10 ||tempMonth == 12){
		if(tempDate>=32){
			tempDate=1;
			tempMonth++;
		}
	}
	else if(tempMonth == 4 || tempMonth == 6 || tempMonth == 9 || tempMonth == 11){
		if(tempDate>=31){
			tempDate=1;
			tempMonth++;
		}
	}
	else if(tempMonth == 2){
		if(tempDate>=29){
			tempDate=1;
			tempMonth++;
		}
	}
	if(tempMonth>=13){
		tempMonth=1;
		tempYear++;
	}

	tempyear=Int2String(tempYear);
	if(tempMonth<10){
		tempmonth="0"+Int2String(tempMonth);
	}
	else
		tempmonth=Int2String(tempMonth);
	if(tempDate<10){
		tempdate="0"+Int2String(tempDate);
	}
	else
		tempdate=Int2String(tempDate);
		
	string result = tempyear+tempmonth+tempdate;
	return result;

}

string StockSummary::incrementMonth(string dated){
	string tempmonth, tempyear;
	int tempMonth, tempYear;
	tempmonth = dated.at(4);
	tempmonth+=dated.at(5);
	tempyear =  dated.at(0);
	tempyear+=dated.at(1);
	tempyear+=dated.at(2);
	tempyear+=dated.at(3);
	tempMonth=atoi(tempmonth.c_str());
	tempYear=atoi(tempyear.c_str());
	
	tempMonth++;
	if(tempMonth>=13){
		tempMonth=1;
		tempYear++;
	}

	tempyear=Int2String(tempYear);
	if(tempMonth<10){
		tempmonth="0"+Int2String(tempMonth);
	}
	else
		tempmonth=Int2String(tempMonth);
		
	string result = tempyear+tempmonth;
	return result;

}

string StockSummary::incrementYear(string dated){
	string tempyear;
	int tempYear;
	tempyear =  dated.at(0);
	tempyear+=dated.at(1);
	tempyear+=dated.at(2);
	tempyear+=dated.at(3);
	tempYear=atoi(tempyear.c_str());
	tempYear++;	   
	
	tempyear=Int2String(tempYear);
		
	string result = tempyear;
	return result;

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
	string monthnum, date, month, year, record, fromdate, todate, startdate, enddate;
	vector<stockrecord> stockvector;
	vector<string> dates;
	ostringstream convert;
	int startDate;
	int endDate;
	bool found = false;
	
		cout << "From(DD-MM-YYYY): ";
		cin >> fromdate;
		cout << "To(DD-MM-YYYY): ";
		cin >> todate;
		startdate = fromdate.at(6);
		startdate += fromdate.at(7);
		startdate += fromdate.at(8);
		startdate += fromdate.at(9);
		startdate += fromdate.at(3);
		startdate += fromdate.at(4);
		startdate += fromdate.at(0);
		startdate += fromdate.at(1);
		enddate = todate.at(6);
		enddate += todate.at(7);
		enddate += todate.at(8);
		enddate += todate.at(9);
		enddate += todate.at(3);
		enddate += todate.at(4);
		enddate += todate.at(0);
		enddate += todate.at(1);
		dates.push_back(startdate);
		while(startdate!=enddate){
			startdate=incrementDate(startdate);
			dates.push_back(startdate);
		}
	afile.open(filename, ios::in);
	if(!afile){
		cout << "File reading failed to open! Exiting..";
	}	 
	else{
		cout << left << setw (5)  << "Day"
			 << left << setw (15)  << "From" 
			 << left << setw (15)  << "To" 
			 << left << setw (50) << "Item Description"
			 << left << setw (25) << "Amount Per Unit($)"
			 << left << setw (15) << "In"
			 << left << setw (15) << "Out" 
			 << left << setw (15) << "Aggregated Total" << endl;
			 
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
				s.endDate=s.compdate;
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
						if(atoi(s.qty.c_str()) >=0){
									s.in=s.qty;
									s.out="0";
								}
								if(atoi(s.qty.c_str()) <0){
									s.in="0";
									s.out=s.qty;
								}
						stockvector.push_back(s);
					}
					else{
						bool foundrecord=false;
						for(int j=0;j<stockvector.size();j++){
							if(stockvector[j].id == s.id){
								foundrecord=true;
								stockvector[j].endDate=s.compdate;
								int quantity = atoi(stockvector[j].qty.c_str())+atoi(s.qty.c_str());
								stockvector[j].qty=Int2String(quantity);
								if(atoi(s.qty.c_str()) >=0){
									int instock = atoi(stockvector[j].in.c_str())+atoi(s.qty.c_str());
									stockvector[j].in=Int2String(instock);
								}
								if(atoi(s.qty.c_str()) <0){
									int outstock = atoi(stockvector[j].out.c_str())+atoi(s.qty.c_str());
									stockvector[j].out=Int2String(outstock);
								}
							}
						}
						if(foundrecord==false){
						if(atoi(s.qty.c_str()) >=0){
									s.in=s.qty;
									s.out="0";
								}
								if(atoi(s.qty.c_str()) <0){
									s.out=s.qty;
									s.in="0";
								}
						stockvector.push_back(s);	    						
						}
					}
					
				}	
				 
			}
			cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
			for(int j=0;j<stockvector.size();j++){
					cout << left << setw (5)  << i+1
			 			 << left << setw (15)  << stockvector[j].compdate 
						 << left << setw (15)  << stockvector[j].endDate 
						 << left << setw (50) << stockvector[j].desc 
						 << left << setw (25) << "$"+stockvector[j].price+".00"
						 << left << setw (15) << stockvector[j].in
						 << left << setw (15) << stockvector[j].out 
						 <<"$"<< left << setw (15) <<(atoi(stockvector[j].qty.c_str())*atoi(stockvector[j].price.c_str()))<< endl;
					
			} 
			if(stockvector.size()==0){
				cout << left << setw (5)  << i+1 <<endl;
			}
			stockvector.clear();
			cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
		}
	}
	afile.close();
}

void StockSummary::weeklyReport(fstream& afile,char filename[])
{
	stockrecord s;
	string monthnum, date, month, year, record, fromdate, todate, startdate, enddate;
	vector<stockrecord> stockvector;
	vector<string> dates;
	ostringstream convert;
	int startDate;
	int endDate;
	int count=1;
	bool found = false;
	
		cout << "From(DD-MM-YYYY): ";
		cin >> fromdate;
		cout << "To(DD-MM-YYYY): ";
		cin >> todate;
		startdate = fromdate.at(6);
		startdate += fromdate.at(7);
		startdate += fromdate.at(8);
		startdate += fromdate.at(9);
		startdate += fromdate.at(3);
		startdate += fromdate.at(4);
		startdate += fromdate.at(0);
		startdate += fromdate.at(1);
		enddate = todate.at(6);
		enddate += todate.at(7);
		enddate += todate.at(8);
		enddate += todate.at(9);
		enddate += todate.at(3);
		enddate += todate.at(4);
		enddate += todate.at(0);
		enddate += todate.at(1);
		cout << left << setw (5)  << "Week"
			 << left << setw (15)  << "From" 
			 << left << setw (15)  << "To" 
			 << left << setw (50) << "Item Description"
			 << left << setw (25) << "Amount Per Unit($)"
			 << left << setw (15) << "In"
			 << left << setw (15) << "Out" 
			 << left << setw (15) << "Aggregated Total" << endl;
		while(startdate!=enddate){
			for(int i=0;i<7;i++){
				if(startdate!=enddate){
					
					dates.push_back(startdate);
					startdate=incrementDate(startdate);
				}
				else{
					dates.push_back(startdate);
				}
			}
	afile.open(filename, ios::in);
	if(!afile){
		cout << "File reading failed to open! Exiting..";
	}	 
	else{
		
			 
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
				s.endDate=s.compdate;
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
						if(atoi(s.qty.c_str()) >=0){
									s.in=s.qty;
									s.out="0";
								}
								if(atoi(s.qty.c_str()) <0){
									s.in="0";
									s.out=s.qty;
								}
						stockvector.push_back(s);
					}
					else{
						bool foundrecord=false;
						for(int j=0;j<stockvector.size();j++){
							if(stockvector[j].id == s.id){
								foundrecord=true;
								stockvector[j].endDate=s.compdate;
								int quantity = atoi(stockvector[j].qty.c_str())+atoi(s.qty.c_str());
								stockvector[j].qty=Int2String(quantity);
								if(atoi(s.qty.c_str()) >=0){
									int instock = atoi(stockvector[j].in.c_str())+atoi(s.qty.c_str());
									stockvector[j].in=Int2String(instock);
								}
								if(atoi(s.qty.c_str()) <0){
									int outstock = atoi(stockvector[j].out.c_str())+atoi(s.qty.c_str());
									stockvector[j].out=Int2String(outstock);
								}
							}
						}
						if(foundrecord==false){
						if(atoi(s.qty.c_str()) >=0){
									s.in=s.qty;
									s.out="0";
								}
								if(atoi(s.qty.c_str()) <0){
									s.out=s.qty;
									s.in="0";
								}
						stockvector.push_back(s);	    						
						}
					}//endelse
					
			    }//endif
				 
			}//endwhile
		}//endfor
	}//endelse
	afile.close();
	cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
			for(int j=0;j<stockvector.size();j++){
					cout << left << setw (5)  << count
			 			 << left << setw (15)  << stockvector[j].compdate 
						 << left << setw (15)  << stockvector[j].endDate 
						 << left << setw (50) << stockvector[j].desc 
						 << left << setw (25) << "$"+stockvector[j].price+".00"
						 << left << setw (15) << stockvector[j].in
						 << left << setw (15) << stockvector[j].out 
						 << "$" << left << setw (15) << atoi(stockvector[j].qty.c_str())*atoi(stockvector[j].price.c_str())<< endl;
					
			} 
			if(stockvector.size()==0){
				cout << left << setw (5)  << count <<endl;
			}
			count++;
			stockvector.clear();
			dates.clear();
			cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;

	}//endwhile
}

void StockSummary::monthlyReport(fstream& afile,char filename[])
{

	
	stockrecord s;
	string monthnum, date, month, year, record, fromdate, todate, startdate, enddate;
	vector<stockrecord> stockvector;
	vector<string> dates;
	ostringstream convert;
	bool found = false;

		cout << "From(DD-MM-YYYY): ";
		cin >> fromdate;
		cout << "To(DD-MM-YYYY): ";
		cin >> todate;
		startdate = fromdate.at(6);
		startdate += fromdate.at(7);
		startdate += fromdate.at(8);
		startdate += fromdate.at(9);
		startdate += fromdate.at(3);
		startdate += fromdate.at(4);
		enddate = todate.at(6);
		enddate += todate.at(7);
		enddate += todate.at(8);
		enddate += todate.at(9);
		enddate += todate.at(3);
		enddate += todate.at(4);
		dates.push_back(startdate);
		while(startdate!=enddate){
			startdate=incrementMonth(startdate);
			dates.push_back(startdate);
		}
		
	afile.open(filename, ios::in);
	if(!afile){
		cout << "File reading failed to open! Exiting..";
	}	 
	else{
		cout << left << setw (5)  << "Month"
			 << left << setw (15)  << "From" 
			 << left << setw (15)  << "To" 
			 << left << setw (50) << "Item Description"
			 << left << setw (25) << "Amount Per Unit($)"
			 << left << setw (15) << "In"
			 << left << setw (15) << "Out" 
			 << left << setw (15) << "Aggregated Total" << endl;
			 
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
				s.endDate=s.compdate;
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
					if(atoi(s.qty.c_str()) >=0){
									s.in=s.qty;
									s.out="0";
								}
								if(atoi(s.qty.c_str()) <0){
									s.in="0";
									s.out=s.qty;
								}
						stockvector.push_back(s);
					}
					else{
						bool foundrecord=false;
						for(int j=0;j<stockvector.size();j++){
							if(stockvector[j].id == s.id){
								foundrecord=true;
								stockvector[j].endDate=s.compdate;
								int quantity = atoi(stockvector[j].qty.c_str())+atoi(s.qty.c_str()); 
								stockvector[j].qty=Int2String(quantity);
								if(atoi(s.qty.c_str()) >=0){
									int instock = atoi(stockvector[j].in.c_str())+atoi(s.qty.c_str());
									stockvector[j].in=Int2String(instock);
								}
								if(atoi(s.qty.c_str()) <0){
									int outstock = atoi(stockvector[j].out.c_str())+atoi(s.qty.c_str());
									stockvector[j].out=Int2String(outstock);
								}
							}
						}
						if(foundrecord==false){
						if(atoi(s.qty.c_str()) >=0){
									s.in=s.qty;
									s.out="0";
								}
								if(atoi(s.qty.c_str()) <0){
									s.in="0";
									s.out=s.qty;
								}
						stockvector.push_back(s);	    						
						}
					}
					
				}	
				 
			}
			cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
			for(int j=0;j<stockvector.size();j++){
					cout << left << setw (5)  << i+1
			 			 << left << setw (15)  << stockvector[j].compdate 
						 << left << setw (15)  << stockvector[j].endDate 
						 << left << setw (50) << stockvector[j].desc 
						 << left << setw (25) << "$"+stockvector[j].price+".00"
						 << left << setw (15) << stockvector[j].in
						 << left << setw (15) << stockvector[j].out 
						 << "$" << left << setw (15) << atoi(stockvector[j].qty.c_str())*atoi(stockvector[j].price.c_str())<< endl;
					
			} 
			if(stockvector.size()==0){
				cout << left << setw (5)  << i+1 <<endl;
			}
			stockvector.clear();
			cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
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
	string fromdate, todate, startdate, enddate;
		cout << "From(DD-MM-YYYY): ";
		cin >> fromdate;
		cout << "To(DD-MM-YYYY): ";
		cin >> todate;
		startdate = fromdate.at(6);
		startdate += fromdate.at(7);
		startdate += fromdate.at(8);
		startdate += fromdate.at(9);
		enddate = todate.at(6);
		enddate += todate.at(7);
		enddate += todate.at(8);
		enddate += todate.at(9);
		dates.push_back(startdate);
		while(startdate!=enddate){
			startdate=incrementYear(startdate);
			dates.push_back(startdate);
		}
		
	afile.open(filename, ios::in);
	if(!afile){
		cout << "File reading failed to open! Exiting..";
	}	 
	else{
		cout << left << setw (5)  << "Year"
			 << left << setw (15)  << "From" 
			 << left << setw (15)  << "To" 
			 << left << setw (50) << "Item Description"
			 << left << setw (25) << "Amount Per Unit($)"
			 << left << setw (15) << "In"
			 << left << setw (15) << "Out" 
			 << left << setw (15) << "Aggregated Total" << endl;
			 
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
				s.endDate=s.compdate;
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
						if(atoi(s.qty.c_str()) >=0){
									s.in=s.qty;
									s.out="0";
								}
								if(atoi(s.qty.c_str()) <0){
									s.in="0";
									s.out=s.qty;
								}
						stockvector.push_back(s);
					}
					else{
						bool foundrecord=false;
						for(int j=0;j<stockvector.size();j++){
							if(stockvector[j].id == s.id){
								foundrecord=true;
								stockvector[j].endDate=s.compdate;
								int quantity = atoi(stockvector[j].qty.c_str())+atoi(s.qty.c_str()); 
								stockvector[j].qty=Int2String(quantity);
								if(atoi(s.qty.c_str()) >=0){
									int instock = atoi(stockvector[j].in.c_str())+atoi(s.qty.c_str());
									stockvector[j].in=Int2String(instock);
								}
								if(atoi(s.qty.c_str()) <0){
									int outstock = atoi(stockvector[j].out.c_str())+atoi(s.qty.c_str());
									stockvector[j].out=Int2String(outstock);
								}
							}
						}
						if(foundrecord==false){
							if(atoi(s.qty.c_str()) >=0){
									s.in=s.qty;
									s.out="0";
								}
								if(atoi(s.qty.c_str()) <0){
									s.in="0";
									s.out=s.qty;
								}	   	   	   	   	   	   
							stockvector.push_back(s);	    						
						}
					}
					
				}	
				 
			}
			cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
			for(int j=0;j<stockvector.size();j++){
					cout << left << setw (5)  << i+1
			 			 << left << setw (15)  << stockvector[j].compdate 
						 << left << setw (15)  << stockvector[j].endDate 
						 << left << setw (50) << stockvector[j].desc 
						 << left << setw (25) << "$"+stockvector[j].price+".00"
						 << left << setw (15) << stockvector[j].in
						 << left << setw (15) << stockvector[j].out 
						 << "$" << left << setw (15) << atoi(stockvector[j].qty.c_str())*atoi(stockvector[j].price.c_str())<< endl;
					
			} 
			if(stockvector.size()==0){
				cout << left << setw (5)  << i+1 <<endl;
			}
			stockvector.clear();
			cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
		}
	}
	afile.close();

}

