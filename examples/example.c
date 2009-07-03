#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <ASMash/api.h>

int
main (int argc, char *argv[])
{
    AAProgram*           program;
    AASection*           section;
    AAInstructionStream* stream;

    if (argc == 1)  {
        fprintf (stderr, "Usage: %s <executable file>\n", argv[0]);
        return 1;
    }

    if ((program = AA_NewProgramFromFile(argv[1])) == NULL) {
        fprintf(stderr, "Error: Couldn't create the AAProgram object.\n");
        return 1;
    }

    if ((section = AA_GetSection(program, ".text")) == NULL) {
        fprintf (stderr, "Error: Unable to get .text content from %s\n", argv[1]);
        return 1;
    }

    stream = AA_NewInstructionStream(section->content);

    printf ("%s\n", AA_InstructionStreamToString(stream, AA_INTEL));


    AA_DestroyStream(stream);
    AA_DestroySection(section);
    AA_DestroyProgram(program);

    return 0;
}

