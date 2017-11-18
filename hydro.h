#ifndef hydro_h
#define hydro_h


void displayHeader();
//promises: display the introduction screen

int readData(FlowList &flow);
/*promises: to read record year, inserts them into the list, and returns the
number of records in the file.
*/

int menu();
//promises: to display the menu screen and return the user's choice.

void pressEnter();
//promises: waits for the user to press enter

void display(const FlowList &flow);
/*promises: displays the list in ascending order based on the flow data.
			Calls average and median function, and displays their data.
*/




void addData(FlowList &flow, int &num);
/*promises: prompts the user to enter an year and flow
			if the year already exists, then gives an error
			if the year doesn't exist in the record, then adds it to the
			list and updates the record. 
*/


void removeData(FlowList &flow, int&num);
/*promises: prompts the user to enter an year and flow
			if the year doesn't exist in the record, then gives an error
			if the year exists in the record, then removes it from the
			list and updates the record. 
*/


#endif