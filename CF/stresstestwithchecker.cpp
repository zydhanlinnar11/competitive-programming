#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;

#define CMD_TO_RUN "./1364C"
#define INPUT_FILE "./in"
#define OUTPUT_FILE "./out"

inline void check(vl &arr) {
    int status = system(CMD_TO_RUN);
    if (status != 0) {
        printf("Runtime Error\n");
        exit(0);
    }
    FILE *output = fopen(OUTPUT_FILE, "r");
    if (!output) {
        printf("Error while reading file\n");
        exit(1);
    }
    vl ans;
    ll tmp;
    while(fscanf(output, "%lld", &tmp) != EOF) {
        ans.push_back(tmp);
    }
    if(ans.size() == 0U) {
        printf("Wrong Answer\n");
        exit(0);
    }
    if(ans.size() == 1 && ans[0] == -1) {
        printf("Skipped\n");
        return;
    }
    set<int> mex;
    for(int i=0; i<100; i++) {
        mex.insert(i);
    }
    for(int i=0; i<(int) ans.size(); i++) {
        auto fnd = mex.find(ans[i]);
        if(fnd != mex.end())
            mex.erase(fnd);
        if(arr[i] != *mex.begin() || ans[i] > 1e6 || ans[i] < 0) {
            printf("Wrong Answer\n");
            exit(0);
        }
    }
    printf("Accepted\n");
    fclose(output);
}

void generateTC(int n, vl &arr) {
    if ((int)arr.size() == n) {
        FILE *input = fopen(INPUT_FILE, "w");
        if (!input) {
            printf("Error while reading file\n");
            exit(1);
        }
        fprintf(input, "%d\n", n);
        for(int i=0; i<n; i++)
            fprintf(input, "%lld%c", arr[i], " \n"[i == n - 1]);
        fclose(input);
        check(arr);
        return;
    }
    for (int i=(arr.empty() ? 0 : arr.back()); i<11; i++) {
        arr.push_back(i);
        generateTC(n, arr);
        arr.pop_back();
    } 
}

int main() {
    int n = 5;
    vl arr;
    generateTC(n, arr);
    return 0;
}