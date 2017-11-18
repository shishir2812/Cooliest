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

/*
However you may need to add member function to get access to the item value
of a node. For this purpose you can also add another data member of type Node*, 
to be able to set it to different nodes when traversing through the list
and haveaccess to the item in the node(this is just a suggestion and you can 
come up with different solutions if you like). 
*/

class FlowList{
public:
//Default Constructor
  FlowList();
  //PROMISES: Creates empty list.

//Copy Constructor
  FlowList(const FlowList& source);
  //REQUIRES:
  //PROMISES: To create a FlowList with the files content

//Assignment Operator  
  FlowList& operator =(const FlowList& rhs);
  //REQUIRES: 
  //PROMISES: To create a FlowList with the files content
 
//Destructor
 // ~FlowList();

//Implementer Functions
  void insert(const int& yearA, const double& flowA);
  // PROMISES:
  //    A node with a copy of item is added in a way that preserves the nondecreasing
  //    order of items in nodes.

  void remove(const int& yearA, const double& flowA);
  //  PROMISES:
  //    If no node has an item matching itemA,list is unchanged.
  //    Otherwise exactly one node with its item == itemA is removed.
  
  void display();
  
private:
  Node *head;
  Node *ptr;
  //void destroy();
  // Deallocate all nodes, set headM to zero.

  void copy(const FlowList& source);
  // List becomes copy of source.

};
#endif