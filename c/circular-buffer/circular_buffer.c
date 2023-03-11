#include "circular_buffer.h"
#include <stdlib.h>
#include <errno.h>

circular_buffer_t* new_circular_buffer(size_t capacity)
{
    circular_buffer_t* buffer = malloc(sizeof(circular_buffer_t));
	buffer->values = malloc(sizeof(buffer_value_t) * capacity);
    buffer->capacity = capacity;
    buffer->items = 0;
    buffer->start = 0;
    return buffer;
}

int16_t read(circular_buffer_t *buffer, buffer_value_t *read_value)
{
    if (buffer->items == 0) {
        errno = ENODATA;
        return EXIT_FAILURE;
    }

    *read_value = buffer->values[buffer->start];
    buffer->start = (buffer->start + 1) % buffer->capacity;
    buffer->items--;
    return EXIT_SUCCESS;
}

int16_t write(circular_buffer_t *buffer, buffer_value_t value)
{
    if (buffer->capacity <= buffer->items) {
        errno = ENOBUFS;
        return EXIT_FAILURE;
    }

    buffer->values[(buffer->start + buffer->items) % buffer->capacity] = value;
    buffer->items++;
    return EXIT_SUCCESS;
}

int16_t overwrite(circular_buffer_t *buffer, buffer_value_t value)
{
    if (buffer->capacity <= buffer->items) {
        buffer->values[(buffer->start + buffer->items) % buffer->capacity] = value;
        buffer->start = (buffer->start + 1) % buffer->capacity;
    } else {
        write(buffer, value);
    }
    
    return EXIT_SUCCESS;
}

void delete_buffer(circular_buffer_t* buffer)
{
    free(buffer->values);
    free(buffer);
}

void clear_buffer(circular_buffer_t* buffer)
{
    buffer->items = 0;
}

