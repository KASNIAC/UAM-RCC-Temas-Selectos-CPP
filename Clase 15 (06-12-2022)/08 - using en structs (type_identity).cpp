#include <iostream>

template<typename T>
struct ejemplo {
   using tipo = T; //tipo dependiente, tipo depende de T
};

int main( ) {
   ejemplo<int>::tipo n = 5;
   std::cout << n << "\n";
}

/*

#include <iostream>

struct ejemplo {
   int k;

   using entero = int;
};

int main( ) {
   ejemplo::entero n = 5;
   std::cout << n << "\n";
}

*/
