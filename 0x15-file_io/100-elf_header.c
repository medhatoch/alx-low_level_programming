#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
#include "print_elf_header.c"

#define BUF_SIZE 64

void print_elf_header(Elf64_Ehdr *header);

int main(int argc, char **argv)
{
int fd;
Elf64_Ehdr header;

if (argc != 2)
{
    fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
    return (98);
}

/* Open the ELF file */
fd = open(argv[1], O_RDONLY);
if (fd == -1)
{
    fprintf(stderr, "Error: Unable to open file '%s'\n", argv[1]);
    return (98);
}

/* Read the ELF header */
if (read(fd, &header, sizeof(header)) != sizeof(header))
{
    fprintf(stderr, "Error: Unable to read ELF header from file '%s'\n", argv[1]);
    close(fd);
    return (98);
}

/* Check that the file is an ELF file */
if (header.e_ident[EI_MAG0] != ELFMAG0 ||
    header.e_ident[EI_MAG1] != ELFMAG1 ||
    header.e_ident[EI_MAG2] != ELFMAG2 ||
    header.e_ident[EI_MAG3] != ELFMAG3)
{
    fprintf(stderr, "Error: File '%s' is not an ELF file\n", argv[1]);
    close(fd);
    return (98);
}

/* Print the ELF header information */
print_elf_header(&header);

/* Close the file */
close(fd);

return (0);
}
