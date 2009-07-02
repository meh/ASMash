CC      = gcc
CXX     = g++
CFLAGS  = -Wall -pedantic # -pedantic-errors # The unistd.h has some errors with pedantic, not our fault
LDFLAGS =

NAME       = ASMash
LIB        = asmash
SRCDIR     = src
INCLUDEDIR = include
PREFIX     = /usr
FILES      = ${SRCDIR}/Bytecode.o ${SRCDIR}/Instruction.o ${SRCDIR}/InstructionList.o ${SRCDIR}/InstructionStream.o \
			 ${SRCDIR}/Arch/api.o ${SRCDIR}/Arch/IA32/api.o \
			 ${SRCDIR}/Format/api.o ${SRCDIR}/Format/ELF/api.o

ARCH = IA32;

ifeq (${DEBUG}, 1)
CFLAGS += -g3
endif

all: $(FILES)
	${CC} ${LDFLAGS} -dynamiclib -shared -Wl,-soname,lib${LIB}.so.0 -o lib${LIB}.so.0.0.0 ${SRCDIR}/*.lo
	ar rcs lib$(LIB).a ${SRCDIR}/*.lo

$(FILES): $(FILES:.o=.c)
	${CC} ${CFLAGS} -DAA_DEFAULT_ARCH='"${ARCH}"' -I./include/ -I./src/ -fPIC -c $*.c -o $*.lo

install:
	mkdir -p $(PREFIX)/lib
	mkdir -p $(PREFIX)/doc
	mkdir -p $(PREFIX)/doc/$(LIB)-$(shell cat VERSION)
	mkdir -p $(PREFIX)/$(INCLUDEDIR)/ASMash
	install -m 0644 README  $(PREFIX)/doc/$(LIB)-$(shell cat VERSION)
	install -m 0644 INSTALL $(PREFIX)/doc/$(LIB)-$(shell cat VERSION)
	install -m 0644 VERSION $(PREFIX)/doc/$(LIB)-$(shell cat VERSION)
	install -m 0644 LICENCE $(PREFIX)/doc/$(LIB)-$(shell cat VERSION)
	install -m 0644 $(INCLUDEDIR)/* $(PREFIX)/include/ASMash
	install -m 0644 lib$(LIB).a $(PREFIX)/lib
	install -m 0755 lib$(LIB).so.0.0.0 $(PREFIX)/lib
	ln -sf $(PREFIX)/lib/lib$(LIB).so.0.0.0 $(PREFIX)/lib/lib$(LIB).so.0
	ldconfig

clean:
	find src | egrep "\.l?o$$" | xargs rm -f
	rm -f lib$(LIB).a
	rm -f lib$(LIB).so.*

uninstall:
	rm $(PREFIX)/include/elfshark.h
	rm $(PREFIX)/include/elfshark_private.h
	rm $(PREFIX)/lib/lib$(LIB).so.*
	rm $(PREFIX)/lib/lib$(LIB).a
