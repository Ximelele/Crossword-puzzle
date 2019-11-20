//
// Created by druzb on 5. 11. 2019.
//

#ifndef ZPRPR_FUNKCIE_H
#define ZPRPR_FUNKCIE_H

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 1000
#define N 'Z' - 'A' + 1

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
        if(sifra[i]=='\0') {
            continue;
        }
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
void histogram(char sifra[]) {
    int pocetnosti[N] = { 0 };
    int text_dlzka = 0;
    float zz;

    for (int i = 0; i < MAX; i++)
    {
        if (sifra[i] == 0)
        {
            break;
        }
        char znak = sifra[i] - 65;
        pocetnosti[znak]++;
        text_dlzka++;
        zz = pocetnosti[znak] * 10 / text_dlzka;
    }




    for (char riadok = zz+1; riadok >= 0; riadok--)
    {
        for (char znak = 0; znak < 26; znak++)
        {


            if (pocetnosti[znak] * 100 / text_dlzka > riadok * 10)
            {
                putchar ('*');
            }
            else
            {
                putchar (' ');
            }
        }
        putchar ('\n');
    }

    for (char i = 0; i < N; i++)
    {
        putchar (i + 'A');
    }
}

void ceasar(char sifra[]){
    char  ch;
    int i, n;

    scanf("%d", &n);
    if(1<n&&n<25){

    for(i = 0; sifra[i] != '\0'; ++i){
        ch = sifra[i];

        if(ch >= 'A' && ch <= 'Z'){
            ch = ch - n;

        if(ch < 'A'){
            ch = ch + 'Z' - 'A' + 1;
        }

        sifra[i] = ch;
    }
}

printf("%s\n", sifra);
}
}




#endif //ZPRPR_FUNKCIE_H
