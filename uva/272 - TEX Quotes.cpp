#include <cstdio>

int main() {
    char a;
    bool first = true;
    while((a = getchar()) != EOF) {
        if(a == '\"' && first) printf("``"), first = false;
        else if(a == '\"' && !first) printf("\'\'"), first = true;
        else putchar(a);
    }
    return 0;
}