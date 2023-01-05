#include <iostream>
#include <memory>

struct animal {
  virtual ~animal( ) = default; //Cosa fea de C++, tengo que decirle al
                           //destructor que sea virtual
                           //Habilitar el polimorfismo del destructor
   virtual void haz_ruidito( ) = 0;
};

struct perro : animal {
   std::string s = "guauguauguauguauguauguauguau";

   ~perro( ) {
      std::cout << "🐶 RIP\n";
   }

   void haz_ruidito( ) {
      std::cout << "guau\n";
   }
};

struct gato : animal {
   ~gato( ) {
      std::cout << "🐱 RIP\n";
   }

   void haz_ruidito( ) {
      std::cout << "miau\n";
   }
};

struct paloma : animal {
   ~paloma( ) {
      std::cout << "🕊️ RIP\n";
   }

   void haz_ruidito( ) {
      std::cout << "cucurrucucu (hace popó)\n";
   }
};

int main( ) {
   std::unique_ptr<animal> a = std::make_unique<perro>( );
   a->haz_ruidito( );
   a = std::make_unique<gato>( );
   a->haz_ruidito( );
   a = std::make_unique<paloma>( );
   a->haz_ruidito( );


   /*
   animal* a = new perro( );
   a->haz_ruidito( );
   delete a;
   a = new gato( );
   a->haz_ruidito( );
   delete a;
   a = new paloma( );
   a->haz_ruidito( );
   delete a;
   */
}
