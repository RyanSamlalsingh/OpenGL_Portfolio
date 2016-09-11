#Ryan Samlalsingh

NAME=hello_world_opengl

CPPC=g++
CFLAGS=
INCLUDES=
LFLAGS=
LIBS=-lglfw3 /usr/lib64/libGLEW.a  -lGL -lm -ldl -lXinerama -lXrandr -lXi -lXcursor -lX11 -lXxf86vm -lpthread
SRC=./Src/$(NAME).cpp
OUT=Bin/$(NAME)

all:
	mkdir -p Bin
	$(CPPC) $(CFLAGS) $(INCLUDES) $(SRC) $(LIBS) -o $(OUT)
	@echo Compilation complete!

clean:
	rm -r -s ./Bin