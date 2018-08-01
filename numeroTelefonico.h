//numeroTelefonico.h
//definicion de la clase NumeroTelefonico

#ifndef NUMEROTELEFONICO_H
#define NUMEROTELEFONICO_H

#include <iostream>
using namespace std;

#include <string>

class NumeroTelefonico{
   friend ostream &operator<<(ostream &, const NumeroTelefonico &);
   friend istream &operator>>(istream &, NumeroTelefonico &);

private:
   string codigoArea;		//codigo de area de tres digitos
   string intercambio;		//intercambio de tres digitos
   string linea;		//linea de 4 digitos
};

#endif
