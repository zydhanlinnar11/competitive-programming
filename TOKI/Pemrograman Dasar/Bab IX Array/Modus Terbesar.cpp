#include <bits/stdc++.h>
using namespace std;
int arr[1001];
int main() {
    int n, maks = 0;
    cin>>n;
    while(n--) {
        int tmp;
        cin>>tmp;
        arr[tmp]++;
    }
    for(int i=0; i<=1000; i++)
        if(arr[maks] <= arr[i])
            maks = i;
    cout<<maks<<'\n';
    return 0;
}