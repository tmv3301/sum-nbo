all: sum_nbo

sum_nbo: sum_nbo.o
	g++ -o sum_nbo sum_nbo.o

sum_nbo.o : sum_nbo.cpp
	g++ -c -o sum_nbo.o sum_nbo.cpp

run: sum_nbo
	echo -n -e '\x00\x00\x03\xe8' > thousand.bin
	echo -n -e '\x00\x00\x01\xf4' > five_hundred.bin
	./sum_nbo thousand.bin five_hundred.bin

clean:
	rm -f sum_nbo sum_nbo.o *.bin

