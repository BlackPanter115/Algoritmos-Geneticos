#ifndef __POBLACION_HPP__
#define __POBLACION_HPP__

#include <fstream>
#include "Individuo.hpp"

class Poblacion
{
  private:
    //datos de la poblacion
    vector <Individuo> poblacion;
  public:
    //metodos de la poblacion
    Poblacion(int noIndividuos,int noGenes,int noAlelos);
    vector <Individuo> consultarPoblacion();
    void generarArchivo();
};

#endif
