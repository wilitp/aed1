CC=gcc
CFLAGS = -std=c99 -Wall -Wextra -g
EJS := $(wildcard ej*[!output]) # ej1 ej2 ej3 ej4 ...
OUTPUT := $(patsubst ej%.c, ej%.output, $(EJS)) # ej1.output ej2.output ej3.output ...

all: clean $(OUTPUT) # clean ej1.output ej2.output ...

$(DIR)%.output: ;
	$(CC) -o $@ $(subst .output,'', $@).c

clean:
	rm -f **.output
