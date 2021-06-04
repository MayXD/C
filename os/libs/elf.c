#include "common.h"
#include "string.h"
#include "include/elf.h"

elf_t elf_from_multiboot(multiboot_t *mb) {

}
const char *elf_lookup_symbol(uint32_t addr, elf_t *elf); 