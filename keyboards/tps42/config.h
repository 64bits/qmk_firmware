// Copyright 2021 Christoph Rehmann (crehmann)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "config_common.h"

#define MASTER_RIGHT

#ifdef PS2_MOUSE_ENABLE
#define PS2_MOUSE_SCROLL_BTN_MASK (1<<PS2_MOUSE_BTN_RIGHT)
#define PS2_MOUSE_SCROLL_BTN_SEND 500

#define PS2_MOUSE_X_MULTIPLIER 4
#define PS2_MOUSE_Y_MULTIPLIER 4
#define PS2_MOUSE_V_MULTIPLIER 3

#define PS2_MOUSE_SCROLL_DIVISOR_H 4
#define PS2_MOUSE_SCROLL_DIVISOR_V 4
#define PS2_MOUSE_ROTATE 90
#endif
