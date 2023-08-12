// Finding square root of number(can be float) using binary search approach O(log n)

#include <iostream>
using namespace std;

long long int sqrt_Int(float num)
{

    int low = 0, high = int(num);
    long long int mid = low + (high - low) / 2;
    long long int ans = -1;

    while (low <= high){
        long long int sq = mid * mid;
        if (sq == num){
            return mid;
        }

        if (sq > num){
            high = mid - 1;
        }

        else{
            ans = mid;
            low = mid + 1;
        }

        mid = low + (high - low) / 2;
    }
    return ans;
}

double sqrt_Float(float n, int decimal, int sq_int){
    double factor = 1;
    double ans = sq_int;

    for(int i = 0; i<decimal; i++){
        factor /= 10;

        for(double j=ans; j*j< n; j += factor){
            ans = j;
        } 
    }
    return ans;
}

int main()
{
    // int n;
    float n;
    cout << "Enter the number: ";
    cin >> n;
    int sq_integer = sqrt_Int(n);
    cout << "square root: " << sqrt_Float(n, 4, sq_integer);
    // cout << "square root: " << sqrt_Int(n);
}