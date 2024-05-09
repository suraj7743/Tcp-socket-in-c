# Makefile for building a multi-file C project

CC = gcc
TARGET = main

# List of source files
SOURCES = socket_server.c ../utils/network_utils.c

# Build the executable
$(TARGET): $(SOURCES)
	$(CC) -o $(TARGET) $(SOURCES) 

# Clean the build
clean:
	rm -f $(TARGET)
