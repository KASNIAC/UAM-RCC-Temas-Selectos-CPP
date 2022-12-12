#include <iostream>

struct fraccion {
   int num, den;

   fraccion( ) {
      num = 0, den = 1;
   }
   fraccion(int n, int d) {
      num = n, den = d;
   }

   void operator+=(const fraccion& f) {
      num = num * f.den + den * f.num;
      den = den * f.den;
   }

   /*
   fraccion operator+(const fraccion& f2) const {
      fraccion temp = *this;
      temp += f2;
      return temp;
   }
   */
};

fraccion operator+(const fraccion& f1, const fraccion& f2) {
   fraccion temp = f1;
   temp += f2;
   return temp;
}

//Se puede redefinir el operador ostream :0, se devuelve std::ostream& para k sea posible hacer algo como:
   //std::cout<<x<<y<<z; en una sola línea
std::ostream& operator<<(std::ostream& os, const fraccion& f) {
   os << f.num << "/" << f.den;
   return os;
}

//Lo mismo ocurre para istream, pero se kita el const ya que sí se modificará.
std::istream& operator>>(std::istream& is, fraccion& f) {
   is >> f.num >> f.den;
   return is;
}

int main( ) {
   fraccion f1(5, 2);
   fraccion f2(7, 4);
   fraccion f3 = f1 + f2;
   f1 += fraccion(1, 2);

   std::cout << f1 << " "
             << f2 << " "
             << f3 << "\n";

   fraccion v;
   std::cin >> v;
   std::cout << v << "\n";
}
