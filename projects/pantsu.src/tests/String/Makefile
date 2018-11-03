CXX=clang++
CXXFLAGS= -Wall -ggdb -O2 -I../../include
LDFLAGS=
OUT=main
SRCS= ./main.cpp \
	../../source/Support/String.cpp


OBJS=$(patsubst %.cpp,%.o,$(SRCS))

all: $(OUT)

$(OUT): $(OBJS)
	$(CXX) -o $@ $(LDFLAGS) $(OBJS)

clean:
	rm $(OUT) $(OBJS)
