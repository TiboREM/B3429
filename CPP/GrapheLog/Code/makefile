# nom de l'executable produit
EXE = analog

# édition des liens
EDL = g++ -o
EDLFLAGS =

# compilation
COMP = g++ -c
COMPFLAGS_DEFAUT = -ansi -g -pedantic -Wall -std=c++11
COMPFLAGS_PERSO = #-DTEST_FLO #-DTEST_TIB #-DMAP
COMPFLAGS = $(COMPFLAGS_DEFAUT) $(COMPFLAGS_PERSO)

# fichiers
REALISATIONS = $(wildcard *.cpp)
OBJETS = $(REALISATIONS:.cpp=.o)

##########################################################################

all : $(EXE)

$(EXE) : $(OBJETS)
	@ echo "creation de l'éxecutable  $@"
	@ $(EDL) $(EDLFLAGS) $(EXE) $^


main.o : main.cpp
	@ echo "compilation pour $@"
	@ $(COMP) $(COMPFLAGS) $<

%.o : %.cpp %.h
	@ echo "compilation pour $@"
	@ $(COMP)  $(COMPFLAGS) $<

.PHONY: clean rendu

clean :
	@ echo "suppression de l'exécutable $(EXE)"
	@ rm -f $(EXE)
	@ echo "suppression des fichiers .o"
	@ rm -f *.o

rendu :
	@ echo "suppression des fichiers .o"
	@ rm -f *.o