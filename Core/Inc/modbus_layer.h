#ifndef MODBUS_LAYER_H
#define MODBUS_LAYER_H

#include <stdint.h>

// Handles a Modbus request and prepares a response
void handle_modbus_request(uint8_t *request, uint16_t request_length, uint8_t *response, uint16_t *response_length);


#endif
