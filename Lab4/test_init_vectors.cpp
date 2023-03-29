#include <iostream>
#include <vector>
#include <algorithm>
int main() {                                                               
    int n = 10;                      //1
    std::vector<int> numbers(n);     //n                                       
    for (int i = 0; i < n; ++i) {    //n                                      
        std::cout << numbers[i];     //1                                        
    }

    std::cout << "\n";               //1       
    return 0;                        //1                                      
}                                    //1+n+(1*n)+1+1 = 2n+3 = O()
