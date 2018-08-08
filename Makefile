sources = main.cpp circle.cpp
sourceDir = sources

includesDir = includes

libs = -lmingw32 -lsfml-graphics -lsfml-window -lsfml-system

output = Ellipzoid
outputDir = bin

compile: main.o circle.o canvas.o
	g++ -g main.o circle.o canvas.o $(libs) -o $(outputDir)/$(output)

forceAll:
	g++ $(sourceDir)/*.cpp -I$(includesDir) $(libs) -o $(outputDir)/$(output)

main.o: $(sourceDir)/main.cpp
	g++ -c -g $(sourceDir)/main.cpp -I$(includesDir) -o main.o

circle.o: $(sourceDir)/circle.cpp
	g++ -c -g $(sourceDir)/circle.cpp -I$(includesDir) -o circle.o

canvas.o: $(sourceDir)/canvas.cpp
	g++ -c -g $(sourceDir)/canvas.cpp -I$(includesDir) -o canvas.o

clean:
	rm -rf *.o && rm -rf *~

run:
	$(outputDir)/$(output)

all: compile clean run

debug:
	g++ -g $(sourceDir)/*.cpp -I$(includesDir) $(libs) -o $(outputDir)/$(output)

produce: 
	g++ $(sourceDir)/*.cpp -I$(includesDir) $(libs) -mwindows -o $(outputDir)/$(output)
