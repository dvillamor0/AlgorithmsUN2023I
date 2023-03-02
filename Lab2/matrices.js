function main() {
        
    let tiempo = 0;
    for (i=0;i<= 10;i+=1){
        let inicial = new Date().getMilliseconds();
        matmul(random_matrix(600,100),random_matrix(100,600));
        tiempo += (new Date().getMilliseconds()-inicial);
    }
    console.log((tiempo/10)+" ns "+tiempo/(10*1000000000)+"s");


}

function matmul(A, B){
    let rows_out = A.length;
    let cols_out = B[0].length;

    if(rows_out == cols_out){

        let out = [];
        for (row=0;row<rows_out;row+=1){
            let lista = [];
            for( col=0;col<cols_out;col+=1){
                lista[col] = 0;
            }
            out[row] = lista;
        }
    
        for ( i=0;i<rows_out;i+=1){
            for ( j=0; j<cols_out;j+=1){
                for ( k=0;k<B.length;k+=1){
                    out[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        return out;
    }else{
        //throw new Exception("no se pueden multiplicar len(A)!= len(B[0])");
        return null;
    }
}

function random_matrix( m, n){
let out = [];
for (row = 0;row < m; row+=1){
    let lista = [];
    for ( col = 0; col < n; col++) {
        lista.push(Math.floor(Math.random() * (100+100 + 1) - 100));
    }
    out.push(lista);
}
return out;
}
main();