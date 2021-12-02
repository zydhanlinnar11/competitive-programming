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

node * update(vector<int> &arr, node * root, int l_range, int r_range, int newval) {
    arr[l_range] += newval;
    arr[r_range + 1] -= newval;
    root = updateVal(root, arr[l_range], arr[l_range] + newval, l_range);
    root = updateVal(root, arr[r_range + 1], arr[r_range + 1] - newval, r_range + 1);
    return root;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> arr(n, 0), diffarr(n, 0);
    for(int i=0; i<n; i++)
        cin>>arr[i];
    diffarr[0] = arr[0];
    for(int i=1; i<n; i++)
        diffarr[i] = arr[i] - arr[i - 1];
    segment_tree st(diffarr, 0, n - 1);
    int l, r, newval;
    cin>>l>>r>>newval;
    cout<<getSum(st.root, 0, l)<<'\n';
    st.root = update(diffarr, st.root, l, r, newval);
    cout<<getSum(st.root, 0, l)<<'\n';
}