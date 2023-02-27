#include <stdio.h>
#include <time.h>
int main()
{
int n;
int tiempo = 0;
for(n=0;n<10;n++){
    time_t inicial, final;
    time(&inicial);
    matmul(random_matrix(600,100),random_matrix(100,600));
    time(&final);
    tiempo +=  difftime(final,inicial);
}

printf(tiempo + "0");

}

int** random_matrix(int m, int n){
    int out[m][n];
    int row,col;
    for (row=0;row<m;row++){
        for(col=0;col<n;col++){
            out[row][col] = rand();
        }
    }
    return out;
}

int** matmul(int** A, int** B){
    int rows_out = sizeof(A);
    int cols_out = sizeof(B[0]);
    
    if(sizeof(A) == sizeof(B[0])){

        int out[rows_out][cols_out];
        int i, j ,k;

        for (i=0;i<rows_out;i++){
            for (j=0;i<cols_out;j++){
                for (k=0;k<sizeof(B);k++){
                    out[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        return out;
    }else{
        printf("no se pueden multiplicar len(A)!= len(B[0])");
        return 0;
    }
}