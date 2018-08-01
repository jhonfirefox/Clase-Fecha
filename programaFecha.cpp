//programaFecha.cpp
//programa de prueba de la clase fecha
#include <iostream>
using std::cout;
using std::endl;

#include "Fecha.h"   //definicion de la clase Fecha

int main()
{
   Fecha d1; //valor predeterminado: Enero 1, 1990
   Fecha d2(27, 12, 1992); //Diciembre 27, 1992
   Fecha d3(99, 0, 8045);  //fecha invalida

   cout << "d1 es " << d1 << "\nd2 es " << d2 << "\nd3 es " << d3;
   cout << "\n\nd2 += 7 es " << (d2 += 7);
 
   d3.setFecha(28, 2, 1992);
   cout << "\n\nd3 es " << d3;
   cout << "\n++d3 es " << ++d3 << " (anio bisiesto premite dia 29)";

   Fecha d4(13, 7, 2002);

   cout << "\n\nPrueba del operador preincremento:\n"
        << " d4 es " << d4 << endl;
   cout << "++d4 es " << ++d4 << endl;

   cout << "\n\nPrueba del operador de postincremento:\n"
        << " d4 es " << d4 << endl;
   cout << "d4++ es " << d4++ << endl;
   cout << "d4 es " << d4;
   cout << "\n\n" << endl;
}//fin de main
