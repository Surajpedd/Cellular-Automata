#include <iostream>
#include <vector>
using namespace std;
#define LENGTH 34          // Length of the string used as a "Seed" 
int n = 15;	              // How many lines the program will generate
vector <vector<int>> rules={{0,0,0},{0,0,1},{0,1,0},{0,1,1},{1,0,0},{1,0,1},{1,1,0},{1,1,1}};

void printRules()  //Utility Function to Print Rules 
{
    int i,j;
	cout << "The rules that define the Rule 90 Celluar Automata are as follows: \n";
	for(i=0;i<8;i++)
	{
	    cout << "\t\tRule "<<i+1<<": ";
	    for(j=0;j<3;j++)
		    cout<<rules[i][j]<<" ";
	   cout <<"-> sets cell to: "<<(rules[i][0]^rules[i][2])<<"\n";
    }
}

void outState(vector <int> s)   //Print the Current State
{
    cout<<"\t\t";
	for (int i = 0; i < LENGTH; i++)
	{
		if (s[i] == 1)
			cout << "\u25A0";
		else if (s[i] == 0)
			cout << " ";
	}
	cout << "\n";
}

int main()
{
	printRules(); // Print out the rules for rule 90 ceulluar Automata:
	cout << "\n\t\t\tSERPINSKI TRIANGLE\n";
    
	// Initialize starting state to serpinski traingle
    vector <int> serpinski(LENGTH),updateState(LENGTH);
	serpinski[(LENGTH)/2 -1] = 1;
	
	// Print Serpinski Traingle Initial String
	cout << "\n";
	outState(serpinski);
	
	// Loop to generate/update the State and Update State arrays then print them
	for (int i = 0; i < n; i++)
	{
		// Erarse the old state
		updateState.assign(LENGTH,0);
		
		// Create the new state
		for (int j = 1; j < LENGTH - 1; j++)
		{	
			// Create an array with the current patter (pulled from the current state)
			int f1 = serpinski[j - 1];
			int f2 = serpinski[j];
			int f3 = serpinski[j + 1];

			vector <int> curPattern;
			curPattern.push_back(f1);
			curPattern.push_back(f2);
			curPattern.push_back(f3);

			// XOR the current state's neighbours to set the cell's value in Update State
			updateState[j]=curPattern[0]^curPattern[2]; 
        }
		// Update the current state
		serpinski.assign(updateState.begin(),updateState.end());
		
		// Print the new current state
		outState(serpinski);
	}
	return 0;
}
