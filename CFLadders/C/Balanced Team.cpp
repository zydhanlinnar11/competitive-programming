#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, res = 1;
    cin>>n;
    int arr[n];
    for(auto &i : arr)
        cin>>i;
    sort(arr, arr + n);
    deque<int> dq;
    for(auto i : arr) {
        if(dq.empty() || i - dq.front() <= 5)
            dq.push_back(i);
        else {
            res = max(res, (int)dq.size());
            while(!dq.empty() && i - dq.front() > 5)
                dq.pop_front();
            dq.push_back(i);
        }
    }
    res = max(res, (int)dq.size());
    cout<<res<<'\n';
    return 0;
}