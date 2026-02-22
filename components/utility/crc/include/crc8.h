#ifndef SELF_SDK_CRC8_H
#define SELF_SDK_CRC8_H

#include "sdk-def.h"
#include "crc-def.h"

#include <stdbool.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

// Using Lookup Table for faster CRC calculation 
// (optional, can be disabled to save memory)
#define INCLUDE_USING_LUT

typedef struct CRC8 {
  byte_t polynomial;   /// The polynomial used for CRC calculation
  byte_t init_value;   /// The initial value for the CRC calculation
  bool reflect_input;  /// Whether to reflect input bits
  bool reflect_output; /// Whether to reflect output bits
  byte_t xor_output;   /// The value to XOR with the final CRC result

#ifdef INCLUDE_USING_LUT
  byte_t lut_crc[256]; // Lookup Table for faster CRC calculation
#endif
} CRC8_t;

/**
 * @brief Set up the CRC8 context with the specified parameters.
 *
 * @param ctx Context structure to be initialized
 * @param polynomial The polynomial to be used for CRC calculation
 * @param init_value The initial value for the CRC calculation
 * @param reflect_input Whether to reflect input bits
 * @param reflect_output Whether to reflect output bits
 * @param xor_output The value to XOR with the final CRC result
 */
void setCRC8(CRC8_t *ctx, byte_t polynomial, byte_t init_value,
             bool reflect_input, bool reflect_output, byte_t xor_output);

/**
 * @brief Set up the CRC8 context based on a predefined CRC8 type.
 * * @param ctx Context structure to be initialized
 * @param type The predefined CRC8 type to be used for initialization
 */
void setCRC8Type(CRC8_t *ctx, enum CRC8Type_t type);

/**
 * @brief Calculate the CRC8 value for a given data buffer.
 *
 * @param ctx The CRC8 context structure
 * @param data The data buffer to calculate CRC for
 * @param length The length of the data buffer in bytes
 * @return byte_t The calculated CRC8 value
 */
byte_t calculateCRC8(CRC8_t *ctx, const byte_t *data, size_t length);

/**
 * @brief Calculate the CRC8 value for a null-terminated string.
 *
 * @param ctx The CRC8 context structure
 * @param string The null-terminated string to calculate CRC for
 * @return byte_t The calculated CRC8 value
 */
byte_t calculateCRC8String(CRC8_t *ctx, const char *string);

/**
 * @brief Reflect the bits of an 8-bit value for CRC calculation.
 *
 * @param value The 8-bit value to be reflected
 * @return byte_t The reflected 8-bit value
 */
byte_t reflectCRC8(byte_t value);

#ifdef __cplusplus
}
#endif

#endif // SELF_SDK_CRC8_H