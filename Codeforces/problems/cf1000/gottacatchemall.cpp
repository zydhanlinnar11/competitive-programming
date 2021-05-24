#include <iostream>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    map<char, int> mp;

    for(char i: s)
        mp[i]++;

    string bulb = "Bulbasaur";

    int minim = INT32_MAX;
    for(char i: bulb) minim = min(minim, (i == 'a' || i == 'u' ? mp[i] / 2 : mp[i]));

    cout<<minim<<'\n';

    return 0;
}