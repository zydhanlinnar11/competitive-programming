#include <bits/stdc++.h>
using namespace std;
typedef struct _stnode {
    int val, l_range, r_range;
    struct _stnode * left = NULL, *right = NULL;
} node;

node * createNode(int val, int l_range, int r_range) {
    node * newNode = new node;
    newNode->val = val;
    newNode->l_range = l_range;
    newNode->r_range = r_range;
    return newNode;
}

node* buildSegmentTree(vector<int> &arr, int l_range, int r_range) {
    if(l_range == r_range)
        return createNode(arr[l_range], l_range, r_range);
    node * newNode = new node;
    newNode->l_range = l_range;
    newNode->r_range = r_range;
    newNode->left = buildSegmentTree(arr, l_range, l_range + ((r_range - l_range) >> 1));
    newNode->right = buildSegmentTree(arr, l_range + ((r_range - l_range) >> 1) + 1, r_range);
    newNode->val = newNode->left->val + newNode->right->val;
    return newNode;
}

typedef struct _st {
    node * root;
    _st(vector<int> &arr, int l_range, int r_range) {
        root = buildSegmentTree(arr, l_range, r_range);
    }
} segment_tree;

int getSum(node * root, int l_range, int r_range) {
    if(root == NULL || r_range < root->l_range || l_range > root->r_range)
        return 0;
    if(l_range <= root->l_range && r_range >= root->r_range)
        return root->val;
    else return getSum(root->right, l_range, r_range) + getSum(root->left, l_range, r_range);
}

node * updateVal(node * root, int before, int after, int index) {
    if(root == NULL)
        return NULL;
    if(index <= root->r_range && index >= root->l_range) {
        root->val += after - before;
        root->left = updateVal(root->left, before, after, index);
        root->right = updateVal(root->right, before, after, index);
    }
    return root;
}

node * update(vector<int> &arr, node * root, int before, int after, int index) {
    arr[index] = after;
    root = updateVal(root, before, after, index);
    return root;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> arr(n, 0);
    for(int i=0; i<n; i++)
        cin>>arr[i];
    segment_tree st(arr, 0, n - 1);
    int l, r;
    cin>>l>>r;
    cout<<getSum(st.root, l, r)<<'\n';
    st.root = update(arr, st.root, arr[2], 11, 2);
    cout<<getSum(st.root, l, r)<<'\n';
}