#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef pair<int, int> pii;
typedef tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update> AVL;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin>>n>>m;
    unsigned long long sum = 0ULL;
    AVL avl;
    int weight[n];
    for(int i=0; i<n; i++) {
        int tmp;
        cin>>tmp;
        avl.insert(make_pair(i, tmp));
        weight[tmp - 1] = i;
    }
    int counter = -1;
    for(int i=0; i<m; i++) {
        int tmp;
        cin>>tmp;
        pii curr = make_pair(weight[tmp - 1], tmp);
        sum += 2*avl.order_of_key(curr);
        avl.erase(curr);
        curr.first = counter--;
        weight[tmp - 1] = curr.first;
        avl.insert(curr);
    }
    cout<<sum<<'\n';
}