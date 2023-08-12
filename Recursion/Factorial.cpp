#include<iostream>
using namespace std;

// recursive sol
int factorial_Rec(int num){
    if (num == 0 || num == 1)
        return 1;
    else
        return (num * factorial_Rec(num - 1));
}

// iterative sol
int factorial_Iter(int num){
    int fact = 1;
    for(int i=1; i<=num; i++)
        fact *= i;

    return fact;
}

int main(){
  int num;
  printf("Enter the number for finding factorial: ");
  scanf("%d", &num);
  // printf("factorial of %d is %d", num, factorial_Rec(num));
  printf("factorial of %d is %d", num, factorial_Iter(num));

  return 0;
}