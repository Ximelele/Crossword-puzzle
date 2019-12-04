#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"
//
// Created by Druzbacky on 5. 11. 2019.
//

#ifndef ZPRPR_FUNKCIE_H
#define ZPRPR_FUNKCIE_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>
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
        if(pole[i]!='\0') {
            printf("%c", pole[i]);
        }
    }
}

void kontrolapola(const char pole[]){
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
    kontrolapola(povodne);
    int velkost=0;
    for (int i=0;i< MAX;i++){
        if((povodne[i]>='A') && (povodne[i]<='Z')){
            sifra[velkost]=povodne[i];
            velkost++; //navysovanie velkosti pola
        }
        if((povodne[i]>='a') && (povodne[i]<='z')){
            sifra[velkost]=toupper(povodne[i]); //prevod na velke pismena,tiez mozeme pouzit toupper()
            velkost++;//navysovanie velkosti pola
        }
    }
    return velkost;//vratenie hodnoty K = velkost pola sifra
}

void vypis_sifri(char sifra[]){
    kontrolapola(sifra);
    vypisanie(sifra);
    putchar('\n');
}

void dlzkaslova(char povodne[]) {
    int dlzkaslova, counter = 1;
    kontrolapola(povodne);
    scanf("%d", &dlzkaslova); //ake dlhe slovo chceme hladat

    if (dlzkaslova >= 1 && dlzkaslova <= 100) {
        for (int pozicia = 0; pozicia < MAX; pozicia++) {
            if(povodne[pozicia]!='\0'){
                counter++;
            }
            if(povodne[pozicia+1]==' '||povodne[pozicia+1]=='\0'){
               if(counter-1==dlzkaslova){
                    for (int j = pozicia-dlzkaslova+1; j <pozicia+1 ; ++j) {
                        putchar(povodne[j]);
                    }
                    putchar('\n'); // vypisanie noveho riadku
                }
                counter=0;//vynulovie aby isiel od zaciatku
            }
        }
    }
}

void histogram(char sifra[]) {
    int pocetnosti[N]={ 0 },text_dlzka = 0;
    int max=0;

    kontrolapola(sifra);

    for (int i = 0; i < MAX; i++)
    {
        if (sifra[i] == '\0'){
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

            if (pocetnosti[znak] * 100 / text_dlzka <= riadok * 10) {
                putchar(' ');
            } else {
                putchar('*');
            }
        }
        putchar ('\n');
    }

    if(sifra[0]!='\0') {
        for (int i = 0; i < N; i++) {
            putchar(i + 'A');
        }
        putchar('\n');
    }
}

void ceasar(char sifra[]){
    char  povodne_pismeno;
    int sifrovanie;

    kontrolapola(sifra);

    scanf("%d", &sifrovanie);
    if((1<=sifrovanie)&&(sifrovanie<=25)){

        for(int pozicia = 0; pozicia<MAX && sifra[pozicia] != '\0'; ++pozicia){
            povodne_pismeno = sifra[pozicia];

            if(povodne_pismeno >= 'A' && povodne_pismeno <= 'Z'){
                povodne_pismeno = povodne_pismeno - sifrovanie;

                if(povodne_pismeno < 'A'){ 
                    povodne_pismeno = povodne_pismeno + 'Z' - 'A' + 1;
                }

                sifra[pozicia] = povodne_pismeno;
            }
        }

        printf("%s\n", sifra);
    }
}




#endif //ZPRPR_FUNKCIE_H