# Makefile para compilar o projeto

# Compilador e flags
CC = g++
CFLAGS = -Wall -std=c++17 -MMD -I./include

# Nome do programa e diretórios
PROGRAM = program
SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin

# Obtém a lista de arquivos fonte e objetos
SRCS = $(wildcard $(SRC_DIR)/**/*.cpp)
SRCS += $(SRC_DIR)/*.cpp
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))
EXEC = $(BIN_DIR)/$(PROGRAM)

# Regra padrão, que chama a regra para gerar o executável
all: $(EXEC)

# Regra para gerar o executável
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

# Define a regra para limpar os arquivos gerados pelo Makefile
.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)/*.o $(BIN_DIR)/$(PROGRAM) $(DEPS)
