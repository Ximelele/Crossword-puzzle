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
    /*
    for (int i = 0; i < 26; i++) {
        for (int k = 0; k < pocet[i]+1; k++) {
            printf("%d ",index[i][k]);
        }
    }
     */
}
void skrt_vpravo(char **hadanka,int ki,int kj,int riadky,int stlpce,int len,char slovo[]) {
    int k=0;
    while (ki != -1 && ki != riadky+1 && kj != -1 && kj != stlpce+1) {

        if ((kj + 1 < stlpce && hadanka[ki][kj + 1] == slovo[kj + 1]) ||hadanka[ki][kj]==slovo[kj]||(kj + 1 < stlpce && islower(hadanka[ki][kj + 1]) == slovo[kj + 1] + 32) ||islower(hadanka[ki][kj]) == slovo[kj] + 32) {//vpravo
            if(!islower(hadanka[ki][kj]))
                hadanka[ki][kj] += 32;
            kj++;
            k++;

        }
        if (k == len) {
            break;
        }
    }
    vypis_pola(hadanka,riadky,stlpce);
}
void skrt_dole(char **hadanka,int ki,int kj,int riadky,int stlpce,int len,char slovo[]) {
    int k=0;
    while (ki != -1 && ki != riadky+1 && kj != -1 && kj != stlpce+1) {

        if ((ki + 1 < riadky && hadanka[ki + 1][kj] == slovo[ki + 1]) ||hadanka[ki][kj] == slovo[ki] ||(ki + 1 <riadky && islower(hadanka[ki + 1][kj]) == slovo[ki + 1] + 32)||islower(hadanka[ki][kj]) == slovo[ki] + 32) {//dole
            if(!islower(hadanka[ki][kj]))
                hadanka[ki][kj]+=32;
            ki++;
            k++;
        }
        if (k == len) {
            break;
        }
    }
    vypis_pola(hadanka,riadky,stlpce);
}
void skrtanie_slovo(char **hadanka,int ki,int kj,int riadky,int stlpce,int len,char slovo[]) {
    int k=0;
    char pole[10];
    int ki_p=ki,kj_p=kj;
    while (ki != -1 && ki != riadky+1 && kj != -1 && kj != stlpce+1) {

        if ((kj + 1 < stlpce && hadanka[ki][kj + 1] == slovo[kj + 1])||hadanka[ki][kj] == slovo[kj] ||(kj + 1 < stlpce && islower(hadanka[ki][kj + 1]) == slovo[kj + 1] + 32)||islower(hadanka[ki][kj]) == slovo[kj] + 32) {//vpravo
            hadanka[ki][kj]+=32;
            k++;
            kj++;
        }
        if ((ki + 1 < riadky && hadanka[ki + 1][kj] == slovo[ki + 1]) ||hadanka[ki][kj] == slovo[ki] ||(ki + 1 <riadky && islower(hadanka[ki + 1][kj]) == slovo[ki + 1] + 32)||islower(hadanka[ki][kj]) == slovo[ki] + 32) {//dole
            if(!islower(hadanka[ki][kj]))
                hadanka[ki][kj]+=32;
            ki++;
            k++;
        }
        if(k==len){
            break;
        }
        //  if((ki-1 >=0 && hadanka[ki-1][kj] == slovo[ki-1])||(ki-1 >=0 && islower(hadanka[ki-1][kj]) == slovo[ki-1]+32)) {
        //     ki--;
        //  }
        //if((kj-1 >=0 && hadanka[ki][kj-1] ==slovo[kj-1])||(kj-1 >=0 && islower(hadanka[ki][kj-1]) == slovo[kj-1]+32)) {
        //      kj--;
        //  }
    }

}
void hladaj_slovo(char **hadanka,int ki,int kj,int riadky,int stlpce,int len,char slovo[]){
    int k=0,vpravo=0,dole=0;
    int ki_p=ki,kj_p=kj;
    while (ki != -1 && ki != riadky+1 && kj != -1 && kj != stlpce+1) {
            if((kj+1 <stlpce && hadanka[ki][kj+1] == slovo[kj+1])||hadanka[ki][kj] == slovo[kj]||(kj+1 <stlpce && islower(hadanka[ki][kj+1]) == slovo[kj+1]+32)) {//vpravo
                kj++;
                vpravo++;

            }
            else if((ki+1 <riadky && hadanka[ki+1][kj] == slovo[ki+1])||hadanka[ki][kj]==slovo[ki]||(ki+1 <riadky && islower(hadanka[ki+1][kj]) == islower(slovo[ki+1]))) {//dole
                ki++;
                dole++;

            }
            if(vpravo==len){
                putchar('\n');
                skrt_vpravo(hadanka,ki_p,kj_p,riadky,stlpce,len,slovo);
                vpravo=0;
                break;
            }
            if(dole==len){
                putchar('\n');
                skrt_dole(hadanka,ki_p,kj_p,riadky,stlpce,len,slovo);
                dole=0;
                break;
            }
    }
    putchar('\n');
}
void nacitanie_slov(char **hadanka,int *index[], int riadky,int stlpce,int pocet[]) {
    FILE *fr;
    fr = (FILE *) otvaranie(fr);
    int line = 0,ki=0,kj=0,slovoind=0;
    char slovo[20]="";
    while (line != riadky + 1) {
        if (getc(fr) == '\n')
            line++;
    }
    while( (fscanf(fr, "%s", slovo))!=EOF) {//dolezite je poradie ty tupy chujS
        slovoind = slovo[0];
        for (int i = 0; i < 26; i++) {
            if (slovoind == index[i][0]) {
                for (int k = 0; k < pocet[i] + 1; k++) {
                    ki = index[i][1];//podla poctu vyskytov,ak sa nenajde pri prvom zisti ci je nejaky iny ..atd.
                    kj = index[i][2];
                    printf("%d %d ", ki, kj);
                    int len = strlen(slovo);
                    hladaj_slovo(hadanka, ki, kj, riadky, stlpce, len, slovo);
                    break;
                }
            }
        }
    }
    //
}


void uvolni(char **slovnik,int riadok) {
    int i;
    for (i = 0; i < riadok; i++)
        free(slovnik[i]);
}







#endif //ZPRPR_FUNKCIE_H