#include <stdio.h>
#include <stdint.h>
#include "algorithm.h"

int main()
{
	algorithm(1U << 31, 30, 64, 0);
	return 0;
}