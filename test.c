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

	return 0;
}

int smoketest2()
{
	ringbuffer_h ring;
	int32_t values[] = {0, 1, 2, 3, 4, 5, 6, 7, 8 ,9};
	int32_t check;

	ringbuffer_init(10);

	for(int i = 0; i < 10; i++)
	{
		ringbuffer_push(ring, values[i]);
	}
	
	printf("The current array is : [");
	for(i = 0; i < 10; i++)
	{
		ringbuffer_pop(ring, &check);
		printf("%d, ", check);
	}
	printf("]\n");
}
	
int main(int argc, char** argv) {
	//return smoketest();
	return smoketest2();
}
