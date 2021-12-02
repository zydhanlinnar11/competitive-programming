#include <cstdio>

int main() {
    unsigned a;
    scanf("%u", &a);
    scanf("%*s");
    printf("%u\n", ++a);
    return 0;
}