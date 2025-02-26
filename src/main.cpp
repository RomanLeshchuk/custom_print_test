/*
On my system, standard formatting was about four times faster,
while two custom methods were about equally efficient.
One of the reasons could be usage of high-level <iostream> library and
not bothering too much about optimization in this custom implementation.
*/

#include "measure_performance.h"
#include "example.h"

int main()
{
    comparePerformance();
    totalExample();

    return 0;
}