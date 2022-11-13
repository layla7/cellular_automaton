#ifndef __ALGORITHM_HEADER__ // this is a 'guard' on the header file, to prevent it's contents from
#define __ALGORITHM_HEADER__ // being redefined more than once during the build process

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint64_t uint_c;

typedef struct algoValues
{
	
	uint_c state;
	uint8_t rule;
	int statelen;
	int generations;
	bool wrap;
	uint_c output;
} AlgoValues;


void algorithm(uint_c state, uint8_t rule, int statelen, int generations, bool wrap, uint_c* output);
int calculateGenerations(int statelen);
int menu();
int menuDisplay();

AlgoValues editValues(AlgoValues data);


#endif