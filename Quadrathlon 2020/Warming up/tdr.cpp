#include <bits/stdc++.h>
using namespace std;

bool compare(char &a, char &b) {
    return a > b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, sum = 0;
    cin>>n;
    string tmp;
    cin>>tmp;
    bool bisa = false;
    for(char i : tmp)
        sum += i - '0';
    sort(tmp.begin(), tmp.end(), compare);
    sum = 9 - (sum % 9);
    for(char &i : tmp) {
        if(sum + i <= '9') {
            i += sum, bisa = true;
            break;
        }
    }
    sum = (sum == 9 ? 9 : 9 - sum);
    if(!bisa) {
        for(int i=n-1; i>=0; i--) {
            if(tmp[i] - sum >= '0') {
                tmp[i] -= sum, bisa = true;
                break;
            }
        }
    }
    sort(tmp.begin(), tmp.end(), compare);
    if(bisa) {
        if(tmp[0] == '0' && n > 1)
            cout<<"-1\n";
        cout<<tmp<<'\n';
    } else cout<<"-1\n";
    return 0;
}