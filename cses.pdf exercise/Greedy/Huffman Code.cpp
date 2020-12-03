#include <bits/stdc++.h>
using namespace std;
typedef pair<unsigned, char> puc;
typedef pair<char, unsigned> pcu;

typedef struct _node {
    bool flag;
    unsigned freq;
    char letter;
    _node * left, * right;
    _node() {
        flag = freq = letter = 0;
        left = right = NULL;
    }
    _node(bool _flag, unsigned _freq, char _letter) {
        flag = _flag;
        freq = _freq;
        letter = _letter;
        left = right = NULL;
    }
} huffman_node;

struct compVal {
    bool operator()(huffman_node const& a, huffman_node const& b) {
        if(a.freq == b.freq)
            return a.letter > b.letter;
        return a.freq > b.freq;
    }
};

typedef class _tree {
private:
    huffman_node * root = NULL;
    unordered_map<char, string> codeword;
    void traverse();
public:
    string compressed = "";
    _tree() {
        root = NULL;
    }
    _tree(string);
    string convertToOriginal(string);
} huffman_tree;

huffman_tree::_tree(string src) {
    unordered_map<char, unsigned> freq;
    for(auto i : src)
        if(freq.find(i) != freq.end())
            freq[i]++;
        else freq.insert(make_pair(i, 1));
    priority_queue<huffman_node, vector<huffman_node>, compVal> pq;
    for(auto i : freq)
        pq.push(huffman_node(1, i.second, i.first));
    while(pq.size() > 1) {
        huffman_node * a = new huffman_node, * b = new huffman_node;
        *a = pq.top();
        pq.pop();
        *b = pq.top();
        pq.pop();
        huffman_node tmp(0, a->freq + b->freq, 0);
        tmp.left = a, tmp.right = b;
        pq.push(tmp);
    }
    root = new huffman_node;
    *root = pq.top();
    pq.pop();
    traverse();
    for(auto i : src)
        compressed += codeword[i];
}

void huffman_tree::traverse() {
    queue<pair<huffman_node, string>> q;
    q.push(make_pair(*root, ""));
    while(!q.empty()) {
        huffman_node now = q.front().first;
        string code = q.front().second;
        q.pop();
        // if(now.flag == 0)
        //     cout<<"Internal node "<<now.freq<<'\n';
        if(now.flag == 1) {
            codeword.insert(make_pair(now.letter, code));
            // cout<<now.letter<<" "<<now.freq<<" " + code<<'\n';
        }
        if(now.left != NULL)
            q.push(make_pair(*now.left, code + "0"));
        if(now.right != NULL)
            q.push(make_pair(*now.right, code + "1"));
    }
}

string huffman_tree::convertToOriginal(string src) {
    string tmp;
    huffman_node now = *root;
    for(auto i : src) {
        if(now.flag == 1) {
            tmp.push_back(now.letter);
            now = *root;
        }
        if(i == '0')
            now = *now.left;
        else now = *now.right;
    }
    if(now.flag == 1)
        tmp.push_back(now.letter);
    return tmp;
}

int main() {
    huffman_tree a("anjay");
    cout<<a.compressed<<'\n';
    cout<<a.convertToOriginal(a.compressed)<<'\n';
    return 0;
}