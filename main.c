#include <stdio.h>
#include <string.h>

#define MAX 1000
#define MAXD 1000

int main() {
    char povodne[MAX]="",sifra[MAXD];
    FILE *fr;
    int c;


    while(c!='k') {//pokial c==k
        switch (c = getchar()) {//nacitanie charakteru pre switch
            case 'n' :
                if ((fr = fopen("1000znakov.txt", "r")) == NULL) {//overenie ci sa subor da otvorit
                    printf("Spravu sa nepodarilo nacitat\n");

                }

                for (int i = 0; i < sizeof(povodne); i++) {//for pre rozsah
                    fscanf(fr, "%c", &povodne[i]);//ukladanie do pola
                }
                break;
            case 'v':
                if(povodne[0]=='\0') {
                        printf("Sprava nie je nacitana");
                        }
                else{
                    for (int i = 0; i < sizeof(povodne); i++) {
                        printf("%c", povodne[i]);//skusobny vypis
                    }
                }
                putchar('\n');
                break;
        }
    }

fclose(fr);
    return 0;
}