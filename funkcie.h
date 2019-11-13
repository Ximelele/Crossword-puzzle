//
// Created by druzb on 5. 11. 2019.
//

#ifndef ZPRPR_FUNKCIE_H
#define ZPRPR_FUNKCIE_H

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 1000
void READ(char povodne[],FILE *fr){
    for (int i = 0; i < MAX; i++) {//for pre rozsah
        fscanf(fr, "%c", &povodne[i]);//ukladanie do pola
    }
}
void VCASE(char povodne[]){
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
void d(char povodne[]) {
    int k, counter = 1;
    scanf("%d", &k);
    if (k > 1 && k < 100) {
        for (int i = 0; i < MAX; i++) {
            if(povodne[i]!='\0'){
                counter++;
            }
            if(povodne[i+1]==' '||povodne[i+1]=='\0'){
                if(counter-1==k){
                    for (int j = i-k+1; j <i+1 ; ++j) {
                        putchar(povodne[j]);
                    }
                    putchar('\n');
                }
                counter=0;
            }

        }

     }
}




#endif //ZPRPR_FUNKCIE_H
