#include <stdio.h>
<<<<<<< HEAD
#include "funkcie.h"//spravil som header s funkciami aby bol kod priehladnejsi

int main() {
    char povodne[MAX]="",sifra[MAX]="",c;//definicia premien ktore budeme vyuzivat v maine
=======
#include "funkcie.h"
#define MAX 1000
#define SUBOR "1000znakov.txt"



int main() {
    char povodne[MAX]="",sifra[MAX]="";
    FILE *fr;
    int c;
>>>>>>> parent of 518ef32... Zlepsenie vyzoru kodu

    while(c!='k') {
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
                histogram(sifra);
                break;

            case 'c':
                if(povodne[0]=='\0') {//overenie ci je pole povodny prazdne
                    printf("Nie je k dispozicii upravena sprava\n");
                }
                ceasar(sifra);
                break;


        }


    }


    fclose(fr);
    return 0;
}