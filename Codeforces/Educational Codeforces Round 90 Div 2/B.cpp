#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned us;
typedef pair<int, int> pii;
#define unset unordered_set
#define unmap unordered_map
#define mpair make_pair

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        string s, s01 = "01", s10 = "10";
        cin>>s;
        int moves = 0;
        while(!s.empty()) {
            auto _01 = s.find(s01, 0);
            if(_01 != s.npos)
                s.erase(_01, 2), moves++;
            auto _10 = s.find(s10, 0);
            if(_10 != s.npos)
                s.erase(_10, 2), moves++;
            if(_01 == s.npos && _10 == s.npos)
                break;
        }
        cout<<((moves & 1) ? "DA\n" : "NET\n");
    }
    return 0;
}