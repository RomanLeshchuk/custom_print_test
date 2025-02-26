#include <iostream>
#include <chrono>
#include <string>
#include <format>

#include "my_print.h"
#include "my_printf.h"

#include "measure_performance.h"

unsigned int testCustomTemplateFormatPrint(unsigned int inputSize)
{
    auto t1 = std::chrono::steady_clock::now();

    for (int i = 0; i < inputSize; i++)
    {
        my_print("{} {} {} ", i, "str", 3.14 + i);
    }

    unsigned int resultTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - t1).count();

    std::flush(std::cout);

    return resultTime;
}

unsigned int testCustomLegacyFormatPrint(unsigned int inputSize)
{
    auto t1 = std::chrono::steady_clock::now();

    for (int i = 0; i < inputSize; i++)
    {
        my_printf("%d %s %f ", i, "str", 3.14 + i);
    }

    unsigned int resultTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - t1).count();

    std::flush(std::cout);

    return resultTime;
}

unsigned int testStandardFormatPrint(unsigned int inputSize)
{
    auto t1 = std::chrono::steady_clock::now();

    for (int i = 0; i < inputSize; i++)
    {
        std::cout << std::format("{} {} {} ", i, "str", 3.14 + i);
    }

    unsigned int resultTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - t1).count();

    std::flush(std::cout);

    return resultTime;
}

void comparePerformance()
{
    constexpr unsigned int inputSize = 10000;

    unsigned int template_time = testCustomTemplateFormatPrint(inputSize);
    unsigned int legacy_time = testCustomLegacyFormatPrint(inputSize);
    unsigned int standard_time = testStandardFormatPrint(inputSize);

    std::cout << "\n\n" << "Custom template formatting: " << template_time << "ms\n";
    std::cout << "Custom legacy formatting: " << legacy_time << "ms\n";
    std::cout << "Standard std::format formatting: " << standard_time << "ms\n";
}
