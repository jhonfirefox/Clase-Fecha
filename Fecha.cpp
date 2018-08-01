//Fecha.cpp
//Definiciones de las funciones miembros y funciones friend de la clase Fecha
#include <iostream>
#include "./Fecha.h"

//inicializa miembro estático en alcance de archivo, una copia a nivel de clases
const int Fecha::dias[] = {0 , 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

static const char *nombreMes[13] = {"", "Enero", "Febrero", "Marzo",
         "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre",
         "Octubre", "Noviembre", "Diciembre"};

//constructor de Fecha
Fecha::Fecha(int d, int m, int a)
{
   setFecha(d, m, a);
}//Fin del constructor de fecha

//establece dia, mes, anio
void Fecha::setFecha(int dd, int mm, int aa){
   mes = (mm >= 1 && mm <= 12)? mm : 1;
   anio = (aa >= 1900 && aa <= 2100) ? aa : 1900;

   //prueba si es anio biciesto
   if (mes == 2 && anioBisiesto(anio))
      dia = ( dd >= 1 && dd <= 29)? dd : 1;
   else
      dia = (dd >= 1 && dd <= dias[mes]) ? dd : 1;
}//Fin de la funcion setFecha

//operador de preincremento sobrecargado
Fecha& Fecha::operator++(){
   ayudaIncremento();	//incrementa la fecha
   return *this; //devuelve referencia para crear un lvalue
}//Fin de la clase de operador sobre cargado

//operador de postincremento sobrecargado; observe que el parametro
//entero de muestra no tiene un nombre de parámetro
Fecha Fecha::operator++(int)
{
   Fecha temp = *this; 	//contiene el estado actual del objeto
   ayudaIncremento(); 
   return *this;
   //devuelve el objeto temporalmente y sin incrementar
}//fin de la funcion operador ++

//suma el numero de dias especificado a la fecha
const Fecha &Fecha::operator+=(int diasAdicionales)
{
   for (int i = 0; i < diasAdicionales; i++){
	ayudaIncremento();
   }//Fin del for

   return *this;
}//Fin del operador +=

//si el anio es biciesto, devuelve true; en caso contrario, devuelve false
bool Fecha::anioBisiesto(int anioPrueba) const
{
  if (anioPrueba % 400 == 0 ||
     (anioPrueba%100 != 0 &anioPrueba%4 == 0))
     return true; //un anio bisiesto
  else
     return false;//no es un anio bisiesto
}//fin de la funcion anioBisiesto

//determina si el dia es el ultimo del mes
bool Fecha::finDeMes(int diaPrueba) const
{
  if (anioBisiesto(anio))
    return diaPrueba == 29; //ano bisiesto
  else
    return diaPrueba == dias[mes];  
}//fin de la funcion finDeMes

//funcion para ayudar a incrementar la fecha
void Fecha::ayudaIncremento()
{
   //dia no es fin de mes
   if (!finDeMes(dia))
     dia++;	//incrementa el dia
   else
    if (mes < 12) //dia es fin de mes y mes < 12
    {
       mes++;	//incrementa mes
       dia = 1;	//primer dia del nuevo mes
    }//fin del if	
    else
    {
       anio++; //incrementa el anio
       mes = 1; //primer mes del nuevo anio
       dia = 1; //primer dia del nuevo mes
    }//fin del else
}//fin de la funcion ayudaIncremento

//operador de salida sobrecargado
ostream &operator<<(ostream &salida, const Fecha &d)
{ 
  salida << nombreMes[d.mes] << ' ' << d.dia << ", " << d.anio;
  return salida;
  // static char *nombreMes[13] = {"", "Enero", "Febrero", "Marzo",
  //     "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre"
  //     "Octubre", "Noviembre", "Diciembre"};
}//fin de la funcion operator<<
