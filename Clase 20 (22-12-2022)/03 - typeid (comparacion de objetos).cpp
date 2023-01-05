#include <iostream>

struct animal {
   virtual ~animal( ) = default;
};

struct perro : animal { };
struct perro_loco : perro { };

int main( ) {
   perro p;
   perro_loco pl;

   animal* a = &pl;
   if (dynamic_cast<perro*>(a) != nullptr) {
      std::cout << "hereda de perro\n";
   }
   if (typeid(*a) == typeid(perro)) {
      std::cout << "es perro\n";
   } else if (typeid(*a) == typeid(perro_loco)) {
      std::cout << "es perro loco\n";
   }
}
