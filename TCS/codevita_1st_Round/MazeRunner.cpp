/*
Que 3) MazeRunner
Problem Description
You are a brave adventurer who finds yourself in the middle of a mysterious maze. The maze is represented by a set of integers viz. 0, 1, 2, and 3. Each element in the maze represents a block. You are given the coordinates of the starting block and the target block in the maze, and your task is to reach the target block such that you travel least distance in doing so.
As you explore the maze, you encounter several obstacles that block your path. Obstacles are represented by block with a value of 1, and you must avoid these blocks at all costs. Additionally, the maze contains blocks with a value of 2. In your travelled path from source to destination there cannot be more than two blocks with value 2.
Furthermore, as you make your way through the maze, you notice that some blocks are marked with the value 3. These blocks are extremely dangerous and must be avoided at all costs unless it is the only possible way to reach the target block and you should cross such blocks as less as possible even if it leads to a longer path. You cannot move diagonally or visit any blocks twice. Your starting point can be any block.
Your task is to use your wits and navigate through the maze such that you travel the shortest distance from the starting block to the target block without violating any of the rules mentioned above. If no such path exists, you must print STUCK. Can you find the way out of the maze and reach the target block safely?

Constraints
2 <= R,C <= 15
2*2 <= RxC <= 15 *15 (assuming it has considerate amount of 1 2 and 3).
Left Top represents 0 0 and Right Bottom represents R C.

Input
The first line contains the number of rows (R) and columns (C) separated by spaces.
Next next R lines, each containing C space seperated integers represent the maze.
The next line contains the coordinates of the starting block.
The last line contains coordinates of the target block.

Output
Print an integer representing the length of the shortest path traveled between the starting and the target block. If no shortest path found print STUCK.

Time Limit (secs)
1

Examples
Example 1
Input
3 3
0 3 0
0 0 2
1 0 0

0 0
0 2

Output
4

Explaination
You start from the block (0,0). Now, you have two options: either you can take the path having block (0,1) or the block (1,0). Since, an alternate path is available you cannot take path involving block containing number 3. Therefore, you take the path with block with number 0. Then, similarly, you take the block (1,1) with number 0 and the block (1,2) with number 2. You can take at most 2 blocks of such number. Finally, you reach the target (0,3). So, the total distance covered is 4.
Therefore, the shortest path would be (0,0) -> (1,0) -> (1,1) -> (1,2) -> (0,2) 

Example2
Input
3 3
0 1 0
0 3 2
1 2 0

0 0
2 2

Output
4

Explanation
You start from block (0, 0). Then, you move to (1, 0) as that's the only possible route from the start point. From (1, 0), (2, 0) is blocked as it has a value of 1. Therefore, the only option is to choose (1, 1) with value 3. Now, from (1, 1), you can take the route of (1, 2) or (2, 1), but as both of them will give the same shortest distance, you can choose either of them. So, the total distance covered is 4.
Therefore, the shortest path would be (0,0) -> (1,0) -> (1,2) -> (2,1) -> (2,2).

Example 3
Input
3 3
0 1 0
0 3 1
0 1 0

0 0
2 2

Output
STUCK

Explaination
If you take account of the previous example its the same but in block (1, 2) or (2, 1) you have obstacle with number 1 and there is no other way you can reach the target therefore you STUCK.

So there will be no path from start to Target

Example 4
Input
3 4
0 1 0 0
0 3 3 0
0 3 0 0

0 0
0 3

Output
7

Explanation
You start from block (0,0) then (0,1) is 1 so it's blocked then block (1,0) is the only possible path then from (1,0) you take both the block (1,1) and (2,0). So the possible route will be (0,0) -> (1,0) -> (1,1) -> (1,2) ->(1,3) -> (0,3) or (0,0) -> (1,0) -> (1,1) -> (1,2) -> (0,2) -> (0,3) but here you will notice that we have crossed blocks with 3 two times but according to the rules we must avoid 3 at all cost unless necessary. So the only possible route is (0,0) -> (1,0) -> (2,0) -> (2,1) -> (2,2) -> (2,3) -> (1,3) -> (0,3) where we cross only one block with 3. Therefore, the total distance is 7.

*/