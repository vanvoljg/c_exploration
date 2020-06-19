CC = clang
CFLAGS = -O

LIBS = -lm

BINDIR = bin
ODIR = obj
SDIR = src

_BINS= mergesort quicksort nderiv
BINS = $(addprefix $(BINDIR)/,$(_BINS))

_OBJ = $(addsuffix .o,$(_BINS))
OBJ  = $(addprefix $(ODIR)/,$(_OBJ))

.PHONY: all
all: $(BINS)

$(BINDIR):
	mkdir $(BINDIR)
$(BINS): | $(BINDIR)

$(ODIR):
	mkdir $(ODIR)
$(OBJ): | $(ODIR)

$(ODIR)/%.o: $(SDIR)/%.c
	$(CC) -c -o $@ $< $(CFLAGS)

$(BINDIR)/%: $(ODIR)/%.o
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean
clean:
	rm -rf $(ODIR) $(BINDIR)
