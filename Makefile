CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -pedantic
TARGET = amethyst_accueil
SOURCE = amethyst_accueil.c

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) $(SOURCE) -o $(TARGET)

clean:
	rm -f $(TARGET)

