#include "sdk-def.h"
#include "utility/crc/include/crc-def.h"
#include "utility/crc/include/crc16.h"
#include "utility/crc/include/crc8.h"

#include <stdio.h>

int main() {
  byte_t data[] = {0x01, 0x02, 0x03, 0x04, 0x05};

  /* CRC8 Test Logic */
  CRC8_t autosar_crc8_ctx;
  setCRC8(&autosar_crc8_ctx, CRC8_POLY_AUTOSAR, CRC8_INIT_AUTOSAR, false, false,
          0x00);
  byte_t crc8 = calculateCRC8(&autosar_crc8_ctx, data, sizeof(data));

  printf("CRC8 (AUTOSAR): 0x%02X\n", crc8);

  /* CRC16 Test Logic */
  CRC16_t xmodem_crc16_ctx;
  setCRC16(&xmodem_crc16_ctx, CRC16_POLY_XMODEM, 0x0000, false, false, 0x0000);

  word_t crc = calculateCRC16(&xmodem_crc16_ctx, data, sizeof(data));

  printf("CRC16 (XMODEM): 0x%04X\n", crc);

  return 0;
}