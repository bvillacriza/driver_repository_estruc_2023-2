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
