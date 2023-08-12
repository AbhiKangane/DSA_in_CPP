// Truck leak one unit fuel every unit of distance it travel
// find minimum possible stops required to reach nearest town
// given : arr1[] => distance of stop from the target town
//         arr2[] => fuel available at each stop
// initial fuel(F) & initial distance from towm(D)

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cout<<"Enter no. of test cases: "; 
    cin>> t;

    while(t--){
        int n;
        cout<<"Enter no. of stops: ";
        cin>>n;

        cout<<"Enter distance from town AND available fuel at each stop: \n";
        vector<pair<int,int>> arr(n);
        for(int i=0; i<n; i++)
            cin>>arr[i].first >>arr[i].second; 

        int d, f;
        cout<<"Enter initial distance & fuel of truck from town: ";
        cin>>d>>f;

        for (int i = 0; i <n; i++){
            arr[i].first = d - arr[i].first; // it will give initial distance of truck from each stop
        }
        // sort arr w.r.t. initial distance of truck from each stop
       sort(arr.begin(), arr.end()); 

       int ans = 0;
       int curr = f;  // availabe fuel

       priority_queue<int, vector<int>> maxheap;
       bool flag = 0;

       for(int i=0; i<n; i++){
            if(curr >= d) 
                break;

            while (curr < arr[i].first){
                if(maxheap.empty()){
                    flag=1;
                    break;
                }
                ans ++;  // taking a stop
                curr += maxheap.top(); // it gives total available fuel at stop 
                maxheap.pop();
            }

            if(flag)
                break;
            maxheap.push(arr[i].second);
       } 

       if(flag){
            cout<<"-1"<<endl;
            continue;;
       }

       while (!maxheap.empty() && curr < d){
            curr += maxheap.top();
            maxheap.pop();
            ans++;
       }
       
       if(curr < d){
            cout<<"-1"<<endl;
            continue;;
       }
       cout<<ans<<endl;
    }
    
    return 0;
}