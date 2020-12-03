#include <bits/stdc++.h>
using namespace std;
string Name[1000];
unsigned short n;
// Menggunakan insertion sort lalu ambil indexnya
unsigned short getPos(string nama, unsigned short n) {
    unsigned short i = n;
    Name[i] = nama;
    if(i!=0) {
        while (Name[i-1] > Name[i] && i>0) {
            swap(Name[i-1], Name[i]);
            i--;
        }
    }
    return i;
}

void swap(string str1, string str2) {
    string tmp;
    tmp = str1;
    str1 = str2;
    str2 = tmp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(unsigned short i = 0; i<n; i++) {
        string temp;
        cin>>temp;
        cout<<getPos(temp, i)+1<<endl;
    }
    return 0;
}