/**
 * The files in this directory and elsewhere which refer to this LICENCE
 * file are part of ElfShark, the library for disassembling/assembling
 * binary code.
 *
 * Copyright (C) 2009 BlackLight and meh. [http://meh.doesntexist.org]
 *
 * ElfShark is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 3 or (at your option) any later 
 * version.
 *
 * ElfShark is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with ElfShark; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA.
 *
 * As a special exception, if other files instantiate templates or use
 * macros or inline functions from these files, or you compile these
 * files and link them with other works to produce a work based on these
 * files, these files do not by themselves cause the resulting work to be
 * covered by the GNU General Public License. However the source code for
 * these files must still be made available in accordance with section (3)
 * of the GNU General Public License.
 *
 * This exception does not invalidate any other reasons why a work based on
 * this file might be covered by the GNU General Public License.
 */

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <elf.h>

#include "elfshark.h"

unsigned char*
ES_GetExecutableElfCode (char *fname, int *code_size, int *addr)
{
    unsigned char* code;
    int            fd;
    int            hlen;
    int            s_off;
    Elf32_Ehdr     elfhdr;

    if (fname == NULL) {
        return NULL;
    }

    if ((fd = open(fname, O_RDONLY)) < 0) {
        return NULL;
    }

    if (read(fd, &elfhdr, sizeof(Elf32_Ehdr)) <= 0) {
        return NULL;
    }

    hlen       = elfhdr.e_phentsize * elfhdr.e_phnum + elfhdr.e_ehsize;
    s_off      = elfhdr.e_shoff;
    *code_size = s_off-hlen;

    if (!(code = (unsigned char*) malloc(*code_size))) {
        return NULL;
    }

    lseek(fd, hlen, SEEK_SET);
    
    if (read(fd, code, *code_size) <= 0) {
        return NULL;
    }

    *addr = elfhdr.e_entry;
    close(fd);

    return code;
}

