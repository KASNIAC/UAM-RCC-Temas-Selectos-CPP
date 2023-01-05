// https://racc.mx/uam/home/2022-o/tslp/dll //HACER UNA CARPETA CON TODOS LOS ARCHIVOS

// animal.h //
#ifndef ANIMAL_H
#define ANIMAL_H

struct animal {
   virtual ~animal( ) = default;
   virtual void haz_ruidito( ) = 0;
};

#endif
