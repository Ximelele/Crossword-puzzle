//
// Created by druzb on 5. 11. 2019.
//

#ifndef ZPRPR_FUNKCIE_H
#define ZPRPR_FUNKCIE_H

#include <stdio.h>
#include <ctype.h>
#define MAX 1000
void READ(char povodne[],FILE *fr){
    for (int i = 0; i < MAX; i++) {//for pre rozsah
        fscanf(fr, "%c", &povodne[i]);//ukladanie do pola
    }
}
void VCASE(char povodne[],char sifra[]){
    for (int i = 0; i < MAX; i++) {
        if(povodne[i]!='\0')
            printf("%c", povodne[i]);
    }
    putchar('\n');
}

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
void SIFRA(char sifra[]){
    for (int i = 0; i < MAX; i++)
    {
        if(sifra[i]=='\0'){
            continue;
        }
        if (i > 0)
            printf("");
        printf("%c", sifra[i]);
    }
    putchar('\n');
}

#endif //ZPRPR_FUNKCIE_H
