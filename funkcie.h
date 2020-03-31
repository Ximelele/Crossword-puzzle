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
void skrt_vldl(char **hadanka,int ki,int kj,int riadky,int stlpce,int len) {
    int k=0;
    while (k!=len) {
        if(!islower(hadanka[ki][kj])){
            hadanka[ki][kj]+=32;
        }
        ki++;
        kj--;
        k++;
    }
    vypis_pola(hadanka,riadky,stlpce);
}
void skrt_hrvl(char **hadanka,int ki,int kj,int riadky,int stlpce,int len) {
    int k=0;
    while (k!=len) {
        if(!islower(hadanka[ki][kj])){
            hadanka[ki][kj]+=32;
        }
        ki--;
        kj--;
        k++;
    }
    vypis_pola(hadanka,riadky,stlpce);
}
void skrt_hrvp(char **hadanka,int ki,int kj,int riadky,int stlpce,int len) {
    int k=0;
    while (k!=len) {
        if(!islower(hadanka[ki][kj])){
            hadanka[ki][kj]+=32;
        }
        ki--;
        kj++;
        k++;
    }
    vypis_pola(hadanka,riadky,stlpce);
}
int hladanie_slova(char **hadanka,int ki,int kj,int riadky,int stlpce,char slovo[],int len){
    int vpravo=0,dole=0,hore=0,vlavo=0,ki_p=ki,kj_p=kj,len_cyklu=0,k=1;
    int jv=0,jz=0,sz=0,sv=0;
    putchar('\n');
    while(1) {
        for (int i = kj; i < len-1; i++) {
            if((i+1<stlpce&&hadanka[ki][i+1]==slovo[k]&&(vlavo==0&&hore==0&&dole==0))||(i+1<stlpce&&islower(hadanka[ki][i])==islower(slovo[k])&&(vlavo==0&&hore==0&&dole==0))){
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
        for (int i = ki; i < len-1; i++) {
            if((i+1<stlpce&&hadanka[i+1][kj]==slovo[k]&&(vlavo==0&&hore==0&&vpravo==0))||(i+1<stlpce&&islower(hadanka[i][kj])==islower(slovo[k])&&(vlavo==0&&hore==0&&vpravo==0))){
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
        while(k!=len) {
            int i=kj;
            if((i-1>=0&&hadanka[ki][i-1]==slovo[k]&&(dole==0&&vlavo==0&&vpravo==0))||(i-1>=0&&islower(hadanka[ki][i-1])==islower(slovo[k])&&(dole==0&&vlavo==0&&vpravo==0))){
                hore=1;
                k++;
                i--;
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
        while(k!=len) {
            int i=kj-1;
            if((i-1>=0&&hadanka[ki][i-1]==slovo[k]&&(dole==0&&hore==0&&vpravo==0))||(i-1>=0&&islower(hadanka[ki][i-1])==islower(slovo[k])&&(dole==0&&hore==0&&vpravo==0))){
                vlavo=1;
                k++;
                i--;
            }
            else{
                vlavo=0;
                k=1;
                break;
            }

        }
        if(vlavo==1){
            skrt_vlavo(hadanka,ki_p,kj_p,riadky,stlpce,len);
            return 1;
        }
        while(k!=len) {
            int i=ki,j=kj;
            if((i+1<stlpce&&j+1<stlpce&&hadanka[i+1][j+1]==slovo[k]&&(dole==0&&hore==0&&vpravo==0))||(i+1<stlpce&&j+1<stlpce&&islower(hadanka[i+1][j+1])==islower(slovo[k])&&(dole==0&&hore==0&&vpravo==0))){
                jv=1;
                k++;
                i++;
                j++;
            }
            else{
                jv=0;
                k=1;
                break;
            }

        }
        if(jv==1){
            skrt_vpdl(hadanka,ki_p,kj_p,riadky,stlpce,len);
            return 1;
        }
        while(k!=len) {
            int i=ki,j=kj;
            if((i+1<stlpce&&j+1<stlpce&&hadanka[i+1][j-1]==slovo[k]&&(dole==0&&hore==0&&vpravo==0))||(i+1<stlpce&&j+1<stlpce&&islower(hadanka[i+1][j-1])==islower(slovo[k])&&(dole==0&&hore==0&&vpravo==0))){
                jz=1;
                k++;
                i++;
                j--;
            }
            else{
                jz=0;
                k=1;
                break;
            }

        }
        if(jz==1){
            skrt_vldl(hadanka,ki_p,kj_p,riadky,stlpce,len);
            return 1;
        }
        while(k!=len) {
            int i=ki-1,j=kj-1;
            if((i-1 >=0&&j-1 >=0&&hadanka[i-1][j-1]==slovo[k]&&(dole==0&&hore==0&&vpravo==0))||(i-1 >=0&&j-1 >=0&&islower(hadanka[i-1][j-1])==islower(slovo[k])&&(dole==0&&hore==0&&vpravo==0))){
                sz=1;
                k++;
                i--;
                j--;
            }
            else{
                sz=0;
                k=1;
                break;
            }

        }
        if(sz==1){
            skrt_hrvl(hadanka,ki_p,kj_p,riadky,stlpce,len);
            return 1;
        }
        while(k!=len) {
            int i=ki-1,j=kj;
            if((i-1 >=0&&j+1<stlpce&&hadanka[i-1][j+1]==slovo[k]&&(dole==0&&hore==0&&vpravo==0))||(i-1 >=0&&j+1<stlpce&&islower(hadanka[i-1][j+1])==islower(slovo[k])&&(dole==0&&hore==0&&vpravo==0))){
                sv=1;
                k++;
                i--;
                j++;
            }
            else{
                sz=0;
                k=1;
                break;
            }

        }
        if(sv==1){
            skrt_hrvp(hadanka,ki_p,kj_p,riadky,stlpce,len);
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