# compiler
CC=g++
# compiler flags
CFLAGS=-std=c++11 -Wall -g -o
# libraries used in this project
LIBS=-Iinclude $(shell pkg-config --libs --cflags sdl SDL_image SDL_ttf jsoncpp)
OBJECTS=main.o event.o event_listener.o graphic_logger.o graphic_renderer.o picture_element.o message_element.o \
  assetsheet.o version_one_converter.o 

BUILDOBJECTS=$(addprefix build/,$(OBJECTS))

all: flt3

flt3: $(BUILDOBJECTS)
	$(CC) $(CFLAGS) $@ $^ $(LIBS)

build/%.o: src/%.cpp 
	$(CC) $(CFLAGS) $@ -c $^ $(LIBS)

.PHONY: clean

clean:
	rm -rf build/*.o flt3

