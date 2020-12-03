#include <bits/stdc++.h>
using namespace std;

int binser(vector<int> &tail, int n, int val) {
    int start = -1, last = n - 1;
    while(start < last - 1) {
        int mid = start + (last - start) / 2;
        if(tail[mid] <= val)
            last = mid;
        else start = mid;
    }
    return last;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, len = 1;
    cin>>n;
    vector<int> tail(n, 0);
    cin>>tail[0];
    for(int i=1; i<n; i++) {
        int curr;
        cin>>curr;
        if(curr < tail[len - 1])
            tail[len++] = curr;
        else if(curr > tail[0])
            tail[0] = curr;
        else
            tail[binser(tail, len, curr)] = curr;
    }
    cout<<len<<'\n';
    return 0;
}