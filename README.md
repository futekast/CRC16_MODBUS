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

Reverse ASCII Check: `"987654321"` -> `0xC9D3`

Reverse HEX Check: `0x09 0x78 0x56 0x34 0x12` -> `0x7C96`

Both bitwise and table-based functions are validated against the same expected results.

## Byte-Order Note

CRC-16/MODBUS is calculated over the byte order provided to the function.

If a protocol displays bytes in one order but defines CRC calculation over the reverse order, the input buffer must be arranged in the protocol-defined CRC order before calling the CRC function.

Example:

Displayed HEX input:

```text
0x12 0x34 0x56 0x78 0x09