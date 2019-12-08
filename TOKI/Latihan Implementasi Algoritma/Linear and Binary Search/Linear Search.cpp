#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin>>n>>m;
    bool found = false;
    int *arr = new int[n];
    for(int i = 0; i < n; i++) {
        cin>>arr[i];
        if(arr[i] == m && !found) {
            cout<<i<<endl;
            found = true;
        }
    }
    if(!found) cout<<"-1"<<endl;
    
    return 0;
}