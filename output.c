
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE  
#define _CRT_NONSTDC_NO_DEPRECATE
#endif

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include "algorithm.h"
#include "output.h"


// function to display a binary value
void displayGenerations(uint_c* pGens, int generations, int statelen)
{
	for (int gen = 0; gen < generations; gen++)
	{
		// loop through each bit, if the bit is 1: print `ONE` (defined in output.h), if the bit is 0, print `ZERO` (also defined in output.h)
		for (int i = 0; i < statelen; i++)
		{
			uint8_t s = pGens[gen] >> i;
			if (s % 2)
			{
				printf("%c", ONE);
			}
			else
			{
				printf("%c", ZERO);
			}
		}
		printf("\n");
	}
}

void saveToFile(uint_c* pGens, int generations, int statelen, char* filename)
{
	FILE* fp;
	fp = fopen(filename, "w");
	for (int gen = 0; gen < generations; gen++)
	{
		// loop through each bit, if the bit is 1: print `ONE` (defined in output.h), if the bit is 0, print `ZERO` (also defined in output.h)
		for (int i = 0; i < statelen; i++)
		{
			uint8_t s = pGens[gen] >> i;
			if (s % 2)
			{
				fprintf(fp, "%c", ONE);
			}
			else
			{
				fprintf(fp, "%c", ZERO);
			}
		}
		fprintf(fp, "\n");
	}
}

void loadFromFile(uint_c* pGens, int generations, char* filename)
{
	FILE* fp;
	fp = fopen(filename, "r");
	char c;

	for (int i = 0; i < generations; i++)
	{
		pGens[i] = 0;
	}

	int lineCounter = 0;
	int charCounter = 0;

	while ((c = fgetc(fp)) != EOF)
	{
		if (c == '\n')
		{
			lineCounter++;
			charCounter = 0;
		}
		else if (c == ONE)
		{
			pGens[lineCounter] += (1U << charCounter);
			charCounter++;
		}
		else
		{
			charCounter++;
		}
	}
}