#include <iostream>

void f( ) {
   std::cout << "f\n";
}

void g( ) {
   std::cout << "g\n";
}

template<typename R, typename... P>
using fptr = R(*)(P...);

int main( ) {
   fptr<void> p = f;
   p( );
   p = g;
   p( );
}
