// leetcode question no 50

#include <iostream>
using namespace std;

double pow(double n, long long p){
    if (p == 0)
        return 1;
    if (p % 2 == 0)
        return pow(n * n, p / 2);
    return n * pow(n * n, (p - 1) / 2);
}

double myPow(double n, int p){
    // base cases
    if (n == 1)
        return 1;
    if (p == 0)
        return 1;
    else if (p == 1)
        return n;

    else if (p < 0)
        return 1.0 / pow(n, (long long)-1 * p);

    return pow(n, (long long)p);
}

int main()
{
    cout << myPow(3.000, 5);
    return 0;
}
