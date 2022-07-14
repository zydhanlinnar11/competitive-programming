#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;

#define CMD_TO_RUN "./d"
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
    if(ans.size() != arr.size()) {
        printf("Wrong Answer\n");
        exit(0);
    }
    for(int i=0; i<(int)ans.size(); i++) {
        if((i + 1) / ans.at(i) != (i + 1) / arr.at(i)) {
            printf("Wrong Answer\n");
            exit(0);
        }
    }
    printf("Accepted\n");
    fclose(output);
}

void generateTC(int n) {
    vl arr(n);
    iota(arr.begin(), arr.end(), 1);
    do {
        FILE *input = fopen(INPUT_FILE, "w");
        if (!input) {
            printf("Error while reading file\n");
            exit(1);
        }
        fprintf(input, "1\n%d\n", n);
        for(int i=0; i<n; i++)
            fprintf(input, "%lld%c", (i + 1) / arr[i], " \n"[i == n - 1]);
        fclose(input);
        check(arr);
    } while(next_permutation(arr.begin(), arr.end()));
}

int main() {
    for(int i=1; i<=7; i++) {
        generateTC(i);
    }
    return 0;
}