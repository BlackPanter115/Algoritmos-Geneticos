a.out:  Poblacion.o Individuo.o main.o
	g++  Poblacion.o Individuo.o main.o
Poblacion.o: Poblacion.cpp
		g++ -c Poblacion.cpp -Wall
Individuo.o: Individuo.cpp
	g++ -c Individuo.cpp -Wall
main.o: main.cpp
	g++ -c main.cpp -Wall
clean:
	rm Poblacion.o Individuo.o main.o a.out
run: a.out
	./a.out
