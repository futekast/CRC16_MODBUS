# CRC16_MODBUS

Reusable C implementation of CRC-16/MODBUS.

## Files

- `include/crc16_modbus.h`
- `src/crc16_modbus.c`
- `examples/main.c`

## CRC Parameters

| Parameter | Value |
|---|---:|
| Name | CRC-16/MODBUS |
| Polynomial | 0x8005 |
| Reflected Polynomial | 0xA001 |
| Initial Value | 0xFFFF |
| Input Reflected | Yes |
| Output Reflected | Yes |
| Final XOR | 0x0000 |

## Validation

ASCII Check: `"123456789"` -> `0x4B37`

HEX Check: `0x12 0x34 0x56 0x78 0x09` -> `0x2590`

Both bitwise and table-based functions are validated against the same expected results.
