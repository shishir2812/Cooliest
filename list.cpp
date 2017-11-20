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
			head = NULL ;
			cursor = head;
		}

//Copy Constructor
	FlowList::FlowList(const FlowList& source)
		{
			this -> head = copy(source);
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
				this -> head = copy(rhs);
			}
			
			reset_cursor();
			return *this;
		}
 
//Destructor
	FlowList::~FlowList()
		{
			destroy();	
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
	
	//Insert Function
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

	//Remove Function	
	int FlowList::remove(const int& yearA)
		{
			Node* ptrprev;
			
			if(!head)
				return 0;
			
			Node* ptr = head;
			
			if((ptr -> item.year) == yearA)
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
		
	//Display Function (For debugging purposes)
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
					
					ptr = ptr -> next;
				}
			
			cout << endl;
		}
	
	//Move_cursor Function
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
		
	//reset_cursor Function
	void FlowList::reset_cursor()
		{
			 cursor = head;
			
		}
	
	//destroy Function
	void FlowList::destroy()
		{

			Node* current = this -> head;
			
			if(!current)
				return;
			
			while(current)
				{	
					
					Node* temp = current -> next;
					delete current;
					current = temp;
				}
			
			head = NULL;
		}

	//copy Function	
	Node* FlowList::copy(const FlowList& source)
		{
			Node* current = source.head;
			
			if(current)
			{
				Node* temp = new Node;
				
				temp -> item.year = current -> item.year;
				temp -> item.flow = current -> item.flow;
							
				temp -> next = NULL;
					
				Node* currenthead = temp;
					
				while(current)
					{
						temp = new Node;
							
						temp -> item.year = current -> item.year;
						temp -> item.flow = current -> item.flow;
							
						temp -> next = NULL;
							
						current = current -> next;
							
					}

				return currenthead;
			}
			
			else
				return NULL;
			
		}