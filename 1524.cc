#include <cstdio>

char tablet[6][9];

int CowToInt(char *s) {
    int ret = 0;
    for ( ; *s; ++s) {
        ret <<= 2;
        if (*s == 'U')
            ret += 1;
        else if (*s == 'C')
            ret += 2;
        else if (*s == 'D')
            ret += 3;
    }
    return ret;
}

void Work() {
    for (int i = 0; i < 6; ++i)
        scanf(" %s", tablet[i]);
    int num1 = CowToInt(tablet[0]);
    int num2 = CowToInt(tablet[1]);
    for (int i = 2; i < 5; ++i) {
        if (tablet[i][0] == 'A')
            num2 += num1;
        else if (tablet[i][0] == 'L')
            num2 <<= 2;
        else if (tablet[i][0] == 'R')
            num2 >>= 2;
    }
    int res = CowToInt(tablet[5]);
    puts(num2 == res ? "YES" : "NO");
}

int main() {
    int n;
    scanf("%d", &n);
    puts("COWCULATIONS OUTPUT");
    while (n--) {
        Work();
    }
    puts("END OF OUTPUT");
    return 0;
}



