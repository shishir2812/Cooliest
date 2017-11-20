// list.h
// ENCM 339 Lab 8 Exercises C
// Last edit: 11/17/2017
// Produced by: Shishir Srivastava and Siobhan O'Dell

#ifndef LIST_H
#define LIST_H

struct ListItem{
	int year;
	double flow;
};

struct Node {
	ListItem item;
	Node *next;
};

class FlowList{
public:
//Default Constructor
	FlowList();
	//PROMISES: Creates empty list.

//Copy Constructor
	FlowList(const FlowList& source);
	//PROMISES: To create a FlowList

//Assignment Operator  
	FlowList& operator =(const FlowList& rhs);
	//PROMISES: To create a FlowList that is a copy of rhs.
 
//Destructor
	~FlowList();

//Getters and Setters
	int get_year() const;
	// PROMISES: Return current cursor values years.
	
	double get_flow() const;
	// PROMISES: Return current cursor values flow.
	
//Implementer Functions
	void insert(const int& yearA, const double& flowA);
	//PROMISES: To insert a new node in the front of the FlowList.

	int remove(const int& yearA);
	//PROMISES: To search the FlowList for yearA, delete it if found and return 1.
	//If not found, then return 0.
  
	void display();
	//PROMISES: To display the FlowList to the screen.
	
	int move_cursor();
	//PROMISES: To move the cursor one node over and return 1 if the next node
	//is not NULL. If NULL, then return 0.
	
	void reset_cursor();
	//PROMISES: To reset cursor to the head of the FlowList.
  
private:
	Node *head;
	Node *cursor;
  
	void destroy();
	// Deallocate all nodes, set head to NULL.

	Node* copy(const FlowList& source);
	// The head of FlowList points to a copy of source.

};
#endif