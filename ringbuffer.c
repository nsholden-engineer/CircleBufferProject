#include "ringbuffer.h"

/*
 * ringbuffer_init
 *
 * Initialize a new int32_t ringbuffer with given size in elements
 *
 * @param size Size in elements
 *
 * @return ringbuffer handle or NULL on error
 */
ringbuffer_h ringbuffer_init(int size) {
	// Implement init here

	// Scrub negative input, and no point in making a
	// Zero-size buffer
	if(size < 1)
	{
		errno = ENOSYS;
		return NULL;
	}

	ringbuffer_h newRing = malloc(sizeof(ringbuffer_t));
	newRing->buffer = malloc(sizeof(uint32_t) * size);
	newRing->head = newRing->buffer; //initialize head and tail to first element
	newRing->tail = newRing->buffer;
	newRing->maxLength = size;
	newRing->currentSize = 0;
	return newRing;
}

/*
 * ringbuffer_push
 *
 * Push a new int32 element onto the given ringbuffer
 *
 * @param ring  ringbuffer handle to add an element to
 * @param value int32 value to push
 * 
 * @return 0 on success, other on failure
 */
int ringbuffer_push(ringbuffer_h ring, int32_t value) {
	// Implement push here

	// Check for full ring buffer
	if(!(ringbuffer_full(ring)))
	{
		errno = ENOSYS;
		return -1;
	}
	// Check for empty ring buffer
	// If so, set zeroth element to value
	if(!(ringbuffer_empty(ring)))
	{
		*(ring->tail) = value;
		ring->currentSize++;
		return 0;

	}

	// Otherwise move tail to the next spot up and
	// Set next element to value
	ring->tail +=1;
	// If tail would go past the edge of ring buffer, loop to beginning
	if (ring->tail >= ring->buffer + ring->maxLength)
		ring->tail = ring->buffer;
	// Set tail location to value
	*(ring->tail) = value;
	ring->currentSize++;
	return 0;
}

/*
 * ringbuffer_pop
 *
 * Pop a int32 element from the given ringbuffer
 *
 * @param ring  ringbuffer handle to add an element to
 * @param value pointer to int32 value populate with popped value
 * 
 * @return 0 on success, other on failure
 */
int ringbuffer_pop(ringbuffer_h ring, int32_t *value) {
	// Implement pop here

	// Fail if attempting to pop element from empty ring buffer
	if(!(ringbuffer_empty(ring)))
	{
		errno = ENOSYS;
		return -1;
	}

	// Set value to head value
	*value = *(ring->head);
	ring->head +=1;
	// After incrementing head, if it goes off edge, loop back
	// To beginning
	if(ring->head > ring->buffer + ring->maxLength)
		ring->head = ring->buffer;
	ring->currentSize--;
	return 0;
}

/*
 * ringbuffer empty
 *
 * Check if a ringbuffer is empty
 * 
 * @param ring ringbuffer to check
 *
 * @return 0 if empty, 1 if non-empty, negative on failure
 */
int ringbuffer_empty(ringbuffer_h ring) {
	// implement empty here
	uint8_t ret = (ring->currentSize == 0) ? (0) : (1);
	return ret;
	errno = ENOSYS;
	return -1;
}

/*
 * ringbuffer full
 *
 * Check if a ringbuffer is full
 * 
 * @param ring ringbuffer to check
 *
 * @return 0 if full, 1 if non-full, negative on failure
 */
int ringbuffer_full(ringbuffer_h ring) {
	// implement full here

	uint8_t ret = (ring->currentSize >= ring->maxLength) ? (0) : (1);
	return ret;
	errno = ENOSYS;
	return -1;
}

/*
 * ringbuffer remaining
 *
 * Get count of remaining slots in ringbuffer
 * 
 * @param ring ringbuffer to check
 *
 * @return number of empty slots, negative on failure
 */
int ringbuffer_remaining(ringbuffer_h ring) {
	// implement remaining here
	return (ring->maxLength - ring->currentSize);

	errno = ENOSYS;
	return -1;
}


/*
 * ringbuffer_destroy
 *
 * Destroy a given ringbuffer
 *
 * @param ring ringbuffer to destroy
 *
 * @return 0 on success, other on failure
 */
int ringbuffer_destroy(ringbuffer_h ring) {
	// implement destroy here

	free(ring->buffer);
	free(ring);
	errno = ENOSYS;
	return -1;
}
