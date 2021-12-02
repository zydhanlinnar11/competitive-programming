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
        int n;
        string s;
        cin>>n;
        cin>>s;
        for(int i=(s.length() - 2); i>=0; i--) {
            while(s[i] == '1' && s[i + 1] == '0') {
                if(i > 0 && s[i - 1] == '1') {
                    s.erase(s.begin() + i);
                    i--;
                } else if(i < (s.length() - 2) && s[i + 2] == '0') {
                    s.erase(s.begin() + i + 1);
                } else s.erase(s.begin() + i);
            }
        }
        cout<<s<<'\n';
    }
    return 0;
}