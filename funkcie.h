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
        printf("Subor sa neda otvorit");
        return 0;
    }
}
int zatvaranie(FILE *fr){
    if((fclose(fr))==EOF) {
        printf("Subor sa neda zatvorit");
        return 0;
    }
}
void uvolnic(char **slovnik,int riadok) {
    int i;
    for (i = 0; i < riadok; i++)
        if(slovnik[i]!=NULL)
            free(slovnik[i]);
}
void uvolnitnt(int **slovnik,int riadok) {
    int i;
    for (i = 0; i < riadok; i++)
        if(slovnik[i] != NULL)
            free(slovnik[i]);
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
void vypis_pola_koniec(char **hadanka,int riadok, int stlpec,int *index[]){
    int velp=0;
    for (int j = 0; j < riadok; ++j) {
        for (int i = 0; i < stlpec +1; ++i) {
            if(isupper(hadanka[j][i]))
                velp++;
        }
    }
    putchar('\n');
    if(velp>=1){
        for (int j = 0; j < riadok; ++j) {
            for (int i = 0; i < stlpec +1; ++i) {
                if(isupper(hadanka[j][i]))

                    printf("%c",hadanka[j][i]);
            }
        }
    }
    else printf("Tajnicka je prazdna");
    uvolnic(hadanka,riadok);
    //uvolnitnt(index,riadok);
}
void pocet_znak(char **hadanka,int *index[],int riadky,int stlpce,int pocet[]) {
    int allocovane[26];
    for (int i = 0; i < 26; ++i)
        allocovane[i]=N;
    for (int riadok = 0; riadok < riadky; riadok++) {
        for (int stlpec = 0; stlpec < stlpce; stlpec++) {
            for (int abeceda = 0; abeceda < 26; abeceda++) { //ak bude pocet[abeceda]==NULL the index[k][pocet[k]=-1
                if(allocovane[abeceda]==pocet[abeceda]){
                    index[abeceda]=(int*)realloc(index[abeceda],sizeof(int)*(pocet[abeceda]+N));//strasny sef keby to funguje
                    allocovane[abeceda]+=N;
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
}//toto je dokonale ,uz sa toho nechytaj mato !!!!
void skrt_vpravo(char **hadanka,int ki,int kj,int riadky,int stlpce,int len) {
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
void skrt_dole(char **hadanka,int ki,int kj,int riadky,int stlpce,int len) {
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
void skrt_hore(char **hadanka,int ki,int kj,int riadky,int stlpce,int len){
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
void skrt_vpdl(char **hadanka,int ki,int kj,int riadky,int stlpce,int len) {
    int k=0;
    while (k!=len) {
        if(!islower(hadanka[ki][kj])){
            hadanka[ki][kj]+=32;
        }
        ki++;
        kj++;
        k++;
    }
    vypis_pola(hadanka,riadky,stlpce);
}
int hladanie_slova(char **hadanka,int ki,int kj,int riadky,int stlpce,char slovo[],int len){
    int vpravo=0,dole=0,hore=0,vlavo=0,ki_p=ki,kj_p=kj,len_cyklu=0,k=0;
    int jv=0,jz=0,sz=0,sv=0;
    char *slv;
    slv=(char*)malloc(len* sizeof(char*));
    strcpy(slv,slovo);
    putchar('\n');
    while(1) {
        for (int i = kj; i < len; i++) {
            if((i+1<stlpce&&hadanka[ki][i]==slovo[k])||(i+1<stlpce&&islower(hadanka[ki][i])==islower(slovo[k]))){
                printf("%c\n",slv[k]);
                vpravo=1;
                k++;
            }
            else{
                vpravo=0;
                k=1;
                break;
            }
        }
        if(vpravo==1){
            skrt_vpravo(hadanka,ki_p,kj_p,riadky,stlpce,len);
            return 1;
        }
        for (int i = ki+1; i < len-1; i++) {
            if((i+1<stlpce&&hadanka[i][kj]==slv[k])||(i+1<stlpce&&islower(hadanka[i][kj])==islower(slv[k]))){
                dole=1;
                k++;
            }
            else{
                dole=0;
                k=1;
                break;
            }
        }
        if(dole==1){
            skrt_dole(hadanka,ki_p,kj_p,riadky,stlpce,len);
            return 1;
        }
        for (int i = ki-1; i < len-1; i--) {
            if((i-1>=0&&hadanka[i][kj]==slv[k])||(i-1>=0&&islower(hadanka[i][kj])==islower(slv[k]))){
                hore=1;
                k++;
            }
            else{
                hore=0;
                k=1;
                break;
            }
        }
        if(hore==1){
            skrt_hore(hadanka,ki_p,kj_p,riadky,stlpce,len);
            return 1;
        }














        if((len_cyklu++)==len){
            return 0;
        }


    }





}


void hladaj_slovo_podlaind(char **hadanka,int riadky,int stlpce,char slovo[],const int pocet[],int *index[]){
    int k=0,ki=0,kj=0,number=1;
    int slovoind =slovo[0];
    int len = strlen(slovo);
    char *p;
    p=(char*)malloc(len* sizeof(char*));
    strcpy(p,slovo);

    for (int i = 0; i < 26; i++) {
        if (slovoind == index[i][0]) {
            for (int j = 0; j < pocet[i]+1; j++) {
                if(k==0&&pocet[i]!=-1){
                    ki=index[i][number++];
                    kj=index[i][number];
                    number++;
                    k=hladanie_slova(hadanka,ki,kj,riadky,stlpce,p,len);
                }
                if(pocet[i]<number&&(k==0)){
                    printf("Slovo %s sa nenachadza v tajnicke\n",slovo);
                    break;
                }
                if(k==1)
                    break;
            }
        }
    }
}
void nacitanie_slov(char **hadanka,int *index[], int riadky,int stlpce,int pocet[]) {
    FILE *fr=NULL;
    fr = (FILE *) otvaranie(fr);
    int line = 0;
    char slovo[20]="";
    while (line != riadky + 1) {
        if (getc(fr) == '\n')
            line++;
    }
    while( (fscanf(fr, "%s", slovo))!=EOF) {//dolezite je poradie ty tupy chuj
        hladaj_slovo_podlaind(hadanka, riadky, stlpce, slovo,pocet,index);
    }
    vypis_pola_koniec(hadanka,riadky,stlpce,index);
    zatvaranie(fr);
}








#endif //ZPRPR_FUNKCIE_H