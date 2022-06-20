#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vi2d;

void printGrid(vi2d &grid) {
    for(auto &row: grid) {
        for(auto &j: row) {
            cout<<j<<" ";
        }
        cout<<"\n";
    }
}

bool isValidGrid(vi2d &grid) {
    bool valid = true;
    set<int> avail;
    int n = grid.size();
    for(int i=1; i<=n * n; i++)
        avail.insert(i);

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            auto unique = avail.find(grid[i][j]) != avail.end();
            valid &= unique;
            if(unique) avail.erase(grid[i][j]);

            int lgCnt = 0, smCnt = 0;
            if(i != 0 && j != 0) {
                lgCnt += grid[i - 1][j - 1] > grid[i][j];
                smCnt += grid[i - 1][j - 1] < grid[i][j];
            }
            if(i != 0 && j != n - 1) {
                lgCnt += grid[i - 1][j + 1] > grid[i][j];
                smCnt += grid[i - 1][j + 1] < grid[i][j];
            }
            if(i != n - 1 && j != 0) {
                lgCnt += grid[i + 1][j - 1] > grid[i][j];
                smCnt += grid[i + 1][j - 1] < grid[i][j];
            }
            if(i != n - 1 && j != n - 1) {
                lgCnt += grid[i + 1][j + 1] > grid[i][j];
                smCnt += grid[i + 1][j + 1] < grid[i][j];
            }
            if(i != 0) {
                lgCnt += grid[i - 1][j] > grid[i][j];
                smCnt += grid[i - 1][j] < grid[i][j];
            }
            if(i != n - 1) {
                lgCnt += grid[i + 1][j] > grid[i][j];
                smCnt += grid[i + 1][j] < grid[i][j];
            }
            if(j != 0) {
                lgCnt += grid[i][j - 1] > grid[i][j];
                smCnt += grid[i][j - 1] < grid[i][j];
            }
            if(j != n - 1) {
                lgCnt += grid[i][j + 1] > grid[i][j];
                smCnt += grid[i][j + 1] < grid[i][j];
            }
            valid &= lgCnt != smCnt;
            if (!valid) {
                printf("(%d, %d)\n", i, j);
                return false;
            }
        }
    }
    
    return valid;
}

void readGrid(vi2d &grid) {
    for(auto &row: grid) {
        for(auto &j: row) {
            cin>>j;
        }
    }
}


vi2d convertToGrid(unsigned size, vi arr) {
    vi2d grid(size, vi(size));
    for(unsigned i=0; i<size * size; i++) {
        grid[i / size][i % size] = arr[i];
    }
    return grid;
}

int cnt = 5;

void _generateUniqueGrid(unsigned size, vi curr, set<int> avail) {
    if(size * size == curr.size()) {
        auto grid = convertToGrid(size, curr);
        if(isValidGrid(grid)) {
            printGrid(grid);
            cout<<"\n";
            if(cnt-- == 0) exit(0);
        }
        return;
    }
    for(auto i: avail) {
        auto cp = avail;
        cp.erase(i);
        auto cpCurr = curr;
        cpCurr.push_back(i);
        _generateUniqueGrid(size, cpCurr, cp);
    }
}

int main() {
    int n; cin>>n;
    // set<int> avail;
    // for(int i=1; i<=n*n; i++) avail.insert(i);
    // _generateUniqueGrid(n, {}, avail);
    vi2d grid(n, vi(n));
    readGrid(grid);
    cout<<isValidGrid(grid)<<"\n";
}