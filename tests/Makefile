CC=gcc
CFLAGS=-W -Wall
EXEC=main
 
all: $(EXEC)
 
$(EXEC): main.o i2cManager.o MPU6050.o

	$(CC) main.o i2cManager.o MPU6050.o -o main -lsupc++
 
main.o: main.cpp i2cManager.h MPU6050.h
	$(CC) -o main.o -c main.cpp $(CFLAGS)
         
i2cManager.o: i2cManager.cpp i2cManager.h
	$(CC) -o i2cManager.o -c i2cManager.cpp $(CFLAGS)
         
MPU6050.o: MPU6050.cpp MPU6050.h 
	$(CC) -o MPU6050.o -c MPU6050.cpp $(CFLAGS)
          
clean:
	rm *.o
