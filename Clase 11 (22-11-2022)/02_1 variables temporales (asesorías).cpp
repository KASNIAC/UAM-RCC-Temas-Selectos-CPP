#include <iostream>

struct numero {
   int valor;

   numero(int v) {
      std::cout << "en constructor\n";
      valor = v;
   }

   ~numero( ) {
      std::cout << "en destructor\n";
   }
};

numero operator+(const numero& a, const numero& b) {
   return a.valor + b.valor;
}

int main( ) {
   numero a = numero(2) + numero(3); //Tanto numero(2) como numero(3) mueren al llegar a ;
                                     // debido a que se trata de temporales (rvalues)
   std::cout << "----\n";
}
