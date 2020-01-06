#include <bits/stdc++.h>
using namespace std;
int arr[100000] = {0}, n, q, d;
int binsearch(int val) {
    int left = 0, right = n - 1;
    while(left <= right) {
        int mid = left + ((right - left) >> 1);
        if(arr[mid] > val)
            right = mid - 1;
        else if(arr[mid] < val)
            left = mid + 1;
        else {
            if(mid == 0)
                return mid;
            else if(arr[mid - 1] < val)
                return mid;
            else
                right = mid - 1;
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>arr[i];
    cin>>q;
    while(q--) {
        cin>>d;
        cout<<binsearch(d)<<'\n';
    }
    return 0;
}