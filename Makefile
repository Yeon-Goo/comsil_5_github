cc=g++
cflags = -W -g
target = go

objects = main.o

$(target) : $(objects)
	$(cc) $(cflags) -o $(target) $(objects)

%.o : %.c
	$(cc) $(cflags) -c -o $@ $<

$(objects) :

.PHONY : clean
clean :
	rm $(target) $(objects)
