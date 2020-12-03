#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main() {
    int n, k, start[26], finish[26] = {0};
    string tamu;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    int available = k;
    cin>>tamu;
    for(int i=0; i<26; i++)
        start[i] = INT_MAX;
    for(int i=0; i<n; i++) {
        if(start[tamu[i] - 'A'] > i)
            start[tamu[i] - 'A'] = i;
        if(finish[tamu[i] - 'A'] < i)
            finish[tamu[i] - 'A'] = i;
    }
    for(int i=0; i<n; i++) {
        if(start[tamu[i] - 'A'] == i) {
            if(available == 0) {
                cout<<"YES\n";
                return 0;
            }
            available--;
        }
        if(finish[tamu[i] - 'A'] == i) {
            available++;
        }
    }
    cout<<"NO\n";
}