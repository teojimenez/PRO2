
all: demo_fechas

demo_ej3: Ejercicio3.cc fecha.o
	g++ -g3 -o demo_ej3 Ejercicio3.cc fecha.o

demo_fechas: main.o fecha.o
	g++ -g3 -o demo_fechas main.o fecha.o

main.o: main.cc fecha.hh
	g++ -g3 -c main.cc

fecha.o: fecha.cc fecha.hh
	g++ -g3 -c fecha.cc

clean:
	rm -f demo_fechas main.o fecha.o