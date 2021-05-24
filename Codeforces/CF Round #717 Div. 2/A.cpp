#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

void prog() {
    int n, k;
    cin>>n>>k;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    for(int i=0; i<n - 1; i++) {
        if(k == 0) break;
        int subs = min(arr[i], k);
        arr[i] -= subs;
        k -= subs;
        arr[n - 1] += subs;
    }
    
    for(int i=0; i<n; i++) {
        cout<<arr[i];
        if(i == n - 1)cout<<'\n';
        else cout<<' ';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) prog();
    return 0;
}