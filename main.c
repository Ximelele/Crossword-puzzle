#include <stdio.h>
#include "funkcie.h"
#define MAX 1000
#define SUBOR "1000znakov.txt"



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
                READ(povodne,fr);

                if(fclose(fr) == EOF) {
                    printf("Chyba: zatvaranie suboru\n");
                }
                break;
            case 'v':
                if(povodne[0]=='\0') {//overenie ci je pole povodny prazdne
                    printf("Sprava nie je nacitana");
                }
                VCASE(povodne);
                break;
            case 'u':
                if(povodne[0]=='\0') {//overenie ci je pole povodny prazdne
                    printf("Sprava nie je nacitana\n");
                }
                ABC(povodne, sifra);
                break;
            case 's':
                if(sifra[0]=='\0') {//overenie ci je pole povodny prazdne
                    printf("Nie je k dispozicii upravena sprava\n");
                }
                SIFRA(sifra);
                break;
            case 'd':
                if(povodne[0]=='\0') {//overenie ci je pole povodny prazdne
                    printf("Sprava nie je nacitana\n");
                }
                d(povodne);
                break;
            case 'h':
                if(povodne[0]=='\0') {//overenie ci je pole povodny prazdne
                    printf("Nie je k dispozicii upravena sprava\n");
                }


        }


    }


    fclose(fr);
    return 0;
}