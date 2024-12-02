#ifndef TCP_CALLBACKS_H
#define TCP_CALLBACKS_H

#include "lwip/tcp.h"

// Callback when a new connection is accepted
err_t tcp_accept_callback(void *arg, struct tcp_pcb *newpcb, err_t err);

// Callback when data is received on a connection
err_t tcp_receive_callback(void *arg, struct tcp_pcb *tpcb, struct pbuf *p, err_t err);

#endif
