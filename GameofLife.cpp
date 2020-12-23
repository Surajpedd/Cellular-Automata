#include<iostream>
#include<stdlib.h>    //for system()
#include<algorithm>   //for copy()
using namespace std;
const int gridSize = 25;
Algorithm printGrid(bool gridOne[gridSize+1][gridSize+1])
{
    for(int i=1;i<gridSize;i++)
    {
        for(int j=1;j<gridSize;j++)
        {
            if(gridOne[i][j])	
                Print " \u25A0 "  //print square if alive
            else
                Print " # "   // print hash if dead
        }
        Print newline
    }
}
Algorithm check(bool gridTwo[gridSize+1][gridSize+1],int a,int b)                    //returns number of living cells adjacent to (a,b)
{
    Set alive = 0
    for(int i = -1; i < 2; i++)                                                   
        for(int j = -1; j < 2; j++)
            if(!(i == 0 && j == 0) && gridTwo[a+i][b+j]==true)                  //checking all adjacent cells are alive 
	     	    alive=alive+1
    return alive
}
Algorithm determineState(bool gridOne[gridSize+1][gridSize+1])
{
    bool gridTwo[gridSize+1][gridSize+1]={}
    copy(&gridOne[0][0], &gridOne[0][0]+(gridSize+1)*(gridSize+1),&gridTwo[0][0])               //copy gridOne into gridTwo
    int alive
    for(int a = 1; a < gridSize; a++)
        for(int b = 1; b < gridSize; b++)
        {
            alive=check(gridTwo,a,b)
            if(alive < 2 || alive > 3 && gridTwo[a][b]==true)           //if less than 2 neighbours alive or more than 3 then cell dies
                gridOne[a][b] = false
            else if(alive == 3 && gridTwo[a][b]==false)                 //if three adjacent cells are alive then cell is born
                gridOne[a][b] = true
        }
}
Algorithm main()
{
    bool gridOne[gridSize+1][gridSize+1]={}                             //gridSize=25 (any value can be chosen)
    int x,y,nc
    Read nc
    for(int i=0;i<nc;i++)
    {
	Read x and y coordinates 
	gridOne[x][y] = true
	printGrid(gridOne)
    }
    Set ch='Y'
    for(nc=1;ch=='Y';nc++)                                              //for loop to generate next state until break
    {
      	system("clear")
        printGrid(gridOne)
        Print "Continue? [Y/N]"
        Read ch
        determineState(gridOne);
    }
}
// loaf- (5 5),(6,5),(5,6),(7,5),(5,7)  static
// boat - (4,5),(5,4),(6,5),(5,6),(7,7) static
//beacon - (1,1),(2,1),(1,2),(4,4),(3,4),(4,3) oscillating
// glider - (6,5),(7,6),(5,7),(6,7),(7,7)  moves across grid (time period of 4)
// blinker - (5,5),(6,5),(7,5) oscillating (time period 2)
