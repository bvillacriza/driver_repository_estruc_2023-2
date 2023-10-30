/*
 * ring_buffer.c
 *
 *  Created on: 30 oct. 2023
 *      Author: BRAYAN ALEXIS
 */


#include "ring_buffer.h"

/**
 * @brief This function initializes the control struct of the ring buffer
*/
void ring_buffer_init(ring_buffer_t *ring_buffer, uint8_t *buffer, uint16_t capacity)
{
	ring_buffer->buffer = buffer;
	ring_buffer->capacity = capacity;

	ring_buffer->head = 0;
	ring_buffer->tail = 0;
	ring_buffer->is_full = 0;
}

/**
 * @brief This function adds a data in the ring buffer
 * @param data: the value to be added
*/
uint8_t ring_buffer_put(ring_buffer_t *ring_buffer, uint8_t data)
{
	ring_buffer->buffer[ring_buffer->head] = data;
	ring_buffer->head = (ring_buffer->head + 1) % ring_buffer->capacity;

	if (ring_buffer->is_full != 0) {
		ring_buffer->tail = (ring_buffer->tail + 1) % ring_buffer->capacity;
	}

	if (ring_buffer->head == ring_buffer->tail) {
		ring_buffer->is_full = 1;
	}
}

/**
 * @brief This function reads a data from the ring buffer
 * @param data: the pointer to the address to write the data
*/
uint8_t ring_buffer_get(ring_buffer_t *ring_buffer, uint8_t *data)
{
	if ((ring_buffer->is_full != 0) || (ring_buffer->tail != ring_buffer->head)) {
		*data = ring_buffer->buffer[ring_buffer->tail];
		ring_buffer->tail = (ring_buffer->tail + 1) % ring_buffer->capacity;
		ring_buffer->is_full = 0;
		return 1;
	}
	return 0;
}

/**
 * @brief This function returns the size of the ring buffer
*/
uint16_t ring_buffer_size(ring_buffer_t *ring_buffer)
{
	uint16_t size = 0;

	if ((ring_buffer->is_full == 0) && (ring_buffer->tail <= ring_buffer->head)) {
		size = ring_buffer->head - ring_buffer->tail;
	} else {
		size = ring_buffer->head + (ring_buffer->capacity - ring_buffer->tail);
	}

	return size;
}

/*ring_buffer_is_empty, que se utiliza para verificar si el buffer circular está vacío. Toma un puntero a una estructura ring_buffer_t como argumento.*/

uint8_t ring_buffer_is_empty(ring_buffer_t *ring_buffer)
{
	return ring_buffer->head == ring_buffer->tail;
}
