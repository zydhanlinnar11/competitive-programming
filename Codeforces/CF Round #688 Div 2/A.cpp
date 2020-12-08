#include <bits/stdc++.h>
using namespace std;

void func() {
    int n, m, sum = 0;
    cin>>n>>m;
    int arr[n];
    for(int &i : arr)
        cin>>i;
    for(int i=0; i<m; i++) {
        int tmp;
        cin>>tmp;
        auto train = lower_bound(arr, arr + n, tmp);
        if(train != (arr + n) && *train == tmp)
            sum++;
    }
    cout<<sum<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
        func();
}