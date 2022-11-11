#include <stdio.h>
#include <stdint.h>
#include "algorithm.h"

int algorithm(uint32_t state, uint8_t rule, int statelen, int wrap)
{
	int generations = statelen / 2;
	// int generations = 2;

	for (int generation = 0; generation < generations; generation++)
	{
		displayValue(state, statelen);
		uint8_t lastBit;
		uint8_t nextBit;
		uint8_t currBit;
		uint8_t firstBit;
		uint8_t bits;
		uint32_t nextState = 0U;

		if (wrap)
			firstBit = state % 2;

		for (int i = 0; i < statelen; i++)
		{
			if (i == 0)
			{
				if (wrap)
					lastBit = (state >> statelen) % 2;
				else
					lastBit = 0U;
				currBit = (state % 2);
				nextBit = (state >> 1) % 2;
			}
			else if (i == statelen - 1)
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
				lastBit = (state % 2);
				currBit = (state >> 1) % 2;
				nextBit = (state >> 2) % 2;
				state = state >> 1;
			}

			uint8_t testLastBit = lastBit << 2;
			uint8_t testCurrBit = currBit << 1;

			bits = ((lastBit << 2) + (currBit << 1) + nextBit);

			uint8_t next = (rule >> bits) % 2;
			nextState += (next << i);
		}
		state = nextState;
	}
	return 0;
}

void displayValue(uint32_t state, int statelen)
{
	for (int i = 0; i < statelen; i++)
	{
		uint8_t s = state >> i;
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