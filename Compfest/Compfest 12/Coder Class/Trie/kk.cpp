#include <bits/stdc++.h>
using namespace std;

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
        cout<<s<<'\n';
        return;
    }
    for(auto i:root->child)
        printAll(i.second, s + i.first);
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    trieNode *root = new trieNode;
    int n;
    cin>>n;
    // root = insert(root, "zydhan", 0);
    // root = insert(root, "nadya", 0);
    // root = insert(root, "naru", 0);
    // printAll(root, "");
    set<string> word;
    while(n--) {
        string query;
        int cmd;
        cin>>cmd>>query;
        switch(cmd) {
            case 1:
                if(word.find(query) == word.end()) {
                    root = insert(root, query, 0);
                    word.insert(query);
                }
                break;
            case 2:
                cout<<searchNode(root, query)<<'\n';
                break;
        }
    }
    return 0;
}