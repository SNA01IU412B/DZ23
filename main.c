#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

void RightMatrix (int* mas, int m, int n);

int main(void){
    int *a;
    int i, j, n, m;
    int o = 0;
    int oo = 0;

    FILE* fl;

    printf("Ammount of peaks:\n");
    scanf("%d", &m);
    printf("Ammount of connections:\n");
    scanf("%d", &n);

    a = (int*)malloc(n*m * sizeof(int));

    for (i = 0; i<n; i++)
    {
        for (j = 0; j<m; j++)
        {
            printf("String %d - Peak %d\n", i+1, j+1);
            scanf("%d", (a + i*m + j));
        }
    }

    RightMatrix(a, m, n);

    fl = fopen("DZ2.dot", "w+");

    fputs("graph G {\n", fl);

    if(fl == NULL) exit(000);

    for (i = 0; i<n; i++)
    {
        for (j = 0; j<m; j++)
        {
            if (*(a + i*m + j) == 1){
                if(o == 0) o = j+1;
                else if(oo == 0) oo = j+1;
            }
        }
        if (oo == 0) {
            fprintf(fl, "%d -- %d;\n", o, o);
        }
        else fprintf(fl, "%d -- %d;\n", o, oo);
        o = 0;
        oo = 0;
    }

    fputs("}", fl);
    fclose(fl);

    system("dot -Tpng DZ2.dot -o DZ2.png");
    system("DZ2.png");

    free(a);
    return 0;
}


void RightMatrix (int* mas, int m, int n){
    int k, l;
    int sch = 0;
    for (k = 0; k<n; k++)
    {
        for (l = 0; l<m; l++)
        {
           if (*(mas + k*m + l) == 1){
               sch = sch +1;
           }
        }
        if (sch >= 3){
            printf("Wrong Matrix");
            exit(228);
        }
        sch = 0;
    }
}