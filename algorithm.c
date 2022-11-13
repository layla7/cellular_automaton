// includes

#include <stdio.h>
#include <stdint.h>
#include "algorithm.h"

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
void algorithm(uint_c state, uint8_t rule, int statelen, int generations, int wrap, uint_c *output)
{

	for (int generation = 0; generation < generations; generation++)
	{
		output[generation] = state;
		// define some varibales to be used later
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
			// NOTE: The state variable always lags one behind i, this is because bit-shifting right may lose data,
			// the 1st bit in `state` is always the (i-1)th bit in the original state variable

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
		state = nextState; // update the state
	}
}
