#include "algorithm.h"

#ifndef __OUTPUT_H
#define __OUTPUT_H

#define ONE '0'
#define ZERO '.'

#endif

void displayGenerations(uint_c *pGens, int generations, int statelen);
void saveToFile(uint_c *pGens, int generations, int statelen, char *filename);
void loadFromFile(uint_c *pGens, int generations, char *filename);