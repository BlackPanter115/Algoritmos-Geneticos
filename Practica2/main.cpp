#include "Poblacion.hpp"

int main (void)
{
  int noAlelos;
  int noGenes;
  int noIndividuos;
  //solicitamos el numero de alelos a utilizar
  cout << "\n\nNumero de Alelos a Trabajar" << endl;
  cin >> noAlelos;
  //solicitamos el numero de genes a utilizar
  cout << "Numero de Genes a Trabajar" << endl;
  cin >> noGenes;
  //solicitamos el numero de individuos a utilizar
  cout << "Numero de Individuos a Trabajar" << endl;
  cin >> noIndividuos;
  //creamos la poblacion
  Poblacion prueba=Poblacion(noIndividuos,noGenes,noAlelos);
  cout << "\nPoblacion Generada\n" << endl;
  //mostramos los individuos generados pertenecientes a la poblacion
  for(int i=0;i<(int)prueba.consultarPoblacion().size();i++)
  {
    cout << "|";
    for(int j=0;j<(int)prueba.consultarPoblacion().at(i).consultarGenes().size();j++)
    {
      cout << prueba.consultarPoblacion().at(i).consultarGenes().at(j) << "|";
    }
    cout << "\t" << prueba.consultarPoblacion().at(i).consultarActitud() << endl;
  }
  cout << endl;
  //ingresamos la informacion necesaria para graficar a un archivo
  prueba.generarArchivo();
}
