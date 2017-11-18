// list.cpp
// ENCM 339 Lab 8 Exercises C
// Last edit: 11/17/2017
// Produced by: Shishir Srivastava and Siobhan O'Dell

#include "list.h"
#include <cassert>
#include <iostream>
using namespace std;

//Default Constructor
	FlowList::FlowList()
		{
			head = NULL;
			cursor = head;
		}

//Copy Constructor
	FlowList::FlowList(const FlowList& source)
		{
			head = NULL;
			copy(source);
			reset_cursor();
		}

//Assignment Operator
	FlowList& FlowList::operator = (const FlowList& rhs)
		{
			
			if(this != &rhs)
			{
				
				//delete the storage
				destroy();
				
				//copy in rhs
				copy(rhs);
			}
			
			reset_cursor();
			return *this;
		}
 
//Destructor
	FlowList::~FlowList()
		{
			
			//destroy();
			//cout << "SUCCESS" << endl;
		}

//Getters and Setters
	int FlowList::get_year() const 
		{
			if(cursor)
				return cursor -> item.year;
			return 0;
		}
		
	double FlowList::get_flow() const 
		{	
			if(cursor)
				return cursor -> item.flow;
			return 0;
		}
		
//Implementer Functions
	void FlowList::insert(const int& yearA, const double& flowA)
		{

			Node* temp = new Node;
			assert(temp != 0);
			temp -> item.year = yearA;
			temp -> item.flow = flowA;
			temp -> next = head;
			head = temp;
			reset_cursor();
		}

	int FlowList::remove(const int& yearA)
		{
			Node* ptrprev;
			
			Node* ptr = head;
				
			if(ptr -> item.year == yearA)
				{
					head = head -> next;
					delete ptr;
					return 1;
				}
			
			ptrprev = ptr;
			ptr = ptr -> next;
			
			while(ptr)
				{

					if(ptr -> item.year == yearA)
						{
							ptrprev -> next = ptr -> next;
							delete ptr;
							return 1;
						}
					
					ptrprev = ptr;
					ptr = ptr -> next;
			
				}
				
			reset_cursor();
			return 0;
		}

	void FlowList::display()
		{
			Node* ptr =	head;
			
			while(ptr)
				{
					
					cout << "YEAR: ";
					cout << ptr -> item.year;
					
					cout << "    FLOW: ";
					cout << ptr -> item.flow;
					
					cout << endl;
					
					cout << "Cursor is pointing to YEAR: ";
					cout << cursor -> item.year;
					
					cout << endl;
					
					ptr = ptr -> next;
				}
			
			cout << endl;
		}
	
	int FlowList::move_cursor()
		{
			if(cursor -> next)
				{
					cursor = cursor -> next;
					return 1;
				}
				
			else
				return 0;
		}
	
	void FlowList::reset_cursor()
		{
			 cursor = head;
			
		}
		
	void FlowList::destroy()
		{

			Node* ptr = head -> next;
			//cout << "1ptr is at: " << ptr -> item.year << endl;
			
			while(ptr)
				{	
					//cout << "2ptr is at: " << ptr -> item.year << endl;
					cout << "^DELETE YEAR: " << head -> item.year << endl;
					delete head;
					//cout << "3ptr is at: " << ptr -> item.year << endl;
					head = ptr;
					//cout << "4ptr is at: " << ptr -> item.year << endl;
					ptr = head -> next;
					//cout << "5ptr is at: " << ptr -> item.year << endl;

				}
			
			cout << "DELETE YEAR: " << head -> item.year << endl;
			delete head;
			head = NULL;
		}

	void FlowList::copy(const FlowList& source)
		{
			Node* move = source.head;
			
			while(move)
				{
					Node* temp = new Node;
					
					temp -> item.year = move -> item.year;
					temp -> item.flow = move -> item.flow;
					
					temp -> next = this -> head;
					
					this -> head = temp;
					
					move = move -> next;
					
					if(!move)
						temp -> next = NULL;
					
				}
				
			this -> head = source.head;
		}