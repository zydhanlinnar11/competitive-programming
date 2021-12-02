#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> arr;
    int sum0 = 0;
    for(int i=0; i<n; i++) {
        int tmp;
        cin>>tmp;
        if(tmp != 1) arr.push_back(tmp);
    }
    for(int i=0; i<arr.size(); i++) {
        if(arr[i] != 0)
            continue;
        if((i + 1) < arr.size() && arr[i + 1] == 3)
            arr[i] = 1;
        else if((i - 1) >= 0 && arr[i - 1] == 3)
            arr[i] = 1;
        else if((i - 1) >= 0 && arr[i - 1] == 2)
            arr[i] = 1, arr[i - 1] = 1;
        else if((i + 1) < arr.size() && arr[i + 1] == 2)
            arr[i] = 1, arr[i + 1] = 1;
    }
    for(int i:arr)
        if(i == 0)
            sum0++;
    cout<<n - sum0<<'\n';
    return 0;
}