/**
 * Group 12
 * 
 * Alba Henderson (2488560)
 * Lowrie Mouat (2481347)
 * Oscar Morris (2497790)
*/
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

/** function to print out an array of binary values
 * @param pGens: Pointer to an array of type `uint_c` containing all generations, outputted from algorithm.c:algorithm
 * @param generations: the number of generations
 * @param statelen: the size of the state (in bits)
 *
 * @returns void
 **/
void displayGenerations(uint_c *pGens, int generations, int statelen)
{
  if (pGens == NULL)
	{
		printf("displayGenerations received null pointer, Exiting");
		exit(1);
	}

	if (statelen > 64)
	{
		printf("displayGenerations received invalid state length");
		exit(1);
	}
  
	for (int gen = 0; gen < generations; gen++)
	{
		// loop through each bit, if the bit is 1: print `ONE` (defined in output.h), if the bit is 0, print `ZERO` (also defined in output.h)
		for (int i = 0; i < statelen; i++)
		{
			uint8_t s = pGens[gen] >> i; // get the ith bit in pGens[gen]
			if (s % 2)
			{
				printf("%c", ONE); // if the ith bit is a one, print the character associated with `ONE` to the screen
			}
			else
			{
				printf("%c", ZERO); // otherwise, print the character associated with a 0 to the screen
			}
		}
		printf("\n"); // at the end of each line, print a newline character
	}
}

/** function to save array of binary value to a file (logic identical to `displayGenerations`)
 * @param pGens: Pointer to an array of type `uint_c` containing all generations, outputted from algorithm.c:algorithm
 * @param generations: the number of generations
 * @param statelen: the size of the state (in bits)
 * @param filename: the path to the file to save to
 *
 * @returns void
 **/
void saveToFile(uint_c *pGens, int generations, int statelen, char *filename)
{
  if (pGens == NULL || filename == NULL)
	{
		printf("saveToFile received null pointer, Exiting");
		exit(1);
	}

	if (statelen > 64)
	{
		printf("saveToFile received invalid state length");
		exit(1);
	}

	// open file
	FILE *fp;
	fp = fopen(filename, "w");

	for (int gen = 0; gen < generations; gen++)
	{
		// loop through each bit, if the bit is 1: print `ONE` (defined in output.h), if the bit is 0, print `ZERO` (also defined in output.h)
		for (int i = 0; i < statelen; i++)
		{
			uint8_t s = pGens[gen] >> i; // get the ith bit in pGens[gen]
			if (s % 2)
			{
				fprintf(fp, "%c", ONE); // if that bit is a one, print the character associated with `ONE` to the file
			}
			else
			{
				fprintf(fp, "%c", ZERO); // otherwise print the charracter associated with `ZERO` to the file
			}
		}
		fprintf(fp, "\n");
	}
}

/** function to load data from a file
 * @param pGens: pointer to an array of type `uint_c` to save each generation into
 * @param generations: the number of generations
 * @param filename: the path to the file to load from
 *
 * @returns void
 **/
void loadFromFile(uint_c *pGens, int generations, char *filename)
{
  	if (pGens == NULL || filename == NULL)
	{
		printf("loadFromFile received null pointer, Exiting");
		exit(1);
	}

	// setup filepointer and char variable
	FILE *fp;
	fp = fopen(filename, "r");
	char c;

	// initialize the `pGens` array
	for (int i = 0; i < generations; i++)
	{
		pGens[i] = 0;
	}

	int lineCounter = 0; // setup some counters
	int charCounter = 0;

	while ((c = fgetc(fp)) != EOF)
	{
		if (c == '\n') // if we've reached a newline, reset the charCounter and increment the lineCounter
		{
			lineCounter++;
			charCounter = 0;
		}
		else if (c == ONE) // if we've reached a one, add that into its proper place
		{
			pGens[lineCounter] += (1U << charCounter);
			charCounter++; // increment charCounter
		}
		else // otherwise just increment charCounter
		{
			charCounter++;
		}
	}
}