#include <iostream>
#include <string>

void f( )  { //voif f() noexcept{ //En general evitar usar noexcept
   int n;
   std::cin >> n;
   if (n == 0) {
      throw 999;
   } else if (n == 1) {
      throw std::string("hola");
   } else {
      throw 3.1416;
   }
}

int main( ) try {
   try {
      f( );
   } catch (int n) {
      std::cout << "capturamos " << n << "\n";
   } catch (const std::string& s) {
      std::cout << "capturamos " << s << "\n";
   } catch (...) {
      std::cout << "capturamos algo\n";
      throw;
   }
} catch (...) {
   std::cout << "volvimos a capturar algo\n";
}
