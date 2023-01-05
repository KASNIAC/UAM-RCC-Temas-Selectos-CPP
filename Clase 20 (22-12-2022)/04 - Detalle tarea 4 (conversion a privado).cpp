#include <iostream>

struct base {
   int n1;
};

class derivado : public base {
public:
   int n2;
};

int main( ) {
   derivado d;
   d.n1;
   d.n2;
}
