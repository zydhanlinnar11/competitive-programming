#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n;
    cin>>t;
    while(t--) {
        cin>>n;
        int arr[n];
        unordered_set<int> elemArray;
        for(int i=0; i<n; i++) {
            cin>>arr[i];
            elemArray.insert(arr[i]);
        }
        if(n & 1) {
            cout<<"-1\n";
            continue;
        }
        bool bisa = true;
        for(int j=1; j<=1024; j++) {
            bisa = true;
            for(int i=0; i < n; i++) {
                if(elemArray.find(arr[i] ^ j) == elemArray.end()) {
                    bisa = false;
                    break;
                } 
            }
            if(bisa) {
                cout<<j<<'\n';
                break;
            }
        }
        if(!bisa) {
            cout<<"-1\n";
        }
    }
    return 0;
}