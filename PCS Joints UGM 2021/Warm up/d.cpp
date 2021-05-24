#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "Halo Dunia!";
    string inp;
    getline(cin, inp);
    if(s.length() != inp.length()) {
        cout<<"TIDAK\n";
        return 0;
    }
    for(int i=0; i<inp.length(); i++)
        if(tolower(inp[i]) != tolower(s[i])) {
            cout<<"TIDAK\n";
            return 0;
        }
    cout<<"YA\n";
}