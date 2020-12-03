#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int arr[n];
    for(auto &i : arr)
        cin>>i;
    sort(arr, arr+n);
    for(int i=0; i<n; i++)
        cout<<arr[i]<<((i == n - 1) ? '\n' : ' ');
    return 0;
}