#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {                                                 //N inst exec by line executed 
    long long execints =0LL;                                               //1
    execints++;

    int n;                                                                 //1
    execints++;

    cin >> n;                                                              //1
    execints++;

    long long max_product = 0LL;                                           //1
    execints++;

	  long long aux_product = 0LL;                                           //1
    execints++;                                                           
    

    for (int i = 0 ; i < n ; i ++){                                        //2n+1
        int number;                                                        //n
        execints++;

        cin>>number;                                                       //n
        execints++;

        long long aux = max(max_product,(long long)number);                //n
        execints++;
        long long aux1 = max(aux_product,(long long)number);               //n
        execints++;

        if ( aux > max_product){                                           //(n-1)n/2 
          execints++;

          aux_product = max_product;                                       //[0,(n-1)n/2 ]
          max_product = aux;                                               //[0,(n-1)n/2 ]
          execints+=2;
        }
        if (aux1 > aux_product && aux1 != max_product){                    //(n-1)n/2
          execints++;

          aux_product = aux1;                                              //[0,(n-1)n/2 ]
          execints++;
        }
    }
    max_product = max_product*aux_product;                                 //1
    execints++; 

    cout<< execints << endl;                     
    return 0;                                                              //7 + 6n + 2(n-1)n/2 + 3*[0,(n-1)n/2]
}        
