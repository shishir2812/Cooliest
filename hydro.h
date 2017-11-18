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


#endif