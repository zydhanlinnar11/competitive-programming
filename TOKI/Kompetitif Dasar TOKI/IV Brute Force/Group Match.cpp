#include <bits/stdc++.h>
#define nextteam valid(a, b + 1)
using namespace std;
int n, score[] = {0, 0, 0, 0, 0}, scoredata[] = {0, 0, 0, 0, 0};

bool valid(int, int);

int main() {
    int t;
    cin>>t;
    while(t--) {
        cin>>n;
        for(int i=0; i<n; i++) cin>>score[i];
        if(valid(0,1)) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}

bool valid(int a, int b) {
    bool mungkin = false;
    if(a == (n - 1)) {
        mungkin = true;
        for(int i=0; i<n; i++) {
            if(score[i] != scoredata[i]) return false;
        }
    } else if(b == n) return (mungkin || valid(a + 1, a + 2));
    else {
        scoredata[a] += 3;
        mungkin |= nextteam;
        scoredata[a] -= 3;

        scoredata[a]++;
        scoredata[b]++;
        mungkin |= nextteam;
        scoredata[a]--;
        scoredata[b]--;

        scoredata[b] += 3;
        mungkin |= nextteam;
        scoredata[b] -= 3;
    }
    return mungkin;
}