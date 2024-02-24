#include <stdint.h>

void putc(char s)
{
    static auto buf = (uint16_t*) 0xB8000;
    *buf = s;
}

void puts(const char *str)
{
    for (uint64_t i = 0; str[i] != '\0'; i++)
        putc(str[i]);
}

extern "C" void kernel_main()
{
    puts("Hello, LunaOS!");
    
    while (1);
}