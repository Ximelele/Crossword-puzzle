//
// Created by Druzbacky on 5. 11. 2019.
//

#ifndef ZPRPR_FUNKCIE_H
#define ZPRPR_FUNKCIE_H

#include <stdio.h>
#include <string.h>
#define MAX 1000 //defina maximalnej velkosti
#define N 'Z' - 'A' + 1 //abeceda
#define SUBOR "sifra.txt"

void nacitaniedopola(char povodne[]){
    FILE *fr;
    //overenie ci sa subor da otvorit
    if ((fr = fopen(SUBOR, "r")) == NULL){
        printf("Spravu sa nepodarilo nacitat\n");
        return;
    }
    //nacitanie prvych 1000znakov
    for (int i = 0; i < MAX; i++){
        fscanf(fr, "%c", &povodne[i]);//ukladanie do pola
    }

    if(fclose(fr) == EOF){
        printf("Chyba: zatvaranie suboru\n");
        return;
    }
}
void vypisanie(char pole[]){
    for (int i = 0; i < MAX; i++) {
        if(pole[i]!='\0')
            printf("%c", pole[i]);
    }
}
void kontrolapola(char pole[]){
    if(pole[0]=='\0') {
        printf("Sprava nie je nacitana");
        return;
    }
}
void vypispovodnehopola(char povodne[]){
    kontrolapola(povodne);
    vypisanie(povodne);
    putchar('\n');
}


int povodnetosifra(char povodne[], char sifra[])
{
    int k=0;
    kontrolapola(povodne);
    for (int i=0;i< MAX;i++){
        if(povodne[i]>='A'&&povodne[i]<='Z'){
            sifra[k]=povodne[i];
            k++;
        }
        if(povodne[i]>='a'&&povodne[i]<='z'){
            sifra[k]=povodne[i]-32; //prevod na velke pismena,tiez mozeme pouzit toupper()
            k++;
        }

    }
    return k;//vratenie hodnoty K = velkost pola sifra
}


void vypis_sifri(char sifra[]){
    kontrolapola(sifra);
    vypisanie(sifra);
    putchar('\n');
}


void dlzkaslova(char povodne[]) {
    int dlzkaslova, counter = 1;

    kontrolapola(povodne);

    scanf("%d", &dlzkaslova);
    if (dlzkaslova > 1 && dlzkaslova < 100) {
        for (int i = 0; i < MAX; i++) {
            if(povodne[i]!='\0'){
                counter++;
            }
            if(povodne[i+1]==' '||povodne[i+1]=='\0'){
                if(counter-1==dlzkaslova){
                    for (int j = i-dlzkaslova+1; j <i+1 ; ++j) {
                        putchar(povodne[j]);
                    }
                    putchar('\n');
                }
                counter=0;
            }

        }

    }
}


int histogram(char sifra[]) {
    int pocetnosti[N] = { 0 },text_dlzka = 0;
    float max;

    kontrolapola(sifra);

    for (int i = 0; i < MAX; i++)
    {
        if (sifra[i] == 0)
        {
            break;
        }

        char znak = sifra[i] - 'A';
        pocetnosti[znak]++;
        text_dlzka++;
        max = pocetnosti[znak] * 10 / text_dlzka + 1;
    }


    for (int riadok = max; riadok >= 0; riadok--)
    {
        for (int znak = 0; znak < N; znak++)
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

    if(sifra[0]!='\0') {
        for (char i = 0; i < N; i++) {
            putchar(i + 'A');
        }
        putchar('\n');
    }
}


void ceasar(char sifra[]){
    char  posun;
    int i, n;

    kontrolapola(sifra);

    scanf("%d", &n);
    if(1<n&&n<25){

        for(i = 0; sifra[i] != '\0'; ++i){
            posun = sifra[i];

            if(posun >= 'A' && posun <= 'Z'){
                posun = posun - n;

                if(posun < 'A'){
                    posun = posun + 'Z' - 'A' + 1;
                }

                sifra[i] = posun;
            }
        }

        printf("%s\n", sifra);
    }
}




#endif //ZPRPR_FUNKCIE_H
