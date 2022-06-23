#include <stdio.h>
#include <stdint.h>
#include "ringbuffer.h"

/* Ringbuffer test file
 *
 * Implement any tests you want in here, and call them from main
 */


int smoketest() {
	ringbuffer_h ring;
	int32_t value;

	ring = ringbuffer_init(10);
	if (ring == NULL) {
		printf("ringbuffer_init returned null\n");
		return 1;
	}

	if (ringbuffer_push(ring, 1)) {
		printf("ringbuffer_push returned unsuccessful\n");
		return 1;
	}

	if (ringbuffer_pop(ring, &value)) {
		printf("ringbuffer_pop returned unsuccessful\n");
		return 1;
	}

	if (value != 1) {
		printf("Expected value 1, but got %d\n", value);
		return 1;
	}

	ringbuffer_destroy(ring);

	return 0;
}

int smoketest2()
{
	ringbuffer_h ring;
	int32_t values[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int32_t check;
	int bufSize = 10;
	int firstPushSize = 5;
	int firstPopSize = 5;
	int secondPushSize = 10;
	int secondPopSize = 2;

	ring = ringbuffer_init(bufSize);
	printf("ST2: Buffer Size is %d.\n", bufSize);

	for(int i = 0; i < firstPushSize; i++)
	{
		if (ringbuffer_push(ring, values[i])) 
		{
			printf("ringbuffer_push returned unsuccessful\n");
			return 1;
		}	
	}
	
	printf("ST2: Remaining Slots in buffer is: %d after push of %d.\n", ringbuffer_remaining(ring), firstPushSize);

	printf("ST2: The following pops are: [");
	for(int i = 0; i < firstPopSize; i++)
	{
		if(ringbuffer_pop(ring, &check))
		{
			printf("ringbuffer_pop returned unsuccessful\n");
			return 1;
		}
		if(i < firstPopSize - 1)
			printf("%d, ", check);
		else
			printf("%d", check);
	}
	printf("]\n");

	// Testing ringbuffer_remaining() function

	printf("ST2: Remaining Slots in buffer is: %d after pop of %d.\n", ringbuffer_remaining(ring), firstPopSize);

	// Test for Adding to a now empty ring where head and tail have moved
	for(int i = 0; i < secondPushSize; i++)
	{
		if (ringbuffer_push(ring, values[i])) 
		{
			printf("ringbuffer_push returned unsuccessful\n");
			return 1;
		}	
	}

	printf("ST2: Remaining Slots in buffer is: %d after push of %d.\n", ringbuffer_remaining(ring), secondPushSize);

	printf("ST2: The following pops are: [");
	for(int i = 0; i < secondPopSize; i++)
	{
		if(ringbuffer_pop(ring, &check))
		{
			printf("ringbuffer_pop returned unsuccessful\n");
			return 1;
		}
		if(i < secondPopSize - 1)
			printf("%d, ", check);
		else
			printf("%d", check);
	}
	printf("]\n");

	printf("ST2: Remaining Slots in buffer is: %d after pop of %d.\n", ringbuffer_remaining(ring), secondPopSize);

	ringbuffer_destroy(ring);

	return 0;
}
	
int main(int argc, char** argv) {
	smoketest2();

	return smoketest();
}
