#include <iostream>

struct fecha {
   int dia, mes, anyo;

   fecha( ) {
      std::cout << "naciendo :)\n";
   }

   ~fecha( ) {
      std::cout << "muriendo :(\n";
   }
};

fecha f;

int main( ) {

}

/*
int main( ) {
   fecha f;
   f.dia = 15;
   f.mes = 11;
   f.año = 2022;
   std::cout << f.mes << "\n";
}

*/
