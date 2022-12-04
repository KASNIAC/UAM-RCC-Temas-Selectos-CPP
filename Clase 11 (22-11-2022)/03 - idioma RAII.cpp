#include <iostream>
#include <utility>
#include <stdio.h>

struct archivo {
   FILE* f;

   //archivo( ) = default; //incorrecto en este caso pq el apuntador se queda apuntando a nulo
   archivo( ) {
      f = nullptr;
   }

   //Inhibimos el constructor por defecto
   archivo(const char* ruta, const char* modo) {
      f = fopen(ruta, modo);
   }

   //Deshabilitamos el contructor por copia para evitarnos problemas
   archivo(const archivo&) = delete;

   //archivo(archivo&& a) = default; //Pasa lo mismo
   archivo(archivo&& a) {
      f = a.f;
      a.f = nullptr;
   }

   ~archivo( ) {
      if (f != nullptr) {
         fclose(f);
      }
   }

   void operator=(const archivo&) = delete;

   void operator=(archivo&& a) {
      if (this != &a) {
         if (f != nullptr) {
            fclose(f);
         }
         f = a.f;
         a.f = nullptr;
      }
   }

   // operador de conversión implícita
   operator FILE*( ) {
      return f;
   }
};

int main( ) {
   archivo arch("archivo.txt", "w");
   fprintf(arch, "VAMOS MEXICO"); //YA NO ES NECESARIO CON EL OPERADOR DE CONVERSION IMPLÍCITA arch.f

   archivo erch = std::move(arch);
}
