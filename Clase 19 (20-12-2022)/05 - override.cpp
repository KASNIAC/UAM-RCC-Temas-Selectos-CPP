#include <iostream>
#include <memory>

struct animal {
   virtual ~animal( ) = default;
   virtual void haz_ruidito( ) = 0;
};

struct perro : animal {
   ~perro( ) {
      std::cout << "🐶 RIP\n";
   }

   void haz_ruidito( ) {
      std::cout << "guau\n";
   }
};

struct perro_loco : perro {
   void haz_ruidito( ) override {
      std::cout << "guauguauguauguauguau\n";
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
   a = std::make_unique<perro_loco>( );
   a->haz_ruidito( );
}
