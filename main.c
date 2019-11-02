#include <stdio.h>
#define MAX 1000
#define MAXD 1000

int main() {
    char povodne[MAX],sifra[MAXD];
    FILE *fr,*fw;
    int i,c,b;
    c = getchar();
while(c!='k') {
    switch (c) {
        case 'n' :
            if ((fr = fopen("1000znakov.txt", "r")) == NULL) {
                printf("Spravu sa nepodarilo nacitat\n");
                return 0;
            }
            while ((b = getc(fr)) != EOF) {
                putchar(b);
            }
    }
}

    return 0;
}