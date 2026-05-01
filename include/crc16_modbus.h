#ifndef CRC16_MODBUS_H
#define CRC16_MODBUS_H

//------------------------------------------------------------------------------
// SPDX-License-Identifier: MIT
// Copyright (c) 2026 FUTEK Advanced Sensor Technology, Inc.
//
// This implementation is based on publicly documented CRC-16/MODBUS mathematical
// definitions. No third-party proprietary source code was used.
//------------------------------------------------------------------------------

#include <stddef.h>
#include <stdint.h>

#define _CRC16_MODBUS_POLYNOMIAL()              (0x8005u)
#define _CRC16_MODBUS_REFLECTED_POLYNOMIAL()    (0xA001u)
#define _CRC16_MODBUS_INITIAL_VALUE()           (0xFFFFu)
#define _CRC16_MODBUS_FINAL_XOR_VALUE()         (0x0000u)

//------------------------------------------------------------------------------
// Function Name: Initialize CRC16 MODBUS
// Description: This function returns the initial CRC-16/MODBUS value.
// Parameters: None
// Returns: Initial CRC-16/MODBUS value
//------------------------------------------------------------------------------
uint16_t initializeCrc16Modbus(void);

//------------------------------------------------------------------------------
// Function Name: Update CRC16 MODBUS Bitwise
// Description: This function updates a running CRC-16/MODBUS value with one byte
//              using the bitwise calculation method.
// Parameters:
//  crcValue - Current CRC-16/MODBUS value
//  dataByte - Input data byte
// Returns: Updated CRC-16/MODBUS value
//------------------------------------------------------------------------------
uint16_t updateCrc16ModbusBitwise(uint16_t crcValue, uint8_t dataByte);

//------------------------------------------------------------------------------
// Function Name: Update CRC16 MODBUS Table
// Description: This function updates a running CRC-16/MODBUS value with one byte
//              using the lookup table calculation method.
// Parameters:
//  crcValue - Current CRC-16/MODBUS value
//  dataByte - Input data byte
// Returns: Updated CRC-16/MODBUS value
//------------------------------------------------------------------------------
uint16_t updateCrc16ModbusTable(uint16_t crcValue, uint8_t dataByte);

//------------------------------------------------------------------------------
// Function Name: Calculate CRC16 MODBUS Bitwise
// Description: This function calculates CRC-16/MODBUS over a data buffer using
//              the bitwise calculation method.
// Parameters:
//  pData - Pointer to input data buffer
//  dataLength - Number of bytes in the input data buffer
// Returns: Calculated CRC-16/MODBUS value
//------------------------------------------------------------------------------
uint16_t calculateCrc16ModbusBitwise(const uint8_t *pData, size_t dataLength);

//------------------------------------------------------------------------------
// Function Name: Calculate CRC16 MODBUS Table
// Description: This function calculates CRC-16/MODBUS over a data buffer using
//              the lookup table calculation method.
// Parameters:
//  pData - Pointer to input data buffer
//  dataLength - Number of bytes in the input data buffer
// Returns: Calculated CRC-16/MODBUS value
//------------------------------------------------------------------------------
uint16_t calculateCrc16ModbusTable(const uint8_t *pData, size_t dataLength);

#endif