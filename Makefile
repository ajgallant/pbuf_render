# $Id: Makefile 189 2016-01-29 22:12:12Z agallant $

# Makefile for OpenGL GLXPbuffer Allocation Test

# Dependencies
# MacOS v11.1
# XQuartz v2.8.0

# include and library paths
IPATH = -I/opt/X11/include
LPATH = -L/opt/X11/lib
GLLIBS =	-lGLU -lGL
COMMONLIBS =    -lX11

# compiler and settings to use
CC =		gcc
CFLAGS =	-ggdb $(IPATH)
# list of libraries to link
LIBS =		$(GLLIBS) $(COMMONLIBS)

# ---------- BEGIN SECTION TO CHANGE AS NEEDED ----------

# name of the program
PROGNAME =  pbuf_render
OBJECT = pbuf_render.o

# ---------- END SECTION TO CHANGE AS NEEDED ----------

.PHONY = clean dev neat default all

.c.o:
	$(CC) -c $(CFLAGS) $<

default: all

$(PROGNAME): $(OBJECT)
	$(CC) -o $(PROGNAME) $(OBJECT) $(LPATH) $(LIBS)

all: $(PROGNAME)

clean:
	-rm -f core *.o *~ "#"*"#"

neat: clean
	-rm -f $(PROGNAME)

dev:
	-rm -f $(PROGNAME)
	make all
