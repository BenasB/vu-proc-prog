CC ?= gcc
BIN_DIR = bin/
DEPS = list.h

all: directories $(BIN_DIR)output

tests: directories $(BIN_DIR)test

directories: 
	$(shell mkdir -p ./$(BIN_DIR))

$(BIN_DIR)output: $(BIN_DIR)main.o $(BIN_DIR)list.o
	$(CC) $^ -o $@

$(BIN_DIR)test: $(BIN_DIR)test.o $(BIN_DIR)list.o
	$(CC) $^ -o $@

$(BIN_DIR)%.o: %.c $(DEPS)
	$(CC) -c -o $@ $<

clean:
	rm -rf $(BIN_DIR)