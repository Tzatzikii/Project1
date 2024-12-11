projroot := .
debugpath := $(projroot)/build/debug
exec := $(debugpath)/client_dbg
bin := $(projroot)/bin
objs := $(addprefix $(bin)/, main.o)

$(exec): main.o
	g++ -o $@ $(bin)/main.o -lGLEW -lGL -lglfw

main.o: src/main/main.cpp
	g++ -c -g src/main/main.cpp -o $(bin)/main.o

$(objs): %.o: %.c
	g++ -c -g $< -o $@

clean:
	rm $(objs) $(exec)