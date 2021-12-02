#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ull t, a, b;
    cin>>t;
    for(ull i=0;  i<t; i++) {
        cin>>a>>b;
        if(((a % b) != 0) && ((b % a) != 0)) {
            cout<<"-1\n";
            continue;
        }
        if(a == b) {
            cout<<"0\n";
            continue;
        }
        ull res = 0;
        ull fact = (a > b) ? (a / b) : (b / a);
        while(fact > 0) {
            if(fact % 8 == 0)
                fact /= 8;
            else if(fact % 4 == 0)
                fact /= 4;
            else if(fact % 2 == 0)
                fact /= 2;
            else break;
            res++;
        }
        if(fact > 1)
            cout<<"-1\n";
        else cout<<res<<'\n';
    }
    return 0;
}