#include <iostream>
#include <stdio.h>

struct archivo {
   FILE* f;

   archivo(const char* ruta, const char* modo) {
      std::cout << "inicio constructor\n";
      f = fopen(ruta, modo);
      if (f == nullptr) {
         throw false;
      }
      std::cout << "fin constructor\n";
   }
   ~archivo( ) {
      std::cout << "destructor\n";
      fclose(f);
   }

   archivo(const archivo&) = delete;
   archivo(archivo&&) = delete;
   void operator=(const archivo&) = delete;
   void operator=(archivo&&) = delete;
};

int main( ) try {
   archivo arch("gatito.txt", "r");
} catch (...) {
   std::cout << "capturamos excepcion";
}

/*
#include <iostream>
#include <stdio.h>

struct archivo {
   FILE* f;

   archivo( ) {
      f = nullptr;
   }
   archivo(const char* ruta, const char* modo) {
      f = fopen(ruta, modo);
   }
   ~archivo( ) { //QUISIERAMOS NO TENER ESE IF FEO
      if(f != nullptr){
         fclose(f);
      }
   }

   archivo(const archivo&) = delete;
   archivo(archivo&&) = delete;
   void operator=(const archivo&) = delete;
   void operator=(archivo&&) = delete;
};

int main( ) {
   archivo arch("gatito.txt", "w");

}

*/
