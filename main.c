#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "algorithm.h"
#include "output.h"

int main()
{
	int statelen = 32;
	int generations = calculateGenerations(statelen);
	uint_c *ptr = NULL;
	ptr = malloc(sizeof(uint_c) * generations);
	// algorithm(1U << 15, 30, statelen, generations, 0, ptr);
	// displayGenerations(ptr, generations, statelen);
	// saveToFile(ptr, generations, statelen, "testfile.txt");

	loadFromFile(ptr, generations, "testfile.txt");
	displayGenerations(ptr, generations, statelen);
	return 0;
}