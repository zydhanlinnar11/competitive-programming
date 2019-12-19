#include <bits/stdc++.h>
using namespace std;
typedef struct dance {
    int d;
    char t;
}tarian;
int ksum[3628800] = {0}, indx = 0, y, r, n;
tarian bebek[10];
bool pernah[10] = {};

void compute(int t, int k, int now, char before, bool yakin) {
    if(t == r) {
        ksum[indx] = k;
        indx++;
        return;
    }
    for(int i=0; i<n; i++) {
        if(pernah[i]) continue;
        int tmp = bebek[i].d;
        if(before == 'P') tmp <<= 1;
        else if(before == 'L') tmp >>= 1;
        if(yakin) tmp += y;
        pernah[i] = true;
        compute(t + 1, k + tmp, i, bebek[i].t, (bebek[i].t == 'Y' || yakin));
        pernah[i] = false;
    }
}

int binsearch(int left, int right, int n) {
    if(left == right || (((right - left) == 1) && (ksum[right] > n))) return left;
    if(((right - left) == 1) && (ksum[right] <= n)) return right; 
    int mid = left + ((right - left) >> 1);
    if(ksum[mid] == n) {
        if(ksum[mid + 1] > n) return mid;
        return binsearch(mid + 1, right, n);
    }
    else if(ksum[mid] > n) return binsearch(left, mid, n);
    else return binsearch(mid, right, n);
}

void merge(int aleft, int aright, int bleft, int bright) {
    int Lsize = aright - aleft + 1;
    int Rsize = bright - bleft + 1;
    int *L = new int[Lsize];
    int *R = new int[Rsize];
    for(int i=0; i<Lsize; i++)
        L[i] = ksum[aleft + i];
    for(int i=0; i<Rsize; i++)
        R[i] = ksum[bleft + i];
    
    int aIndex = 0, bIndex = 0, tIndex = aleft;
    while(aIndex < Lsize && bIndex < Rsize) {
        if(L[aIndex] <= R[bIndex]) {
            ksum[tIndex] = L[aIndex];
            aIndex++;
        } else {
            ksum[tIndex] = R[bIndex];
            bIndex++;
        }
        tIndex++;
    }
    while(aIndex < Lsize) {
        ksum[tIndex] = L[aIndex];
        aIndex++;
        tIndex++;
    }
    while(bIndex < Rsize) {
        ksum[tIndex] = R[bIndex];
        bIndex++;
        tIndex++;
    }
    delete L;
    delete R;
}

void mergesort(int left, int right) {
    if(left == right) return;
    int aright = left + ((right - left) >> 1);
    mergesort(left, aright);
    mergesort(aright + 1, right);
    merge(left, aright, aright + 1, right);
}

int main() {
    int j, h;
    scanf("%*s %*d");
    cin>>n>>r>>y>>j;
    for(int i=0; i<n; i++) {
        cin>>bebek[i].d>>bebek[i].t;
    }
    for(int i=0; i<n; i++) {
        pernah[i] = true;
        compute(1, bebek[i].d, i, bebek[i].t, bebek[i].t == 'Y');
        pernah[i] = false;
    }
    mergesort(0, indx - 1);
    for(int i=0; i<j; i++) {
        cin>>h;
        if(h > ksum[indx - 1]) {
            cout<<0<<'\n';
            continue;
        }
        if(h < ksum[0]) {
            cout<<indx<<'\n';
            continue;
        }
        cout<<indx - binsearch(0, indx - 1, h) - 1<<'\n';
    }
    return 0;
}