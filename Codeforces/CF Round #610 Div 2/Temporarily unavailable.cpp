#include <bits/stdc++.h>
using namespace std;

int main() {
    long long t, a, b, c, r;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--) {
        cin>>a>>b>>c>>r;
        long long before = 0, after = 0, left = c - r, right = c + r;
        if(a > b) {
            a ^= b;
            b ^= a;
            a ^= b;
        }
        if(left >= a && left <= b && right <=b && right >=a) {
            cout<<(b - right) + (left - a)<<'\n';
        } else if(left>=a && left <= b && !(right <=b && right >=a)) {
            cout<<(left - a)<<'\n';
        } else if(!(left>=a && left <= b) && !(right <=b && right >=a)) {
            if((left < a && right < a) || (left > b && right > b)) {
                cout<<(b - a)<<'\n';
            } else {
                cout<<"0\n";
            }
        } else if(!(left>=a && left <= b) && (right <=b && right >=a)) {
            cout<<(b - right)<<'\n';
        }
    }
    return 0;
}