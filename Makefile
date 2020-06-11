# IDIR = include
CC = clang
# CFLAGS = -I$(IDIR) -O
CFLAGS = -O
MAKEFLAGS = -j$(shell nproc)

BINDIR = bin
LDIR = lib
ODIR = obj
SDIR = src

.PHONY: all
all: $(BINS) | $(BINDIR)

_BINS= mergesort quicksort test
BINS = $(addprefix $(BINDIR)/,$(_BINS))
$(BINS) : | $(BINDIR)
$(BINDIR):
	mkdir $(BINDIR)

# _DEPS=
# DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

# LIBS =

_OBJ = mergesort.o quicksort.o test.o
OBJ  = $(addprefix $(ODIR)/,$(_OBJ))
#$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
#	$(CC) -c -o $@ $< $(CFLAGS)
$(OBJ): | $(ODIR)
$(ODIR):
	mkdir $(ODIR)

$(ODIR)/%.o: $(SDIR)/%.c
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: mergesort ms
mergesort: ms
ms: $(ODIR)/mergesort.o
	$(CC) -o $(BINDIR)/$@ $^ $(CFLAGS)

.PHONY: quicksort qs
quicksort: qs
qs: $(ODIR)/quicksort.o
	$(CC) -o $(BINDIR)/$@ $^ $(CFLAGS)

#.PHONY: example
#example: $(OBJ)
#	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean
clean:
	rm -rf $(ODIR) $(BINDIR)

.PHONY: test
test: $(ODIR)/test.o
	$(CC) -o $(BINDIR)/$@ $^ $(CFLAGS)
