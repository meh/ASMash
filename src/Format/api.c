/**
 * The files in this directory and elsewhere which refer to this LICENCE
 * file are part of ASMash, the library for disassembling/assembling
 * binary code.
 *
 * Copyright (C) 2009 meh. and BlackLight
 *
 * ASMash is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 3 or (at your option) any later 
 * version.
 *
 * ASMash is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with ASMash; if not, write to the Free Software Foundation, Inc.,
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

#include "Format/api.h"

#include "Format/ELF/api.h"
#include "Format/PE/api.h"

#define AA_NEW_FORMAT(name) { #name, &AA_## name ##_GetSymbolAt, &AA_## name ##_GetSectionAddress, &AA_## name ##_GetSection }
#define AA_END_FORMATS { 0, 0, 0, 0 }

#define AA_FORMAT_ELF 0
#define AA_FORMAT_PE  1

const AAFormat AAFormats[] = {
    AA_NEW_FORMAT(ELF),
    AA_NEW_FORMAT(PE),

    AA_END_FORMATS
};

