# algo training solutions
My solutions of various software training problems.

## Usage
### Paste test case into terminal
In order to check solution, compile it using g++ and run:
```bash
g++ -o {solution_file} {solution_file}.cpp judge.cpp
./{solution_file}
```
Then copy/paste test case from in folder. Compare it with results from out folder to see correctness.

### Redirect file to stdin
In order to avoid cluttered terminal (input mixes with output), add:
```cpp
#include <fstream>
``` 
at the beggining of the {solution}.cpp file, and add:
```cpp
freopen("in/{test_case}.in","r", stdin);
```
to redirect file to input stream and see only results in terminal.

## Week 1
Bit manipulation
 - bit counting algorithm
 - set container with up to 200 000 000 numbers (65mb space limit)
 - friends problem (representing subsets as bitmasks)
 - partition (is it possible to represent a set as two subsets with equal sum)
 - bit reversal (quickest way)
 
## Week 2
Backtracking and recursion
 - create logo out of preset stamps
 - overtime distribution between workers
 - partition again, but recursive
 - sudoku solver
 - octopus comp

## Week 3
Graphs
 - Airports BFS 
 - Graph 2-coloring
 - Create filesystem and find safest directiory
 - 2D map BFS
 - "Tower of Hanoi"-like water puzzle