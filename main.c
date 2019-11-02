#include <stdio.h>
#define MAX 1000
#define MAXD 1000

int main() {
    char povodne[MAX],sifra[MAXD];
    FILE *fr,*fw;
    int i,c,counter=0;
    c = getchar();
    while(c!='k') {
        switch (c) {
            case 'n' :
                if ((fr = fopen("1000znakov.txt", "r")) == NULL) {
                    printf("Spravu sa nepodarilo nacitat\n");

                }
                while ((c = getc(fr)) != EOF) {
                    if((c>= 'a'&& c<='z')||(c>= 'A'&& c<='Z')){
                        counter++;
                    }
                }
                printf("%d",counter);


        }
        break;
    }

    return 0;
}