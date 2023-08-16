#include<bits/stdc++.h>
using namespace std;

int32_t main(){
    int ladders,snakes;
    cout<<"Enter no. of Ladders & Snakes : ";
    cin>>ladders>>snakes;

    map<int,int> lad;
    map<int,int> snak;

    cout<<"Enter ladders :"<<endl;
    for (int i = 0; i < ladders; i++){
        int u,v;
        cin>>u>>v;
        lad[u] = v;         // from u cell we can go v cell
    }

    cout<<"Enter Snakes :"<<endl;
    for (int i = 0; i < snakes; i++){
        int u,v;
        cin>>u>>v;
        snak[u] = v;       // from u cell we can go v cell
    }

    int moves = 0;
    queue<int> q;
    q.push(1);
    bool found = false;
    vector<bool> vis(101,false); 
    vis[1] = true;

    while (!q.empty() and !found){
        int sz = q.size();
        while (sz--){
            int t = q.front();
            q.pop();

            for (int die = 1; die<=6; die++){
                if(t+die == 100)
                    found = true;
                if(t+die <= 100 && lad[t+die] && !vis[lad[t+die]]){   // for ladder
                    vis[lad[t+die]] = true;
                    if(lad[t+die] == 100)
                        found = true;
                    q.push(lad[t+die]);
                }
                else if(t+die <= 100 && snak[t+die] && !vis[snak[t+die]]){   // for snake
                    vis[lad[t+die]] = true;
                    if(snak[t+die] == 100)
                        found = true;
                    q.push(snak[t+die]);
                }

                else if(t+die <= 100 && !snak[t+die] && !lad[t+die] && !vis[t+die]){   // for empty square
                    vis[lad[t+die]] = true;
                    q.push(t+die);
                }
            }
        }
        moves ++;
    }

    if(found)
        cout<<"Minimum no of steps required to reach at 100 : "<<moves;
    else
        cout<<"-1";
    return 0;
}