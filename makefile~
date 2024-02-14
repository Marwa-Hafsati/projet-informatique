CC = gcc
CFLAGS = -ansi -pedantic -lgraph
OFILES = main.o gestion_serpent.o gestion_chrono.o
EXEC =	jeu

### BUT PAR DEFAUT ###

but:	$(EXEC)

# Règles de compilation des fichiers objets

# Déclaration des dépendances
gestion_serpent.o: gestion_serpent.c gestion_serpent.h
	$(CC) $(CFLAGS) -c gestion_serpent.c -o gestion_serpent.o 

gestion_chrono.o: gestion_chrono.c gestion_chrono.h
	$(CC) $(CFLAGS) -c gestion_chrono.c -o gestion_chrono.o

main.o: main.c gestion_serpent.h gestion_chrono.h
	$(CC) $(CFLAGS) -c main.c -o main.o

$(EXEC): $(OFILES)
	$(CC) $(CFLAGS) $(OFILES) -o $(EXEC)

# Règle pour nettoyer les fichiers objets et l'exécutable
clean:
	 rm -f $(OFILES) $(EXEC)
### FIN ###
