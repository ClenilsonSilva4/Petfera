CC = g++
CCP = -ansi -pedantic -Wall -std=c++11 -fPIC -O0 -g -I$(INC)

BIN = ./bin
BUI = ./build
INC = ./include
SRC = ./src
LIB = ./lib

PROG = $(BIN)/projetoFinal

OBJ = $(BUI)/animalSilvestre.o $(BUI)/animalExotico.o $(BUI)/animalNativo.o $(BUI)/animal.o $(BUI)/anfibio.o \
	  $(BUI)/anfibioExotico.o $(BUI)/anfibioNativo.o $(BUI)/ave.o $(BUI)/aveExotica.o $(BUI)/aveNativa.o $(BUI)/mamifero.o \
	  $(BUI)/mamiferoExotico.o $(BUI)/mamiferoNativo.o $(BUI)/reptil.o $(BUI)/reptilExotico.o $(BUI)/reptilNativo.o \
	  $(BUI)/funcionario.o $(BUI)/veterinario.o $(BUI)/tratador.o $(BUI)/gerenciamento.o $(BUI)/main.o

all: mkdir $(PROG)

#Comando para criar as pastas essenciais.

exportar:
	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/kaio/Downloads/Projeto_Final/lib

mkdir:
	mkdir -p $(BIN)
	mkdir -p $(BUI)
	mkdir -p ./data
	mkdir -p $(LIB)

#Criação da Aplicação.
$(PROG): $(LIB)/libpetfera.so
	$(CC) -ansi -pedantic -Wall -std=c++11 -O0 -g -I$(INC) -o $(PROG) -L$(LIB) -lpetfera

#Criação dos objetos.
$(BUI)/animalSilvestre.o: $(SRC)/animalSilvestre.cpp $(INC)/animalSilvestre.h
	$(CC) $(CCP) -c $(SRC)/animalSilvestre.cpp -o $(BUI)/animalSilvestre.o

$(BUI)/animalExotico.o: $(SRC)/animalExotico.cpp $(INC)/animalExotico.h $(INC)/animalSilvestre.h
	$(CC) $(CCP) -c $(SRC)/animalExotico.cpp -o $(BUI)/animalExotico.o

$(BUI)/animalNativo.o: $(SRC)/animalNativo.cpp $(INC)/animalNativo.h $(INC)/animalSilvestre.h
	$(CC) $(CCP) -c $(SRC)/animalNativo.cpp -o $(BUI)/animalNativo.o

$(BUI)/animal.o: $(SRC)/animal.cpp $(INC)/animal.h
	$(CC) $(CCP) -c $(SRC)/animal.cpp -o $(BUI)/animal.o

$(BUI)/anfibio.o: $(SRC)/anfibio.cpp $(INC)/anfibio.h
	$(CC) $(CCP) -c $(SRC)/anfibio.cpp -o $(BUI)/anfibio.o

$(BUI)/anfibioExotico.o: $(SRC)/anfibioExotico.cpp $(INC)/anfibioExotico.h
	$(CC) $(CCP) -c $(SRC)/anfibioExotico.cpp -o $(BUI)/anfibioExotico.o

$(BUI)/anfibioNativo.o: $(SRC)/anfibioNativo.cpp $(INC)/anfibioNativo.h
	$(CC) $(CCP) -c $(SRC)/anfibioNativo.cpp -o $(BUI)/anfibioNativo.o

$(BUI)/ave.o: $(SRC)/ave.cpp $(INC)/ave.h
	$(CC) $(CCP) -c $(SRC)/ave.cpp -o $(BUI)/ave.o

$(BUI)/aveExotica.o: $(SRC)/aveExotica.cpp $(INC)/aveExotica.h
	$(CC) $(CCP) -c $(SRC)/aveExotica.cpp -o $(BUI)/aveExotica.o

$(BUI)/aveNativa.o: $(SRC)/aveNativa.cpp $(INC)/aveNativa.h
	$(CC) $(CCP) -c $(SRC)/aveNativa.cpp -o $(BUI)/aveNativa.o

$(BUI)/mamifero.o: $(SRC)/mamifero.cpp $(INC)/mamifero.h
	$(CC) $(CCP) -c $(SRC)/mamifero.cpp -o $(BUI)/mamifero.o

$(BUI)/mamiferoExotico.o: $(SRC)/mamiferoExotico.cpp $(INC)/mamiferoExotico.h
	$(CC) $(CCP) -c $(SRC)/mamiferoExotico.cpp -o $(BUI)/mamiferoExotico.o

$(BUI)/mamiferoNativo.o: $(SRC)/mamiferoNativo.cpp $(INC)/mamiferoNativo.h
	$(CC) $(CCP) -c $(SRC)/mamiferoNativo.cpp -o $(BUI)/mamiferoNativo.o

$(BUI)/reptil.o: $(SRC)/reptil.cpp $(INC)/reptil.h
	$(CC) $(CCP) -c $(SRC)/reptil.cpp -o $(BUI)/reptil.o

$(BUI)/reptilExotico.o: $(SRC)/reptilExotico.cpp $(INC)/reptilExotico.h
	$(CC) $(CCP) -c $(SRC)/reptilExotico.cpp -o $(BUI)/reptilExotico.o

$(BUI)/reptilNativo.o: $(SRC)/reptilNativo.cpp $(INC)/reptilNativo.h
	$(CC) $(CCP) -c $(SRC)/reptilNativo.cpp -o $(BUI)/reptilNativo.o

$(BUI)/funcionario.o: $(SRC)/funcionario.cpp $(INC)/funcionario.h $(INC)/excecoes.h
	$(CC) $(CCP) -c $(SRC)/funcionario.cpp -o $(BUI)/funcionario.o

$(BUI)/veterinario.o: $(SRC)/veterinario.cpp $(INC)/veterinario.h
	$(CC) $(CCP) -c $(SRC)/veterinario.cpp -o $(BUI)/veterinario.o

$(BUI)/tratador.o: $(SRC)/tratador.cpp $(INC)/tratador.h
	$(CC) $(CCP) -c $(SRC)/tratador.cpp -o $(BUI)/tratador.o

$(BUI)/gerenciamento.o: $(SRC)/gerenciamento.cpp $(INC)/gerenciamento.h $(INC)/acoes.h
	$(CC) $(CCP) -c $(SRC)/gerenciamento.cpp -o $(BUI)/gerenciamento.o

$(BUI)/main.o: $(SRC)/main.cpp $(INC)/gerenciamento.h
	$(CC) $(CCP) -c $(SRC)/main.cpp -o $(BUI)/main.o

#Criação da biblioteca.
$(LIB)/libpetfera.so: $(OBJ)
	$(CC) -shared $(OBJ) -o $@

#Comando para executar o programa.
run:
	exportar
	reset
	$(PROG)

#Comando para executar o debugger.
gdb:
	gdb $(PROG)

#Comando para limpar as pastas para exportar a aplicação.
clean:
	rm -rf $(BIN)
	rm -rf $(BUI)
	rm -rf $(LIB)