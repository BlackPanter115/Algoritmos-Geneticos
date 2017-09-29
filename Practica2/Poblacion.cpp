#include "Poblacion.hpp"

Poblacion :: Poblacion(int noIndividuos, int noGenes, int noAlelos)
{
  //realizamos este proceso la N cantidad de individuos que se solicitaron
  for (int i=0;i<noIndividuos;i++)
  {
    //insertamos individuos en la poblacion
    poblacion.push_back(Individuo(noGenes,noAlelos));
  }
};

vector <Individuo> Poblacion :: consultarPoblacion()
{
  //permitimos el acceso a la poblacion
  return poblacion;
}

void Poblacion :: generarArchivo()
{
  ofstream Archivo;
  //intentamos abrir el archivo
  Archivo.open("Poblacion.txt");
  //verificamos que el acceso al archivo sea correcto
  if (Archivo.is_open())
  {
    //realizamos el recorido de la poblacion
    for(int i=0;i<(int)poblacion.size();i++)
    {
      //escribimos en el archivo
      Archivo << poblacion.at(i).consultarActitud();
      Archivo << " Poblacion_1 " << i+1 << endl;
    }
    //cerramos el archivo
    Archivo.close();
  }
  else
    cout << "Error al intentar acceder al archivo" << endl;
}
