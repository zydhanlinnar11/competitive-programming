#include <bits/stdc++.h>
using namespace std;
bool sudah[9];
deque<int> dq;
int n, k;

void kp(int depth) {
    if(depth == n) {
        cout<<dq.front();
        auto i = dq.begin();
        i++;
        for(; i != dq.end(); i++)
            cout<<' '<<*i;
        cout<<'\n';
    } else {
        for(int i=1; i<=n; i++) {
            if(sudah[i] || (!dq.empty() && abs(dq.back() - i) > k))
                continue;
            sudah[i] = true;
            dq.push_back(i);
            kp(depth + 1);
            sudah[i] = false;
            dq.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    kp(0);
    return 0;
}