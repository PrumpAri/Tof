#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]){
    
    int n = atoi(argv[1]); // fær n af skipannalínunni
    int k = atoi(argv[2]); // fær k af skipannalínu

    if (n <= 0 || k <= 0){
        printf("Ógilt inntak. Bæði n og k verða að vera jákvæðar tölur");
        return 1;
    }

    int *a = (int *)calloc(n, sizeof(int)); // Býr til n staka heiltölufylkið a
    if (a == NULL){
        printf("Mistókst að taka frá minni.\n");
        return 1;
    }

    srand(time(0)); // Stillir slembitöluna af

    for(int i = 0; i <k * n; i++){
        int r = rand()%n; //búið til slembitölu n á bili [0,n-1]
        a[r]++; //Hækkar a[r] um einn eftir keyrslu
    }

    int telja = 0;
    for (int i=0;i<n;i++){
        if (a[i] == 0){
            telja++;
        }
    }

    float prosenta = (float)telja / n * 100;
    printf("Eftir %d ítranir eru %d hólf ennþá 0, eða %.1f%%\n", k*n,telja,prosenta);
    free(a); 
    return 0;

}