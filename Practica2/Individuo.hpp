#ifndef __INDIVIDUO_HPP__
#define __INDIVIDUO_HPP__

#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

//definiciones/fuciones dedicadas para la creacion de los genes
#define PESOBIT(bpos) 1<<bpos
#define CONSULTARBIT(var,bpos) (*(unsigned*)&var & PESOBIT(bpos))?1:0
#define PONE_1(var,bpos) *(unsigned*)&var |= PESOBIT(bpos)

using namespace std;

class Individuo
{
  private:
    //datos del individuo
    int actitud;
    vector<int> genes;
  public:
    //metodos del individuo
    Individuo(int noGenes,int noAlelos);
    vector <int> consultarGenes();
    int consultarActitud();
};

#endif
