#include "modbus_layer.h"
#include <string.h>
/*
// Parses a Modbus request and prepares a response
void handle_modbus_request(uint8_t *request, uint16_t request_length, uint8_t *response, uint16_t *response_length) {
    // Check minimum Modbus request length
    if (request_length < 6) {
        *response_length = 0; // Invalid request
        return;
    }

    uint16_t transaction_id = (request[0] << 8) | request[1];
    uint16_t protocol_id = (request[2] << 8) | request[3];
    uint16_t length_field = (request[4] << 8) | request[5];
    uint8_t unit_id = request[6];

    // Validate Modbus protocol (protocol ID must be 0 for Modbus)
//    if (protocol_id != 0) {
//        *response_length = 0; // Invalid protocol
//        return;
//    }

    // Prepare a "Hi" response
    uint16_t index = 0;
//    response[index++] = (transaction_id >> 8) & 0xFF; // Transaction ID (High Byte)
//    response[index++] = transaction_id & 0xFF;        // Transaction ID (Low Byte)
//    response[index++] = (protocol_id >> 8) & 0xFF;    // Protocol ID (High Byte)
//    response[index++] = protocol_id & 0xFF;           // Protocol ID (Low Byte)
//    response[index++] = 0x00;                         // Response Length (High Byte)
//    response[index++] = 3;                            // Response Length (Low Byte)
//    response[index++] = unit_id;                      // Unit ID
    response[index++] = 'H';                          // 'H'
    response[index++] = 'i';                          // 'i'

    *response_length = index;
}*/

void handle_modbus_request(uint8_t *request, uint16_t request_length, uint8_t *response, uint16_t *response_length) {
    // Directly copy the incoming request to the response
    memcpy(response, request, request_length);


    // Set the response length to the request length
    *response_length = request_length;
}
