CC = gcc
CFLAGS = -Wall -Werror
TARGET = writer

all: $(TARGET)

$(TARGET): writer.c
	$(CROSS_COMPILE)$(CC) $(CFLAGS) writer.c -o $(TARGET)

clean:
	rm -f $(TARGET) *.o