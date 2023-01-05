#include <iostream>
#include <memory>
#include <numbers>
#include <vector>
#include <stdlib.h>

struct figura;
struct calculo;

struct figura {
   virtual ~figura( ) = default;
   virtual double evalua(calculo*) = 0;
};

struct circulo : figura {
   double radio;

   circulo(double r)
   : radio(r) {
   }

   double evalua(calculo*) override;
};

struct cuadrado : figura {
   double lado;

   cuadrado(double s)
   : lado(s) {
   }

   double evalua(calculo*) override;
};

struct calculo {
   virtual ~calculo( ) = default;
   virtual double evalua(circulo*) = 0;
   virtual double evalua(cuadrado*) = 0;
};

struct area : calculo {
   double evalua(circulo* c) override {
      std::cout << "circulo con area\n";
      return std::numbers::pi_v<double> * c->radio * c->radio;
   }
   double evalua(cuadrado* c) override {
      std::cout << "cuadrado con area\n";
      return c->lado * c->lado;
   }
};

struct perimetro : calculo {
   double evalua(circulo* c) override {
      std::cout << "circulo con perimetro\n";
      return std::numbers::pi_v<double> * 2 * c->radio;
   }
   double evalua(cuadrado* c) override {
      std::cout << "cuadrado con perimetro\n";
      return 4 * c->lado;
   }
};

double circulo::evalua(calculo* calc) {
   return calc->evalua(this);
}

double cuadrado::evalua(calculo* calc) {
   return calc->evalua(this);
}

int main( ) {
   std::vector<figura*> figuras;
   for (int i = 0; i < 4; ++i) {
      if (rand( ) % 2 == 0) {
         figuras.push_back(new circulo(i + 1));
      } else {
         figuras.push_back(new cuadrado(i + 1));
      }
   }

   std::vector<calculo*> calculos;
   for (int i = 0; i < 4; ++i) {
      if (rand( ) % 2 == 0) {
         calculos.push_back(new area( ));
      } else {
         calculos.push_back(new perimetro( ));
      }
   }

   for (int i = 0; i < 4; ++i) {
      std::cout << figuras[i]->evalua(calculos[i]) << "\n";
   }
}
