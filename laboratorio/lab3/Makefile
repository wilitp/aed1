CC=gcc
CFLAGS = -std=c99 -Wall -Wextra
DIR = ej
DIRS := $(wildcard $(DIR)*)
OUTPUT := $(patsubst $(DIR)%, $(DIR)%.output, $(DIRS))

all: $(OUTPUT)

$(DIR)%.output: ;
	$(CC) -o $@ $(subst .output,"", $@)/main.c

clean:
	rm **.output
