// Given n jobs having deadline & profit associted with it
// TASK: find no. of jobs done & maximum profit

#include<bits/stdc++.h>
using namespace std;

struct Job{
    int Job_id;
    int deadline; 
    int profit;
};

static bool cmp(Job j1, Job j2){
    return j1.profit > j2.profit; // for sorting jobs w.r.t their profit in descending order
}

vector<int> JobScheduling(Job arr[], int n){
    // sorting jobs w.r.t their profit in descending order
    sort(arr, arr+n, cmp);

    int maxDeadline =  INT_MIN;
    for (int i = 0; i < n; i++){
        maxDeadline = max(maxDeadline, arr[i].deadline); // finding maximum deadline among all jobs for creating schedule array 
    }
    
    vector<int> schedule(maxDeadline+1, -1); // 1 based indexing

    int count = 0;
    int maxProfit = 0;

    for (int i = 0; i < n; i++){
        int currJob_id = arr[i].Job_id;
        int currDeadline = arr[i].deadline;
        int currProfit = arr[i].profit;

        for (int k = currDeadline; k > 0; k--){
            if(schedule[k] == -1){
                count ++; // we can perform job in this slot
                maxProfit += currProfit;
                schedule[k] = currJob_id;
                break;
            }
        }
    }
    
    vector<int> ans;
    ans.push_back(count);
    ans[1] = maxProfit;

    return ans;
}


int main(){
    int n;
    cout<<"Enter no. of jobs : ";
    cin>>n;

    Job j[n];  // creationg array of jobss contains (job_id, deadline, profit) pairs
    cout<<"Enter (job_id, deadline, profit) of each job : \n";
    for (int i = 0; i < n; i++){
        cin>>j[i].Job_id>>j[i].deadline>>j[i].profit;
    }
    
    vector<int> ans = JobScheduling(j, n);
    cout<<"No. of jobs done & Maximum profit earned: "<<ans[0]<<" "<<ans[1]<<endl;
    return 0;
}