#include <bits/stdc++.h>
using namespace std;
long long kabeh = 0;
bool dontadd = false;
string last;

typedef struct _tn {
    map<char, _tn*> child;
    bool isEnd = false;
    map<char, int> word;
} trieNode;

trieNode* insert(trieNode* root, string s, int idx) {
    if(idx == s.size()) {
        root->isEnd = true;
        return root;
    }
    if(root->child.empty() || root->child.find(s[idx]) == root->child.end()) {
        trieNode *child = new trieNode;
        root->child.insert(make_pair(s[idx], child));
        root->word.insert(make_pair(s[idx], 0));
    }
    root->word[s[idx]]++;
    root->child[s[idx]] = insert(root->child[s[idx]], s, idx + 1);
    return root;
}

void printAll(trieNode* root, string s) {
    if(root->isEnd) {
        // cout<<"enter "+s+'\n';
        if(!dontadd) kabeh++;
        if(s == last)
            dontadd = true;
        if(!dontadd) kabeh++;
        return;
    }
    for(auto i:root->child) {
        // cout<<"insert "<<i.first<<'\n';
        kabeh++;
        printAll(i.second, s + i.first);
    }
    if(!dontadd) {
        kabeh++;
        // cout<<"backspace\n";
    }
}

int searchNode(trieNode *root, string s) {
    for(int i=0; i<s.size(); i++) {
        auto curr = root->child.find(s[i]);
        if(curr == root->child.end())
            return 0;
        else {
            if(i == s.size() - 1)
                break;
            root = curr->second;
        }
    }
    return root->word[s[s.size() - 1]];
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    trieNode *root = new trieNode;
    int n;
    cin>>n;
    set<string> word;
    while(n--) {
        string tmp;
        cin>>tmp;
        if(word.find(tmp) != word.end()) {
            kabeh++;
            continue;
        }
        word.insert(tmp);
        root = insert(root, tmp, 0);
    }
    last = *word.rbegin();
    printAll(root, "");
    cout<<kabeh<<'\n';
    return 0;
}