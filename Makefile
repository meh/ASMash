CC      = gcc
CXX     = g++
CFLAGS  = -Wall -pedantic # -pedantic-errors # The unistd.h has some errors with pedantic, not our fault
LDFLAGS =

LIB        = elfshark
SRCDIR     = src
INCLUDEDIR = include
PREFIX     = /usr/local
FILES      = ${SRCDIR}/decode.o ${SRCDIR}/elf.o ${SRCDIR}/op_bits8.o ${SRCDIR}/op_jmp.o ${SRCDIR}/op_pushpop.o ${SRCDIR}/op_reg32.o ${SRCDIR}/op_scal32.o ${SRCDIR}/op_scal81.o ${SRCDIR}/single.o ${SRCDIR}/utils.o

ifeq (${DEBUG}, 1)
CFLAGS += -g3
endif

all: $(FILES)
	${CC} ${LDFLAGS} -dynamiclib -shared -Wl,-soname,lib${LIB}.so.0 -o lib${LIB}.so.0.0.0 ${SRCDIR}/*.lo
	ar rcs lib$(LIB).a ${SRCDIR}/*.lo

$(FILES): $(FILES:.o=.c)
	${CC} ${CFLAGS} -I./include/ -I./src/ -fPIC -c $*.c -o $*.lo

install:
	mkdir -p $(PREFIX)/lib
	mkdir -p $(PREFIX)/doc
	mkdir -p $(PREFIX)/doc/$(LIB)-$(shell cat VERSION)
	mkdir -p $(PREFIX)/$(INCLUDEDIR)/ElfShark
	install -m 0644 README  $(PREFIX)/doc/$(LIB)-$(shell cat VERSION)
	install -m 0644 INSTALL $(PREFIX)/doc/$(LIB)-$(shell cat VERSION)
	install -m 0644 VERSION $(PREFIX)/doc/$(LIB)-$(shell cat VERSION)
	install -m 0644 LICENCE $(PREFIX)/doc/$(LIB)-$(shell cat VERSION)
	install -m 0644 $(INCLUDEDIR)/* $(PREFIX)/include/ElfShark
	install -m 0644 lib$(LIB).a $(PREFIX)/lib
	install -m 0755 lib$(LIB).so.0.0.0 $(PREFIX)/lib
	ln -sf $(PREFIX)/lib/lib$(LIB).so.0.0.0 $(PREFIX)/lib/lib$(LIB).so.0
	ldconfig

clean:
	rm *.o
	rm lib$(LIB).a
	rm lib$(LIB).so.*

uninstall:
	rm $(PREFIX)/include/elfshark.h
	rm $(PREFIX)/include/elfshark_private.h
	rm $(PREFIX)/lib/lib$(LIB).so.*
	rm $(PREFIX)/lib/lib$(LIB).a
