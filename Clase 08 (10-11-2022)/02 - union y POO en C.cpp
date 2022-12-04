#include <iostream>

struct profesor {
   int num_eco;
   char nombre[20];
   float salario;
};

struct administrativo {
   int num_eco;
   char nombre[20];
   char puesto[20];
};

struct alumno {
   int matricula;
   char nombre[20];
   float promedio;
   char carrera[20];
};

enum tipo_persona {
   PROFESOR = 0,
   ADMINISTRATIVO = 1,
   ALUMNO = 2
};

struct persona {
   tipo_persona t;   // 4
   union {
      profesor prof;   // 28
      administrativo admin;  // 44
      alumno al;   // 48
   } mem;
};

int main( ) {
   std::cout << "Dame el tipo de persona: ";
   int tipo;
   std::cin >> tipo;

   persona p;
   //p.t = tipo; //Esto compila en C, pero no en C++
   p.t = tipo_persona(tipo);
   if (p.t == PROFESOR) {
      p.mem.prof.num_eco = 23;
   } else if (p.t == ADMINISTRATIVO) {
      p.mem.admin.num_eco = 45;
   } else if (p.t == ALUMNO) {
      p.mem.al.matricula = 2000;
   }

   std::cout << sizeof(persona); //4 + 48 (maximo valor de la union)
}
