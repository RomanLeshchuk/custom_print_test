#pragma once

#ifndef MEASURE_PERFORMANCE_H
#define MEASURE_PERFORMANCE_H

unsigned int testCustomTemplateFormatPrint(unsigned int inputSize);
unsigned int testCustomLegacyFormatPrint(unsigned int inputSize);
unsigned int testStandardFormatPrint(unsigned int inputSize);
void comparePerformance();

#endif