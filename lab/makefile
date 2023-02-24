CC := gcc
LDFLAGS := -L.
LIBs:= librocksdb.a
TARGET := output
INC :=-I. rocksdb

$(TARGET):main.o
	$(CC) -o $@ $^ $(LIBS)

main.o:main.cpp
	$(cc) -c $^ -o $@

clean:
	rm -fr *.o

	rm -fr $(TARGET)