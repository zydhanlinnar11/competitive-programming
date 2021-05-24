#include <stdio.h>

// 012594dccfd22c70924e105341fc36313b26c325c5418c23e2ac112d2ea015d5

int main() {
    int n, jml_plus=0;
    scanf("%d", &n);
    getchar();
    for(int i=0; i<n; i++) {
        int action = getchar();
        if(action == '-' && jml_plus > 0)
            jml_plus--;
        if(action == '+')
            jml_plus++;
    }
    printf("%d\n", jml_plus);
    
}