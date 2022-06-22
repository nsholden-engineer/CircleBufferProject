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
	ringbuffer_h newRing = malloc(sizeof(ringbuffer_t));
	newRing->buffer = malloc(sizeof(uint32_t) * size);
	newRing->head = 0; //initialize head and tail to 0
	newRing->tail = 0;
	newRing->maxLength = size;
	return newRing;


	errno = ENOSYS;
	return NULL;
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
	errno = ENOSYS;
	return -1;
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
	errno = ENOSYS;
	return -1;
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

	(ring->head == ring->tail) ? (return 0) : (return 1);
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

	(ring->tail >= ring->size) ? (return 0) : (return 1);
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
