#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> jml_hrf('z' - 'a' + 1, 0);
    int n, k;
    cin>>n>>k;
    string s, sb = "";
    cin>>s;
    for(auto i : s)
        jml_hrf[i - 'a']++;
    if(n == k) {
        cout<<'\n';
        exit(0);
    }
    for(auto &i : jml_hrf) {
        if(i < k)
            k -= i, i = 0;
        else {
            i -= k, k = 0;
            break;
        }
    }
    reverse(s.begin(), s.end());
    for(auto i : s) {
        if(jml_hrf[i - 'a'] > 0)
            sb.push_back(i), jml_hrf[i - 'a']--;
    }
    reverse(sb.begin(), sb.end());
    cout<<sb<<'\n';
    return 0;
}