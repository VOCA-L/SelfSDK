#ifndef SELF_SDK_CRC16_H
#define SELF_SDK_CRC16_H

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

typedef struct CRC16 {
  word_t polynomial;   /// The polynomial used for CRC calculation
  word_t init_value;   /// The initial value for the CRC calculation
  bool reflect_input;  /// Whether to reflect input bits
  bool reflect_output; /// Whether to reflect output bits
  word_t xor_output;   /// The value to XOR with the final CRC result

#ifdef INCLUDE_USING_LUT
  word_t lut_crc[256]; // Lookup Table for faster CRC calculation
#endif
} CRC16_t;

/**
 * @brief Set up the CRC16 context with the specified parameters.
 *
 * @param ctx Context structure to be initialized
 * @param polynomial The polynomial to be used for CRC calculation
 * @param init_value The initial value for the CRC calculation
 * @param reflect_input Whether to reflect input bits
 * @param reflect_output Whether to reflect output bits
 * @param xor_output The value to XOR with the final CRC result
 */
void setCRC16(CRC16_t *ctx, word_t polynomial, word_t init_value,
              bool reflect_input, bool reflect_output, word_t xor_output);

/**
 * @brief Set up the CRC16 context based on a predefined CRC16 type.
 * 
 * @param ctx Context structure to be initialized
 * @param type The predefined CRC16 type to be used for initialization
 */
void setCRC16Type(CRC16_t *ctx, enum CRC16Type_t type);

/**
 * @brief Calculate the CRC16 value for a given data buffer.
 *
 * @param ctx The CRC16 context structure
 * @param data The data buffer to calculate CRC for
 * @param length The length of the data buffer in bytes
 * @return word_t The calculated CRC16 value
 */
word_t calculateCRC16(CRC16_t *ctx, const byte_t *data, size_t length);

/**
 * @brief Calculate the CRC16 value for a null-terminated string.
 *
 * @param ctx The CRC16 context structure
 * @param string The null-terminated string to calculate CRC for
 * @return word_t The calculated CRC16 value
 */
word_t calculateCRC16String(CRC16_t *ctx, const char *string);

/**
 * @brief Reflect the bits of a 16-bit value for CRC calculation.
 *
 * @param value The 16-bit value to be reflected
 * @return word_t The reflected 16-bit value
 */
word_t reflectCRC16(word_t value);

#ifdef __cplusplus
}
#endif

#endif // SELF_SDK_CRC16_H