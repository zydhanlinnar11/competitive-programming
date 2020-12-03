#include <bits/stdc++.h>
using namespace std;

bool compare(string &a, string &b) {
    if(a.length() == b.length())
        return a < b;
    return a.length() < b.length();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> arr;
    int n;
    cin>>n;
    for(int i=0; i<n; i++) {
        string tmp;
        cin>>tmp;
        arr.push_back(tmp);
    }
    // Sort sesuai ketentuan soal
    sort(arr.begin(), arr.end(), compare);
    for(auto i : arr)
        cout<<i<<'\n';
    return 0;
}