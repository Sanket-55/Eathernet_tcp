#include "tcp.h"
#include "modbus_layer.h"
#include "lwip/tcp.h"
#include <string.h>

// Callback when data is received on a connection
err_t tcp_receive_callback(void *arg, struct tcp_pcb *tpcb, struct pbuf *p, err_t err) {
    uint8_t response[5000];
    uint16_t response_length = 0;

    // Check for valid data
    if (p == NULL) {
        tcp_close(tpcb); // Connection closed by client
        return ERR_OK;
    }

    // Step 1: Handle Modbus TCP request
    handle_modbus_request((uint8_t *)p->payload, p->len, response, &response_length);

    // Step 2: Send response if valid
    if (response_length > 0) {
        tcp_write(tpcb, response, response_length, TCP_WRITE_FLAG_COPY);
        tcp_output(tpcb);
    }

    // Free the received pbuf
    pbuf_free(p);
    return ERR_OK;
}

// Callback when a new connection is accepted
err_t tcp_accept_callback(void *arg, struct tcp_pcb *newpcb, err_t err) {
    // Set receive callback for this connection
    tcp_recv(newpcb, tcp_receive_callback);
    return ERR_OK;
}
