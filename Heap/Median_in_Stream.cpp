#include<iostream>
#include<queue>
using namespace std;


// sol 1: by Love Babbar
int signum(int a, int b){
    if(a==b)        return 0;
    else if(a>b)    return 1;
    else            return -1;
}

void callMedian(int element, priority_queue<int> &maxi,
                priority_queue<int, vector<int>, greater<int>> &mini, int &median){

    switch (signum(maxi.size(), mini.size())){

        case 0: if(element > median){
                    mini.push(element);
                    median = mini.top();
                }
                else{
                    maxi.push(element);
                    median = maxi.top();
                }
            break;
            
        case 1: if(element > median){
                    mini.push(element);
                    median = (mini.top() + maxi.top()) / 2;
                }
                else{
                    mini.push(maxi.top());
                    maxi.pop();
                    maxi.push(element);
                    median = (mini.top() + maxi.top()) / 2;
                }
            break;

        case -1: if(element > median){
                    maxi.push(mini.top());
                    mini.pop();
                    mini.push(element);
                    median = (mini.top() + maxi.top()) / 2;
                }
                else{
                    maxi.push(element);
                    median = (mini.top() + maxi.top()) / 2;
                }
            break;

        default:
            break;
    }
}

vector<int>findMedian(vector<int> &arr, int n){
    vector<int> ans;
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    int median = 0;

    for(int i = 0; i < n; i++){
        callMedian(arr[i], maxheap, minheap, median);
        ans.push_back(median);
    }
    
    return ans;
}


// sol 2: by apna college
priority_queue<int,vector<int>,greater<int>> pqmin;
priority_queue<int,vector<int>> pqmax;

void insert(int x){
    if(pqmax.size() == pqmin.size()){
        if(pqmax.size() == 0){ // initially
            pqmax.push(x);
            return;
        }
        if(x < pqmax.top())
            pqmax.push(x);

        else
            pqmin.push(x);
    }

    else{
        // case 1: size of maxheap > size of minheap
        if(pqmax.size() > pqmin.size()){
            if(x >= pqmax.top())
                pqmin.push(x);
            
            else{// remove pqmax.top() & push it into pqmin && push x into pqmax
                int maxTop = pqmax.top();
                pqmin.push(maxTop);
                pqmax.pop();
                pqmax.push(x);
            }
        }
        // case 2: size of maxheap < size of minheap
        else{  
            if(x <= pqmin.top())
                pqmax.push(x);
            
            else{// remove pqmin.top() & push it into pqmax && push x into pqmin
                int minTop = pqmin.top();
                pqmax.push(minTop);
                pqmin.pop();
                pqmin.push(x);
            }
        }
    }
}

double findMedian2(){
    if(pqmax.size() == pqmin.size())
        return (pqmin.top() + pqmax.size()) / 2;
    
    else if(pqmax.size() > pqmin.size())
        return pqmax.top();
    
    else
        return pqmin.top();
}

int main(){
    vector<int> v = {4, 3, 1, 5, 2, 9, 7, 8 ,6};

// sol 1
    // vector<int> medians_array = findMedian(v, 9);
    // cout<<"Printing vector of Medians till index : \n";
    // for (int i = 0; i < 9; i++){
    //     cout<<medians_array[i]<<" ";
    // }
    
// sol 2
    cout<<"Printing vector of Medians till index : \n";
    for(int i=0; i<v.size(); i++){
        insert(v[i]);
        cout<<findMedian2()<<" ";
    }

    return 0;
}