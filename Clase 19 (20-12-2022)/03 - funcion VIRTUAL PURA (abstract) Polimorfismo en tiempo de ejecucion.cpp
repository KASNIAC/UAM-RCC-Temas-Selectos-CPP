#include <iostream>

struct animal {
   virtual void haz_ruidito( ) = 0; //Funcion VIRTUAL PURA
};

struct perro : animal {
   void haz_ruidito( ) {
      std::cout << "guau\n";
   }
};

struct gato : animal {
   void haz_ruidito( ) {
      std::cout << "miau\n";
   }
};

struct paloma : animal {
   void haz_ruidito( ) {
      std::cout << "cucurrucucu (hace popó)\n";
   }
};

//[dll] animal* funcion_dll( );

int main( ) {
   perro p;
   gato g;
   paloma m;

   animal* a;
   a = &p;
   a->haz_ruidito( );
   a = &g;
   a->haz_ruidito( );
   a = &m;
   a->haz_ruidito( );

   /*
   std::cout << "Elige el dll que quieres cargar";
   std::string s;
   std::cin >> s;

   carga_dll(s);
   a = funcion_dll( );
   a->haz_ruidito( );
   */
}
