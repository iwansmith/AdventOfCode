CPPFLAGS=-O1 -std=c++17 -g -Wall -Wshadow -pthread -lcrypto -I../CommonTools

Files = $(patsubst %.cpp,%,$(wildcard *.cpp)) 

all: $(Files) 
	:
clean:
	rm $(Files)
