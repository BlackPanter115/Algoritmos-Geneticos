#include "Individuo.hpp"

Individuo :: Individuo(int noGenes, int noAlelos)
{
  //generamos una nueva semilla para evitar la generacion de individuos
  //diferentes a la ejecucion anterior
  srand(clock());
  int gen=0;
  actitud=0;
  //repetimos tantos genes se solicitaron
  for(int j=0;j<noGenes;j++)
  {
    //solicitamos tantos alelos se solicitaron
    for(int alelo=noAlelos-1,i=0;i < noAlelos;i++,alelo--)
    {
      //verificamos si llegamos al ultimo alelo
      if(alelo == 0)
      {
        //estamos en el ultimo alelo
        //insertamos el ultimo alelo
        if(rand()%2 == true)
        {
          PONE_1(gen,alelo);
        }
        //ingresamos el gen final al individuo
        genes.push_back(gen);
        //sumamos el gen creado a la actitud del individuo
        actitud+=gen;
        //reiniciamos la cuenta de los alelos
        alelo=noAlelos-1;
        //reiniciamos el gen para poder crear uno nuevo
        gen=0;
      }
      //no hemos llegado al ultimo alelo, en ese caso intentamos insertar un uno al gen
      else if(rand()%2 == true)
      {
        PONE_1(gen,alelo);
      }
    }
  }
};

vector <int> Individuo :: consultarGenes()
{
  //permitimos el acceso a los genes del individuo
  return genes;
}

int Individuo :: consultarActitud()
{
  //permitimos el acceso a la actitud del individuo
  return actitud;
}
