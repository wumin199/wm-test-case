/*
 * Copyright (c) MinWu - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 * Author: MinWu <wumin199@126.com>
 */

#include <iostream>

using byte = uint8_t;

using usigned_word = uint16_t;
using signed_word = int16_t;
using usigned_dword = uint32_t;
using signed_dword = int32_t;

typedef byte *pbyte;

#ifndef HEXDUMP_COLS
#define HEXDUMP_COLS 16
#endif
void hexdump(void *mem, unsigned int len) {
  unsigned int i, j;

  for (i = 0;
       i <
       len + ((len % HEXDUMP_COLS) ? (HEXDUMP_COLS - len % HEXDUMP_COLS) : 0);
       i++) {
    /* print offset */
    if (i % HEXDUMP_COLS == 0) {
      printf("0x%04x: ", i);
    }

    /* print hex data */
    if (i < len) {
      printf("%02x ", 0xFF & ((char *)mem)[i]);
    } else /* end of block, just aligning for ASCII dump */
    {
      printf("   ");
    }

    /* print ASCII dump */
    if (i % HEXDUMP_COLS == (HEXDUMP_COLS - 1)) {
      for (j = i - (HEXDUMP_COLS - 1); j <= i; j++) {
        if (j >= len) /* end of block, not really printing */
        {
          putchar(' ');
        } else if (isprint((((char *)mem)[j] & 0x7F))) /* printable char */
        {
          putchar(0xFF & ((char *)mem)[j]);
        } else /* other char */
        {
          putchar('.');
        }
      }
      putchar('\n');
    }
  }
}

usigned_word get_word(byte *buffer, int pos) {}

int main(int argc, char *argv[]) {
  byte MB[16];         // 16 Merker bytes
  byte EB[16];         // 16 Digital Input bytes
  byte AB[16];         // 16 Digital Output bytes
  usigned_word TM[8];  // 8 timers
  usigned_word CT[8];  // 8 counters

  byte DB[10];
  DB[0] = 10;
  DB[1] = 11;
  DB[2] = 12;
  DB[3] = 13;
  DB[4] = 14;
  DB[5] = 15;
  DB[6] = 16;
  DB[7] = 17;
  DB[8] = 18;
  DB[9] = 19;
  hexdump(&DB[0], 10);
}
