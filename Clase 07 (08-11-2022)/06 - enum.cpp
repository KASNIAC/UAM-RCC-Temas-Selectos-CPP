#include<iostream>

enum dia{
    LUN,
    MAR,
    MIE,
    JUE,
    VIE,
    SAB,
    DOM
};

enum prueba{
    xx = 5,
    yy,
    zz
};

int main(){
    std::cout<<"enum dia:\n";
    std::cout << LUN << " "<<MAR<<" " <<MIE<<"\n";

    dia d = LUN;
    dia e = MAR;
    std::cout<<d<<"\n";

    dia b = dia(5);
    std::cout<<b<<"\n";

    std::cout<<"Tamanio de dia: "<<sizeof(dia)<<"\n";
    std::cout<<"Tamanio de un dia (variable d): "<<sizeof(d)<<"\n";

    //dia a = 2; DUDAAAAAAAAAAAAAAAAAAAA
    //dia b = 24; DUDAAAAAAAA



    //----------------------------------------------------
    std::cout<<"\n\nenum Prueba:\n";

    std::cout<<yy<<"\n";

}
