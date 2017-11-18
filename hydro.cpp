/*
Name: Shishir Srivastava and Siobhan Odell
Version 1.0
Lab Section: B03

 */ 

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include "list.h"

#include "hydro.h"
 
int main()
{
	FlowList flow;
	displayHeader();
	int numRecords = readData(flow);
	int quit = 0;
	while (1)
	{
		switch(menu())
		{
			case 1:
			//calls display function
			display(flow);
			pressEnter();
			break;
			
			case 5:
			cout << "program terminated" << endl;
			quit = 1;
			break;
			
			default:
			cout << "not a valid input" << endl;
			break;
			
			
		}
		if (quit==1)
			break;
	}
	
}

void displayHeader()
{
	cout<<"Program: Flow Studies- Fall 2017\n Version:1.0 \n Lab section: B03 \n Producted by: Shishir Srivastava and Shiobhan Odell\n "<<endl;
	pressEnter();
}

int readData(FlowList &flow)
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
	
	
	while (inFlow >> y >> d)
	{
		flow.insert(y,d);
		return num;
	}
	
	
	
	inFlow.close();
		
	return num;
}


int menu()
{
	int choice;	
	cout <<"1. Display flow list, average, and median"<< endl;
	cout <<"2. Add data"<< endl;
	cout <<"3. Save data into the file"<< endl;
	cout <<"4. Remove data << endl" <<endl;	
	cout <<"5. Quit" <<endl;	
	cout << "Enter your choice (1, 2, 3, 4, 5)"  <<endl;	
	cin >> choice;
	return choice;
}

void pressEnter()
{
	cout <<"\n<<< Press enter to continue>>>" << endl;
	cin.get();
}


void display(const FlowList &flow)
{
	
	
}


