SRCDIR=src
TESTSDIR=tests
TESTSOUTPUT=testsOutput
LIBDIR=lib
DOCDIR=doc
BINDIR=bin
INCLUDEDIR=include
CC = gcc
AR = ar
LATEXDIR = latex
CFLAGS=-Wall -pedantic -g -std=c99 -I$(INCLUDEDIR)
TESTSFLAGS=-lcunit
EXEC=itispell
LIBRARIES= $(LIBDIR)/libListeChainee.a $(LIBDIR)/libTAD_Dictionnaire.a $(LIBDIR)/libElementsArbreNAire.a $(LIBDIR)/libTAD_Mot.a $(LIBDIR)/libTAD_Correcteur.a
LDFLAGS= -lListeChainee -lTAD_Dictionnaire -lElementsArbreNAire -lTAD_Mot -lTAD_Correcteur

all :  $(BINDIR)/$(EXEC)
tests:  $(TESTSDIR)/$(TESTSOUTPUT)
doc : DOXY

$(TESTSDIR)/$(TESTSOUTPUT) : $(SRCDIR)/test.o $(LIBRARIES)
	$(CC) -o $@ $^ $(LDFLAGS) -L $(LIBDIR) $(TESTSFLAGS)

$(BINDIR)/$(EXEC) :  $(LIBRARIES) $(SRCDIR)/AD1.o $(SRCDIR)/aide.o $(SRCDIR)/completerDico.o $(SRCDIR)/main.o
	$(CC)  -o $@ $^ $(LDFLAGS) -L $(LIBDIR)

$(SRCDIR)/%.o : $(SRCDIR)/%.c
	$(CC) -o $@ -c $< $(CFLAGS)

$(LIBDIR)/libElementsArbreNAire.a : $(SRCDIR)/elementsArbreNaire.o
	$(AR) -r $@ $^

$(LIBDIR)/libTAD_Correcteur.a : $(SRCDIR)/TAD_Correcteur.o
	$(AR) -r $@ $^

$(LIBDIR)/libTAD_Mot.a : $(SRCDIR)/TAD_Mot.o
	$(AR) -r $@ $^

$(LIBDIR)/libListeChainee.a : $(SRCDIR)/listeChainee.o
	$(AR) -r $@ $^

$(LIBDIR)/libTAD_Dictionnaire.a : $(SRCDIR)/TAD_Dictionnaire.o
	$(AR) -r $@ $^ 

DOXY : 
	doxygen Doxyfile

clean :
	rm $(SRCDIR)/*.o
	rm $(LIBDIR)/*
	rm $(TESTSDIR)/*
	rm $(BINDIR)/*
	rm -rf $(DOCDIR)/*

