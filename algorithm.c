#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdlib.h>
#include <stdio.h>
#include "algorithm.h"
#include <stdbool.h>


/** algorithm function to perform the evolution algorithm
 *  state uses custom datatype to make changing the width simpler
 * @param state: the initial state of the automaton
 * @param rule: the rule to use when running the automaton
 * @param statelen: the size of the state (in bits)
 * @param generations: the number of generations to run for
 * @param wrap: boolean value, if false, there is no wrapping, if true the left/right sides wrap to each other
 * @param output: pointer to array to output data to (can be input to any of the display/save functions in output.c)
 *
 * @returns void
 **/
void algorithm(uint_c state, uint8_t rule, int statelen, int generations, bool wrap, uint_c* output)
{
  if (output == NULL)
	{
		printf("Algorithm received null pointer. Exiting");
		exit(1);
	}

	int generation = 0;
	for (generation = 0; generation < generations; generation++)
	{
		output[generation] = state;
		// define some varibales;
		uint8_t lastBit;
		uint8_t nextBit;
		uint8_t currBit;
		uint8_t firstBit;
		uint8_t bits;
		uint8_t next;
		uint_c nextState = 0U;

		if (wrap) // if wrap is true then save the first bit in the current state
			firstBit = state % 2;

		for (int i = 0; i < statelen; i++)
		{
			if (i == 0) // if currently on the first bit, imply 0 outside of the width or wrap to the last bit
			{
				if (wrap)
					lastBit = (state >> statelen) % 2;
				else
					lastBit = 0U;
				currBit = (state % 2);		// first bit in the state
				nextBit = (state >> 1) % 2; // second bit in the state
			}
			else if (i == statelen - 1) // if on the last bit, imply 0 outside of the width or wrap to the saved first bit
			{
				lastBit = (state % 2);
				currBit = (state >> 1) % 2;
				if (wrap)
					nextBit = firstBit;
				else
					nextBit = 0U;
			}
			else
			{
				// get the next 3 bits and then shift state right by 1
				lastBit = (state % 2);
				currBit = (state >> 1) % 2;
				nextBit = (state >> 2) % 2;
				state = state >> 1;
			}

			bits = ((lastBit << 2) + (currBit << 1) + nextBit); // put the 3 bits together into a binary value

			next = (rule >> bits) % 2;		  // get the bits th bit of the rule (i.e. if bits is 4, get the value of the 4th bit in the rule)
			nextState += ((uint_c)next << i); // update the next state of the automaton
		}
		state = nextState;
	}
	// return 0;
}

int calculateGenerations(int statelen)
{
	return statelen / 2;
}

void displayValue(uint32_t state, int statelen)
{
	for (int i = 0; i < statelen; i++)
	{
		uint32_t s = state >> i;
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

AlgoValues editValues(AlgoValues data)
{
	int userInputSInt = 0;
	uint8_t userInputUInt8 = 0;
	uint32_t userInputUInt32 = 0;
	
	AlgoValues tempValues = data;

	printf("Please follow the instructions on screen\n");
	printf("if you wish for default values, enter -1\n");
	printf("Any values out of bounds will be set to default\n\n");

	printf("please enter a value between 1-64 for the width of display;\n");
	printf("Default value: 32;\n");
	if (scanf("%d", &userInputSInt) != 0);
	if (userInputSInt == -1)
	{
		tempValues.statelen = 32;
	}
	else if (userInputSInt >= 1 && userInputSInt <= 64)
	{

	}
	else
	{
		printf("Input %d out of bounds, reverting to default", userInputSInt);
		tempValues.statelen = 32;
	}
	printf("Width of the display is %d\n\n", tempValues.statelen);

	printf("please enter a value between 1-64 for the state;\n"); //need a better word than state
	printf("Default value: half the size of the width;\n");
	if (scanf("%u", &userInputUInt32) != 0);
	if (userInputUInt32 == -1)
	{
		tempValues.state = tempValues.statelen / 2;
	}
	else if (userInputUInt32 >= 1 && userInputUInt32 <= 64)
	{
		tempValues.state = userInputUInt32;
	}
	else
	{
		printf("Input %u out of bounds, reverting to default", userInputUInt32);
		tempValues.state = tempValues.statelen / 2;
	}
	printf("Start position is %u\n\n", tempValues.statelen);

	printf("please enter a value between 1-255 for the cellular automata rule\n");
	printf("Default value: 30;\n");
	//sscanf("%d", &userInputUInt8);
	if (scanf("%hhu", &userInputUInt8) != 0);

	if (userInputUInt8 == -1)
	{
		tempValues.rule = 30;
	}
	else if (userInputUInt8 >= 1 && userInputUInt8 <= 255)
	{
		tempValues.rule = userInputUInt8;
	}
	else
	{
		printf("Input %u out of bounds, reverting to default\n", userInputUInt32);
		tempValues.rule = 30;
	}
	printf("Rule is %u\n\n", tempValues.rule);

	printf("Please select if you would like the display to wrap\n");
	printf("Enter 1 for true\n");
	printf("Enter 0 for false\n");
	printf("Default value: False;\n");
	if (scanf("%u", &userInputSInt) != 0)
	if (userInputSInt == 1)
	{
		tempValues.wrap = true;
		printf("wrapping is on\n");
	}
	else if (userInputSInt == 0)
	{
		tempValues.wrap = false;
		printf("wrapping is off\n");
	}
	else
	{
		printf("Input %d out of bounds, reverting to default\n", userInputSInt);
		tempValues.wrap = false;
		printf("wrapping is off");
	}

	printf("please enter a value between 1-64 for the Generation;\n"); //need a better word than state
	printf("Default value: half the size of the width;\n");
	if (scanf("%u", &userInputUInt32) != 0);
	if (userInputUInt32 == -1)
	{
		tempValues.generations = tempValues.statelen / 2;
	}
	else if (userInputUInt32 >= 1 && userInputUInt32 <= 64)
	{
		tempValues.generations = userInputUInt32;
	}
	else
	{
		printf("Input %u out of bounds, reverting to default", userInputUInt32);
		tempValues.generations = tempValues.statelen / 2;
	}
	printf("Start position is %u\n\n", tempValues.generations);

	printf("All values set!");
	return tempValues;
}