#include <iostream>
#define maxTable 10
using namespace std;

int main(){
	//groups of person book table to be seated together 
	//groups = jobs
	//tables = blocks
	//each tables have different number of seats
	//eg. group[1] will be seated at table[3] 
	int availableTable[maxTable] = {5,5,6,6,1,2,1,3,8,10}; 
    int action, grpAmt, table[maxTable];
    cout << "Welcome to the restaurant !\n";
    cout << "1. Next Fit \n2. Worst Fit \n";
    cout << "Select an operation >> ";
    cin >> action;
    cout << "Available table :\n";
    for (int i=0;i<maxTable;i++){
    	cout << "Table[" << (i+1) << "] has " << availableTable[i] << " seat(s).\n";
	}
	cout<<endl;
    switch(action){
        case 1:{
            //Next Fit
            cout << "Booking table using Next Fit Algorithm :\n";
            cout << "How many groups of person ? >> ";
            cin >> grpAmt;
            for (int i = 0; i < grpAmt; i++) {
                cout << "Group[" << (i+1) << "] needs how many seats? >> ";
                cin >> table[i];
            }
            cout << endl;
            //eg. 3 groups , table[0] = 2 , table[1] = 4 etc.

            bool allocated = false;
            int lastHole = 0;
            //store respective table for the groups 
            int allocatedSeat[grpAmt]={};
            
            //loop through the request of users
            for (int i=0;i<grpAmt;i++){
            	allocated = false;
            	int j = lastHole; // start searching from lastHole
            	
            	// find the next available table with enough seats
                while (!allocated && j < maxTable) {
                    if (table[i] <= availableTable[j]) {
                        allocated = true;
                        break;
                    }
                    j++;
                }

                if (allocated) {
                    cout << "Group[" << (i + 1) << "] with " << table[i] << " people is seated at table[" << (j + 1) << "] with a remaining seat(s) of "<< (availableTable[j] -= table[i])<<".\n";
                    lastHole = (j + 1) % maxTable; // update lastHole
                } else { 
                	cout << "Could not allocate any table for Group[" << (i + 1) << "]!\n";
                    
                }
            }
            break;
        }

        case 2:{
            //Worst Fit
            cout << "Booking table using Worst Fit Algorithm :\n";
            cout << "How many groups of people? >> ";
    		cin >> grpAmt;
    			for (int i = 0; i < grpAmt; i++) {
        			cout << "Group[" << (i+1) << "] needs how many seats? >> ";
        			cin >> table[i];
    			}
    			cout << endl;

    			// Allocate tables using Worst Fit algorithm
    			for (int i = 0; i < grpAmt; i++) {
        			int worstFitIndex = -1;
        			int worstFitSize = -1;

        			// Find the largest available table
        			for (int j = 0; j < maxTable; j++) {
            			if (table[i] <= availableTable[j] && availableTable[j] > worstFitSize) {
                			worstFitIndex = j;
                			worstFitSize = availableTable[j];
            			}
        			}

        			// Allocate the group to the largest available table
        			if (worstFitIndex != -1) {
            			cout << "Group[" << (i+1) << "] with " << table[i] << " people is seated at table[" << (worstFitIndex+1) << "] with a remaining seat(s) of " << (availableTable[worstFitIndex] -= table[i]) << ".\n";
            			// Mark the allocated table as unavailable
            			availableTable[worstFitIndex] = 0;
        			} else {
            			cout << "Could not allocate any table for Group[" << (i+1) << "]!\n";
        			}
    			}
            break;
        }
    }
}
