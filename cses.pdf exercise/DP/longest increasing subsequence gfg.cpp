#include <bits/stdc++.h>
using namespace std;
// Time Complexity O(n . log(n))
void func() {
    int n;
    cin>>n;
    int arr[n];
    vector<int> end(n, 0);
    int len = 1;
    for(int i=0; i<n; i++)
        cin>>arr[i];
    end[0] = arr[0];
    for(int i=1; i<n; i++) {
        if(arr[i] < end[0])
            end[0] = arr[i];
        else if(arr[i] > end[len - 1])
            end[len++] = arr[i];
        else end[distance(end.begin(), lower_bound(end.begin(), end.begin() + len, arr[i]))] = arr[i];
    }
    cout<<len<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
        func();
}