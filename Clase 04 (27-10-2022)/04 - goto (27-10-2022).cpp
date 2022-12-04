#include <iostream>

int main( ) {
   goto eti1;

eti1:
   std::cout << "hola\n";
   goto eti5;
eti2:
   std::cout << "gato\n";
   goto fin;
eti3:
   std::cout << "perro\n";
   goto eti2;
eti4:
   std::cout << "taco\n";
   goto eti3;
eti5:
   std::cout << "michiberto\n";
   goto eti2;
fin:
   ;
}


*/


/*
//Esto no es estándar, pero GCC lo permite
#include <iostream>

int main( ) {
   //Arreglo que guarda las direcciones de las etiquetas
   void* arr[] = {
      &&eti1, &&eti3, &&eti2,
      &&eti4, &&eti5, &&eti4,
      &&eti1, &&eti2, &&eti2,
      && fin
   };
   int indice = 0;

inicio:
   goto *arr[indice++];

eti1:
   std::cout << "hola\n";
   goto inicio;
eti2:
   std::cout << "gato\n";
   goto inicio;
eti3:
   std::cout << "perro\n";
   goto inicio;
eti4:
   std::cout << "taco\n";
   goto inicio;
eti5:
   std::cout << "michiberto\n";
   goto inicio;
fin:
   ;
}


*/


/*
//Esto se usa para programar un intérprete (Hilado Directo) para programación de sistemas
#include <iostream>

int main( ) {
   void* arr[] = {
      &&eti1, &&eti3, &&eti2,
      &&eti4, &&eti5, &&eti4,
      &&eti1, &&eti2, &&eti2,
      &&fin
   };
   int indice = 0;

   goto *arr[indice++];

eti1:
   std::cout << "hola\n";
   goto *arr[indice++];
eti2:
   std::cout << "gato\n";
   goto *arr[indice++];
eti3:
   std::cout << "perro\n";
   goto *arr[indice++];
eti4:
   std::cout << "taco\n";
   goto *arr[indice++];
eti5:
   std::cout << "michiberto\n";
   goto *arr[indice++];
fin:
   ;
}


*/
