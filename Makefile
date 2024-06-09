all: main

CC = gcc
override CFLAGS += -g -Wno-everything -pthread -lm 

SRCS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.c' -print)
HEADERS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.h' -print)

main: $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) $(SRCS) -o "$@"

main-debug: $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) -O0 $(SRCS) -o "$@"

clean:
	rm -f main main-debug



# TESTE DE COMPILAÇÃO COM NCURSES LOCAL
# all: main

# CC = gcc
# override CFLAGS += -g -Wno-everything -pthread -lm -I$(PWD)/local/include
# override LDFLAGS += -L$(PWD)/local/lib -lncurses

# SRCS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.c' -print)
# HEADERS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.h' -print)

# main: $(SRCS) $(HEADERS)
# 	$(CC) $(CFLAGS) $(SRCS) -o "$@" $(LDFLAGS)

# main-debug: $(SRCS) $(HEADERS)
# 	$(CC) $(CFLAGS) -O0 $(SRCS) -o "$@" $(LDFLAGS)

# clean:
# 	rm -f main main-debug

