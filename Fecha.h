//Fecha.h
//Definicion de la clase para establecer la fecha
#ifndef FECHA_H
#define FECHA_H

#include <iostream>

using std::istream;
using std::ostream;

class Fecha
{
   friend ostream &operator<<( ostream &, const Fecha &);
   //friend istream &operator>>(istream &, const Fecha);
public:
   Fecha(int d = 1, int m = 1, int a = 900);	//constructor predeterminado
   void setFecha(int, int, int); //establece mes, anio, dia
   Fecha &operator++();	//operador de preincremento
   Fecha operator++(int); //operador de post
   const Fecha &operator+=(int);//suma dias, modififica el objeto
   bool anioBisiesto(int) const; // esta es la fecha en un anio biciesto
   bool finDeMes(int) const;	//esta es la fecha de fin de mes
private:
   int mes;
   int dia;
   int anio;

   static const int dias[]; //arreglo de dia por mes
   //static const char *nombreMes[];//arrreglo de nombre de los meses de al nio
   void ayudaIncremento ();   //funcion de utileria para incrementsar la fecha
};
#endif
