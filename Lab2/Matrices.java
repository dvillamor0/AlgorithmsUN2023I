//package Lab2;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.TimeUnit;

public class Matrices {
    public static void main(String[] args) {
        
        Long tiempo = Long.valueOf(0);
        for (int i=0;i<= 10;i+=1){
            Long inicial = System.currentTimeMillis();
            matmul(random_matrix(600,100),random_matrix(100,600));
            tiempo += (System.currentTimeMillis()-inicial);
        }
        System.out.println((tiempo/10)+" ns "+tiempo/(10*1000000000)+"s");


    }

    private static List<List<Integer>> matmul(List<List<Integer>> A, List<List<Integer>> B){
        Integer rows_out = A.size();
        Integer cols_out = B.get(0).size();
    
        if(rows_out == cols_out){

            List<List<Integer>> out = new ArrayList<>();
            for (Integer row=0;row<rows_out;row+=1){
                List<Integer> lista = new ArrayList<>();
                for(Integer col=0;col<cols_out;col+=1){
                    lista.add(0);
                }
                out.add(lista);
            }
        
            for (int i=0;i<rows_out;i+=1){
                for (int j=0; j<cols_out;j+=1){
                    for (int k=0;k<B.size();k+=1){
                        Integer valor = out.get(i).get(j);
                        valor += A.get(i).get(k) * B.get(k).get(j);
                    }
                }
            }
            return out;
        }else{
            //throw new Exception("no se pueden multiplicar len(A)!= len(B[0])");
            return new ArrayList<>();
        }
    }

    private static List<List<Integer>> random_matrix(Integer m,Integer n){
    List<List<Integer>> out = new ArrayList<>();
    for (Integer row = 0;row < m; row+=1){
        List<Integer> lista = new ArrayList<>();
        for (Integer col = 0; col < n; col++) {
            lista.add((int)Math.floor(Math.random() * (100+100 + 1) - 100));
        }
        out.add(lista);
    }
    return out;
    }
}
