#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N;
    if(N == 0)
        cout<<"1\n";
    else if(N == 1)
        cout<<"0\n";
    else if(N == 2)
        cout<<"8\n";
    else {
        if(N & 1) {
            cout<<'4';
            N--;
        }
        while(N) {
            cout<<'8';
            N -= 2;
        }
        cout<<'\n';
    }
    return 0;
}