/*
 * Micro Python TC33100 Driver
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2016 Kimball Johnson
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <string.h>
#include <stdarg.h>
#include <errno.h>

#include "py/nlr.h"
#include "py/objtuple.h"
#include "py/objlist.h"
#include "py/stream.h"
#include "py/runtime.h"
#include "netutils.h"
#include "modnetwork.h"
#include "pin.h"
#include "genhdr/pins.h"
#include "spi.h"
#include "pybioctl.h"


#include "simplelink.h"


STATIC int cc3100_gethostbyname(mp_obj_t nic, const char *name, mp_uint_t len, uint8_t *out_ip) {
  return 0;
}

STATIC int cc3100_socket_socket(mod_network_socket_obj_t *socket, int *_errno) {
  return 0;

}

STATIC void cc3100_socket_close(mod_network_socket_obj_t *socket) {

}

STATIC int cc3100_socket_bind(mod_network_socket_obj_t *socket, byte *ip, mp_uint_t port, int *_errno) {
  return 0;
}

STATIC int cc3100_socket_listen(mod_network_socket_obj_t *socket, mp_int_t backlog, int *_errno) {
  return 0;

}

STATIC int cc3100_socket_accept(mod_network_socket_obj_t *socket, mod_network_socket_obj_t *socket2, byte *ip, mp_uint_t *port, int *_errno) {
  return 0;

}

STATIC int cc3100_socket_connect(mod_network_socket_obj_t *socket, byte *ip, mp_uint_t port, int *_errno) {
  return 0;

}

STATIC mp_uint_t cc3100_socket_send(mod_network_socket_obj_t *socket, const byte *buf, mp_uint_t len, int *_errno) {
  return 0;

}

STATIC mp_uint_t cc3100_socket_recv(mod_network_socket_obj_t *socket, byte *buf, mp_uint_t len, int *_errno) {
  return 0;

}

STATIC mp_uint_t cc3100_socket_sendto(mod_network_socket_obj_t *socket, const byte *buf, mp_uint_t len, byte *ip, mp_uint_t port, int *_errno) {
  return 0;

}

STATIC mp_uint_t cc3100_socket_recvfrom(mod_network_socket_obj_t *socket, byte *buf, mp_uint_t len, byte *ip, mp_uint_t *port, int *_errno) {
  return 0;

}

STATIC int cc3100_socket_setsockopt(mod_network_socket_obj_t *socket, mp_uint_t level, mp_uint_t opt, const void *optval, mp_uint_t optlen, int *_errno) {
  return 0;

}

STATIC int cc3100_socket_settimeout(mod_network_socket_obj_t *socket, mp_uint_t timeout_ms, int *_errno) {
  return 0;

}

STATIC int cc3100_socket_ioctl(mod_network_socket_obj_t *socket, mp_uint_t request, mp_uint_t arg, int *_errno) {
  return 0;

}

/******************************************************************************/
// Micro Python bindings; CC3100 class

typedef struct _cc3100_obj_t {
    mp_obj_base_t base;
} cc3100_obj_t;

STATIC const cc3100_obj_t cc3100_obj = {{(mp_obj_type_t*)&mod_network_nic_type_cc3100}};

// \classmethod \constructor(spi, pin_cs, pin_en, pin_irq)
// Initialise the CC3000 using the given SPI bus and pins and return a CC3K object.
//
// Note: pins were originally hard-coded to:
//      PYBv1.0: init(pyb.SPI(2), pyb.Pin.board.Y5, pyb.Pin.board.Y4, pyb.Pin.board.Y3)
//        [SPI on Y position; Y6=B13=SCK, Y7=B14=MISO, Y8=B15=MOSI]
//
//      STM32F4DISC: init(pyb.SPI(2), pyb.Pin.cpu.A15, pyb.Pin.cpu.B10, pyb.Pin.cpu.B11)
STATIC mp_obj_t cc3100_make_new(const mp_obj_type_t *type, mp_uint_t n_args, mp_uint_t n_kw, const mp_obj_t *args) {

    // register with network module
    mod_network_register_nic((mp_obj_t)&cc3100_obj);

    return (mp_obj_t)&cc3100_obj;
}


STATIC const mp_map_elem_t cc3100_locals_dict_table[] = {

};

STATIC MP_DEFINE_CONST_DICT(cc3100_locals_dict, cc3100_locals_dict_table);

const mod_network_nic_type_t mod_network_nic_type_cc3100 = {
    .base = {
        { &mp_type_type },
        .name = MP_QSTR_CC3100,
        .make_new = cc3100_make_new,
        .locals_dict = (mp_obj_t)&cc3100_locals_dict,
    },
    .gethostbyname = cc3100_gethostbyname,
    .socket = cc3100_socket_socket,
    .close = cc3100_socket_close,
    .bind = cc3100_socket_bind,
    .listen = cc3100_socket_listen,
    .accept = cc3100_socket_accept,
    .connect = cc3100_socket_connect,
    .send = cc3100_socket_send,
    .recv = cc3100_socket_recv,
    .sendto = cc3100_socket_sendto,
    .recvfrom = cc3100_socket_recvfrom,
    .setsockopt = cc3100_socket_setsockopt,
    .settimeout = cc3100_socket_settimeout,
    .ioctl = cc3100_socket_ioctl,
};
