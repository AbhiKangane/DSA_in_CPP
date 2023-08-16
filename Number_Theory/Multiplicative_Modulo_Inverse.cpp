// (A * B) % m = 1
// here B is a (multiplicative modulo inverse) exists only if A & m are coprime i.e. gcd(A,m) = 1
// (A*B)-1 = mN, where N is any integer
// ex: (17*(-1)) % 3 = 1 => (-2)%3 = 1 =>(-2+3) % 3 = 1
// (12 * 3) % 7 = 1

// now, a%b = a - (a/b) * b 

#include<bits/stdc++.h>
using namespace std;

// Extended Euclid Algorithm
// ax + by = gcd(a,b) = gcd(b, a%b) = bx1 + (a%b)y1
// putting value of (a%b) into above eq.
// ax + by = bx1 + (a - (a/b)*b)y1
// by comparing we get, x = y1 and y = x1 - (a/b)*y1

// 1) if(b=0) => ax + 0 = gcd(a,0) = a  & y = 0
struct triplet{
    int x, y, gcd;
};

triplet extended_Euclid(int a, int b){
    if(b==0){
        triplet ans;
        ans.x = 1;
        ans.gcd = a;
        ans.y = 0;
        return ans;
    }

    triplet smallAns = extended_Euclid(b, a%b);
    triplet ans;
    ans.x = smallAns.y;
    ans.gcd = smallAns.gcd;
    ans.y = smallAns.x - (a/b)*smallAns.y;
    return ans;
}

int multiplicative_Modulo_Inverse(int a, int m){
    triplet temp = extended_Euclid(a,m);
    return temp.x;
}

int main(){
    int a,m;
    cin>> a >> m;

    cout<<multiplicative_Modulo_Inverse(a,m);

    return 0;
}