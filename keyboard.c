#include "keyboard.h"

uint8_t last_keycode = 0;

void _keyboard_int(int keycode) {
    last_keycode = keycode;
    hexes_write_char(get_last_key(), 0, 2);
}

uint8_t key_translate[] = {
    0x00, 0x00, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, // 0x00
    0x37, 0x38, 0x39, 0x30, 0x2D, 0x3D, 0x7F, 0x09, // 0x08
    0x71, 0x77, 0x65, 0x72, 0x74, 0x79, 0x75, 0x69, // 0x10
    0x6F, 0x70, 0x00, 0x00, 0x0A, 0x00, 0x61, 0x73, // 0x18
    0x64, 0x66, 0x67, 0x68, 0x6A, 0x6B, 0x6C, 0x00, // 0x20
    0x00, 0x00, 0x00, 0x00, 0x7A, 0x78, 0x63, 0x76, // 0x28
    0x62, 0x6E, 0x6D, 0x00, 0x2E, 0x2F, 0x00, 0x00, // 0x30
    0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00  // 0x38
};

uint8_t get_last_key() {
    if (last_keycode < 0xFF) {
        return key_translate[last_keycode];
    } else {
        return 0x00;
    }
}