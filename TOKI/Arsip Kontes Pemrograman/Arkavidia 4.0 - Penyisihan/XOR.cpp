#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

ull func(ull a) {
    if(a % 4 == 3) return 0;
    else if(a % 4 == 2) return a+1;
    else if(a % 4) return 1;
    else return a;
};

int main() {
    ull l, r;
    unsigned t;
    cin>>t;
    while(t--) {
        cin>>l>>r;
        cout<<(func(l-1)^func(r))<<'\n';
    }
    return 0;
}