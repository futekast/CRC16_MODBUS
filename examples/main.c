//------------------------------------------------------------------------------
// SPDX-License-Identifier: MIT
// Copyright (c) 2026 FUTEK Advanced Sensor Technology, Inc.
//
// This file provides example validation for the CRC-16/MODBUS implementation.
//------------------------------------------------------------------------------

#include <stdint.h>
#include <stdio.h>

#include "crc16_modbus.h"

#define _CRC16_MODBUS_ASCII_CHECK_INPUT()                    ("123456789")
#define _CRC16_MODBUS_ASCII_CHECK_INPUT_LENGTH()             (9u)
#define _CRC16_MODBUS_ASCII_EXPECTED_RESULT()                (0x4B37u)

#define _CRC16_MODBUS_HEX_CHECK_INPUT_LENGTH()               (5u)
#define _CRC16_MODBUS_HEX_EXPECTED_RESULT()                  (0x2590u)

#define _CRC16_MODBUS_REVERSE_ASCII_CHECK_INPUT()            ("987654321")
#define _CRC16_MODBUS_REVERSE_ASCII_CHECK_INPUT_LENGTH()     (9u)
#define _CRC16_MODBUS_REVERSE_ASCII_EXPECTED_RESULT()        (0xC9D3u)

#define _CRC16_MODBUS_REVERSE_HEX_CHECK_INPUT_LENGTH()       (5u)
#define _CRC16_MODBUS_REVERSE_HEX_EXPECTED_RESULT()          (0x7C96u)

static const uint8_t crc16ModbusHexCheckInput[] = {
    0x12u,
    0x34u,
    0x56u,
    0x78u,
    0x09u
};

static const uint8_t crc16ModbusReverseHexCheckInput[] = {
    0x09u,
    0x78u,
    0x56u,
    0x34u,
    0x12u
};

