
#RNG

rng.o: rng/rng.cc rng/rng.hh
		g++ -c rng/rng.cc

main_rng.o: rng/main_rng.cc rng/rng.cc rng/rng.hh
		g++ -c rng/main_rng.cc

demo_rng: main_rng.o rng.o
		g++ -o demo_rng main_rng.o rng.o

# fechas

fecha.o: fecha/fecha.cc fecha/fecha.hh
	g++ -c fecha/fecha.cc

main_fechas.o: fecha/main_fechas.cc fecha/fecha.cc fecha/fecha.hh
		g++ -c fecha/main_fechas.cc

demo_fechas: main_fechas.o fecha.o
			g++ -o demo_fechas main_fechas.o fecha.o

#ejercici

main_ejercici1.o: Ejercici/main_ejercici1.cc fecha/fecha.cc fecha/fecha.hh rng/rng.cc rng/rng.hh
				g++ -c Ejercici/main_ejercici1.cc

ejercici1: main_ejercici1.o fecha.o rng.o
		g++ -o ejercici1 main_ejercici1.o fecha.o rng.o


#comandos

clean:
	rm -rf *.o demo* ejercici1

zip_fechas:
	zip programa.zip *.o demo_fechas

.PHONY: clean zip_fechas