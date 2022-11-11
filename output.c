#include <stdio.h>
#include <stdint.h>
#include "algorithm.h"

// function to display a binary value
void displayGenerations(uint_c *pGens, int generations, int statelen)
{
	for (int gen = 0; gen < generations; gen++)
	{
		// loop through each bit, if the bit is 1: print a '0' (i.e. filled in), if the bit is 0, print a '.' (i.e. empty)
		for (int i = 0; i < statelen; i++)
		{
			uint8_t s = pGens[gen] >> i;
			if (s % 2)
			{
				printf("0");
			}
			else
			{
				printf(".");
			}
		}
		printf("\n");
	}
}