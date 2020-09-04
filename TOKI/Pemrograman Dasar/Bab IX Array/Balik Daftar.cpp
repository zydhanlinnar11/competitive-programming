#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr;
    int tmp;
    while(scanf("%d", &tmp) != EOF)
        arr.push_back(tmp);
    for(auto i=arr.rbegin(); i != arr.rend(); i++)
        cout<<*i<<'\n';
    return 0;
}