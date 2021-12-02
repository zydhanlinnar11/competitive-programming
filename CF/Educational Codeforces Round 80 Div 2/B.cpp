#include <bits/stdc++.h>
using namespace std;

int main() {
    unsigned long long t, a, b, arr[] = {0, 9, 99, 999, 9999, 99999, 999999, 9999999, 99999999, 999999999};
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--) {
        cin>>a>>b;
        unsigned long long i = 9;
        while(arr[i] > b)
            i--;
        cout<<(i * a)<<'\n';
    }
    return 0;
}