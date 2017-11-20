// OLList.cpp
// ENCM 339  Lab 8 Exercise A and B


#include <iostream>
#include <stdlib.h>
#include "OLList.h"
using namespace std;


OLList::OLList()
: headM(0)
{
}

OLList::OLList(const OLList& source)
{
    copy(source);
}

OLList& OLList::operator =(const OLList& rhs)
{
    if (this != &rhs)
	{
		destroy();
		copy(rhs);
	}
    return *this;
}

OLList::~OLList()
{
    destroy();
}

void OLList::print() const
{
    cout << '[';
    if (headM != 0) {
        cout << ' ' << headM->item;
        for (const Node *p = headM->next; p != 0; p = p->next)
            cout << ", " << p->item;
    }
    cout << " ]\n";
}

void OLList::insert(const ListItem& itemA)
{
    Node *new_node = new Node;
    new_node->item = itemA;
    
    if (headM == 0 || itemA <= headM->item ) {
        new_node->next = headM;
        headM = new_node;
        // point one
    }
    else {
        Node *before = headM;      // will point to node in front of new node
        Node *after = headM->next; // will be 0 or point to node after new node
        while(after != 0 && itemA > after->item) {
            before = after;
            after = after->next;
        }
        new_node->next = after;
        before->next = new_node;
        // point two
    }
}

void OLList::remove(const ListItem& itemA)
{
    // if list is empty, do nothing
    if (headM == 0 || itemA < headM->item)
        return;
    
    Node *doomed_node = 0;
    
    if (itemA == headM->item) {
        doomed_node = headM;
        headM = headM->next;
    }
    else {
        Node *before = headM;
        Node *maybe_doomed = headM->next;
        while(maybe_doomed != 0 && itemA > maybe_doomed->item) {
            before = maybe_doomed;
            maybe_doomed = maybe_doomed->next;
        }
		//so far, maybe_doomed is set to the node to be deleted
		//and before is set to the node before the one to be deleted
		
		
		//doomed_node will set the node to be deleted and maybe_node
		//will be set to the node after.
		doomed_node = maybe_doomed;
		maybe_doomed = maybe_doomed -> next;
		
		//the node before the doomed node will point to the node after
		//the node to be deleted
		before -> next = maybe_doomed;
		
		//the doomed_node pointed is cleared and deallocated.
		delete doomed_node;
		doomed_node = NULL;
    }
    
}


void OLList::destroy()
{
	//doomed_node will be pointing to the nodes to be deleted 
	
	Node* doomed_node = headM;
			
	
	while(doomed_node!= NULL)
	{
		
		Node* temp = doomed_node -> next;
		delete doomed_node;
		doomed_node = temp;
			
	}
	delete doomed_node;
	headM = NULL;


    
    
}

void OLList::copy(const OLList& source)
{
	
	headM = new Node;
	Node* current = source.headM; 
	Node* temp = headM;		
	//at this point current is pointing to the start of the original list		
	while(current)
	{
		temp -> item = current -> item;
		
		if (current->next)
		{
					
			temp -> next = new Node;	
			temp = temp ->next;
		}
		current = current -> next;	
		
	}
	temp -> next = NULL;
				
	
				
}


