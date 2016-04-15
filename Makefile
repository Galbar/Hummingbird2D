OUT    := lib/libhum
CC     := g++
CFLAGS := -std=c++11 -Wall -fpic -O3
ODIR   := obj
LDIR   := lib
SDIR   := src/hummingbird
INC    := -Iinclude/hummingbird

SOURCES = $(shell find ./$(SDIR) -name '*.cpp')
OBJS = $(patsubst $(SDIR)/%,$(ODIR)/%,$(SOURCES:./%.cpp=%.o))

all: static shared

$(ODIR)/%.o: $(SDIR)/%.cpp
	$(CC) -c $(INC) -o $@ $< $(CFLAGS)

static: $(OBJS)
	ar rvs $(OUT).a $^

shared: $(OBJS)
	$(CC) -o $(OUT).so $(ODIR)/*.o $(CFLAGS) -shared $(INC)

.PHONY: clean

clean:
	rm -rf $(ODIR)/*.o $(OUT).a $(OUT).so
