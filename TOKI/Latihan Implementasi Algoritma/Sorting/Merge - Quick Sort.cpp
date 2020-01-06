#include <bits/stdc++.h>
using namespace std;
int n, m[100000];
void merge(int aleft, int aright, int bleft, int bright) {
    int Lsize = (aright - aleft + 1), Rsize = (bright - bleft + 1);
    int * L = new int[Lsize];
    int * R = new int[Rsize];
    for(int i=0; i<Lsize; i++)
        L[i] = m[aleft + i];
    for(int i=0; i<Rsize; i++)
        R[i] = m[bleft + i];
    
    int aIndex = 0, bIndex = 0, tIndex = aleft;
    while((aIndex < Lsize) && (bIndex < Rsize)) {
        if(L[aIndex] < R[bIndex])
            m[tIndex++] = L[aIndex++];
        else
            m[tIndex++] = R[bIndex++];
    }

    while(aIndex < Lsize)
        m[tIndex++] = L[aIndex++];
    while(bIndex < Rsize)
        m[tIndex++] = R[bIndex++];

    delete L;
    delete R;
}

void mergesort(int left, int right) {
    if(left == right) return;
    int mid = left + ((right - left) >> 1);
    mergesort(left, mid);
    mergesort(mid + 1, right);
    merge(left, mid, mid + 1, right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>m[i];
    mergesort(0, n - 1);
    for(int i=0; i<n; i++)
        cout<<m[i]<<'\n';
    return 0;
}