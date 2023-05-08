#include <stdio.h>
#include <elf.h>

/**
 * print_elf_header - prints the ELF header information
 * @header: pointer to the ELF header structure
 */
void print_elf_header(Elf64_Ehdr *header)
{
int i;
printf("ELF Header:\n");
printf("  Magic:   ");
for (i = 0; i < EI_NIDENT; i++)
    printf("%02x ", header->e_ident[i]);
printf("\n");
printf("  Class:                             %s\n",
        header->e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" :
        header->e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" :
        "Invalid ELF class");
printf("  Data:                              %s\n",
        header->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" :
        header->e_ident[EI_DATA] == ELFDATA2MSB ? "2's complement, big endian" :
        "Invalid data encoding");
printf("  Version:                           %d%s\n",
        header->e_ident[EI_VERSION],
        header->e_ident[EI_VERSION] == EV_CURRENT ? " (current)" : "");
printf("  OS/ABI:                            %s\n",
        header->e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX - System V" :
        header->e_ident[EI_OSABI] == ELFOSABI_HPUX ? "UNIX - HP-UX" :
        header->e_ident[EI_OSABI] == ELFOSABI_NETBSD ? "UNIX - NetBSD" :
        header->e_ident[EI_OSABI] == ELFOSABI_LINUX ? "UNIX - Linux" :
        header->e_ident[EI_OSABI] == ELFOSABI_SOLARIS ? "UNIX - Solaris" :
        header->e_ident[EI_OSABI] == ELFOSABI_IRIX ? "UNIX - IRIX" :
        header->e_ident[EI_OSABI] == ELFOSABI_FREEBSD ? "UNIX - FreeBSD" :
        header->e_ident[EI_OSABI] == ELFOSABI_TRU64 ? "UNIX - TRU64" :
        header->e_ident[EI_OSABI] == ELFOSABI_ARM_AEABI ? "ARM EABI" :
        header->e_ident[EI_OSABI] == ELFOSABI_ARM ? "ARM" :
        header->e_ident[EI_OSABI] == ELFOSABI_STANDALONE ? "Standalone App" :
        "Unknown");
printf("  ABI Version:                       %d\n",
        header->e_ident[EI_ABIVERSION]);
printf("  Type:                              %s\n",
        header->e_type == ET_NONE ? "NONE (None)" :
        header->e_type == ET_REL ? "REL (Relocatable file)" :
        header->e_type == ET_EXEC ? "EXEC (Executable file)" :
        header->e_type == ET_DYN ? "DYN (Shared object file)" :
        header->e_type == ET_CORE ? "CORE (Core file)" :
        "Unknown type");
printf("  Entry point address:               %lx\n",
        (unsigned long)header->e_entry);
}
