CC ?= gcc
BIN_DIR = bin/
DEPS = processing.h

all: directories $(BIN_DIR)output

directories: 
	$(shell mkdir -p ./$(BIN_DIR))

$(BIN_DIR)output: $(BIN_DIR)main.o $(BIN_DIR)processing.o
	$(CC) $^ -o $@

$(BIN_DIR)%.o: %.c $(DEPS)
	$(CC) -c -o $@ $<

clean:
	rm -rf $(BIN_DIR)