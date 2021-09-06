#ifndef CONVERSORBASES_H
#define CONVERSORBASES_H
#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
#include <math.h>
#include <vector>

class ConversorBases
{
private:
    int base;
    std::string numero;
    double numeroDouble;
public:
    ConversorBases();
    double converteParaDecimal( char * V, int b);
    std::string converteParaBaseDesejada(double numero, int base);
};

#endif // CONVERSORBASES_H
