#include <bits/stdc++.h>

using namespace std;

short movex[] = {0, 0, 1, -1}, movey[] = {1, -1, 0, 0}, bola[25][25], m, n, xmax, ymax, runtuh[25] = {0};
int nilai, maks;
bool visited[25][25] = {0}, mark;

void count(short x, short y, short ball) {
    if((bola[x][y] != ball) || ((mark) ? false : visited[x][y]) || (y < 0) || (x < 0) || (y >= 25) || (x >= 25)) return;
    else {
        if(mark) bola[x][y] = -1;
        else {
            visited[x][y] = true;
            nilai++;
        }
        for(int i=0; i < (sizeof(movex) / sizeof(short)); i++) {
            count(x + movex[i], y + movey[i], ball);
        }
    }
}

int main() {
    maks = -1;
    cin>>m>>n;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++)
            cin>>bola[i][j];
    }
    mark = false;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(!visited[i][j]) {
                nilai = 0;
                count(i, j, bola[i][j]);
                if (nilai > maks) {
                    maks = nilai;
                    xmax = i;
                    ymax = j;
                }
            }
        }
    }
    memset(runtuh, 0, 25);
    mark = true;
    count(xmax, ymax, bola[xmax][ymax]);
    for(int i = 0; i < n; i++) {
        int marked = 0, indexy = 0;
        for(int j = 0; j < m; j++) {
            if(bola[j][i] == -1) marked++;
            else {
                runtuh[indexy] = bola[j][i];
                indexy++;
            }
        }
        for(int j = 0; j < marked; j++) {
            bola[j][i] = -1;
        }
        int k = 0;
        for(int j = marked; j <= marked+indexy; j++, k++) {
            bola[j][i] =  runtuh[k];
        }
    }
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(bola[i][j] == -1) cout<<'.';
            else cout<<bola[i][j];
            if(j == n-1) cout<<endl;
            else cout<<' ';
        }
    }
    return 0;
}