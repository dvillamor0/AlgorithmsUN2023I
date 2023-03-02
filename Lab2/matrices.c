#include <stdio.h>
#include <time.h>
#include <stdlib.h> 

int main()
{
int n;
int tiempo = 0;
for(n=0;n<10;n++){
    time_t inicial, final;
    time(&inicial);
    
    int ma,na,mb,nb;
    ma = 600;
    na = 100;
    
    mb = 100;
    nb = 600;
    
    int A[ma][na];
    int B[mb][nb];
    int row,col;
    for (row=0;row<ma;row++){
        for(col=0;col<na;col++){
            A[row][col] = rand();
        }
    }

    for (row=0;row<mb;row++){
        for(col=0;col<nb;col++){
            B[row][col] = rand();
        }
    }

    int rows_out = sizeof(A);
    int cols_out = sizeof(B[0]);
    int largoa = sizeof(A) / sizeof(A[0]);
    int largob = sizeof(B[0]) / sizeof(int);
    printf("largoa: %d \n",largoa);
    printf("largob: %d \n",largob);
    if(largoa == largob){

        int out[rows_out][cols_out];
        int i, j ,k;

        for (i=0;i<rows_out;i++){
            for (j=0;i<cols_out;j++){
                for (k=0;k<sizeof(B);k++){
                    out[i][j] += A[i][k] * B[k][j];
                }
            }
        }
    }else{
        printf("no se pueden multiplicar len(A)!= len(B[0])");
    }
    
    time(&final);
    tiempo +=  difftime(final,inicial);
}

printf("tiempo: %d",tiempo);

}