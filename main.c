#include <stdio.h>
#include "funkcie.h"
#define MAX 1000


int main() {
    char povodne[MAX]="",sifra[MAX]="",c;

    while(c!='k') {//pokial c==k
        switch (c = getchar()) {//nacitanie charakteru pre switch
            case 'n' :
                nacitaniedopola(povodne);
                break;
            case 'v':
                vypispovodnehopola(povodne);
                break;
            case 'u':
                povodnetosifra(povodne, sifra);
                break;
            case 's':
                vypis_sifri(sifra);
                break;
            case 'd':
                dlzkaslova(povodne);
                break;
            case 'h':
                histogram(sifra);
                break;
            case 'c':
                ceasar(sifra);
                break;
        }
    }
    return 0;
}