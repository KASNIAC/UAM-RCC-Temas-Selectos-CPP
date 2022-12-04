//---------------------------EJEMPLO 1-------------------------------
//01 - Sobrecarga ambigua de funcion (Ejemplo 1, NO Compila).cpp
#include <iostream>

int f(int n) {
   return n + 1;
}

double f(double x) {
   return 2 * x;
}

int main( ) {
   std::cout << f(5) << "\n";
   std::cout << f(5.0) << "\n";

   long z = 2;
   std::cout << f(z) << "\n"; // error: call of overloaded 'f(long int&)' is ambiguous
}


//--------------------------EJEMPLO 2-------------------------------
/*
//02 - Sobrecarga ambigua de funcion (Ejemplo 2).cpp
#include <iostream>

void f(int n, char c) {
   std::cout << "f(int, char)\n";
}

void f(char c, int n) {
   std::cout << "f(char, int)\n";
}

int main( ) {
   //f('@', '@'); //es ambigua y no compila
   f('@',5);
   f(5,'@');
}

*/


//---------------------------EJEMPLO 3-------------------------------
/*
//03 - Sobrecarga ambigua de funcion (Ejemplo 3, NO Compila).cpp
#include <iostream>

int f(int n) {
   return n + 1;
}

double f(double x) {
   return 2 * x;
}

int main( ) {
   std::cout << f(5) << "\n";
   std::cout << f(5.0) << "\n";

   long long z = 5;
   std::cout << f(z) << "\n"; // error: call of overloaded 'f(long int&)' is ambiguous
}
*/


//---------------------------EJEMPLO 4-------------------------------
/*
//04 - Sobrecarga ambigua de funcion (Ejemplo 4).cpp
#include <iostream>

void f(int n) {
   std::cout << "f(int)";
}

void f(long long n) {
   std::cout << "f(long long)";
}

void f(auto n) {
   std::cout << "f(auto)";
}

int main( ) {
   //Prefiere f(long long) pq el compilador no tiene que averiguar nada mas
   f(5LL);
}
*/



//---------------------------EJEMPLO 5-------------------------------
/*
//05 - Sobrecarga ambigua de funcion (Ejemplo 5).cpp
#include <iostream>

void f(int a, int b = 5) {
   std::cout << "f(int, int=)";
}

void f(int a, long b) {
   std::cout << "f(int, long)";
}

int main( ) {
   f(5);
}

*/
