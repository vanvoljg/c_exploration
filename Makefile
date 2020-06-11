# IDIR = include
CC = clang
# CFLAGS = -I$(IDIR) -O
CFLAGS = -O
MAKEFLAGS = -j$(shell nproc)

BINDIR = bin
ODIR = obj
LDIR = lib
SDIR = src

# LIBS =

# _DEPS=
# DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = mergesort.o quicksort.o test.o
OBJ  = $(patsubst %,$(ODIR)/%,$(_OBJ))

.PHONY: all
all: $(OBJ)

#$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
#	$(CC) -c -o $@ $< $(CFLAGS)
$(ODIR)/%.o: $(SDIR)/%.c
	$(CC) -c -o $@ $< $(CFLAGS)

$(OBJ): | $(ODIR)
$(ODIR):
	mkdir $(ODIR)

$(BINDIR):
	mkdir $(BINDIR)

.PHONY: mergesort ms
mergesort: ms
ms: $(ODIR)/mergesort.o | $(BINDIR)
	$(CC) -o $(BINDIR)/$@ $^ $(CFLAGS)

.PHONY: quicksort qs
quicksort: qs
qs: $(ODIR)/quicksort.o | $(BINDIR)
	$(CC) -o $(BINDIR)/$@ $^ $(CFLAGS)

#.PHONY: example
#example: $(OBJ)
#	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean
clean:
	rm -rf $(ODIR) $(BINDIR)

.PHONY: test
test: $(ODIR)/test.o | $(BINDIR)
	$(CC) -o $(BINDIR)/$@ $^ $(CFLAGS)
