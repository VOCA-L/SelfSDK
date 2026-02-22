#include "utility/crc/include/crc16.h"
#include "utility/crc/include/crc-def.h"

#include <stdbool.h>
#include <string.h>

#ifdef INCLUDE_USING_LUT
static void crateLookupTable(CRC16_t* ctx) {
    word_t x;
    for (word_t i = 0; i < 256; i++) {
        x = i << 8;
        for (int j = 0; j < 8; j++) {
            x = (x & 0x8000) ? ((x << 1) ^ ctx->polynomial) : (x << 1);
        }
        ctx->lut_crc[i] = x;
    }
}
#endif

void setCRC16(CRC16_t* ctx, word_t polynomial, word_t init_value,
                bool reflect_input, bool reflect_output, word_t xor_output) {
    if (ctx == NULL) return;

    ctx->polynomial     = polynomial;
    ctx->init_value     = init_value;
    ctx->reflect_input  = reflect_input;
    ctx->reflect_output = reflect_output;
    ctx->xor_output     = xor_output;

#ifdef INCLUDE_USING_LUT
    crateLookupTable(ctx);
#endif
}

void setCRC16Type(CRC16_t *ctx, enum CRC16Type_t type) {
    switch (type) {
        case CRC16_TYPE_ARC:
            setCRC16(ctx, CRC16_POLY_ARC, CRC16_INIT_ARC, true, true, 0x0000);
            break;
        case CRC16_TYPE_CCITT_FALSE:
            setCRC16(ctx, CRC16_POLY_CCITT_FALSE, CRC16_INIT_CCITT_FALSE, false, false, 0x0000);
            break;
        case CRC16_TYPE_AUG_CCITT:
            setCRC16(ctx, CRC16_POLY_AUG_CCITT, CRC16_INIT_AUG_CCITT, false, false, 0x0000);
            break;
        case CRC16_TYPE_BUYPASS:
            setCRC16(ctx, CRC16_POLY_BUYPASS, CRC16_INIT_BUYPASS, false, false, 0x0000);
            break;
        case CRC16_TYPE_CDMA2000:
            setCRC16(ctx, CRC16_POLY_CDMA2000, CRC16_INIT_CDMA2000, false, false, 0x0000);
            break;
        case CRC16_TYPE_DDS_110:
            setCRC16(ctx, CRC16_POLY_DDS_110, CRC16_INIT_DDS_110, false, false, 0x0000);
            break;
        case CRC16_TYPE_DECT_R:
            setCRC16(ctx, CRC16_POLY_DECT_R, CRC16_INIT_DECT_R, false, false, 0x0001);
            break;
        case CRC16_TYPE_DECT_X:
            setCRC16(ctx, CRC16_POLY_DECT_X, CRC16_INIT_DECT_X, false, false, 0x0001);
            break;
        case CRC16_TYPE_DNP:
            setCRC16(ctx, CRC16_POLY_DNP, CRC16_INIT_DNP, true, true, 0xFFFF);
            break;
        case CRC16_TYPE_EN_13757:
            setCRC16(ctx, CRC16_POLY_EN_13757, CRC16_INIT_EN_13757, true, true, 0xFFFF);
            break;
        case CRC16_TYPE_GENIBUS:
            setCRC16(ctx, CRC16_POLY_GENIBUS, CRC16_INIT_GENIBUS, false, false, 0x0000);
            break;
        case CRC16_TYPE_MAXIM:
            setCRC16(ctx, CRC16_POLY_MAXIM, CRC16_INIT_MAXIM, true, true, 0xFFFF);
            break;
        case CRC16_TYPE_MCRF4XX:
            setCRC16(ctx, CRC16_POLY_MCRF4XX, CRC16_INIT_MCRF4XX, false, false, 0x0000);
            break;
        case CRC16_TYPE_RIELLO:
            setCRC16(ctx, CRC16_POLY_RIELLO, CRC16_INIT_RIELLO, true, true, 0x0000);
            break;
        case CRC16_TYPE_T10_DIF:
            setCRC16(ctx, CRC16_POLY_T10_DIF, CRC16_INIT_T10_DIF, false, false, 0x0000);
            break;
        case CRC16_TYPE_TELEDISK:
            setCRC16(ctx, CRC16_POLY_TELEDISK, CRC16_INIT_TELEDISK, false, false, 0x0000);
            break;
        case CRC16_TYPE_TMS37157:
            setCRC16(ctx, CRC16_POLY_TMS37157, CRC16_INIT_TMS37157, false, false, 0x89EC);
            break;
        case CRC16_TYPE_USB:
            setCRC16(ctx, CRC16_POLY_USB, CRC16_INIT_USB, true, true, 0xFFFF);
            break;
        case CRC16_TYPE_A:
            setCRC16(ctx, CRC16_POLY_A, CRC16_INIT_A, true, true, 0x0000);
            break;
        case CRC16_TYPE_KERMIT:
            setCRC16(ctx, CRC16_POLY_KERMIT, CRC16_INIT_KERMIT, true, true, 0x0000);
            break;
        case CRC16_TYPE_MODBUS:
            setCRC16(ctx, CRC16_POLY_MODBUS, CRC16_INIT_MODBUS, true, true, 0x0000);
            break;
        case CRC16_TYPE_X_25:
            setCRC16(ctx, CRC16_POLY_X_25, CRC16_INIT_X_25, true, true, 0xFFFF);
            break;
        case CRC16_TYPE_XMODEM:
            setCRC16(ctx, CRC16_POLY_XMODEM, CRC16_INIT_XMODEM, false, false, 0x0000);
            break;
        default:
            break;
    }
}

/* 핵심 CRC 계산 로직 */
word_t calculateCRC16(CRC16_t* ctx, const byte_t* data, size_t length) {
    if (ctx == NULL || data == NULL) return 0;

    word_t crc = ctx->init_value;

#ifdef INCLUDE_USING_LUT
    for (size_t i = 0; i < length; i++) {
        byte_t byte = ctx->reflect_input ? REFLECT_BIT_ORDER_TABLE[data[i]] : data[i];
        crc = (crc << 8) ^ ctx->lut_crc[((crc >> 8) ^ byte) & 0xFF];
    }
#else
    for (size_t i = 0; i < length; i++) {
        byte_t byte = ctx->reflect_input ? REFLECT_BIT_ORDER_TABLE[data[i]] : data[i];
        crc ^= (byte << 8);
        for (int j = 0; j < 8; j++) {
            crc = (crc & 0x8000) ? ((crc << 1) ^ ctx->polynomial) : (crc << 1);
        }
    }
#endif

    if (ctx->reflect_output) {
        crc = reflectCRC16(crc);
    }

    crc = (crc ^ ctx->xor_output) & 0xFFFF;
    return crc;
}

/* 문자열용 편리한 래퍼 함수 */
word_t calculateCRC16String(CRC16_t* ctx, const char* string) {
    if (ctx == NULL || string == NULL) return 0;
    return calculateCRC16(ctx, (const byte_t*)string, strlen(string));
}

word_t reflectCRC16(word_t value) {
    word_t reflected = 0;
    for (int i = 0; i < 16; i++) {
        if (value & 0x01) {
            reflected |= (1 << ((16 - 1) - i));
        }
        value = (value >> 1);
    }
    return reflected;
}
