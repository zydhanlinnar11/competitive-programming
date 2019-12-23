#include <bits/stdc++.h>
using namespace std;
#define mod (unsigned long long)1000000007

int main() {
    unsigned long long i = 0, total = 1;
    string s;
    cin>>s;
    if(s.find('m') != s.npos || s.find('w') != s.npos) {
        cout<<0<<endl;
        return 0;
    } else {
        unsigned long long curr[100009] = {0};
        curr[0] = 1, curr[1] = 1;
        for(int i=1; i <= s.length(); i++) {
            curr[i] = curr[i - 1] % mod;
            if((s[i - 1] == 'n' || s[i - 1] == 'u') && (s[i - 1] == s[i - 2])) {
                curr[i] = ((curr[i - 1] % mod) + (curr[(((i - 2) < 0) ? 0 : (i - 2))] % mod)) % mod;
            }
        }
        cout<<curr[s.length()]<<endl;
    }
    return 0;
}