#ifndef list_h
#define list_h



struct ListItem
{
	int year;
	double flow;
};


struct Node
{
	ListItem item;
	Node * next;
};

class Flowlist
{
	public:
	Flowlist();
	~Flowlist();
	
	
	private:
	Node* head;
	
};

#endif