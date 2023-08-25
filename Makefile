all: SolMain.o SolStart.o SolCal.o SolTest.o  
	g++ SolMain.o SolStart.o SolCal.o SolTest.o -o Sol.exe

SolMain.o: SolMain.cpp
	g++ SolMain.cpp -c

SolStart.o: SolStart.cpp
	g++ SolStart.cpp -c

SolCal.o: SolCal.cpp
	g++ SolCal.cpp -c

SolTest.o: SolTest.cpp
	g++ SolTest.cpp -c
