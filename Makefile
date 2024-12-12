cc := g++
projroot := .
srcpath := $(projroot)/src
binpath := $(projroot)/bin
debugpath := $(projroot)/build/debug
exec := $(debugpath)/client_dbg
objs := $(addprefix $(binpath)/, main.o geometry.o)
libs := -lGLEW -lGL -lglfw

$(exec): $(objs)
	$(cc) -o $@ $(objs) $(libs)
 
$(objs): $(debugpath)/%.o: $(srcs)/main/%.cpp
	$(cc) -c -g $< -o $@


clean:
	rm $(objs) $(exec)