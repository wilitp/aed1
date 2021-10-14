CC=gcc
CFLAGS = -std=c99 -Wall -Wextra -g
DIR = ej
DIRS := $(wildcard $(DIR)*[!output]) # ej1 ej2 ej3 ej4 ...
OUTPUT := $(patsubst $(DIR)%, $(DIR)%.output, $(DIRS)) # ej1.output ej2.output ej3.output ...

all: clean $(OUTPUT) # clean ej1.output ej2.output ...

$(DIR)%.output: ;
	$(CC) -o $@ $(subst .output,"", $@)/main.c tools/tools.c

clean:
	rm -f **.output
