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
void histogram(char sifra[]){
    int i,j,k,hist[N],pocet_vsetkych=0;
    for(i=0;i<N;i++){//nastavi pocet kazdeho vyskytu pismena na 0
        hist[i]=0;
    }
    for(k=0;k<MAX;k++){//pocita pocet vyskytu kazdeho pismena od a po Z
        if(sifra[k]>='A'&&sifra[k]<='Z'){
            hist[sifra[k]-'A']++;
            pocet_vsetkych++;
        }
    }


    for( i = 10; i >= 1; --i){
        for(j=0;j <N;++j)
        {
            if( i <= hist[j])
                putchar('*');
            else
                putchar(' ');
        }
        putchar('\n');
    }
    for(i=0;i<N;i++){//vykresli abecedu dole
        putchar('A'+i);
    }
    putchar('\n');
}


void ceasar(char sifra[]){
    char  ch;
    int i, znak;

    scanf("%d", &znak);

    for(i = 0; sifra[i] != '\0'; ++i){
        ch = sifra[i];

        if(ch >= 'a' && ch <= 'z'){
            ch = ch - znak;

        if(ch < 'a'){
            ch = ch + 'z' - 'a' + 1;
        }

        sifra[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = ch - znak;

        if(ch < 'A'){
            ch = ch + 'Z' - 'A' + 1;
        }

        sifra[i] = ch;
    }
}

printf("%s\n", sifra);
}




#endif //ZPRPR_FUNKCIE_H
