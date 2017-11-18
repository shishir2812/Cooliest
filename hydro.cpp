/*
Name: Shishir Srivastava and Siobhan Odell
Version 1.0
Lab Section: B03

 */ 

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include "hydro.h"
#include "list.cpp"
#include "list.h"
 
int main(void)
{
	displayHeader();
	int number_of_records = readData();
	
}

void displayHeader()
{
	cout<<"Program: Flow Studies- Fall 2017\n Version:1.0 \n Lab section: B03 \n Producted by: Shishir Srivastava and Shiobhan Odell\n <<Press Enter to Continue>>"<<endl;
	
}

int readData()
{
	int num= 0;
	int y;
	double d;	
	ifstream inFlow;
	inFlow.open("flow.txt",ios::in);
	
	//unsuccessful at opening
	if (inFlow.fail())
	{
		cerr<<"Unsuccesful in opening flow.txt"<<endl;
		exit(1);
	}
	//inserts the date and year into the ListItem structure
	
	/*
	while (inFlow >> y >> d)
	{
		Flowlist.insert(y,d);
		return num;
	}
	
	
	*/
	inFlow.close();
		
	return num;
}

