#include <bits/stdc++.h>
using namespace std;
vector<int> *adjList;
vector<int> matkul;

bool topsort(int n, vector<int> &indegree) {
    priority_queue<int, vector<int>, greater<int>> pq;
    int cnt = 0;
    for(int i=0; i<indegree.size(); i++)
        if(indegree[i] == 0)
            pq.push(i);
    while(!pq.empty()) {
        int top = pq.top();
        pq.pop();
        matkul.push_back(top), cnt++;
        if(cnt > n)
            return false;
        for(int i=0; i<adjList[top].size(); i++) {
            if(--indegree[adjList[top][i]] == 0) {
                pq.push(adjList[top][i]);
            }
        }
    }
    return cnt == n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin>>n>>m;
    adjList = new vector<int>[n];
    vector<int> indegree(n, 0);
    for(int i=0; i<m; i++) {
        int src, dst;
        cin>>src>>dst;
        src--, dst--;
        indegree[dst]++;
        adjList[src].push_back(dst);
    }
    bool available = topsort(n, indegree);
    for(int i=0; i<n; i++) {
        cout<<(available ? matkul[i] + 1 : -1)<<((i == (n - 1)) ? '\n' : ' ');
    }
    return 0;
}