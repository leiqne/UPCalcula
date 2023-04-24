CC = cl
CFLAGS = /EHsc
LDFLAGS = /Fe
SOURCES = ./UPCalcula1/cli.cpp
EXECUTABLE = ./cli.exe

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES)
	$(CC) $(CFLAGS) $(LDFLAGS)$(EXECUTABLE) $(SOURCES)

clean:
	del *.obj
