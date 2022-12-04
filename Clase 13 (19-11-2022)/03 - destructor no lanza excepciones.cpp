#include <iostream>

struct s {
   s( ) {
      std::cout << "constructor\n";
   }
   ~s( ) {
      std::cout << "destructor\n";
      throw "bye"; //ERRORR
   }
};

void g( ) {
   throw "saludos";
}

void f( ) {
   s arr[3];
   g( );
}

int main( ) try {
   f( );
} catch (...) {
   std::cout << "capturamos algo";
}
