#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    bool sorted = false;
    while(!sorted) {
        sorted = true;
        for(int i=0; i<n-1; i++) {
            if(arr[i] > arr[i+1]) {
                arr[i] ^= arr[i+1];
                arr[i+1] ^= arr[i];
                arr[i] ^= arr[i+1];
                sorted = false;
            }
        }
    }
    for(int i=0; i<n; i++)
        cout<<arr[i]<<'\n';
    return 0;
}