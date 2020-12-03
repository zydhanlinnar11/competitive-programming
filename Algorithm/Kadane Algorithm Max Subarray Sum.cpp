#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {1, 4, -1, 9, -30, -5, 2, 6};
    int total = INT_MIN, curr = INT_MIN;
    for(int i=0; i<sizeof(arr)/sizeof(int); i++)
        curr = max(curr, 0) + arr[i], total = max(curr, total);
    cout<<"Max : "<<total<<'\n';
    return 0;
}