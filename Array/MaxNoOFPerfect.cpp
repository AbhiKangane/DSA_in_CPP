// perfect number is a number whose sum of all divisors(excluding itself) equals to original number
// ex: 6 = 1+2+3
#include<iostream>
#include<cmath>
using namespace std;

bool isNumPerfect(int n){
    int sum = 1;
    for(int i=2; i<sqrt(n); i++){
        if(n%i == 0){ // if i is divisor of n
            if(i == n/i) // if i is square root of n
                sum += i;
            else
                sum += i + n/i; 
        }
    }

    if(sum == n && n != 1)
        return true;
    
    return false;
}


int maxSum(int arr[], int n, int subarr_size){
    if(n<subarr_size){
        cout<<"Invalid Values"<<endl;
        return -1;
    }

    int res = 0;
    for (int i = 0; i < subarr_size; i++){
        res += arr[i];
    }
    
    int sum = res;
    for(int i = subarr_size; i<n; i++){
        sum += arr[i] - arr[i-subarr_size];
        res = max(res,sum);
    }

    return res;
}

int maxNoOfPerfects(int arr[], int n, int subarr_Size){
    for (int i = 0; i < n; i++){
        if(isNumPerfect(arr[i]))
            arr[i] = 1;
        else
            arr[i] = 0;
    }
    return maxSum(arr,n,subarr_Size);
}

int main(){
    int arr[] = {28,2,3,6};

    cout<<maxNoOfPerfects(arr,4,3);
    return 0;
}