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
}
void skrt_vpravo(char **hadanka,int ki,int kj,int riadky,int stlpce,int len,char slovo[]) {
    int k=0;
    while (k!=len) {
        if(!islower(hadanka[ki][kj])) {
            hadanka[ki][kj] += 32;
        }
        kj++;
        k++;
    }
    vypis_pola(hadanka,riadky,stlpce);
}
void skrt_dole(char **hadanka,int ki,int kj,int riadky,int stlpce,int len,char slovo[]) {
    int k=0;
    while (k!=len) {
        if(!islower(hadanka[ki][kj])){
            hadanka[ki][kj]+=32;
        }
        ki++;
        k++;
    }
    vypis_pola(hadanka,riadky,stlpce);
}
void skrt_hore(char **hadanka,int ki,int kj,int riadky,int stlpce,int len,char slovo[]){
    int k=0;
    while (k!=len) {

        if(!islower(hadanka[ki][kj]))
            hadanka[ki][kj]+=32;
        ki--;
        k++;
    }
    vypis_pola(hadanka,riadky,stlpce);
}
void skrt_vlavo(char **hadanka,int ki,int kj,int riadky,int stlpce,int len) {
    int k=0;
    while (k!=len) {
        if(!islower(hadanka[ki][kj]))
            hadanka[ki][kj]+=32;
        kj--;
        k++;
    }
    vypis_pola(hadanka,riadky,stlpce);
}

int hladanie_slova(char **hadanka,int ki,int kj,int riadky,int stlpce,char slovo[],int len){
    int vpravo=1,dole=1,hore=1,vlavo=1,ki_p=ki,kj_p=kj,len_cyklu=0,k=0,kek=len;
    char *p;
    p=(char*)malloc(len* sizeof(char*));
    strcpy(p,slovo);
    strrev(p);

    while (ki != -1 && ki != riadky+1 && kj != -1 && kj != stlpce+1) {

        if((kj+1 <stlpce &&hadanka[ki][kj+1]==slovo[k+1])||hadanka[ki][kj+1]==(slovo[k+1]+=32)) {//vpravo
            k++;
            vpravo++;
            kj++;
        }
        else if((ki+1 <riadky && hadanka[ki+1][kj] == slovo[k+1])||(ki+1 <riadky && hadanka[ki+1][kj] == (slovo[k+1]+=32))) {//dole
            k++;
            dole++;
            ki++;
        }
        else if ((kj-1 >=0&&hadanka[ki][kj-1] == p[k+1])||(kj - 1 >= 0 && hadanka[ki][kj-1] == (p[k+1]+=32))) {
            k++;
            vlavo++;
            kj--;
        }
        else if ((ki-1 >= 0 && hadanka[ki - 1][kj] == p[k+1]) ||(ki-1 >= 0 && hadanka[ki-1][kj]) == (p[k+1]+=32)) {
            ki--;
            k++;
            hore++;
        }

        if(vpravo==len-1){
            putchar('\n');
            skrt_vpravo(hadanka,ki_p,kj_p,riadky,stlpce,len,slovo);
            vpravo=1;
            return 1;
            break;
        }
       if(hore==len-1){
            putchar('\n');
            skrt_hore(hadanka,ki_p,kj_p,riadky,stlpce,len,slovo);
            hore=1;
            return 1;
            break;
        }

        if(vlavo==len-1){
            putchar('\n');
            skrt_vlavo(hadanka,ki_p,kj_p,riadky,stlpce,len);
            vlavo=1;
            return 1;
            break;
        }
        if(dole==len-1){
            putchar('\n');
            skrt_dole(hadanka,ki_p,kj_p,riadky,stlpce,len,slovo);
            dole=1;
            return 1;
            break;
        }
        len_cyklu++;
        if(len_cyklu==len+1) {
            return 0;
        }
    }

}

void hladaj_slovo_podlaind(char **hadanka,int riadky,int stlpce,char slovo[],int pocet[],int *index[]){
    int k=0,ki=0,kj=0,number=1;
    int slovoind =slovo[0];
    int len = strlen(slovo);

    for (int i = 0; i < 26; i++) {
        if (slovoind == index[i][0]) {
            for (int j = 0; j < pocet[i]+1; j++) {
                if(k==0){
                    ki=index[i][number++];
                    kj=index[i][number];
                    number++;
                    k=hladanie_slova(hadanka,ki,kj,riadky,stlpce,slovo,len);
                }
                else break;
            }
        }
    }
    putchar('\n');
}
void nacitanie_slov(char **hadanka,int *index[], int riadky,int stlpce,int pocet[]) {
    FILE *fr;
    fr = (FILE *) otvaranie(fr);
    int line = 0,ki=0,kj=0,slovoind=0,kokotina;
    char slovo[20]="";
    while (line != riadky + 1) {
        if (getc(fr) == '\n')
            line++;
    }
    while( (fscanf(fr, "%s", slovo))!=EOF) {//dolezite je poradie ty tupy chuj
        hladaj_slovo_podlaind(hadanka, riadky, stlpce, slovo,pocet,index);
    }

}


void uvolni(char **slovnik,int riadok) {
    int i;
    for (i = 0; i < riadok; i++)
        free(slovnik[i]);
}







#endif //ZPRPR_FUNKCIE_H