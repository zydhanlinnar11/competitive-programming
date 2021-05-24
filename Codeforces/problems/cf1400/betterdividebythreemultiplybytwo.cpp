#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<pair<int, ull>> arr;
    for(int i=0 ; i<n; i++) {
        pair<int, ull> tmp;
        cin>>tmp.second;
        tmp.first = 0;
        ull number = tmp.second;
        while(number % 3 == 0) {
            tmp.first++;
            number /= 3;
        }
        tmp.first *= -1;
        arr.push_back(tmp);
    }

    sort(arr.begin(), arr.end());
    for(int i=0; i<n; i++) {
        cout<<arr[i].second;
        if(i == n - 1) cout<<'\n';
        else cout<<' ';
    }
}