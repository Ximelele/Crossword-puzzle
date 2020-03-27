#ifndef ZPRPR_FUNKCIE_H
#define ZPRPR_FUNKCIE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define SUBOR "cisla1.txt"
#define N 3

int otvaranie(FILE *fr){
    if((fr=fopen(SUBOR,"r"))==NULL) {
        printf("Neda sa otvorit");
        return 0;
    }
}
int zatvaranie(FILE *fr){
    if((fclose(fr))==EOF) {
        printf("Neda sa zatvorit");
        return 0;
    }
}
void nacitaj_velkost(int *riadok,int *stlpec){
    FILE *fr = NULL;
    fr= (FILE *) otvaranie(fr);
    int line=0,x=0,y=0;
    while(line!=1) {
        fscanf(fr,"%d %d", &x, &y);
        line++;
    }
    *riadok=x;
    *stlpec=y;
    zatvaranie(fr);
}
void nacitaj_pole(char **pole,int riadok, int stlpec){
    FILE *fr=NULL;
    fr= (FILE *) otvaranie(fr);
    fseek(fr,5,SEEK_SET);
    for (int i = 0; i < riadok; ++i) {
        for (int j = 0; j < stlpec+1; ++j) {
            fscanf(fr,"%c",&pole[i][j]);
        }
    }
    zatvaranie(fr);
}

void vypis_pola(char **hadanka,int riadok, int stlpec){
    for (int j = 0; j < riadok; ++j) {
        for (int i = 0; i < stlpec +1; ++i) {
            printf("%c",hadanka[j][i]);
        }
    }
}
void pocet_znak(char **hadanka,int *index[],int riadky,int stlpce,int pocet[]) {
    int allocovane[26]={6};
    for (int riadok = 0; riadok < riadky; riadok++) {
        for (int stlpec = 0; stlpec < stlpce; stlpec++) {
            for (int abeceda = 0; abeceda < 26; abeceda++) { //ak bude pocet[abeceda]==NULL the index[k][pocet[k]=-1
                if(allocovane[abeceda]==pocet[abeceda]){
                    index[abeceda]=(int*)realloc(index[abeceda],N* sizeof(int));//strasny sef
                    allocovane[abeceda]+=N* sizeof(int);
                    pocet[abeceda]+=2;
                    index[abeceda][pocet[abeceda]-1]=riadok;
                    index[abeceda][pocet[abeceda]]=stlpec;
                }
                else if (hadanka[riadok][stlpec]==index[abeceda][0]){
                    if(pocet[abeceda]==-1) {
                        pocet[abeceda]=0;
                    }
                    pocet[abeceda]+=2;
                    index[abeceda][pocet[abeceda]-1]=riadok;
                    index[abeceda][pocet[abeceda]]=stlpec;
                    break;
                }// pole na alakovanie, zapis > naalokovane
            }
        }
    }
    //pogchamp dal si to ako sef|| potreboval som pocet nastavit na -1 namiesto 0
    for (int i = 0; i < 26; i++) {
        for (int k = 0; k < pocet[i]+1; k++) {
            printf("%d ",index[i][k]);
        }
    }
}

void nacitanie_slov(char **hadanka,int *index[], int riadky,int stlpce,int pocet[]) {
    FILE *fr;
    fr = (FILE *) otvaranie(fr);
    int line = 0;
    char slovo[20]="";
    while (line != riadky + 1) {
        if (getc(fr) == '\n')
            line++;
    }
    fscanf(fr, "%s", slovo);//musis prebehnut index, a ci sa z toho da poskladat to slovo,tak nebud kokot a zajtra to prerob, a do vsetkych smerov ty autista| sprav for cyklus o hodnote 26 aby si nasiel v indexe adresi
    for (int i = 0; i < riadky; ++i) {
        for (int j = 0; j <stlpce; ++j) {
            for (int k = 0; k < 26; k++) {
                if (slovo[0] == index[k][i] && index[k][pocet[i]] != -1)
                   printf("im here");
            }
        }
    }


    //vypis_pola(hadanka,riadky,stlpce);
}


void uvolni(char **slovnik,int riadok) {
    int i;
    for (i = 0; i < riadok; i++)
        free(slovnik[i]);
}







#endif //ZPRPR_FUNKCIE_H