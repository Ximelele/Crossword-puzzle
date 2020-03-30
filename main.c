// nacitanie najviac N prvych roznych slov do N-prvkoveho pola ukazovatelov na retazce
// v N-prvkovom poli celych cisel si pamatame pocty vyskytov
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funkcie.h"
#define N 3
#define SUBOR "cisla1.txt"



int main() {
    char **hadanka=NULL;
    int stlpec=0,riadok=0,*index[26],x=65,pocet[26]={-1};
    nacitaj_velkost(&riadok,&stlpec);
    hadanka=(char**) malloc(riadok* sizeof(char*));
    for (int i = 0; i < riadok; ++i) {
        hadanka[i]=(char*) calloc(stlpec,sizeof(char*));
    }
    nacitaj_pole(hadanka,riadok,stlpec);
    for (int k = 0; k < 26; k++) {
        index[k]=(int*) malloc(N*sizeof(int*));
        index[0][k]=-1;//na kazdy index dopredu nastavim ze sa tam nenachadzaju a nasledne ich doplnam za pozicie
        index[k][0]=x++;
    }
    vypis_pola(hadanka,riadok,stlpec);
    pocet_znak(hadanka,index,riadok,stlpec,pocet);
    nacitanie_slov(hadanka,index,riadok,stlpec,pocet);

    uvolnic(hadanka,riadok);


    return 0;
}
