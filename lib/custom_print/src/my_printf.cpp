#include <iostream>
#include <cstdarg>

#include "my_printf.h"

void my_printf(const char* str, ...)
{
    va_list list;

    va_start(list, str);

    for (unsigned int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != '%')
        {
            std::cout << str[i];
            continue;
        }

        i++;

        switch (str[i])
        {
            case '%':
                std::cout << '%';
                break;

            case 'd':
                std::cout << va_arg(list, int);
                break;

            case 'f':
                std::cout << va_arg(list, double);
                break;

            case 's':
                std::cout << va_arg(list, const char*);
        }
    }

    va_end(list);
}