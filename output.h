#include "algorithm.h"

#ifndef __OUTPUT_H
#define __OUTPUT_H

#define ONE '0'	 // value to be printed when one is detected (filled in)
#define ZERO '.' // value to be printed when zero is detected (empty)

/** function to print out an array of binary values
 * @param pGens: Pointer to an array of type `uint_c` containing all generations, outputted from algorithm.c:algorithm
 * @param generations: the number of generations
 * @param statelen: the size of the state (in bits)
 *
 * @returns void
 **/
void displayGenerations(uint_c *pGens, int generations, int statelen);

/** function to save array of binary value to a file (logic identical to `displayGenerations`)
 * @param pGens: Pointer to an array of type `uint_c` containing all generations, outputted from algorithm.c:algorithm
 * @param generations: the number of generations
 * @param statelen: the size of the state (in bits)
 * @param filename: the path to the file to save to
 *
 * @returns void
 **/
void saveToFile(uint_c *pGens, int generations, int statelen, char *filename);

/** function to load data from a file
 * @param pGens: pointer to an array of type `uint_c` to save each generation into
 * @param generations: the number of generations
 * @param filename: the path to the file to load from
 *
 * @returns void
 **/
void loadFromFile(uint_c *pGens, int generations, char *filename);

#endif