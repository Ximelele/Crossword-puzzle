#include <stdio.h>
#include <ctype.h>
#define MAX 1000
#define SUBOR "sifra.txt"

int READ(char povodne[],FILE *fr){
    for (int i = 0; i < MAX; i++) {//for pre rozsah
        fscanf(fr, "%c", &povodne[i]);//ukladanie do pola
    }
}
int VCASE(char povodne[],char sifra[]){
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
int SIFRA(char povodne[],char sifra[]){
    for (int i = 0; i < MAX; i++)
    {
        if (i > 0)
            printf("");
        printf("%c", sifra[i]);
    }
    printf("\n");
}


int main() {
    char povodne[MAX]="",sifra[MAX]="";
    FILE *fr;
    int c;

    while(c!='k') {//pokial c==k
        switch (c = getchar()) {//nacitanie charakteru pre switch
            case 'n' :
                if ((fr = fopen(SUBOR, "r")) == NULL) {//overenie ci sa subor da otvorit
                    printf("Spravu sa nepodarilo nacitat\n");
                }
                int kappa = READ(povodne,fr);

                if(fclose(fr) == EOF) {
                    printf("Chyba: zatvaranie suboru\n");
                }
                break;
            case 'v':
                if(povodne[0]=='\0') {//overenie ci je pole povodny prazdne
                    printf("Sprava nie je nacitana");
                }
                int print = VCASE(povodne,sifra);
                break;
            case 'u':
                if(povodne[0]=='\0') {//overenie ci je pole povodny prazdne
                    printf("Sprava nie je nacitana\n");
                }
                int ucase = ABC(povodne, sifra);
                break;
            case 's':
                if(sifra[0]=='\0') {//overenie ci je pole povodny prazdne
                    printf("Nie je k dispozicii upravena sprava\n");
                }
                int som = SIFRA(povodne,sifra);
                break;
            case 'd':
                if(povodne[0]=='\0') {//overenie ci je pole povodny prazdne
                    printf("Sprava nie je nacitana\n");
                }

        }


    }


    fclose(fr);
    return 0;
}