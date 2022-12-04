#include <iostream>
#include <string>

struct s {
   ~s( ) {
      std::cout << "s muriendo\n";
   }
};

void h( ) {
   s var;
   throw std::string("VAMOS MEXICO");
}

void g( ) {
   s var;
   h( );
}

void f( ) {
   s var;
   g( );
}

int main( ) {
   try {
      s var;
      f( );
   } catch (int v) {
      std::cout << "capturamos un int\n";
   } catch (const std::string& v) {
      std::cout << "capturamos un string\n";
   }
}
