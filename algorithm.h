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
	uint_c *output;
} AlgoValues;

/** algorithm function to perform the evolution algorithm
 *  state uses custom datatype to make changing the width simpler
 * @param initialState: the initial state of the automaton NOTE: state reverses the initial state
 * @param rule: the rule to use when running the automaton
 * @param statelen: the size of the state (in bits)
 * @param generations: the number of generations to run for
 * @param wrap: boolean value, if false, there is no wrapping, if true the left/right sides wrap to each other
 * @param output: pointer to array to output data to (can be input to any of the display/save functions in output.c)
 *
 * @returns void
 **/
void algorithm(uint_c initialState, uint8_t rule, int statelen, int generations, bool wrap, uint_c *output);

/**
 * Processing user input and calling the corresponding functions.
 * @returns int
 */
int menu();

/**
 * Displays menu options to user.
 * @returns int
 */
int menuDisplay();

/**
 * Function for user to set values to change the outcome of the evolution algorithm.
 * @param data struct containing relevant values to the algorithm.
 * @returns tempValues holder for user inputs.
 */
AlgoValues editValues(AlgoValues data);

#endif