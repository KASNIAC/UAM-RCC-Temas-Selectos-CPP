#include <iostream>

//Ya lo podemos pasar tanto por valor como por referencia, std::array ocupa el mismo truco
struct arreglo {
   int mem[5];
};

void f(arreglo a) {
   a.mem[0] = 8;
}

void g(arreglo& a) {
   a.mem[0] = 777;
}

arreglo h( ) {
   arreglo b = { { 4, 4, 4, 4, 4 } };
   return b;
}

int main( ) {
   arreglo a = { { 1, 2, 3, 4, 5 } };

   f(a);
   std::cout << a.mem[0] << "\n";

   g(a);
   std::cout << a.mem[0] << "\n";

   arreglo b = h( );
   std::cout << b.mem[0] << "\n";
}


