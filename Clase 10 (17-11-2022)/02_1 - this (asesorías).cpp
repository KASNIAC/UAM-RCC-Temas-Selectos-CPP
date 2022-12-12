#include <iostream>

struct s {
   int a, b;

   void imprime1( ) {
      std::cout << a << " " << b << "\n";
   }

   void imprime2( ) {
      std::cout << "this apunta a " << this << "\n";
      std::cout << (*this).a << " " << this->b << "\n";
   }
};

int main( ) {
   s var = { 5, 7 };
   std::cout << "var vive en " << &var << "\n";
   var.imprime2( );

   s bar = { 5, 7 };
   std::cout << "bar vive en " << &bar << "\n";
   bar.imprime2( );
}

/*
struct s {
   int a, b;

   s(int a, int b) {
      this->a = a;
      this->b = b;
   }
};

*/
