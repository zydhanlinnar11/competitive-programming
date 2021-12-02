#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    float res = 0;
    for(int i=n; i>0; i--)
        res += 1/(float)i;
    cout<<fixed;
    cout<<setprecision(12)<<res<<'\n'; 
}