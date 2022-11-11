// includes

#include <stdio.h>
#include <stdint.h>
#include "algorithm.h"

// algorithm function to perform the evolution algorithm
// state uses custom datatype to make changing the width simpler
void algorithm(uint_c state, uint8_t rule, int statelen, int generations, int wrap, uint_c *output)
{

	for (int generation = 0; generation < generations; generation++)
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
