/*
Que 4) Perfect Budget
Problem Description
Shasank is a government civil engineer, who constructs the infrastructure like roads, bridges, water resources etc. Once he receive the appropriate budget and the list of constructions(or projects), he will start them one after the other.
These projects are based on different regions and he has to move from one site to another site along with the resources. These sites have their own rules and by the end day of the project, the higher officials in that site will give/ take an amount towards reward / penalty for early / late completion.

For every project, given
Expenditure - the expenditure for the given project
Completion bonus - the amount received as gratuity after the project is completed.
Reward / Penalty - this is an amount that is either given/taken to/from Shasank according to the site norms. The '+' sign indicates reward, else it is considered as penalty for being late.

A budget is called perfect budget if within that amount, he can complete all the projects in every possible order. Help Shasank in calculating what is the minimum perfect budget for the given list of projects.

Note: The site officials will not charge penalty which is greater than the bonus for that project ie., bonus - penalty >= 0 for all projects.

Constraints
1 <= n <= 1000
0 <= expenditure, bonus <= 10^4
1 <= reward <= 10^4
-10^4 <= penalty <= -1

Input
First line contains n denoting the number of projects.
Next n lines will contain expenditure, completion bonus, reward / penalty separated by space.

Output
Print the minimum budget needed to complete all the projects in every possible order.

Time Limit (secs)
1

Examples
Example 1
Input
4
3 9 +4
0 4 -2
7 10 -1
4 2 +1

Output
8

Explanation
Initial Budget       An order which is not possible within the given initial budget
2                       P1, P2, P3, P4
3                       P4, P3, P2, P1
5                       P3, P4, P2, P1
7                       P4, P3, P2, P1
8                     All orders are possible
Thus we can complete the given projects in every possible way with a budget of 8, hence print 8.

Example 2
Input
3
13 9 +6
7 3 -3
9 6 +11

Output
20

Explanation
Initial Budget       An order which is not possible within the given initial budget
4                        P3, P2, P1
9                        P1, P2, P3
12                       P1, P2, P3
15                       P2, P1, P3
17                       P2, P1, P3
20                   All orders are possible
Thus we can complete the given projects in every possible way with a budget of 20, hence print 20.
*/