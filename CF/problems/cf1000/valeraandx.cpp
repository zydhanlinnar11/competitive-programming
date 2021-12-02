#include <iostream>
#include <map>
#define sij s[i][j]
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    string s[n];
    for(int i=0; i<n; i++) {
        cin>>s[i];
    }
    map<char, int> diagonal;
    map<char, int> nondiagonal;
    char x_let = s[0][0], non_x_let = s[0][1];
    bool bisa = x_let != non_x_let;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i == n/2 && j == i) diagonal[sij]++;
            else if(i == n/2 && j != i) nondiagonal[sij]++;
            else if(i != n/2 && (i == j || j == n - 1 - i)) diagonal[sij]++;
            else if(i != n/2) nondiagonal[sij]++;
        }
    }

    bisa &= diagonal.size() == 1;
    bisa &= nondiagonal.size() == 1;

    cout<<(bisa ? "YES\n" : "NO\n");
}