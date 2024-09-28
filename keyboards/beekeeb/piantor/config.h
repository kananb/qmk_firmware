// Copyright 2022 beekeeb
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once


#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1000U

#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP0
#define SERIAL_USART_RX_PIN GP1

#define CAPS_WORD_INVERT_ON_SHIFT
#define CAPS_WORD_IDLE_TIMEOUT 0

#define LEADER_PER_KEY_TIMING
#define PERMISSIVE_HOLD
#define TAPPING_TERM_PER_KEY
#define QUICK_TAP_TERM_PER_KEY
#define RETRO_TAPPING_PER_KEY

#define LEADER_TIMEOUT 250
#define TAPPING_TERM 185
#define QUICK_TAP_TERM 150
#define COMBO_TERM 55

#define DYNAMIC_MACRO_NO_NESTING
#define MAX_DEFERRED_EXECUTORS 10
#define DUMMY_MOD_NEUTRALIZER_KEYCODE KC_RIGHT_CTRL
