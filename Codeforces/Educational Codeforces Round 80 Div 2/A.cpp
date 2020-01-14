#include <bits/stdc++.h>
using namespace std;

int main() {
    short t;
    long long n, d;
    cin>>t;
    while (t--) {
        cin>>n>>d;
        bool can = false;
        long long last = n;
        while(1) {
            if(d <= n) {
                can = true;
                break;
            }
            if((last + ceil((double)d/(last + 1))) > n) {
                if(last == 1) break;
                last = ceil((double)last/2);
            } else {
                can = true;
                break;
            }
        }
        printf("%s\n", (can) ? "YES" : "NO");
    }
    return 0;
}