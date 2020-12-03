#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x, y;
    cin>>n>>x>>y;
    if(x > y) {
        cout<<n<<'\n';
    } else {
        int res = 0;
        for(int i=0; i<n; i++) {
            int tmp;
            cin>>tmp;
            if(tmp <= x)
                res++;
        }
        cout<<((res + 1) >> 1)<<'\n';
    }
    return 0;
}