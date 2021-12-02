#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    string s;
    bool berkurang = false;
    cin>>s;
    for(auto &i : s) {
        if(berkurang) {
            i = '1';
            continue;
        }
        if(i == '1' || i == '0')
            continue;
        else if(!berkurang) {
            berkurang = true;
            i = '1';
        }
    }
    int power[12], len = s.length(), res = 0;
    power[0] = 1;
    for(int i=1; i<12; i++)
        power[i] = power[i - 1] * 2;
    for(int i=len - 1; i >= 0; i--) {
        if(s[i] == '1')
            res += power[len - i - 1];
    }
    cout<<res<<'\n';
    return 0;
}