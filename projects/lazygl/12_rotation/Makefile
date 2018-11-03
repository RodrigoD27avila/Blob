OBJS=lutil.cpp ltexture.cpp main.cpp
CXX=g++
CXXFLAGS=-Wall
LDFLAGS=-lGL -lGLU -lglut -lIL -lILU -ggdb
OUT=main

all: $(OBJS)
	$(CXX) $(OBJS) $(CXXFLAGS) $(LDFLAGS) -o $(OUT)
