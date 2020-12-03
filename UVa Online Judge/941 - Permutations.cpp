#include <bits/stdc++.h>
using namespace std;
#define MAX_CHAR 20
typedef unsigned long long ull;
string s;
ull dp[MAX_CHAR], n, t;

void print() {
    sort(s.begin(), s.end());
    ull len = s.length();
    for(int i=0; i<len; i++) {
        ull fact = dp[len - (1 + i)], bagi = n / fact;
        cout<<s[bagi];
        s.erase(bagi, 1);
        n %= fact;
    }
    cout<<'\n';
}

int main() {
    dp[0] = 1;
    dp[1] = 1;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i=2; i < MAX_CHAR; i++)
        dp[i] = dp[i - 1] * i;
    cin>>t;
    while(t--) {
        cin>>s>>n;
        print();
    }
    return 0;
}