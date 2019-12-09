CC = g++ -std=c++11
EXE = proj3_app

$(EXE): driver.o util.o Zoo.o Animal.o SeaLion.o Tiger.o BlackBear.o
	$(CC) driver.o util.o Zoo.o Animal.o SeaLion.o Tiger.o BlackBear.o -o $(EXE)

driver.o: driver.cpp
	$(CC) -c driver.cpp
util.o: util.cpp
	$(CC) -c util.cpp
Zoo.o: Zoo.cpp
	$(CC) -c Zoo.cpp
Animal.o: Animal.cpp
	$(CC) -c Animal.cpp
SeaLion.o: SeaLion.cpp
	$(CC) -c SeaLion.cpp
Tiger.o: Tiger.cpp
	$(CC) -c Tiger.cpp
BlackBear.o: BlackBear.cpp
	$(CC) -c BlackBear.cpp

clean:
	rm -f *.out *.o $(EXE)