#include <cstdio>
#include <cstring>
#define eq a ==
unsigned short getCode(char a) {
    if(eq 'B' || eq 'P' || eq 'F' || eq 'V') return 1;
    else if(eq 'C' || eq 'S' || eq 'K' || eq 'G' || eq 'J' || eq 'Q' || eq 'X' || eq 'Z') return 2;
    else if(eq 'D' || eq 'T') return 3;
    else if(eq 'L') return 4;
    else if(eq 'M' || eq 'N') return 5;
    else if(eq 'R') return 6;
    else return 7;
}

int main() {
    printf("%13s%33s\n", "NAME", "SOUNDEX CODE");
    char name[21];
    while (scanf("%s", name) != EOF) {
        unsigned long long len = strlen(name);
        short encoded = 0;
        printf("         %s", name);
        for(int i=1; i <= (25 - len); i++)
            printf(" ");
        printf("%c", name[0]);
        for(int i=1; i < len; i++) {
            if(getCode(name[i]) == 7 || getCode(name[i-1]) == getCode(name[i]))
                continue;
            printf("%hu", getCode(name[i])), encoded++;
            if(encoded == 3) break;
        }
        if(encoded < 3) {
            for(int i=0; i<(3 - encoded); i++)
                printf("0");
        }
        printf("\n");
    }
    printf("%32s\n", "END OF OUTPUT");
    return 0;
}