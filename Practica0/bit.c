#include <stdio.h>
#define PESOBIT(bpos) 1<<bpos
#define CONSULTARBIT(var,bpos) (*(unsigned*)&var & PESOBIT(bpos))?1:0
#define PONE_1(var,bpos) *(unsigned*)&var |= PESOBIT(bpos)
#define PONE_0(var,bpos) *(unsigned*)&var &= ~(PESOBIT(bpos))
#define CAMBIA(var,bpos) *(unsigned*)&var ^= PESOBIT(bpos)

int main(void)
{
	int i,numero,n_bits; //Auxiliares
	//unsigned char numero[8]={'2','2','2','2','2','2','2','2'}; //cadena de 64 bits
	//preguntar por el caracter a invocar
	printf("ingrese el numero a comvertir: ");
	scanf("%d",&numero);
	//Determinar la longitud de los bits a operar
	printf("Numero de bits\n");
	n_bits=sizeof(numero)*4;
	printf("%2d bits",n_bits);
	printf("\n");
	//Revisar el valor de cada bit
	printf("Valor de los bits\n");
	for (i=n_bits-1; i>=0; i--)
		printf("%d",CONSULTARBIT(numero,i));
	printf("\n");
}