//------------------------------------------------------------------------------
// Function Name: Main
// Description: This function validates the CRC-16/MODBUS bitwise and table-based
//              calculation methods using standard and reverse-order check values.
// Parameters: None
// Returns: 0 if all checks pass, otherwise 1
//------------------------------------------------------------------------------
int main(void) {
    uint16_t asciiBitwiseCrcValue;
    uint16_t asciiTableCrcValue;
    uint16_t hexBitwiseCrcValue;
    uint16_t hexTableCrcValue;
    uint16_t reverseAsciiBitwiseCrcValue;
    uint16_t reverseAsciiTableCrcValue;
    uint16_t reverseHexBitwiseCrcValue;
    uint16_t reverseHexTableCrcValue;
    uint8_t checkResult;

    asciiBitwiseCrcValue = calculateCrc16ModbusBitwise(
        (const uint8_t *)_CRC16_MODBUS_ASCII_CHECK_INPUT(),
        _CRC16_MODBUS_ASCII_CHECK_INPUT_LENGTH()
    );

    asciiTableCrcValue = calculateCrc16ModbusTable(
        (const uint8_t *)_CRC16_MODBUS_ASCII_CHECK_INPUT(),
        _CRC16_MODBUS_ASCII_CHECK_INPUT_LENGTH()
    );

    hexBitwiseCrcValue = calculateCrc16ModbusBitwise(
        crc16ModbusHexCheckInput,
        _CRC16_MODBUS_HEX_CHECK_INPUT_LENGTH()
    );

    hexTableCrcValue = calculateCrc16ModbusTable(
        crc16ModbusHexCheckInput,
        _CRC16_MODBUS_HEX_CHECK_INPUT_LENGTH()
    );

    reverseAsciiBitwiseCrcValue = calculateCrc16ModbusBitwise(
        (const uint8_t *)_CRC16_MODBUS_REVERSE_ASCII_CHECK_INPUT(),
        _CRC16_MODBUS_REVERSE_ASCII_CHECK_INPUT_LENGTH()
    );

    reverseAsciiTableCrcValue = calculateCrc16ModbusTable(
        (const uint8_t *)_CRC16_MODBUS_REVERSE_ASCII_CHECK_INPUT(),
        _CRC16_MODBUS_REVERSE_ASCII_CHECK_INPUT_LENGTH()
    );

    reverseHexBitwiseCrcValue = calculateCrc16ModbusBitwise(
        crc16ModbusReverseHexCheckInput,
        _CRC16_MODBUS_REVERSE_HEX_CHECK_INPUT_LENGTH()
    );

    reverseHexTableCrcValue = calculateCrc16ModbusTable(
        crc16ModbusReverseHexCheckInput,
        _CRC16_MODBUS_REVERSE_HEX_CHECK_INPUT_LENGTH()
    );

    if ((asciiBitwiseCrcValue == _CRC16_MODBUS_ASCII_EXPECTED_RESULT())
        && (asciiTableCrcValue == _CRC16_MODBUS_ASCII_EXPECTED_RESULT())
        && (hexBitwiseCrcValue == _CRC16_MODBUS_HEX_EXPECTED_RESULT())
        && (hexTableCrcValue == _CRC16_MODBUS_HEX_EXPECTED_RESULT())
        && (reverseAsciiBitwiseCrcValue == _CRC16_MODBUS_REVERSE_ASCII_EXPECTED_RESULT())
        && (reverseAsciiTableCrcValue == _CRC16_MODBUS_REVERSE_ASCII_EXPECTED_RESULT())
        && (reverseHexBitwiseCrcValue == _CRC16_MODBUS_REVERSE_HEX_EXPECTED_RESULT())
        && (reverseHexTableCrcValue == _CRC16_MODBUS_REVERSE_HEX_EXPECTED_RESULT())) {
        checkResult = 1u;
    } else {
        checkResult = 0u;
    }

    printf("CRC-16/MODBUS ASCII Bitwise Result:         0x%04X Expected: 0x%04X\n",
           asciiBitwiseCrcValue,
           _CRC16_MODBUS_ASCII_EXPECTED_RESULT());

    printf("CRC-16/MODBUS ASCII Table Result:           0x%04X Expected: 0x%04X\n",
           asciiTableCrcValue,
           _CRC16_MODBUS_ASCII_EXPECTED_RESULT());

    printf("CRC-16/MODBUS HEX Bitwise Result:           0x%04X Expected: 0x%04X\n",
           hexBitwiseCrcValue,
           _CRC16_MODBUS_HEX_EXPECTED_RESULT());

    printf("CRC-16/MODBUS HEX Table Result:             0x%04X Expected: 0x%04X\n",
           hexTableCrcValue,
           _CRC16_MODBUS_HEX_EXPECTED_RESULT());

    printf("CRC-16/MODBUS Reverse ASCII Bitwise Result: 0x%04X Expected: 0x%04X\n",
           reverseAsciiBitwiseCrcValue,
           _CRC16_MODBUS_REVERSE_ASCII_EXPECTED_RESULT());

    printf("CRC-16/MODBUS Reverse ASCII Table Result:   0x%04X Expected: 0x%04X\n",
           reverseAsciiTableCrcValue,
           _CRC16_MODBUS_REVERSE_ASCII_EXPECTED_RESULT());

    printf("CRC-16/MODBUS Reverse HEX Bitwise Result:   0x%04X Expected: 0x%04X\n",
           reverseHexBitwiseCrcValue,
           _CRC16_MODBUS_REVERSE_HEX_EXPECTED_RESULT());

    printf("CRC-16/MODBUS Reverse HEX Table Result:     0x%04X Expected: 0x%04X\n",
           reverseHexTableCrcValue,
           _CRC16_MODBUS_REVERSE_HEX_EXPECTED_RESULT());

    printf("CRC-16/MODBUS Status: %s\n",
           (checkResult == 1u) ? "PASS" : "FAIL");

    return (checkResult == 1u) ? 0 : 1;
}