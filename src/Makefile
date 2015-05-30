IDIR =../include
CC=g++
CFLAGS=-I$(IDIR) -Wall -std=c++11 -O3 -g

ODIR=obj
LDIR =../lib

LIBS=-lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

_DEPS = AKEngine.h AKWindow.h AKGraphics.h  AKTexture.h  AKViewport.h AKGameObject.h AKJoystick.h AKKeyboard.h AKCamera.h AKTimer.h Player.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o AKEngine.o AKWindow.o AKGraphics.o  AKTexture.o  AKViewport.o AKGameObject.o AKJoystick.o AKKeyboard.o AKCamera.o AKTimer.o Player.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

BIN=hawkeye

.PHONY: all clean

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $^ $(CFLAGS) $(LIBS) -o $@

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c $< $(CFLAGS) -o $@

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~