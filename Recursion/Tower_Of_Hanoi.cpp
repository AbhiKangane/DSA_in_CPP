#include<iostream>
using namespace std;

void towerOfHanoi(int n, int src, int helper, int dest ) {
		if(n==1) {
			cout<<"Transer Disk "<<n<<" from "<<src<<" to "<<dest<<endl;
			return;
		}
		
		// transfer of n-1 from src -> helper using dest as 'helper'
		towerOfHanoi(n-1, src, dest, helper);
		
		// transfer nth from src to dest
		cout<<"Transer Disk "<<n<<" from "<<src<<" to "<<dest<<endl;
		
		// transfer of n-1 from helper -> dest using src as 'helper'
		towerOfHanoi(n-1, helper, src, dest);
	}

int main(){
    towerOfHanoi(3, 1,2,3);
    return 0;
}