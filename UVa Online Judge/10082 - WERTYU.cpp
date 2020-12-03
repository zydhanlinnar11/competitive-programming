#include <bits/stdc++.h>
using namespace std;
int DP[184] = {0}, x, y;
bool filled[184] = {false};
char key[4][16] = {0};
void locate(char n) {
    for(int i=0; i<4; i++) {
        short len = strlen(key[i]);
        for(int j=0; j<len; j++)
            if(key[i][j] == n) x = i, y = j;
    }
}
char substitute(char n) {
    if(filled[(short)n])
        return DP[(short)n];
    filled[(short)n] = true;
    locate(n);
    DP[(short)n] = (int)key[x][y - 1];
    return DP[(short)n];
}

int main() {
    strcpy(key[0], "`1234567890-=\0");
    strcpy(key[1], "\tQWERTYUIOP[]\\\0");
    strcpy(key[2], "ASDFGHJKL;'\n\0");
    strcpy(key[3], "ZXCVBNM,./\0");
    char a;
    while ((a = getchar()) != EOF) {
        if(a == ' ' || a == '\n') cout<<a;
        else cout<<substitute(a);
    }
    return 0;
}