#include <iostream>

struct base {
   int b;

   virtual ~base( ) = default;
};

struct hijo1 : virtual base {
   int h1;
};

struct hijo2 : virtual base {
   int h2;
};

struct nieto : hijo1, hijo2 {
   int n;
};

int main( ) {
   std::cout << sizeof(base) << "\n";
   std::cout << sizeof(hijo1) << "\n";
   std::cout << sizeof(hijo2) << "\n";
   std::cout << sizeof(nieto) << "\n";
}
