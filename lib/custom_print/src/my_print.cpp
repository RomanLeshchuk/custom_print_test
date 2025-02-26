#include <iostream>
#include <string_view>

#include "my_print.h"

void my_print(std::string_view str)
{
    for (unsigned int i = 0; i < str.size(); i++)
    {
        if (str[i] != '{' || i + 1 == str.size() || str[i + 1] != '}')
        {
            std::cout << str[i];
            continue;
        }

        i++;
    }
}