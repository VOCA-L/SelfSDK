#include "utility/crc/include/crc8.h"
#include "utility/crc/include/crc-def.h"

#include <stdbool.h>
#include <string.h>

#ifdef INCLUDE_USING_LUT
static void createLookupTable(CRC8_t* ctx) {
    byte_t x;
    for (int i = 0; i < 256; i++) {
        x = (byte_t)i;
        for (int j = 0; j < 8; j++) {
            x = (x & 0x80) ? ((x << 1) ^ ctx->polynomial) : (x << 1);
        }
        ctx->lut_crc[i] = x;
    }
}
#endif

void setCRC8(CRC8_t* ctx, byte_t polynomial, byte_t init_value,
             bool reflect_input, bool reflect_output, byte_t xor_output) {
    if (ctx == NULL) return;

    ctx->polynomial     = polynomial;
    ctx->init_value     = init_value;
    ctx->reflect_input  = reflect_input;
    ctx->reflect_output = reflect_output;
    ctx->xor_output     = xor_output;

#ifdef INCLUDE_USING_LUT
    createLookupTable(ctx);
#endif
}

void setCRC8Type(CRC8_t *ctx, enum CRC8Type_t type) {
    switch (type) {
        /* 대표적인 CRC8 알고리즘 예시입니다. 
           crc-def.h에 정의된 매크로 이름에 맞게 수정하여 사용하세요. */
        case CRC8_TYPE_AUTOSAR:
            setCRC8(ctx, CRC8_POLY_AUTOSAR, CRC8_INIT_AUTOSAR, false, false, 0x00);
            break;
        case CRC8_TYPE_BLUETOOTH:
            setCRC8(ctx, CRC8_POLY_BLUETOOTH, CRC8_INIT_BLUETOOTH, true, true, 0x00);
            break;
        case CRC8_TYPE_CDMA2000:
            setCRC8(ctx, CRC8_POLY_CDMA2000, CRC8_INIT_CDMA2000, false, false, 0x00);
            break;
        case CRC8_TYPE_DARC:
            setCRC8(ctx, CRC8_POLY_DARC, CRC8_INIT_DARC, true, true, 0x00);
            break;
        case CRC8_TYPE_DVB_S2:
            setCRC8(ctx, CRC8_POLY_DVB_S2, CRC8_INIT_DVB_S2, false, false, 0x00);
            break;
        case CRC8_TYPE_GSM_A:
            setCRC8(ctx, CRC8_POLY_GSM_A, CRC8_INIT_GSM_A, false, false, 0x00);
            break;
        case CRC8_TYPE_GSM_B:
            setCRC8(ctx, CRC8_POLY_GSM_B, CRC8_INIT_GSM_B, false, false, 0x00);
            break;
        case CRC8_TYPE_HITAG:
            setCRC8(ctx, CRC8_POLY_HITAG, CRC8_INIT_HITAG, false, false, 0x00);
            break;
        case CRC8_TYPE_I_432_1:
            setCRC8(ctx, CRC8_POLY_I_432_1, CRC8_INIT_I_432_1, false, false, 0x00);
            break;
        case CRC8_TYPE_I_CODE:
            setCRC8(ctx, CRC8_POLY_I_CODE, CRC8_INIT_I_CODE, false, false, 0x00);
            break;
        case CRC8_TYPE_LTE:
            setCRC8(ctx, CRC8_POLY_LTE, CRC8_INIT_LTE, false, false, 0x00);
            break;
        case CRC8_TYPE_MAXIM_DOW:
            setCRC8(ctx, CRC8_POLY_MAXIM_DOW, CRC8_INIT_MAXIM_DOW, false, false, 0x00);
            break;
        case CRC8_TYPE_MIFARE_MAD:
            setCRC8(ctx, CRC8_POLY_MIFARE_MAD, CRC8_INIT_MIFARE_MAD, false, false, 0x00);
            break;
        case CRC8_TYPE_NRSC_5:
            setCRC8(ctx, CRC8_POLY_NRSC_5, CRC8_INIT_NRSC_5, false, false, 0x00);
            break;
        case CRC8_TYPE_OPENSAFETY:
            setCRC8(ctx, CRC8_POLY_OPENSAFETY, CRC8_INIT_OPENSAFETY, false, false, 0x00);
            break;
        case CRC8_TYPE_ROHC:
            setCRC8(ctx, CRC8_POLY_ROHC, CRC8_INIT_ROHC, true, true, 0x00);
            break;
        case CRC8_TYPE_SAE_J1850:
            setCRC8(ctx, CRC8_POLY_SAE_J1850, CRC8_INIT_SAE_J1850,false,false , 0x00);
            break;
        case CRC8_TYPE_SMBUS:
            setCRC8(ctx,CRC8_POLY_SMBUS,CRC8_INIT_SMBUS,false,false , 0x00);
            break;
        case CRC8_TYPE_TECH_3250:
            setCRC8(ctx,CRC8_POLY_TECH_3250,CRC8_INIT_TECH_3250,false,false , 0x00);
            break;
        case CRC8_TYPE_WCDMA:
            setCRC8(ctx,CRC8_POLY_WCDMA,CRC8_INIT_WCDMA,false,false , 0x00);
            break;
        default:
            break;
    }
}

/* 핵심 CRC 계산 로직 */
byte_t calculateCRC8(CRC8_t* ctx, const byte_t* data, size_t length) {
    if (ctx == NULL || data == NULL) return 0;

    byte_t crc = ctx->init_value;

#ifdef INCLUDE_USING_LUT
    for (size_t i = 0; i < length; i++) {
        byte_t byte = ctx->reflect_input ? REFLECT_BIT_ORDER_TABLE[data[i]] : data[i];
        crc = ctx->lut_crc[(crc ^ byte) & 0xFF];
    }
#else
    for (size_t i = 0; i < length; i++) {
        byte_t byte = ctx->reflect_input ? REFLECT_BIT_ORDER_TABLE[data[i]] : data[i];
        crc ^= byte;
        for (int j = 0; j < 8; j++) {
            crc = (crc & 0x80) ? ((crc << 1) ^ ctx->polynomial) : (crc << 1);
        }
    }
#endif

    if (ctx->reflect_output) {
        crc = reflectCRC8(crc);
    }

    crc = (crc ^ ctx->xor_output) & 0xFF;
    return crc;
}

/* 문자열용 편리한 래퍼 함수 */
byte_t calculateCRC8String(CRC8_t* ctx, const char* string) {
    if (ctx == NULL || string == NULL) return 0;
    return calculateCRC8(ctx, (const byte_t*)string, strlen(string));
}

byte_t reflectCRC8(byte_t value) {
    byte_t reflected = 0;
    for (int i = 0; i < 8; i++) {
        if (value & 0x01) {
            reflected |= (1 << ((8 - 1) - i));
        }
        value = (value >> 1);
    }
    return reflected;
}