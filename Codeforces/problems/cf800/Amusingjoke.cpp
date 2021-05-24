#include <bits/stdc++.h>
using namespace std;

bool canBeConstructed(string pile, map<char, int> finalchar) {
    for(char i: pile)
        finalchar[i]--;
    
    for(auto i: finalchar) {
        cout<<i.second<<'\n';
        if(i.second != 0)
            return false;
    }
    
    return true;
}

int main() {
    string final = "New Year and Christmas Men";
    map<char, int> finalchar;
    for(char i:final)
        if(i != ' ')
            finalchar[i]++;

    string pile;
    cin>>pile;
    if(canBeConstructed(pile, finalchar)) {
        cout<<"YES\n";
        return 0;
    }
    cin>>pile;
    if(canBeConstructed(pile, finalchar)) {
        cout<<"YES\n";
        return 0;
    }
    cin>>pile;
    if(canBeConstructed(pile, finalchar)) {
        cout<<"YES\n";
        return 0;
    }
    cout<<"NO\n";
    return 0;
}