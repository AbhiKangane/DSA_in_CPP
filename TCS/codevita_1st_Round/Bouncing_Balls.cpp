/*
Que 6) Bouncing Balls
Problem Description
James is playing a shooting game called "Bouncing Balls in the Box." In this game, he needs to shoot all the balls that are moving inside a big rectangular box to win.
James has successfully shot all but two balls, and he has only one bullet left. Luckily, these two remaining balls overlap each other at some point in their movement trajectory. If he aims at the right moment during their overlap, he can eliminate both balls with a single shot.
The game is set in a big rectangular box with dimensions MxN, which is divided into MxN cells. Inside this box, two balls are the targets.
The balls move from one cell to their neighboring cell one step at a time. Each ball maintains its respective direction until it hits the wall of the big box, at which point it changes direction due to the impact with the wall. James needs to time his shot to hit both balls while they overlap for the perfect shot.

                -1,-1     0,-1     1,-1
                     \     |     /
                       \   |   /
                -1,0------ 0,0 ---- 1,0
                        /  |  \
                      /    |    \
                -1,1      0,1     1,1


Matrix:        1,1  2,1  3,1  4,1  5,1
               1,2  2,2  3,2  4,2  5,2
               1,3  2,3  3,3  4,3  5,3
               1,4  2,4  3,4  4,4  5,4
               1,5  2,5  3,5  4,5  5,5

These directions describe how the target box moves within the rectangular box, starting from the initial position [3, 3] and progressing through subsequent cells based on the specified direction. When the target boxes are moving in their corresponding directions, they will eventually hit the wall of the rectangular box and bounce back according to the laws of reflection. Here's how the the path and the bouncing behavior would look for each direction from the position [3,3]:


1. Direction: (-1, -1)
    Initially: [3, 3] -> [2, 2] -> [1, 1]
    Bounce (due to hitting the wall): [1, 1] -> [2, 2] -> [3, 3] -> ...
2. Direction: (0, -1)
    Initially: [3, 3] -> [3, 2] -> [3, 1]
    Bounce (due to hitting the wall): [3, 1] -> [3, 2] -> [3, 3] -> ...
3. Direction: (1, -1)
    Initially: [3, 3] -> [4, 2] -> [5, 1]
    Bounce (due to hitting the wall): [5, 1] -> [4, 2] -> [3, 3] -> ...
4. Direction: (-1, 0)
    Initially: [3, 3] -> [2, 3] -> [1, 3]
    Bounce (due to hitting the wall): [1, 3] -> [2, 3] -> [3, 3] -> ...
5. Direction: (0, 0)
    Initially: [3, 3] -> [3, 3] -> [3, 3] (No change in position as the direction is [0, 0])
6. Direction: (1, 0)
    Initially: [3, 3] -> [4, 3] -> [5, 3]
    Bounce (due to hitting the wall): [5, 3] -> [4, 3] -> [3, 3] -> ...
7. Direction: (-1, 1)
    Initially: [3, 3] -> [2, 4] -> [1, 5]
    Bounce (due to hitting the wall): [1, 5] -> [2, 4] -> [3, 3] -> ...
8. Direction: (0, 1)
    Initially: [3, 3] -> [3, 4] -> [3, 5]
    Bounce (due to hitting the wall): [3, 5] -> [3, 4] -> [3, 3] -> ...
9. Direction: (1, 1)
    Initially: [3, 3] -> [4, 4] -> [5, 5]
    Bounce (due to hitting the wall): [5, 5] -> [4, 4] -> [3, 3] -> ...
Suppose if the ball is in the position [4,3] in the above grid and is moving in the direction (1,1) then the initial path will be [4,3] -> [5,4] and then it had hit the wall, so the reflection will be along the cells, [4,5] -> [3,4] -> [2,3] ...

Now that you know how the balls moves inside the rectangular box, predict when the two target balls will overlap or will be in the same cell, and help James in shooting.

Note:
James is a good shooter and will never miss the hitting, all he needs is to have both the balls in the same cell.
Balls will never stop moving until they are shot.
Constraints
0 < M, N < 1000

Input
The first line consists of two space-separated integers representing the total number of rows and columns, MxN of the box.
The second line consists of two space-separated integers representing the position of the first target ball.
The third line consists of two space-separated integers representing the direction in which the first target ball is moving. Each integer can be either -1, 0, or 1.
The fourth line consists of two space-separated integers representing the position of the second target ball.
The fifth line consists of two space-separated integers representing the direction in which the second target ball is moving. Each integer can be either -1, 0, or 1.

Output
A Single integer that represents the minimum number of steps after which both the balls overlap. Print "Never" if they will never overlap.

Time Limit (secs)
1

Examples
Example 1
Input
5 5
4 2
1 -1
4 4
1 1

Output
3

Explanation
Target ball 1 is in [4,2] and the path traced was [5,1],[4,2],[3,3]
Target ball 2 is in [4,4] and the path traced was [5,5],[4,4],[3,3]
At the third step both balls will overlap i.e. will be in the same cell. Hence, print 3.

Example 2
Input
10 10
2 2
1 1
6 6
1 1

Output
6

Explanation
Target ball 1 :[ 2, 2],[ 3, 3],[ 4, 4],[ 5, 5],[ 6, 6],[ 7, 7],[ 8, 8]
Target ball 2 :[ 6, 6],[ 7, 7],[ 8, 8],[ 9, 9],[10,10],[ 9, 9],[ 8, 8]
At the sixth step both balls will overlap i.e. will be in the same cell. Hence, print 6.
*/