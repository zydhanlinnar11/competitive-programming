#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define mpair(a, b) make_pair(a, b)

void func() {
    int i_gnp = 0, i_gnjl = 0, gnjl = 0, gnp = 0, n, misplaced = 0;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin>>arr[i];
        if(arr[i] & 1)
            gnjl++;
        else gnp++;
        if(i & 1)
            i_gnjl++;
        else i_gnp++;
        if((i % 2) != (arr[i] % 2))
            misplaced++;
    }
    if(gnjl != i_gnjl || gnp != i_gnp)
        cout<<"-1\n";
    else cout<<(misplaced / 2)<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while (t--)
        func();
    
    return 0;
}