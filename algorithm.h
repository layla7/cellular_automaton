// custom type definition to make it simple to change the width seen
typedef uint64_t uint_c;

// function definitions
void algorithm(uint_c state, uint8_t rule, int statelen, int generations, int wrap, uint_c *output);
int calculateGenerations(int statelen);