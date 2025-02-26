#pragma once

#include <iostream>
#include <string_view>

void my_print(std::string_view str);

// Template functions must be implemented in header files

template <typename T>
void my_print(std::string_view str, T&& arg)
{
    for (unsigned int i = 0; i < str.size(); i++)
    {
        if (str[i] != '{' || i + 1 == str.size() || str[i + 1] != '}')
        {
            std::cout << str[i];
            continue;
        }

        std::cout << arg;

        str.remove_prefix(i + 2);
        my_print(str);

        break;
    }
}

template <typename T, typename... U>
void my_print(std::string_view str, T&& arg, U&&... args)
{
    for (unsigned int i = 0; i < str.size(); i++)
    {
        if (str[i] != '{' || i + 1 == str.size() || str[i + 1] != '}')
        {
            std::cout << str[i];
            continue;
        }

        std::cout << arg;

        str.remove_prefix(i + 2);
        my_print(str, args...);

        break;
    }
}