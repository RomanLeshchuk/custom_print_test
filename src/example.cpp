#include "my_print.h"
#include "my_printf.h"

#include "example.h"

void myPrintExample()
{
    // just print string
    my_print("\nTesting template print:\n");

    // use placeholders
    my_print("(placeholders) string: {}, integer: {}, double: {}\n", "any string", 123, 3.14);

    // if more arguments - they are safely ignored
    my_print("just one placeholder: {}\n", "text", "ignored", "ignored");

    // if more placeholders - they are just ignored
    my_print("many placeholders: {} {}{}{}{}{}{} (most are ignored)\n", "a", 1);

    // if no arguments given - just ignore placeholders
    my_print("placeholders with no arguments: {}{}{} (ignored)\n");

    my_print("How to use brackets and placeholders in one print: {{}} {}\n", "", "placeholdered text");
}

void myPrintfExample()
{
    // just print string
    my_printf("\nTesting legacy print:\n");

    // use placeholders
    my_printf("percent: %%, string: %s, integer: %d, double: %f\n", "any string", 123, 3.14);

    // any other percent combinations are just ignored, except single percent sign
    my_printf("%q(%%q) and %w(%%w) are just ignored, as well as single percent sign in separate print call\n");

    // single percent in separate print call is just ignored
    my_printf("%");
}

void totalExample()
{
    myPrintExample();
    myPrintfExample();
}