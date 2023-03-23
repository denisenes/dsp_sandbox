all : main.o Jack.o Oscillator.o Utils.o Wavetable.o
	g++ -o main main.o Jack.o Oscillator.o Utils.o Wavetable.o -lstdc++ -lm `pkg-config --cflags --libs jack`

main.o : main.cpp Jack.h Adder.h Oscillator.h Utils.h NoiseGenerator.h
	g++ -g -c main.cpp

Jack.o : Jack.cpp Jack.h Utils.h
	g++ -g -c Jack.cpp

Oscillator.o : Oscillator.cpp Oscillator.h Utils.h
	g++ -g -c Oscillator.cpp

Utils.o : Utils.cpp Utils.h
	g++ -g -c Utils.cpp

Wavetable.o : Wavetable.cpp Wavetable.h Utils.h Jack.h
	g++ -g -c Wavetable.cpp

clean:
	rm *.o