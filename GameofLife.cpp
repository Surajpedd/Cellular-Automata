#include<iostream>
#include<stdlib.h>    //for system()
#include<algorithm>   //for copy()
using namespace std;
const int gridSize = 25;
void printGrid(bool gridOne[gridSize+1][gridSize+1])
{
    for(int i=1;i<gridSize;i++)
    {
        for(int j=1;j<gridSize;j++)
        {
            if(gridOne[i][j])	
                cout << " \u25A0 ";
            else
                cout << " # ";
        }
        cout<<endl;
    }
}
int check(bool gridTwo[gridSize+1][gridSize+1],int a,int b)
{
    int alive=0;
    for(int i = -1; i < 2; i++)
        for(int j = -1; j < 2; j++)
            if(!(i == 0 && j == 0) && gridTwo[a+i][b+j]==true)                  //checking all adjacent cells are alive
	     	    alive++;
    return alive;
}
void determineState(bool gridOne[gridSize+1][gridSize+1])
{
    bool gridTwo[gridSize+1][gridSize+1]={};
    copy(&gridOne[0][0], &gridOne[0][0]+(gridSize+1)*(gridSize+1),&gridTwo[0][0]);               //copy gridOne into gridTwo
    int alive;
    for(int a = 1; a < gridSize; a++)
        for(int b = 1; b < gridSize; b++)
        {
            alive=check(gridTwo,a,b);
            if(alive < 2 || alive > 3)               //if less than 2 neighbours alive and more than 3 then cell dies
                gridOne[a][b] = false;
            else if(alive == 3)                      //if three adjacent cells are alive then cell is birthed
                gridOne[a][b] = true;
        }
}
int main()
{
    bool gridOne[gridSize+1][gridSize+1]={};
    char ch='Y';
    int x,y,nc;
    cin >> nc;
    for(int i=0;i<nc;i++)
    {
	cout <<"Enter the coordinates of cell " << i+1 << " : "<<endl;
	cin>>x>>y;
	gridOne[x][y] = true;
	printGrid(gridOne);
    }
    for(nc=1;ch=='Y';nc++)
    {
      	 system("clear");                   //for windows use clrscr()
        cout<<"State "<<nc<<endl;
        printGrid(gridOne);
        cout<<"Continue? [Y/N]";
        cin>>ch;
        determineState(gridOne);
    }
}
// loaf- (5 5),(6,5),(5,6),(7,5),(5,7)  static
// boat - (4,5),(5,4),(6,5),(5,6),(7,7) static
//beacon - (1,1),(2,1),(1,2),(4,4),(3,4),(4,3) oscillating
// glider - (6,5),(7,6),(5,7),(6,7),(7,7) 