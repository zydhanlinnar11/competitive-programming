#include <bits/stdc++.h>
using namespace std;
string alph = "ABCDEFGHIJKLMNOPQRSTUVWXYZ", voc, cons;
short pos[26] = {0};

bool isVocal(char a) {
    return (a == 'A' || a == 'I' || a == 'U' || a == 'E' || a == 'O');
}

void getNew() {
    for(int i = 0; i < alph.length(); i++) {
        if(isVocal(alph[i])) voc += alph[i];
        else cons += alph[i];
    }
    for(int i = 0; i < 26; i++) {
        pos[i] = (isVocal(i + 'A')) ? ((voc.find(i + 'A') + 1) % 5) : ((cons.find(i + 'A') + 1) % 21);
    }
}

int main() {
    string k, s;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>k;
    cin.ignore();
    getline(cin, s);
    for(int i = 0; i < k.length(); i++)
        alph.erase(alph.find(k[i]), 1);
    alph += k;
    getNew();
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == ' ') continue;
        s[i] = (isVocal(s[i])) ? voc[pos[s[i] - 'A']] : cons[pos[s[i] - 'A']];
    }
    cout<<s<<'\n';
    return 0;
}