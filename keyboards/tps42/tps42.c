// Copyright 2021 Christoph Rehmann (crehmann)
// SPDX-License-Identifier: GPL-2.0-or-later
#include "tps42.h"

#ifdef SWAP_HANDS_ENABLE
// clang-format off
__attribute__ ((weak)) const keypos_t PROGMEM hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
    {{0, 4}, {1, 4}, {2, 4}, {3, 4}, {4, 4}, {5, 4},
    {{0, 5}, {1, 5}, {2, 5}, {3, 5}, {4, 5}, {5, 5},
    {{0, 6}, {1, 6}, {2, 6}, {3, 6}, {4, 6}, {5, 6},
    {{0, 7}, {1, 7}, {2, 7}, {3, 7}, {4, 7}, {5, 7},
    {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0},
    {{0, 1}, {1, 1}, {2, 1}, {3, 1}, {4, 1}, {5, 1},
    {{0, 2}, {1, 2}, {2, 2}, {3, 2}, {4, 2}, {5, 2},
    {{0, 3}, {1, 3}, {2, 3}, {3, 3}, {4, 3}, {5, 3}
};
// clang-format on
#endif

#ifdef PS2_MOUSE_ENABLE
    #include "ps2_mouse.h"
    #include "ps2.h"
#endif

#ifdef PS2_MOUSE_ENABLE
void ps2_mouse_init_user() {
    uint8_t rcv;

    // see p24 https://blogs.epfl.ch/icenet/documents/Ykt3Eext.pdf

    // set TrackPoint sensitivity
    PS2_MOUSE_SEND(0xE2, "tpsens: 0xE2");
    PS2_MOUSE_SEND(0x81, "tpsens: 0x81");
    PS2_MOUSE_SEND(0x4A, "tpsens: 0x4A");
    PS2_MOUSE_SEND(0x49, "tpsens: 0x80");

    // set TrackPoint Negative Inertia factor
    PS2_MOUSE_SEND(0xE2, "tpnegin: 0xE2");
    PS2_MOUSE_SEND(0x81, "tpnegin: 0x81");
    PS2_MOUSE_SEND(0x4D, "tpnegin: 0x4D");
    PS2_MOUSE_SEND(0x06, "tpnegin: 0x06");

    // set TrackPoint speed
    // (transfer function upper plateau speed)
    PS2_MOUSE_SEND(0xE2, "tpsp: 0xE2");
    PS2_MOUSE_SEND(0x81, "tpsp: 0x81");
    PS2_MOUSE_SEND(0x60, "tpsp: 0x60");
    PS2_MOUSE_SEND(0x61, "tpsp: 0x61");

    // inquire pts status
    rcv = ps2_host_send(0xE2);
    rcv = ps2_host_send(0x2C);
    rcv = ps2_host_recv_response();
    if ((rcv & 1) == 1) {
    // if on, disable pts
    rcv = ps2_host_send(0xE2);
    rcv = ps2_host_send(0x47);
    rcv = ps2_host_send(0x2C);
    rcv = ps2_host_send(0x01);
    }

}
#endif
