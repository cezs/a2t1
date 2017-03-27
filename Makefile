#
# Makefile for 5CS003, Assignment 2, Task 1
#

APP = a2t1

IDIR = include
SDIR = src
ODIR = obj

CC = gcc
CFLAGS = -I$(IDIR)

_DEPS = tools.h data.h 
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_CFIL = main.c tools.c data.c
CFIL = $(patsubst %,$(SDIR)/%,$(_CFIL))

_OBJ = $(_CFIL:.c=.o)
OBJ = $(addprefix $(ODIR)/,$(_OBJ))


all: $(APP)

$(APP): $(OBJ)
	$(CC) $^ -o bin/$@

$(ODIR)/%.o: $(SDIR)/%.c	
	$(CC) -c $< -o $@


.PHONY: clean

clean:
	rm -rf $(OBJ)

# Print variable
# Example: make print-OBJ
print-%:
	@echo $* = $($*)
