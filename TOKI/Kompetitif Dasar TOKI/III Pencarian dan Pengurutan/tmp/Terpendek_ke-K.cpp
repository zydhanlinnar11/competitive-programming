#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin>>n>>k;
    int arr[n];
    for(int &i : arr)
        cin>>i;
    // Data diurutkan dari yang terkecil, lalu ambil index yang bersangkutan
    sort(arr, arr + n);
    cout<<arr[k - 1]<<'\n';
    return 0;
}