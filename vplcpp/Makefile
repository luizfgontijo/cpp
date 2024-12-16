# Compilador
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude

# Diretórios
SRC = src/entidades
BUILD = build
TARGET = a.exe

# Lista de arquivos-fonte e objetos
SRCS = $(SRC)/Passageiro.cpp $(SRC)/Transporte.cpp $(SRC)/Trem.cpp $(SRC)/Metro.cpp $(SRC)/Onibus.cpp src/main.cpp
OBJS = $(BUILD)/Passageiro.o $(BUILD)/Transporte.o $(BUILD)/Trem.o $(BUILD)/Metro.o $(BUILD)/Onibus.o $(BUILD)/main.o

# Regra padrão
all: $(TARGET)

# Regra para criar o executável
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Regras para compilar cada arquivo .cpp para .o
$(BUILD)/Passageiro.o: $(SRC)/Passageiro.cpp
	$(CXX) $(CXXFLAGS) -c $(SRC)/Passageiro.cpp -o $(BUILD)/Passageiro.o

$(BUILD)/Transporte.o: $(SRC)/Transporte.cpp
	$(CXX) $(CXXFLAGS) -c $(SRC)/Transporte.cpp -o $(BUILD)/Transporte.o

$(BUILD)/Trem.o: $(SRC)/Trem.cpp
	$(CXX) $(CXXFLAGS) -c $(SRC)/Trem.cpp -o $(BUILD)/Trem.o

$(BUILD)/Metro.o: $(SRC)/Metro.cpp
	$(CXX) $(CXXFLAGS) -c $(SRC)/Metro.cpp -o $(BUILD)/Metro.o

$(BUILD)/Onibus.o: $(SRC)/Onibus.cpp
	$(CXX) $(CXXFLAGS) -c $(SRC)/Onibus.cpp -o $(BUILD)/Onibus.o

$(BUILD)/main.o: src/main.cpp
	$(CXX) $(CXXFLAGS) -c src/main.cpp -o $(BUILD)/main.o

# Limpeza dos arquivos compilados
clean:
	@if [ -e $(BUILD)/*.o ]; then rm -f $(BUILD)/*.o; fi
	@if [ -e $(TARGET) ]; then rm -f $(TARGET); fi

# Limpeza completa
distclean: clean
	@if [ -e $(TARGET) ]; then rm -f $(TARGET); fi
