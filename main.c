#include <stdio.h>
#include <ctype.h>
#define MAX 1000
#define SUBOR "sifra.txt"

int ABC(char povodne[], char sifra[])
{
    int i,k=0;
    for (i=0;i< MAX;i++){
        if((povodne[i]>='A'&&povodne[i]<='Z')||(povodne[i]>='a'&&povodne[i]<='z')){
            sifra[k]=toupper(povodne[i]);
            k++;
        }

    }
    return k;
}


int main() {
    char povodne[MAX]="",sifra[MAX]="";
    FILE *fr;
    int c;


    while(c!='k') {//pokial c==k
        switch (c = getchar()) {//nacitanie charakteru pre switch
            case 'n' :
                if ((fr = fopen(SUBOR, "r")) == NULL) {//overenie ci sa subor da otvorit
                    printf("Spravu sa nepodarilo nacitat\n");

                }
                for (int i = 0; i < sizeof(povodne); i++) {//for pre rozsah
                    fscanf(fr, "%c", &povodne[i]);//ukladanie do pola
                }
                if(fclose(fr) == EOF) {
                    printf("Chyba: zatvaranie suboru\n");
                }
                break;
            case 'v':
                if(povodne[0]=='\0') {//overenie ci je pole povodny prazdne
                    printf("Sprava nie je nacitana");
                }
                else{
                    for (int i = 0; i < sizeof(povodne); i++) {
                        if(povodne[i]!='\0')
                            printf("%c", povodne[i]);//skusobny vypis
                    }
                }
                putchar('\n');
                break;
            case 'u':
                if(povodne[0]=='\0') {//overenie ci je pole povodny prazdne
                    printf("Sprava nie je nacitana\n");
                }
                int ucase = ABC(povodne, sifra);
                break;
            case 's':
                if(sifra[0]=='\0') {//overenie ci je pole povodny prazdne
                    printf("Nie je k dispozicii upravena sprava\n");
                }
                for (int i = 0; i < ucase; i++)
                {
                    if (i > 0)
                        printf("");
                    printf("%c", sifra[i]);
                }
                printf("\n");
                break;
        }


    }


    fclose(fr);
    return 0;
}