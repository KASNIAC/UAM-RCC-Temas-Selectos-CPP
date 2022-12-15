#include <iostream>

struct a {
   int v1;
};

struct b : a {
   int v2;
};

int main( ) {
   std::cout << sizeof(a) << " "
             << sizeof(b) << "\n";

   b y;
   y.v1 = 5;
   y.v2 = 7;

   b* p1 = &y;
   std::cout << p1->v1 << "\n";
   std::cout << p1->v2 << "\n";

   a* p2 = &y;
   std::cout << p2->v1 << "\n";
   std::cout << p2->v2 << "\n";  // error: el apuntador a "a" sólo puede ver el subobjeto de "a"
}
