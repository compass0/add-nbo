add-nbo.exe : add-nbo.o
	g++ -o add-nbo.exe add-nbo.o

add-nbo.o : add-nbo.cpp
	g++ -c -o add-nbo.o add-nbo.cpp

clean:
	rm *.o add-nbo.exe