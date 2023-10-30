/*
 * ring_buffer.h
 *
 *  Created on: 30 oct. 2023
 *      Author: BRAYAN ALEXIS
 */

#ifndef INC_RING_BUFFER_H_
#define INC_RING_BUFFER_H_


#include <stdint.h>

typedef struct {
	uint8_t  *buffer;  /*!\ Pointer to memory location */
	uint16_t head;     /*!\ To write new data */
	uint16_t tail;     /*!\ To read old data */

	uint16_t capacity;
	uint8_t  is_full;

} ring_buffer_t;

#endif /* INC_RING_BUFFER_H_ */
