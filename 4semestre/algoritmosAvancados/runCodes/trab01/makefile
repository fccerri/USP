TARGET = main
SRC = $(TARGET).cpp

all:
	g++ -std=c++11 -O2 $(SRC) -o $(TARGET)

zip:
	zip zipe makefile $(SRC)

clean:
	rm -f $(TARGET) zipe.zip

run:
	./$(TARGET)

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)