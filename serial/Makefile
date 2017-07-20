CC  =   g++
#CC  =   icpc
CFLAGS  = -g 
OTHERFLAGS = -c

main: Principal sistema-lineal
	$(CC) $(CFLAGS)  Principal.o sistema-lineal.o -o run

Principal: Principal.cpp
	$(CC)  $(CFLAGS) $(OTHERFLAGS) Principal.cpp

sistema-lineal: sistema-lineal.cpp
	$(CC)  $(CFLAGS) $(OTHERFLAGS) sistema-lineal.cpp
