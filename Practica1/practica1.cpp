#include <iostream>
#include <cstdlib>
#include <ctime>

#define PESOBIT(bpos) 1<<bpos
#define CONSULTARBIT(var,bpos) (*(unsigned*)&var & PESOBIT(bpos))?1:0
#define PONE_1(var,bpos) *(unsigned*)&var |= PESOBIT(bpos)

using namespace std;

int main()
{
  srand(clock());
  int i,j,elementos, repeticiones, bitpos,numero;
  cout << endl << "ingrese el no. de elementos"<< endl;
  cin >> elementos;
  cout << endl << "ingrese el no. de repeticiones "<< endl;
  cin >> repeticiones;
  bool matriz[repeticiones][elementos];
  for(j=0;j < repeticiones;j++)
    for(i=0;i < elementos;i++)
    {
      matriz[j][i]=rand()%2;
    }
  cout << endl << "representacion binaria"<< endl;
  for(j=0;j < repeticiones;j++)
  {
    cout << j +1 << "| ";
    for(i=0;i < elementos;i++)
    {
      if(matriz[j][i]==true)
        cout << "1 ";
      else
        cout << "0 ";
    }
    cout << endl;
  }
  cout << endl<< "representacion decimal"<< endl;
  numero=0;
  for(j=0;j < repeticiones;j++)
  {
    cout << j +1 << "| ";
    for(bitpos=3,i=0;i < elementos;i++,bitpos--)
    {
      if(bitpos<0)
      {
        bitpos=3;
        cout << numero << " ";
        numero=0;
      }
      else if(matriz[j][i]==true)
      {
        PONE_1(numero,bitpos);
      }
    }
    cout << numero << " ";
    numero=0;
    cout << endl;
  }
}
