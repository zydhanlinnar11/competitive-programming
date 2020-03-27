#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n;
    string x;
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>t;
    while(t--) {
        cin>>n>>x;
        string a, b;
        cout<<'1';
        bool sudahsatu = false;
        int kasihnolsejakindex = x.length();
        for(int i=1; i<x.length(); i++)
            if(!sudahsatu)
                if(x[i] == '0') cout<<'0';
                else if(x[i] == '1') {
                    cout<<'1';
                    sudahsatu = true;
                    kasihnolsejakindex = i + 1;
                } else cout<<'1';
            else cout<<'0';
        cout<<"\n1";
        for(int i=1; i<x.length(); i++)
            if(i >= kasihnolsejakindex)
                cout<<x[i];
            else
                if(x[i] == '2') cout<<'1';
                else cout<<'0';
        cout<<'\n';
    }
}