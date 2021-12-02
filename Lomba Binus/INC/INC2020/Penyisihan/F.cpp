#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
int arr[26];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    string s;
    cin>>n>>k;
    cin>>s;
    int minmoves = k;
    for(int i=0; i<k; i++)
        arr[s[i] - 'A']++;
    for(int i=0; i < (n - k); arr[s[i] - 'A']--, arr[s[i + k] - 'A']++, i++) {
        for(int j : arr)
            minmoves = min(minmoves, k - j);
    }
    for(int j : arr)
        minmoves = min(minmoves, k - j);
    cout<<minmoves<<'\n';
    return 0;
}