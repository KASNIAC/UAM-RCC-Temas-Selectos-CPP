#include <iostream>

void f( ) {
   std::cout << "f( )\n";
}

void f(int n) {
   std::cout << "f(" << n << ")\n";
}

void g(int n) {
   std::cout << "g(" << n << ")\n";
}

template<typename R, typename... P>
using fptr = R(*)(P...);

int main( ) {
   // void(*p)(int) = f;
   // fptr<void, int> p = f;
   fptr<void, int> p = f;
   //auto p = f; //auto fracasa si esta sobrecargada la función o si la función es una plantilla
   p(5);
   p = g;
   p(7);
}
