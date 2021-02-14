# Cellular-Automata
## Theory of Computation Project
A cellular Automaton is a discrete model similar to any other automaton which has its own start state(s) and a set of rules. 
A cellular automaton is a model of a system of "cell" objects with following characteristics :

* The cells live on a grid which can be either 1D or even multi dimensional
* Each cell has a state. The number of state possibilities is typically finite. The simplest example has the two possibilities of 1 and 0
* Each cell has a neighbourhood but it is typically a list of adjacent cells.

![CA](https://github.com/Surajpedd/Cellular-Automata/blob/main/Img/CA.jpg)

## Working
<ul>
 <li>An initial state (time t=0) is selected by assigning a state for each cell</li>
 <li>A new generation is created (advancing t by 1), according to some fixed rule that determines the new state of each cell in terms of:
     <ol>
         <li>The current state of the cell</li>
         <li>The states of the cells in its neighbourhood</li>
     </ol>
 </li>
 <li>Hence, we calculate a new state by looking at all previous neighbouring state</li>
</ul>

## Examples

 ### 1. [Rule 90](https://github.com/Surajpedd/Cellular-Automata/blob/main/Rule90.cpp)
 
Rule 90 is an elementary cellular automaton that consists of a one-dimensional array of cells, each of which can hold either a 0 or a 1 value. When the initial state has a single nonzero cell, this diagram has the appearance of the Sierpiński triangle.<br>
In Rule 90, each cell is the <b>exclusive or(XOR)</b> of its two neighbors and since this is equivalent to modulo-2 addition, this generates the modulo-2 version of Pascal's triangle.<br>

![Rule 90](https://github.com/Surajpedd/Cellular-Automata/blob/main/Img/Rule%2090.jpg)

 ### 2. [Game of Life](https://github.com/Surajpedd/Cellular-Automata/blob/main/GameofLife.cpp)
 
The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970. It is a zero-player game, meaning that its evolution is determined by its initial state, requiring no further input.

The Rules for Evolution are :-
<ol>
<li> Any live cell with fewer than two live neighbours dies, as if by underpopulation.</li>
<li> Any live cell with two or three live neighbours lives on to the next generation.</li>
<li> Any live cell with more than three live neighbours dies, as if by overpopulation.</li>
<li> Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction</li>
</ol>

During the process of evolution of "life" various patterns emerge some of which are as follows

1. Static Patterns


![Game of Life](https://github.com/Surajpedd/Cellular-Automata/blob/main/Img/Loaf.png)

2. Oscillating Patterns


![Game of Life](https://github.com/Surajpedd/Cellular-Automata/blob/main/Img/Beacon.gif)

and many more...
