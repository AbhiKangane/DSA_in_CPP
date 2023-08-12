// given array arr[] of n books, arr[i] denotes pages of book, m is the no. of students
// we have to allocates minimum pages for m students
#include<bits/stdc++.h>
using namespace std;

bool isPossible(int books[], int n, int stu, int mid){
    int stuReuired = 1, sum = 0;

    for (int i = 0; i < n; i++){
        if(books[i] > mid )
            return false;
        
        if(sum+books[i] > mid){
            stuReuired++;
            sum = books[i];

        if(stuReuired > stu)
            return false;
        }

        else
            sum += books[i];
    }
    return true;
}


int allocateMinPages(int books[], int n, int stu){
    int sum = 0;
    if(n < stu)
        return -1;
    
    for(int i=0; i<n; i++)
        sum += books[i];
    
    int start = 0, end = sum, ans = INT_MAX;

    while (start <= end){
        int mid = (start + end)/2;
        if(isPossible(books,n,stu,mid)){
            ans = min(ans, mid);
            end = mid-1; // for left part
        } 
        else
            start = mid+1; // for right part
    }
    return ans;
}

int main(){
    int books[] = {10,30,60,90};
    int n=4, stu=2;

    cout<<"The minimum no. of pages : "<<allocateMinPages(books,n,stu);

    return 0;
}