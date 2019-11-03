#include <stdio.h>
#include <string.h>
#define MAX 1000
#define MAXD 1000

int main() {
    char povodne[MAX]="1000znakov.txt",sifra[MAXD];
    FILE *fr,*fw;
    int n,c;


    while(c!='k') {//pokial c==k
        switch (c = getchar()) {//nacitanie charakteru pre switch
            case 'n' :
                if ((fr = fopen("1000znakov.txt", "r")) == NULL) {//overenie ci sa subor da otvorit
                    printf("Spravu sa nepodarilo nacitat\n");

                }

                    for (int i = 0; i < sizeof(povodne) ; i++) {//for pre rozsah
                        fscanf(fr,"%c",&povodne[i]);//ukladanie do pola
                        printf("%c",povodne[i]);//skusobny vypis s ostrenim
                    }
                break;
            case 'v': printf("What now\n");
        }
    }
fclose(fr);
    return 0;
}