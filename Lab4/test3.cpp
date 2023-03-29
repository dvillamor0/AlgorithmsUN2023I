#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long MaxPairwiseProductL(const std::vector<int>& numbers) {
    long long max_product = 0LL;
	  long long aux_product = 0LL;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
          if(numbers[first] != numbers[second]){
            aux_product =  (long long) numbers[first] * numbers[second];
            if ( max_product < aux_product)  {
				        max_product = aux_product;
             }
          }
			       
        }
    }

    return max_product;
}

int main() {

    srand(time(NULL));
    long long execints = 0LL;
    execints++;

    for (int j = 0 ; j < 20 ; j++){

      int n = rand()%19 +2;
      execints++;

      long long max_product = 0LL;
      execints++;

      long long aux_product = 0LL;
      execints++;                                                           
      
      vector <int> numeros(n);

      for (int i = 0 ; i < n ; i ++){
          int number = rand()%10;
          execints++;
          cout << number << " ";

          numeros[i] = number;

          long long aux = max(max_product,(long long)number);
          execints++;
          long long aux1 = max(aux_product,(long long)number);
          execints++;

          if ( aux > max_product){
            execints++;

            aux_product = max_product;
            max_product = aux;
            execints+=2;
          }
          if (aux1 > aux_product && aux1 != max_product){
            execints++;

            aux_product = aux1;
            execints++;
          }
      }
      cout<< endl;
      max_product = max_product*aux_product;   
      execints++;
      int product2 = MaxPairwiseProductL(numeros);

      if (max_product == product2){
        cout<< "Ok"<< endl;
      } else{
        cout<< "Respuesta incorrecta" <<endl;
      }
    }
    cout<<"Excints: " <<execints << endl;
    return 0;
}        
