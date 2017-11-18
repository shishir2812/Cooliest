// list.h
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
		ptr = head;
	}

//Copy Constructor
FlowList::FlowList(const FlowList& source)
	{
		copy(source);
	}

//Assignment Operator
FlowList& FlowList::operator = (const FlowList& rhs)
	{
		if(this != &rhs)
		{
			//delete the storage
			//destroy();
			
			copy(rhs);
		}
		
		return *this;
	}
 
//Destructor
  //~FlowList(){}

//Implementer Functions
void FlowList::insert(const int& yearA, const double& flowA)
	{

		Node* temp = new Node;
		assert(temp != 0);
		temp -> item.year = yearA;
		temp -> item.flow = flowA;
		temp -> next = head;
		head = temp;
	  
	}

//void FlowList::remove(const int& yearA, const double& flowA){}
  //  PROMISES:
  //    If no node has an item matching itemA,list is unchanged.
  //    Otherwise exactly one node with its item == itemA is removed.

void FlowList::display()
{
	ptr = head;
	
	while(ptr)
	{
		
		cout << "YEAR: ";
		cout << ptr -> item.year;
		
		cout << "FLOW: ";
		cout << ptr -> item.flow;
		
		cout << endl;
		
		ptr = ptr -> next;
	}
	
	cout << endl;
}


//void FlowList::destroy(){}
  // Deallocate all nodes, set headM to zero.

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