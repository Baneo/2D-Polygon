#  LO27 PROJECT : 2D Polygon library

#  File : Makefile
#  This file is used to simplify the compilation of our program, thanks to this file you just have to type "make clean run" to run the program. 
#
#  File created by : Nicolas Gaud

#  Modified by :

#TSAGALOS Thibault
# thibault.tsagalos@utbm.fr

#DURANCE Aurélien
# aurelien.durance@utbm.fr

# My general makefile template
CXX = gcc
CFLAGS = -Wall -Werror -g -ansi -pedantic -fpic -lm
LIBSDIR = -L. -L/usr/lib -lm
INCLUDEDIR = -I. -I/usr/include

# Library-related macros
LIBTARGET2 = Polygon
LIBTARGET = libPolygon.so
LIBSOURCE = polygon
LIBSOURCECFILE = $(LIBSOURCE:=.c)
LIBSOURCEOFILE = $(LIBSOURCE:=.o)



# Application-related macros
TARGET = polygon2D.exe
EXESOURCE = polygonmain
EXESOURCECFILE = $(EXESOURCE:=.c)
EXESOURCEOFILE = $(EXESOURCE:=.o)


# Running the program
all: $(TARGET)
	@echo "\n Executing the executable " $(TARGET)
	./$(TARGET)

# Generating the executable
$(TARGET): $(EXESOURCEOFILE) $(LIBTARGET) 
	@echo "\n Generating the executable " $@
	$(CXX) $(EXESOURCEOFILE) -l$(LIBTARGET2) $(LIBSDIR) -o $(TARGET)

# Generating the libPolygon.so binary code
lib: $(ALIBSOURCEOFILE)
	@echo "\n Generating the library libPolygon.so only"
	$(CXX) $(CFLAGS) -shared $(LIBSOURCEOFILE) -o $(LIBTARGET)

# Generating the library binary code
$(LIBTARGET): $(LIBSOURCEOFILE)
	@echo "\n Generating the library " $@
	$(CXX) $(CFLAGS) -shared $(LIBSOURCEOFILE) -o $(LIBTARGET)

# Generating an object file from a C file having the same name
.c.o:
	@echo "\n Generating " $@ " from " $<
	$(CXX) $(CFLAGS) $(INCLUDEDIR) -c -o $@ $<

# Cleaning the content of the current directory
clean:
	@echo "\n Cleaning temporary files"
	rm -rf *.o *~ *.so *.exe

#Running the program
run: $(TARGET)
	@echo "\n Executing the executable " $(TARGET)
	./$(TARGET)
