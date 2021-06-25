#ifndef __SGCPU_DATA_H__
#define __SGCPU_DATA_H__

#include <stdint.h>

typedef struct sg_instr_t sg_instr_t;

struct sg_instr_t
{
    const char *name;
    const char *arg;
    int chg_data, chg_code;
};

// Nothing!
#define SG_NOP (uint32_t)(0b000000000000000000000000)

// Conditionals(not part of the microcode itself, just for generation)
#define SG_FLG_AXZ (uint32_t)(0b100000000000000000000000)
#define SG_FLG_BXZ (uint32_t)(0b010000000000000000000000)
#define SG_FLG_AXN (uint32_t)(0b001000000000000000000000)
#define SG_FLG_BXN (uint32_t)(0b000100000000000000000000)
#define SG_FLG_CRY (uint32_t)(0b000010000000000000000000)
#define SG_FLG_ZRO (uint32_t)(0b000001000000000000000000)
#define SG_FLG_NCR (uint32_t)(0b000000100000000000000000)
#define SG_FLG_NZR (uint32_t)(0b000000010000000000000000)

// Affect on rising edge
#define SG_AXO (uint32_t)(0b000000000001000000000000)
#define SG_BXO (uint32_t)(0b000000000010000000000000)
#define SG_DXO (uint32_t)(0b000000000011000000000000)
#define SG_DHO (uint32_t)(0b000000000100000000000000)
#define SG_TXO (uint32_t)(0b000000000101000000000000)
#define SG_RXO (uint32_t)(0b000000000110000000000000)
#define SG_RHO (uint32_t)(0b000000000111000000000000)
#define SG_XIO (uint32_t)(0b000000001000000000000000)
#define SG_YIO (uint32_t)(0b000000001001000000000000)
#define SG_SPO (uint32_t)(0b000000001010000000000000)
#define SG_IPO (uint32_t)(0b000000001011000000000000)
#define SG_SW1 (uint32_t)(0b000000001100000000000000)
#define SG_SW2 (uint32_t)(0b000000001101000000000000)
#define SG_SW3 (uint32_t)(0b000000001110000000000000)
#define SG_SW4 (uint32_t)(0b000000001111000000000000)

// Affect on rising edge
#define SG_AXI (uint32_t)(0b000000000000000100000000)
#define SG_BXI (uint32_t)(0b000000000000001000000000)
#define SG_DXI (uint32_t)(0b000000000000001100000000)
#define SG_DHI (uint32_t)(0b000000000000010000000000)
#define SG_DLI (uint32_t)(0b000000000000010100000000)
#define SG_TXI (uint32_t)(0b000000000000011000000000)
#define SG_THI (uint32_t)(0b000000000000011100000000)
#define SG_TLI (uint32_t)(0b000000000000100000000000)
#define SG_RXI (uint32_t)(0b000000000000100100000000)
#define SG_RHI (uint32_t)(0b000000000000101000000000)
#define SG_RLI (uint32_t)(0b000000000000101100000000)
#define SG_XII (uint32_t)(0b000000000000110000000000)
#define SG_YII (uint32_t)(0b000000000000110100000000)
#define SG_SPI (uint32_t)(0b000000000000111000000000)
#define SG_IPI (uint32_t)(0b000000000000111100000000)

// Affect on rising edge
#define SG_WRI (uint32_t)(0b000000000000000010000000)
#define SG_REA (uint32_t)(0b000000000000000001000000)

// Affect on rising edge
#define SG_ADD (uint32_t)(0b000000000000000000001000)
#define SG_SUB (uint32_t)(0b000000000000000000010000)
#define SG_AND (uint32_t)(0b000000000000000000011000)
#define SG_ORR (uint32_t)(0b000000000000000000100000)
#define SG_XOR (uint32_t)(0b000000000000000000101000)
#define SG_SHR (uint32_t)(0b000000000000000000110000)
#define SG_NEG (uint32_t)(0b000000000000000000111000)

// Affect on falling edge
#define SG_DEX (uint32_t)(0b000000000000000000000001)
#define SG_DEY (uint32_t)(0b000000000000000000000010)
#define SG_DSP (uint32_t)(0b000000000000000000000011)
#define SG_INX (uint32_t)(0b000000000000000000000100)
#define SG_INY (uint32_t)(0b000000000000000000000101)
#define SG_ISP (uint32_t)(0b000000000000000000000110)
#define SG_IIP (uint32_t)(0b000000000000000000000111)

// Masks
#define SG_MSK_OUT (uint32_t)(0b000000001111000000000000)
#define SG_MSK_INP (uint32_t)(0b000000000000111100000000)
#define SG_MSK_ALU (uint32_t)(0b000000000000000000111000)
#define SG_MSK_INC (uint32_t)(0b000000000000000000000111)

// Instruction count
#define SG_CNT 0xC0

static const uint32_t sg_ucode_arr[] = {
    // 0x00: LDA $X
    SG_TXI | SG_IPO,
    SG_IPI | SG_XIO,
    SG_RLI | SG_REA | SG_IIP,
    SG_RHI | SG_REA,
    SG_IPI | SG_TXO,
    SG_AXI | SG_RXO | SG_IIP,
    SG_NOP,
    SG_NOP,

    // 0x01: LDB $X
    SG_TXI | SG_IPO,
    SG_IPI | SG_XIO,
    SG_RLI | SG_REA | SG_IIP,
    SG_RHI | SG_REA,
    SG_IPI | SG_TXO,
    SG_BXI | SG_RXO | SG_IIP,
    SG_NOP,
    SG_NOP,

    // 0x02: LDD $X
    SG_TXI | SG_IPO,
    SG_IPI | SG_XIO,
    SG_RLI | SG_REA | SG_IIP,
    SG_RHI | SG_REA,
    SG_IPI | SG_TXO,
    SG_DXI | SG_RXO | SG_IIP,
    SG_NOP,
    SG_NOP,

    // 0x03: LDX $X
    SG_TXI | SG_IPO,
    SG_IPI | SG_XIO,
    SG_RLI | SG_REA | SG_IIP,
    SG_RHI | SG_REA,
    SG_IPI | SG_TXO,
    SG_XII | SG_RXO | SG_IIP,
    SG_NOP,
    SG_NOP,

    // 0x04: LDY $X
    SG_TXI | SG_IPO,
    SG_IPI | SG_XIO,
    SG_RLI | SG_REA | SG_IIP,
    SG_RHI | SG_REA,
    SG_IPI | SG_TXO,
    SG_YII | SG_RXO | SG_IIP,
    SG_NOP,
    SG_NOP,

    // 0x05: LDH $X
    SG_TXI | SG_IPO,
    SG_IPI | SG_XIO,
    SG_DHI | SG_REA,
    SG_IPI | SG_TXO | SG_IIP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0x06: LDL $X
    SG_TXI | SG_IPO,
    SG_IPI | SG_XIO,
    SG_DLI | SG_REA,
    SG_IPI | SG_TXO | SG_IIP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0x07: LDS $X
    SG_TXI | SG_IPO,
    SG_IPI | SG_XIO,
    SG_RLI | SG_REA | SG_IIP,
    SG_RHI | SG_REA,
    SG_IPI | SG_TXO,
    SG_SPI | SG_RXO | SG_IIP,
    SG_NOP,
    SG_NOP,

    // 0x08: STA $X
    SG_TXI | SG_IPO,
    SG_IPI | SG_XIO,
    SG_RXI | SG_AXO,
    SG_WRI | SG_RXO | SG_IIP,
    SG_WRI | SG_RHO,
    SG_IPI | SG_TXO | SG_IIP,
    SG_NOP,
    SG_NOP,

    // 0x09: STB $X
    SG_TXI | SG_IPO,
    SG_IPI | SG_XIO,
    SG_RXI | SG_BXO,
    SG_WRI | SG_RXO | SG_IIP,
    SG_WRI | SG_RHO,
    SG_IPI | SG_TXO | SG_IIP,
    SG_NOP,
    SG_NOP,

    // 0x0A: STD $X
    SG_TXI | SG_IPO,
    SG_IPI | SG_XIO,
    SG_RXI | SG_DXO,
    SG_WRI | SG_RXO | SG_IIP,
    SG_WRI | SG_RHO,
    SG_IPI | SG_TXO | SG_IIP,
    SG_NOP,
    SG_NOP,

    // 0x0B: STX $X
    SG_TXI | SG_IPO,
    SG_IPI | SG_XIO,
    SG_RXI | SG_XIO,
    SG_WRI | SG_RXO | SG_IIP,
    SG_WRI | SG_RHO,
    SG_IPI | SG_TXO | SG_IIP,
    SG_NOP,
    SG_NOP,

    // 0x0C: STY $X
    SG_TXI | SG_IPO,
    SG_IPI | SG_XIO,
    SG_RXI | SG_YIO,
    SG_WRI | SG_RXO | SG_IIP,
    SG_WRI | SG_RHO,
    SG_IPI | SG_TXO | SG_IIP,
    SG_NOP,
    SG_NOP,

    // 0x0D: STH $X
    SG_TXI | SG_IPO,
    SG_IPI | SG_XIO,
    SG_WRI | SG_DHO,
    SG_IPI | SG_TXO | SG_IIP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0x0E: STL $X
    SG_TXI | SG_IPO,
    SG_IPI | SG_XIO,
    SG_WRI | SG_DXO,
    SG_IPI | SG_TXO | SG_IIP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0x0F: STZ $X
    SG_TXI | SG_IPO,
    SG_IPI | SG_XIO,
    SG_WRI,
    SG_IPI | SG_TXO | SG_IIP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0x10: LDA $Y
    SG_TXI | SG_IPO,
    SG_IPI | SG_YIO,
    SG_RLI | SG_REA | SG_IIP,
    SG_RHI | SG_REA,
    SG_IPI | SG_TXO,
    SG_AXI | SG_RXO | SG_IIP,
    SG_NOP,
    SG_NOP,

    // 0x11: LDB $Y
    SG_TXI | SG_IPO,
    SG_IPI | SG_YIO,
    SG_RLI | SG_REA | SG_IIP,
    SG_RHI | SG_REA,
    SG_IPI | SG_TXO,
    SG_BXI | SG_RXO | SG_IIP,
    SG_NOP,
    SG_NOP,

    // 0x12: LDD $Y
    SG_TXI | SG_IPO,
    SG_IPI | SG_YIO,
    SG_RLI | SG_REA | SG_IIP,
    SG_RHI | SG_REA,
    SG_IPI | SG_TXO,
    SG_DXI | SG_RXO | SG_IIP,
    SG_NOP,
    SG_NOP,

    // 0x13: LDX $Y
    SG_TXI | SG_IPO,
    SG_IPI | SG_YIO,
    SG_RLI | SG_REA | SG_IIP,
    SG_RHI | SG_REA,
    SG_IPI | SG_TXO,
    SG_XII | SG_RXO | SG_IIP,
    SG_NOP,
    SG_NOP,

    // 0x14: LDY $Y
    SG_TXI | SG_IPO,
    SG_IPI | SG_YIO,
    SG_RLI | SG_REA | SG_IIP,
    SG_RHI | SG_REA,
    SG_IPI | SG_TXO,
    SG_YII | SG_RXO | SG_IIP,
    SG_NOP,
    SG_NOP,

    // 0x15: LDH $Y
    SG_TXI | SG_IPO,
    SG_IPI | SG_YIO,
    SG_DHI | SG_REA,
    SG_IPI | SG_TXO | SG_IIP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0x16: LDL $Y
    SG_TXI | SG_IPO,
    SG_IPI | SG_YIO,
    SG_DLI | SG_REA,
    SG_IPI | SG_TXO | SG_IIP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0x17: LDS $Y
    SG_TXI | SG_IPO,
    SG_IPI | SG_YIO,
    SG_RLI | SG_REA | SG_IIP,
    SG_RHI | SG_REA,
    SG_IPI | SG_TXO,
    SG_SPI | SG_RXO | SG_IIP,
    SG_NOP,
    SG_NOP,

    // 0x18: STA $Y
    SG_TXI | SG_IPO,
    SG_IPI | SG_YIO,
    SG_RXI | SG_AXO,
    SG_WRI | SG_RXO | SG_IIP,
    SG_WRI | SG_RHO,
    SG_IPI | SG_TXO | SG_IIP,
    SG_NOP,
    SG_NOP,

    // 0x19: STB $Y
    SG_TXI | SG_IPO,
    SG_IPI | SG_YIO,
    SG_RXI | SG_BXO,
    SG_WRI | SG_RXO | SG_IIP,
    SG_WRI | SG_RHO,
    SG_IPI | SG_TXO | SG_IIP,
    SG_NOP,
    SG_NOP,

    // 0x1A: STD $Y
    SG_TXI | SG_IPO,
    SG_IPI | SG_YIO,
    SG_RXI | SG_DXO,
    SG_WRI | SG_RXO | SG_IIP,
    SG_WRI | SG_RHO,
    SG_IPI | SG_TXO | SG_IIP,
    SG_NOP,
    SG_NOP,

    // 0x1B: STX $Y
    SG_TXI | SG_IPO,
    SG_IPI | SG_YIO,
    SG_RXI | SG_XIO,
    SG_WRI | SG_RXO | SG_IIP,
    SG_WRI | SG_RHO,
    SG_IPI | SG_TXO | SG_IIP,
    SG_NOP,
    SG_NOP,

    // 0x1C: STY $Y
    SG_TXI | SG_IPO,
    SG_IPI | SG_YIO,
    SG_RXI | SG_YIO,
    SG_WRI | SG_RXO | SG_IIP,
    SG_WRI | SG_RHO,
    SG_IPI | SG_TXO | SG_IIP,
    SG_NOP,
    SG_NOP,

    // 0x1D: STH $Y
    SG_TXI | SG_IPO,
    SG_IPI | SG_YIO,
    SG_WRI | SG_DHO,
    SG_IPI | SG_TXO | SG_IIP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0x1E: STL $Y
    SG_TXI | SG_IPO,
    SG_IPI | SG_YIO,
    SG_WRI | SG_DXO,
    SG_IPI | SG_TXO | SG_IIP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0x1F: STZ $Y
    SG_TXI | SG_IPO,
    SG_IPI | SG_YIO,
    SG_WRI,
    SG_IPI | SG_TXO | SG_IIP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0x20: LDA imm
    SG_IIP,
    SG_RLI | SG_REA | SG_IIP,
    SG_RHI | SG_REA | SG_IIP,
    SG_AXI | SG_RXO,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0x21: LDB imm
    SG_IIP,
    SG_RLI | SG_REA | SG_IIP,
    SG_RHI | SG_REA | SG_IIP,
    SG_BXI | SG_RXO,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0x22: LDD imm
    SG_IIP,
    SG_RLI | SG_REA | SG_IIP,
    SG_RHI | SG_REA | SG_IIP,
    SG_DXI | SG_RXO,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0x23: LDX imm
    SG_IIP,
    SG_RLI | SG_REA | SG_IIP,
    SG_RHI | SG_REA | SG_IIP,
    SG_XII | SG_RXO,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0x24: LDY imm
    SG_IIP,
    SG_RLI | SG_REA | SG_IIP,
    SG_RHI | SG_REA | SG_IIP,
    SG_YII | SG_RXO,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0x25: LDH imm
    SG_IIP,
    SG_DHI | SG_REA | SG_IIP,
    SG_IIP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0x26: LDL imm
    SG_IIP,
    SG_DLI | SG_REA | SG_IIP,
    SG_IIP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0x27: LDS imm
    SG_IIP,
    SG_RLI | SG_REA | SG_IIP,
    SG_RHI | SG_REA | SG_IIP,
    SG_SPI | SG_RXO,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0x28: SRA
    SG_RXI | SG_SHR | SG_IIP,
    SG_AXI | SG_RXO,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0x29: SRB
    SG_RXI | SG_AXO | SG_IIP,
    SG_AXI | SG_BXO,
    SG_BXI | SG_SHR,
    SG_AXI | SG_RXO,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0x2A: SLA
    SG_TXI | SG_BXO | SG_IIP,
    SG_BXI | SG_AXO,
    SG_RXI | SG_ADD,
    SG_AXI | SG_RXO,
    SG_BXI | SG_TXO,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0x2B: SLB
    SG_TXI | SG_AXO | SG_IIP,
    SG_AXI | SG_BXO,
    SG_RXI | SG_ADD,
    SG_BXI | SG_RXO,
    SG_AXI | SG_TXO,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0x2C: NGA
    SG_RXI | SG_NEG | SG_IIP,
    SG_AXI | SG_RXO,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0x2D: NGB
    SG_RXI | SG_AXO | SG_IIP,
    SG_AXI | SG_BXO,
    SG_BXI | SG_NEG,
    SG_AXI | SG_RXO,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0x2E: INX
    SG_INX,
    SG_IIP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0x2F: INY
    SG_INY,
    SG_IIP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0x30: ADA B
    SG_RXI | SG_ADD | SG_IIP,
    SG_AXI | SG_RXO,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0x31: ADB A
    SG_RXI | SG_ADD | SG_IIP,
    SG_BXI | SG_RXO,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0x32: SBA B
    SG_RXI | SG_SUB | SG_IIP,
    SG_AXI | SG_RXO,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0x33: SBB A
    SG_TXI | SG_AXO | SG_IIP,
    SG_AXI | SG_BXO,
    SG_BXI | SG_TXO,
    SG_RXI | SG_SUB,
    SG_BXI | SG_RXO,
    SG_AXI | SG_TXO,
    SG_NOP,
    SG_NOP,

    // 0x34: ANA B
    SG_RXI | SG_AND | SG_IIP,
    SG_AXI | SG_RXO,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0x35: ANB A
    SG_RXI | SG_AND | SG_IIP,
    SG_BXI | SG_RXO,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0x36: ORA B
    SG_RXI | SG_ORR | SG_IIP,
    SG_AXI | SG_RXO,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0x37: ORB A
    SG_RXI | SG_ORR | SG_IIP,
    SG_BXI | SG_RXO,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0x38: EXA B
    SG_RXI | SG_XOR | SG_IIP,
    SG_AXI | SG_RXO,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0x39: EXB A
    SG_RXI | SG_XOR | SG_IIP,
    SG_BXI | SG_RXO,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0x3A: PSH A
    SG_RXI | SG_AXO | SG_IIP,
    SG_TXI | SG_IPO,
    SG_IPI | SG_SPO | SG_ISP,
    SG_WRI | SG_RXO | SG_IIP,
    SG_WRI | SG_RHO | SG_ISP,
    SG_IPI | SG_TXO,
    SG_NOP,
    SG_NOP,

    // 0x3B: PSH B
    SG_RXI | SG_BXO | SG_IIP,
    SG_TXI | SG_IPO,
    SG_IPI | SG_SPO | SG_ISP,
    SG_WRI | SG_RXO | SG_IIP,
    SG_WRI | SG_RHO | SG_ISP,
    SG_IPI | SG_TXO,
    SG_NOP,
    SG_NOP,

    // 0x3C: PSH D
    SG_RXI | SG_DXO | SG_IIP,
    SG_TXI | SG_IPO,
    SG_IPI | SG_SPO | SG_ISP,
    SG_WRI | SG_RXO | SG_IIP,
    SG_WRI | SG_RHO | SG_ISP,
    SG_IPI | SG_TXO,
    SG_NOP,
    SG_NOP,

    // 0x3D: PSH X
    SG_RXI | SG_XIO | SG_IIP,
    SG_TXI | SG_IPO,
    SG_IPI | SG_SPO | SG_ISP,
    SG_WRI | SG_RXO | SG_IIP,
    SG_WRI | SG_RHO | SG_ISP,
    SG_IPI | SG_TXO,
    SG_NOP,
    SG_NOP,

    // 0x3E: PSH Y
    SG_RXI | SG_YIO | SG_IIP,
    SG_TXI | SG_IPO,
    SG_IPI | SG_SPO | SG_ISP,
    SG_WRI | SG_RXO | SG_IIP,
    SG_WRI | SG_RHO | SG_ISP,
    SG_IPI | SG_TXO,
    SG_NOP,
    SG_NOP,

    // 0x3F: PSH imm
    SG_IIP,
    SG_RLI | SG_REA | SG_IIP,
    SG_RHI | SG_REA | SG_IIP,
    SG_TXI | SG_IPO,
    SG_IPI | SG_SPO | SG_ISP,
    SG_WRI | SG_RXO | SG_IIP,
    SG_WRI | SG_RHO | SG_ISP,
    SG_IPI | SG_TXO,

    // 0x40: ADA D
    SG_TXI | SG_BXO | SG_IIP,
    SG_BXI | SG_DXO,
    SG_RXI | SG_ADD,
    SG_AXI | SG_RXO,
    SG_BXI | SG_TXO,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0x41: ADB D
    SG_TXI | SG_AXO | SG_IIP,
    SG_AXI | SG_BXO,
    SG_BXI | SG_DXO,
    SG_RXI | SG_ADD,
    SG_BXI | SG_RXO,
    SG_AXI | SG_TXO,
    SG_NOP,
    SG_NOP,

    // 0x42: SBA D
    SG_TXI | SG_BXO | SG_IIP,
    SG_BXI | SG_DXO,
    SG_RXI | SG_SUB,
    SG_AXI | SG_RXO,
    SG_BXI | SG_TXO,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0x43: SBB D
    SG_TXI | SG_AXO | SG_IIP,
    SG_AXI | SG_BXO,
    SG_BXI | SG_DXO,
    SG_RXI | SG_SUB,
    SG_BXI | SG_RXO,
    SG_AXI | SG_TXO,
    SG_NOP,
    SG_NOP,

    // 0x44: ANA D
    SG_TXI | SG_BXO | SG_IIP,
    SG_BXI | SG_DXO,
    SG_RXI | SG_AND,
    SG_AXI | SG_RXO,
    SG_BXI | SG_TXO,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0x45: ANB D
    SG_TXI | SG_AXO | SG_IIP,
    SG_AXI | SG_BXO,
    SG_BXI | SG_DXO,
    SG_RXI | SG_AND,
    SG_BXI | SG_RXO,
    SG_AXI | SG_TXO,
    SG_NOP,
    SG_NOP,

    // 0x46: ORA D
    SG_TXI | SG_BXO | SG_IIP,
    SG_BXI | SG_DXO,
    SG_RXI | SG_ORR,
    SG_AXI | SG_RXO,
    SG_BXI | SG_TXO,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0x47: ORB D
    SG_TXI | SG_AXO | SG_IIP,
    SG_AXI | SG_BXO,
    SG_BXI | SG_DXO,
    SG_RXI | SG_ORR,
    SG_BXI | SG_RXO,
    SG_AXI | SG_TXO,
    SG_NOP,
    SG_NOP,

    // 0x48: EXA D
    SG_TXI | SG_BXO | SG_IIP,
    SG_BXI | SG_DXO,
    SG_RXI | SG_XOR,
    SG_AXI | SG_RXO,
    SG_BXI | SG_TXO,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0x49: EXB D
    SG_TXI | SG_AXO | SG_IIP,
    SG_AXI | SG_BXO,
    SG_BXI | SG_DXO,
    SG_RXI | SG_XOR,
    SG_BXI | SG_RXO,
    SG_AXI | SG_TXO,
    SG_NOP,
    SG_NOP,

    // 0x4A: POP A
    SG_DSP,
    SG_TXI | SG_IPO | SG_DSP,
    SG_IPI | SG_SPO,
    SG_RLI | SG_REA | SG_IIP,
    SG_RHI | SG_REA,
    SG_IIP | SG_TXO | SG_IIP,
    SG_AXI | SG_RXO,
    SG_NOP,

    // 0x4B: POP B
    SG_DSP,
    SG_TXI | SG_IPO | SG_DSP,
    SG_IPI | SG_SPO,
    SG_RLI | SG_REA | SG_IIP,
    SG_RHI | SG_REA,
    SG_IIP | SG_TXO | SG_IIP,
    SG_BXI | SG_RXO,
    SG_NOP,

    // 0x4C: POP D
    SG_DSP,
    SG_TXI | SG_IPO | SG_DSP,
    SG_IPI | SG_SPO,
    SG_RLI | SG_REA | SG_IIP,
    SG_RHI | SG_REA,
    SG_IIP | SG_TXO | SG_IIP,
    SG_DXI | SG_RXO,
    SG_NOP,

    // 0x4D: POP X
    SG_DSP,
    SG_TXI | SG_IPO | SG_DSP,
    SG_IPI | SG_SPO,
    SG_RLI | SG_REA | SG_IIP,
    SG_RHI | SG_REA,
    SG_IIP | SG_TXO | SG_IIP,
    SG_XII | SG_RXO,
    SG_NOP,

    // 0x4E: POP Y
    SG_DSP,
    SG_TXI | SG_IPO | SG_DSP,
    SG_IPI | SG_SPO,
    SG_RLI | SG_REA | SG_IIP,
    SG_RHI | SG_REA,
    SG_IIP | SG_TXO | SG_IIP,
    SG_YII | SG_RXO,
    SG_NOP,

    // 0x4F: RET
    SG_DSP,
    SG_DSP,
    SG_IPI | SG_SPO,
    SG_RLI | SG_REA | SG_IIP,
    SG_RHI | SG_REA,
    SG_IPI | SG_RXO,
    SG_NOP,
    SG_NOP,

    // 0x50: ADA X
    SG_TXI | SG_BXO | SG_IIP,
    SG_BXI | SG_XIO,
    SG_RXI | SG_ADD,
    SG_AXI | SG_RXO,
    SG_BXI | SG_TXO,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0x51: ADB X
    SG_TXI | SG_AXO | SG_IIP,
    SG_AXI | SG_BXO,
    SG_BXI | SG_XIO,
    SG_RXI | SG_ADD,
    SG_BXI | SG_RXO,
    SG_AXI | SG_TXO,
    SG_NOP,
    SG_NOP,

    // 0x52: SBA X
    SG_TXI | SG_BXO | SG_IIP,
    SG_BXI | SG_XIO,
    SG_RXI | SG_SUB,
    SG_AXI | SG_RXO,
    SG_BXI | SG_TXO,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0x53: SBB X
    SG_TXI | SG_AXO | SG_IIP,
    SG_AXI | SG_BXO,
    SG_BXI | SG_XIO,
    SG_RXI | SG_SUB,
    SG_BXI | SG_RXO,
    SG_AXI | SG_TXO,
    SG_NOP,
    SG_NOP,

    // 0x54: ANA X
    SG_TXI | SG_BXO | SG_IIP,
    SG_BXI | SG_XIO,
    SG_RXI | SG_AND,
    SG_AXI | SG_RXO,
    SG_BXI | SG_TXO,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0x55: ANB X
    SG_TXI | SG_AXO | SG_IIP,
    SG_AXI | SG_BXO,
    SG_BXI | SG_XIO,
    SG_RXI | SG_AND,
    SG_BXI | SG_RXO,
    SG_AXI | SG_TXO,
    SG_NOP,
    SG_NOP,

    // 0x56: ORA X
    SG_TXI | SG_BXO | SG_IIP,
    SG_BXI | SG_XIO,
    SG_RXI | SG_ORR,
    SG_AXI | SG_RXO,
    SG_BXI | SG_TXO,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0x57: ORB X
    SG_TXI | SG_AXO | SG_IIP,
    SG_AXI | SG_BXO,
    SG_BXI | SG_XIO,
    SG_RXI | SG_ORR,
    SG_BXI | SG_RXO,
    SG_AXI | SG_TXO,
    SG_NOP,
    SG_NOP,

    // 0x58: EXA X
    SG_TXI | SG_BXO | SG_IIP,
    SG_BXI | SG_XIO,
    SG_RXI | SG_XOR,
    SG_AXI | SG_RXO,
    SG_BXI | SG_TXO,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0x59: EXB X
    SG_TXI | SG_AXO | SG_IIP,
    SG_AXI | SG_BXO,
    SG_BXI | SG_XIO,
    SG_RXI | SG_XOR,
    SG_BXI | SG_RXO,
    SG_AXI | SG_TXO,
    SG_NOP,
    SG_NOP,

    // 0x5A: JMP X
    SG_IPI | SG_XIO,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0x5B: JMP Y
    SG_IPI | SG_YIO,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0x5C: JMP imm
    SG_IIP,
    SG_RLI | SG_REA | SG_IIP,
    SG_RHI | SG_REA,
    SG_IPI | SG_RXO,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0x5D: JSR X
    SG_IIP,
    SG_RXI | SG_IPO,
    SG_IPI | SG_SPO | SG_ISP,
    SG_WRI | SG_RXO | SG_IIP,
    SG_WRI | SG_RHO | SG_ISP,
    SG_IPI | SG_XIO,
    SG_NOP,
    SG_NOP,

    // 0x5E: JSR Y
    SG_IIP,
    SG_RXI | SG_IPO,
    SG_IPI | SG_SPO | SG_ISP,
    SG_WRI | SG_RXO | SG_IIP,
    SG_WRI | SG_RHO | SG_ISP,
    SG_IPI | SG_YIO,
    SG_NOP,
    SG_NOP,

    // 0x5F: JSR imm
    SG_IIP,
    SG_TLI | SG_REA | SG_IIP,
    SG_THI | SG_REA,
    SG_RXI | SG_IPO,
    SG_IPI | SG_SPO | SG_ISP,
    SG_WRI | SG_RXO | SG_IIP,
    SG_WRI | SG_RHO | SG_ISP,
    SG_IPI | SG_TXO,

    // 0x60: ADA Y
    SG_TXI | SG_BXO | SG_IIP,
    SG_BXI | SG_YIO,
    SG_RXI | SG_ADD,
    SG_AXI | SG_RXO,
    SG_BXI | SG_TXO,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0x61: ADB Y
    SG_TXI | SG_AXO | SG_IIP,
    SG_AXI | SG_BXO,
    SG_BXI | SG_YIO,
    SG_RXI | SG_ADD,
    SG_BXI | SG_RXO,
    SG_AXI | SG_TXO,
    SG_NOP,
    SG_NOP,

    // 0x62: SBA Y
    SG_TXI | SG_BXO | SG_IIP,
    SG_BXI | SG_YIO,
    SG_RXI | SG_SUB,
    SG_AXI | SG_RXO,
    SG_BXI | SG_TXO,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0x63: SBB Y
    SG_TXI | SG_AXO | SG_IIP,
    SG_AXI | SG_BXO,
    SG_BXI | SG_YIO,
    SG_RXI | SG_SUB,
    SG_BXI | SG_RXO,
    SG_AXI | SG_TXO,
    SG_NOP,
    SG_NOP,

    // 0x64: ANA Y
    SG_TXI | SG_BXO | SG_IIP,
    SG_BXI | SG_YIO,
    SG_RXI | SG_AND,
    SG_AXI | SG_RXO,
    SG_BXI | SG_TXO,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0x65: ANB Y
    SG_TXI | SG_AXO | SG_IIP,
    SG_AXI | SG_BXO,
    SG_BXI | SG_YIO,
    SG_RXI | SG_AND,
    SG_BXI | SG_RXO,
    SG_AXI | SG_TXO,
    SG_NOP,
    SG_NOP,

    // 0x66: ORA Y
    SG_TXI | SG_BXO | SG_IIP,
    SG_BXI | SG_YIO,
    SG_RXI | SG_ORR,
    SG_AXI | SG_RXO,
    SG_BXI | SG_TXO,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0x67: ORB Y
    SG_TXI | SG_AXO | SG_IIP,
    SG_AXI | SG_BXO,
    SG_BXI | SG_YIO,
    SG_RXI | SG_ORR,
    SG_BXI | SG_RXO,
    SG_AXI | SG_TXO,
    SG_NOP,
    SG_NOP,

    // 0x68: EXA Y
    SG_TXI | SG_BXO | SG_IIP,
    SG_BXI | SG_YIO,
    SG_RXI | SG_XOR,
    SG_AXI | SG_RXO,
    SG_BXI | SG_TXO,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0x69: EXB Y
    SG_TXI | SG_AXO | SG_IIP,
    SG_AXI | SG_BXO,
    SG_BXI | SG_YIO,
    SG_RXI | SG_XOR,
    SG_BXI | SG_RXO,
    SG_AXI | SG_TXO,
    SG_NOP,
    SG_NOP,

    // 0x6A: JAZ X
    SG_IIP,
    SG_FLG_AXZ | SG_IPI | SG_XIO,
    SG_FLG_AXZ | SG_NOP,
    SG_FLG_AXZ | SG_NOP,
    SG_FLG_AXZ | SG_NOP,
    SG_FLG_AXZ | SG_NOP,
    SG_FLG_AXZ | SG_NOP,
    SG_FLG_AXZ | SG_NOP,

    // 0x6B: JAZ Y
    SG_IIP,
    SG_FLG_AXZ | SG_IPI | SG_YIO,
    SG_FLG_AXZ | SG_NOP,
    SG_FLG_AXZ | SG_NOP,
    SG_FLG_AXZ | SG_NOP,
    SG_FLG_AXZ | SG_NOP,
    SG_FLG_AXZ | SG_NOP,
    SG_FLG_AXZ | SG_NOP,

    // 0x6C: JAZ imm
    SG_IIP,
    SG_RLI | SG_REA | SG_IIP,
    SG_RHI | SG_REA | SG_IIP,
    SG_FLG_AXZ | SG_IPI | SG_RXO,
    SG_FLG_AXZ | SG_NOP,
    SG_FLG_AXZ | SG_NOP,
    SG_FLG_AXZ | SG_NOP,
    SG_FLG_AXZ | SG_NOP,

    // 0x6D: JBZ X
    SG_IIP,
    SG_FLG_BXZ | SG_IPI | SG_XIO,
    SG_FLG_BXZ | SG_NOP,
    SG_FLG_BXZ | SG_NOP,
    SG_FLG_BXZ | SG_NOP,
    SG_FLG_BXZ | SG_NOP,
    SG_FLG_BXZ | SG_NOP,
    SG_FLG_BXZ | SG_NOP,

    // 0x6E: JBZ Y
    SG_IIP,
    SG_FLG_BXZ | SG_IPI | SG_YIO,
    SG_FLG_BXZ | SG_NOP,
    SG_FLG_BXZ | SG_NOP,
    SG_FLG_BXZ | SG_NOP,
    SG_FLG_BXZ | SG_NOP,
    SG_FLG_BXZ | SG_NOP,
    SG_FLG_BXZ | SG_NOP,

    // 0x6F: JBZ imm
    SG_IIP,
    SG_RLI | SG_REA | SG_IIP,
    SG_RHI | SG_REA | SG_IIP,
    SG_FLG_BXZ | SG_IPI | SG_RXO,
    SG_FLG_BXZ | SG_NOP,
    SG_FLG_BXZ | SG_NOP,
    SG_FLG_BXZ | SG_NOP,
    SG_FLG_BXZ | SG_NOP,

    // 0x70: ADA imm
    SG_TXI | SG_BXO | SG_IIP,
    SG_RLI | SG_REA | SG_IIP,
    SG_RHI | SG_REA | SG_IIP,
    SG_BXI | SG_RXO,
    SG_RXI | SG_ADD,
    SG_AXI | SG_RXO,
    SG_BXI | SG_TXO,
    SG_NOP,

    // 0x71: ADB imm
    SG_TXI | SG_AXO | SG_IIP,
    SG_AXI | SG_BXO,
    SG_RLI | SG_REA | SG_IIP,
    SG_RHI | SG_REA | SG_IIP,
    SG_BXI | SG_RXO,
    SG_RXI | SG_ADD,
    SG_BXI | SG_RXO,
    SG_AXI | SG_TXO,

    // 0x72: SBA imm
    SG_TXI | SG_BXO | SG_IIP,
    SG_RLI | SG_REA | SG_IIP,
    SG_RHI | SG_REA | SG_IIP,
    SG_BXI | SG_RXO,
    SG_RXI | SG_SUB,
    SG_AXI | SG_RXO,
    SG_BXI | SG_TXO,
    SG_NOP,

    // 0x73: SBB imm
    SG_TXI | SG_AXO | SG_IIP,
    SG_AXI | SG_BXO,
    SG_RLI | SG_REA | SG_IIP,
    SG_RHI | SG_REA | SG_IIP,
    SG_BXI | SG_RXO,
    SG_RXI | SG_SUB,
    SG_BXI | SG_RXO,
    SG_AXI | SG_TXO,

    // 0x74: ANA imm
    SG_TXI | SG_BXO | SG_IIP,
    SG_RLI | SG_REA | SG_IIP,
    SG_RHI | SG_REA | SG_IIP,
    SG_BXI | SG_RXO,
    SG_RXI | SG_AND,
    SG_AXI | SG_RXO,
    SG_BXI | SG_TXO,
    SG_NOP,

    // 0x75: ANB imm
    SG_TXI | SG_AXO | SG_IIP,
    SG_AXI | SG_BXO,
    SG_RLI | SG_REA | SG_IIP,
    SG_RHI | SG_REA | SG_IIP,
    SG_BXI | SG_RXO,
    SG_RXI | SG_AND,
    SG_BXI | SG_RXO,
    SG_AXI | SG_TXO,

    // 0x76: ORA imm
    SG_TXI | SG_BXO | SG_IIP,
    SG_RLI | SG_REA | SG_IIP,
    SG_RHI | SG_REA | SG_IIP,
    SG_BXI | SG_RXO,
    SG_RXI | SG_ORR,
    SG_AXI | SG_RXO,
    SG_BXI | SG_TXO,
    SG_NOP,

    // 0x77: ORB imm
    SG_TXI | SG_AXO | SG_IIP,
    SG_AXI | SG_BXO,
    SG_RLI | SG_REA | SG_IIP,
    SG_RHI | SG_REA | SG_IIP,
    SG_BXI | SG_RXO,
    SG_RXI | SG_ORR,
    SG_BXI | SG_RXO,
    SG_AXI | SG_TXO,

    // 0x78: EXA imm
    SG_TXI | SG_BXO | SG_IIP,
    SG_RLI | SG_REA | SG_IIP,
    SG_RHI | SG_REA | SG_IIP,
    SG_BXI | SG_RXO,
    SG_RXI | SG_XOR,
    SG_AXI | SG_RXO,
    SG_BXI | SG_TXO,
    SG_NOP,

    // 0x79: EXB imm
    SG_TXI | SG_AXO | SG_IIP,
    SG_AXI | SG_BXO,
    SG_RLI | SG_REA | SG_IIP,
    SG_RHI | SG_REA | SG_IIP,
    SG_BXI | SG_RXO,
    SG_RXI | SG_XOR,
    SG_BXI | SG_RXO,
    SG_AXI | SG_TXO,

    // 0x7A: JAN X
    SG_IIP,
    SG_FLG_AXN | SG_IPI | SG_XIO,
    SG_FLG_AXN | SG_NOP,
    SG_FLG_AXN | SG_NOP,
    SG_FLG_AXN | SG_NOP,
    SG_FLG_AXN | SG_NOP,
    SG_FLG_AXN | SG_NOP,
    SG_FLG_AXN | SG_NOP,

    // 0x7B: JAN Y
    SG_IIP,
    SG_FLG_AXN | SG_IPI | SG_YIO,
    SG_FLG_AXN | SG_NOP,
    SG_FLG_AXN | SG_NOP,
    SG_FLG_AXN | SG_NOP,
    SG_FLG_AXN | SG_NOP,
    SG_FLG_AXN | SG_NOP,
    SG_FLG_AXN | SG_NOP,

    // 0x7C: JAN imm
    SG_IIP,
    SG_RLI | SG_REA | SG_IIP,
    SG_RHI | SG_REA | SG_IIP,
    SG_FLG_AXN | SG_IPI | SG_RXO,
    SG_FLG_AXN | SG_NOP,
    SG_FLG_AXN | SG_NOP,
    SG_FLG_AXN | SG_NOP,
    SG_FLG_AXN | SG_NOP,

    // 0x7D: JBN X
    SG_IIP,
    SG_FLG_BXN | SG_IPI | SG_XIO,
    SG_FLG_BXN | SG_NOP,
    SG_FLG_BXN | SG_NOP,
    SG_FLG_BXN | SG_NOP,
    SG_FLG_BXN | SG_NOP,
    SG_FLG_BXN | SG_NOP,
    SG_FLG_BXN | SG_NOP,

    // 0x7E: JBN Y
    SG_IIP,
    SG_FLG_BXN | SG_IPI | SG_YIO,
    SG_FLG_BXN | SG_NOP,
    SG_FLG_BXN | SG_NOP,
    SG_FLG_BXN | SG_NOP,
    SG_FLG_BXN | SG_NOP,
    SG_FLG_BXN | SG_NOP,
    SG_FLG_BXN | SG_NOP,

    // 0x7F: JBN imm
    SG_IIP,
    SG_RLI | SG_REA | SG_IIP,
    SG_RHI | SG_REA | SG_IIP,
    SG_FLG_BXN | SG_IPI | SG_RXO,
    SG_FLG_BXN | SG_NOP,
    SG_FLG_BXN | SG_NOP,
    SG_FLG_BXN | SG_NOP,
    SG_FLG_BXN | SG_NOP,

    // 0x80: JEQ X
    SG_IIP,
    SG_FLG_ZRO | SG_IPI | SG_XIO,
    SG_FLG_ZRO | SG_NOP,
    SG_FLG_ZRO | SG_NOP,
    SG_FLG_ZRO | SG_NOP,
    SG_FLG_ZRO | SG_NOP,
    SG_FLG_ZRO | SG_NOP,
    SG_FLG_ZRO | SG_NOP,

    // 0x81: JEQ Y
    SG_IIP,
    SG_FLG_ZRO | SG_IPI | SG_YIO,
    SG_FLG_ZRO | SG_NOP,
    SG_FLG_ZRO | SG_NOP,
    SG_FLG_ZRO | SG_NOP,
    SG_FLG_ZRO | SG_NOP,
    SG_FLG_ZRO | SG_NOP,
    SG_FLG_ZRO | SG_NOP,

    // 0x82: JEQ imm
    SG_IIP,
    SG_RLI | SG_REA | SG_IIP,
    SG_RHI | SG_REA | SG_IIP,
    SG_FLG_ZRO | SG_IPI | SG_RXO,
    SG_FLG_ZRO | SG_NOP,
    SG_FLG_ZRO | SG_NOP,
    SG_FLG_ZRO | SG_NOP,
    SG_FLG_ZRO | SG_NOP,

    // 0x83: JNE X
    SG_IIP,
    SG_FLG_NZR | SG_IPI | SG_XIO,
    SG_FLG_NZR | SG_NOP,
    SG_FLG_NZR | SG_NOP,
    SG_FLG_NZR | SG_NOP,
    SG_FLG_NZR | SG_NOP,
    SG_FLG_NZR | SG_NOP,
    SG_FLG_NZR | SG_NOP,

    // 0x84: JNE Y
    SG_IIP,
    SG_FLG_NZR | SG_IPI | SG_YIO,
    SG_FLG_NZR | SG_NOP,
    SG_FLG_NZR | SG_NOP,
    SG_FLG_NZR | SG_NOP,
    SG_FLG_NZR | SG_NOP,
    SG_FLG_NZR | SG_NOP,
    SG_FLG_NZR | SG_NOP,

    // 0x85: JNE imm
    SG_IIP,
    SG_RLI | SG_REA | SG_IIP,
    SG_RHI | SG_REA | SG_IIP,
    SG_FLG_NZR | SG_IPI | SG_RXO,
    SG_FLG_NZR | SG_NOP,
    SG_FLG_NZR | SG_NOP,
    SG_FLG_NZR | SG_NOP,
    SG_FLG_NZR | SG_NOP,

    // 0x86: MSX
    SG_SPI | SG_XIO | SG_IIP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0x87: MSY
    SG_SPI | SG_YIO | SG_IIP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0x88: MXS
    SG_XII | SG_SPO | SG_IIP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0x89: MYS
    SG_YII | SG_SPO | SG_IIP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0x8A: JGT X
    SG_IIP,
    SG_FLG_NZR | SG_FLG_NCR | SG_IPI | SG_XIO,
    SG_FLG_NZR | SG_FLG_NCR | SG_NOP,
    SG_FLG_NZR | SG_FLG_NCR | SG_NOP,
    SG_FLG_NZR | SG_FLG_NCR | SG_NOP,
    SG_FLG_NZR | SG_FLG_NCR | SG_NOP,
    SG_FLG_NZR | SG_FLG_NCR | SG_NOP,
    SG_FLG_NZR | SG_FLG_NCR | SG_NOP,

    // 0x8B: JGT Y
    SG_IIP,
    SG_FLG_NZR | SG_FLG_NCR | SG_IPI | SG_YIO,
    SG_FLG_NZR | SG_FLG_NCR | SG_NOP,
    SG_FLG_NZR | SG_FLG_NCR | SG_NOP,
    SG_FLG_NZR | SG_FLG_NCR | SG_NOP,
    SG_FLG_NZR | SG_FLG_NCR | SG_NOP,
    SG_FLG_NZR | SG_FLG_NCR | SG_NOP,
    SG_FLG_NZR | SG_FLG_NCR | SG_NOP,

    // 0x8C: JGT imm
    SG_IIP,
    SG_RLI | SG_REA | SG_IIP,
    SG_RHI | SG_REA | SG_IIP,
    SG_FLG_NZR | SG_FLG_NCR | SG_IPI | SG_RXO,
    SG_FLG_NZR | SG_FLG_NCR | SG_NOP,
    SG_FLG_NZR | SG_FLG_NCR | SG_NOP,
    SG_FLG_NZR | SG_FLG_NCR | SG_NOP,
    SG_FLG_NZR | SG_FLG_NCR | SG_NOP,

    // 0x8D: JLS X
    SG_IIP,
    SG_FLG_NZR | SG_FLG_CRY | SG_IPI | SG_XIO,
    SG_FLG_NZR | SG_FLG_CRY | SG_NOP,
    SG_FLG_NZR | SG_FLG_CRY | SG_NOP,
    SG_FLG_NZR | SG_FLG_CRY | SG_NOP,
    SG_FLG_NZR | SG_FLG_CRY | SG_NOP,
    SG_FLG_NZR | SG_FLG_CRY | SG_NOP,
    SG_FLG_NZR | SG_FLG_CRY | SG_NOP,

    // 0x8E: JLS Y
    SG_IIP,
    SG_FLG_NZR | SG_FLG_CRY | SG_IPI | SG_YIO,
    SG_FLG_NZR | SG_FLG_CRY | SG_NOP,
    SG_FLG_NZR | SG_FLG_CRY | SG_NOP,
    SG_FLG_NZR | SG_FLG_CRY | SG_NOP,
    SG_FLG_NZR | SG_FLG_CRY | SG_NOP,
    SG_FLG_NZR | SG_FLG_CRY | SG_NOP,
    SG_FLG_NZR | SG_FLG_CRY | SG_NOP,

    // 0x8F: JLS imm
    SG_IIP,
    SG_RLI | SG_REA | SG_IIP,
    SG_RHI | SG_REA | SG_IIP,
    SG_FLG_NZR | SG_FLG_CRY | SG_IPI | SG_RXO,
    SG_FLG_NZR | SG_FLG_CRY | SG_NOP,
    SG_FLG_NZR | SG_FLG_CRY | SG_NOP,
    SG_FLG_NZR | SG_FLG_CRY | SG_NOP,
    SG_FLG_NZR | SG_FLG_CRY | SG_NOP,

    // 0x90: JCR X
    SG_IIP,
    SG_FLG_CRY | SG_IPI | SG_XIO,
    SG_FLG_CRY | SG_NOP,
    SG_FLG_CRY | SG_NOP,
    SG_FLG_CRY | SG_NOP,
    SG_FLG_CRY | SG_NOP,
    SG_FLG_CRY | SG_NOP,
    SG_FLG_CRY | SG_NOP,

    // 0x91: JCR Y
    SG_IIP,
    SG_FLG_CRY | SG_IPI | SG_YIO,
    SG_FLG_CRY | SG_NOP,
    SG_FLG_CRY | SG_NOP,
    SG_FLG_CRY | SG_NOP,
    SG_FLG_CRY | SG_NOP,
    SG_FLG_CRY | SG_NOP,
    SG_FLG_CRY | SG_NOP,

    // 0x92: JCR imm
    SG_IIP,
    SG_RLI | SG_REA | SG_IIP,
    SG_RHI | SG_REA | SG_IIP,
    SG_FLG_CRY | SG_IPI | SG_RXO,
    SG_FLG_CRY | SG_NOP,
    SG_FLG_CRY | SG_NOP,
    SG_FLG_CRY | SG_NOP,
    SG_FLG_CRY | SG_NOP,

    // 0x93: JNC X
    SG_IIP,
    SG_FLG_NCR | SG_IPI | SG_XIO,
    SG_FLG_NCR | SG_NOP,
    SG_FLG_NCR | SG_NOP,
    SG_FLG_NCR | SG_NOP,
    SG_FLG_NCR | SG_NOP,
    SG_FLG_NCR | SG_NOP,
    SG_FLG_NCR | SG_NOP,

    // 0x94: JNC Y
    SG_IIP,
    SG_FLG_NCR | SG_IPI | SG_YIO,
    SG_FLG_NCR | SG_NOP,
    SG_FLG_NCR | SG_NOP,
    SG_FLG_NCR | SG_NOP,
    SG_FLG_NCR | SG_NOP,
    SG_FLG_NCR | SG_NOP,
    SG_FLG_NCR | SG_NOP,

    // 0x95: JNC imm
    SG_IIP,
    SG_RLI | SG_REA | SG_IIP,
    SG_RHI | SG_REA | SG_IIP,
    SG_FLG_NCR | SG_IPI | SG_RXO,
    SG_FLG_NCR | SG_NOP,
    SG_FLG_NCR | SG_NOP,
    SG_FLG_NCR | SG_NOP,
    SG_FLG_NCR | SG_NOP,

    // 0x96: SW1
    SG_RXI | SG_IPO,
    SG_IPI | SG_SPO | SG_ISP,
    SG_WRI | SG_RXO | SG_IIP,
    SG_WRI | SG_RHO | SG_ISP,
    SG_IPI | SG_SW1,
    SG_RLI | SG_REA | SG_IPI,
    SG_RHI | SG_REA,
    SG_IPI | SG_RXO,

    // 0x97: SW2
    SG_RXI | SG_IPO,
    SG_IPI | SG_SPO | SG_ISP,
    SG_WRI | SG_RXO | SG_IIP,
    SG_WRI | SG_RHO | SG_ISP,
    SG_IPI | SG_SW2,
    SG_RLI | SG_REA | SG_IPI,
    SG_RHI | SG_REA,
    SG_IPI | SG_RXO,

    // 0x98: SW3
    SG_RXI | SG_IPO,
    SG_IPI | SG_SPO | SG_ISP,
    SG_WRI | SG_RXO | SG_IIP,
    SG_WRI | SG_RHO | SG_ISP,
    SG_IPI | SG_SW3,
    SG_RLI | SG_REA | SG_IPI,
    SG_RHI | SG_REA,
    SG_IPI | SG_RXO,

    // 0x99: SW4
    SG_RXI | SG_IPO,
    SG_IPI | SG_SPO | SG_ISP,
    SG_WRI | SG_RXO | SG_IIP,
    SG_WRI | SG_RHO | SG_ISP,
    SG_IPI | SG_SW4,
    SG_RLI | SG_REA | SG_IPI,
    SG_RHI | SG_REA,
    SG_IPI | SG_RXO,

    // 0x9A: NOP
    SG_IIP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0x9B: HLT
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0x9C: RST
    SG_IPI,
    SG_SPI,
    SG_AXI,
    SG_BXI,
    SG_DXI,
    SG_XII,
    SG_YII,
    SG_NOP,

    // 0x9D: MHL
    SG_DHI | SG_DXO | SG_IIP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0x9E: MLH
    SG_DLI | SG_DHO | SG_IIP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0x9F: THL
    SG_RLI | SG_DHO | SG_IIP,
    SG_DHI | SG_DXO,
    SG_DLI | SG_RXO,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0xA0: MAB
    SG_AXI | SG_BXO | SG_IIP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0xA1: MAD
    SG_AXI | SG_DXO | SG_IIP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0xA2: MAX
    SG_AXI | SG_XIO | SG_IIP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0xA3: MAY
    SG_AXI | SG_YIO | SG_IIP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0xA4: MBA
    SG_BXI | SG_AXO | SG_IIP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0xA5: MBD
    SG_BXI | SG_DXO | SG_IIP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0xA6: MBX
    SG_BXI | SG_XIO | SG_IIP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0xA7: MBY
    SG_BXI | SG_YIO | SG_IIP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0xA8: MDA
    SG_DXI | SG_AXO | SG_IIP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0xA9: MDB
    SG_DXI | SG_BXO | SG_IIP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0xAA: MDX
    SG_DXI | SG_XIO | SG_IIP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0xAB: MDY
    SG_DXI | SG_YIO | SG_IIP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0xAC: MXA
    SG_XII | SG_AXO | SG_IIP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0xAD: MXB
    SG_XII | SG_BXO | SG_IIP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0xAE: MXD
    SG_XII | SG_DXO | SG_IIP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0xAF: MXY
    SG_XII | SG_YIO | SG_IIP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0xB0: MYA
    SG_YII | SG_AXO | SG_IIP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0xB1: MYB
    SG_YII | SG_BXO | SG_IIP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0xB2: MYD
    SG_YII | SG_DXO | SG_IIP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0xB3: MYX
    SG_YII | SG_XIO | SG_IIP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0xB4: TAB
    SG_RXI | SG_AXO | SG_IIP,
    SG_AXI | SG_BXO,
    SG_BXI | SG_RXO,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0xB5: TAD
    SG_RXI | SG_AXO | SG_IIP,
    SG_AXI | SG_DXO,
    SG_DXI | SG_RXO,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0xB6: TAX
    SG_RXI | SG_AXO | SG_IIP,
    SG_AXI | SG_XIO,
    SG_XII | SG_RXO,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0xB7: TAY
    SG_RXI | SG_AXO | SG_IIP,
    SG_AXI | SG_YIO,
    SG_YII | SG_RXO,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0xB8: TBD
    SG_RXI | SG_BXO | SG_IIP,
    SG_BXI | SG_DXO,
    SG_DXI | SG_RXO,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0xB9: TBX
    SG_RXI | SG_BXO | SG_IIP,
    SG_BXI | SG_XIO,
    SG_XII | SG_RXO,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0xBA: TBY
    SG_RXI | SG_BXO | SG_IIP,
    SG_BXI | SG_YIO,
    SG_YII | SG_RXO,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0xBB: TDX
    SG_RXI | SG_DXO | SG_IIP,
    SG_DXI | SG_XIO,
    SG_XII | SG_RXO,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0xBC: TDY
    SG_RXI | SG_DXO | SG_IIP,
    SG_DXI | SG_YIO,
    SG_YII | SG_RXO,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0xBD: TXY
    SG_RXI | SG_XIO | SG_IIP,
    SG_XII | SG_YIO,
    SG_YII | SG_RXO,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0xBE: DEX
    SG_DEX,
    SG_IIP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,

    // 0xBF: DEY
    SG_DEY,
    SG_IIP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP,
    SG_NOP};

static const sg_instr_t sg_instr_arr[] = {
    (sg_instr_t){"LDA", "$X", 1, 0},
    (sg_instr_t){"LDB", "$X", 1, 0},
    (sg_instr_t){"LDD", "$X", 1, 0},
    (sg_instr_t){"LDX", "$X", 1, 0},
    (sg_instr_t){"LDY", "$X", 1, 0},
    (sg_instr_t){"LDH", "$X", 1, 0},
    (sg_instr_t){"LDL", "$X", 1, 0},
    (sg_instr_t){"LDS", "$X", 1, 0},
    (sg_instr_t){"STA", "$X", 1, 0},
    (sg_instr_t){"STB", "$X", 1, 0},
    (sg_instr_t){"STD", "$X", 1, 0},
    (sg_instr_t){"STX", "$X", 1, 0},
    (sg_instr_t){"STY", "$X", 1, 0},
    (sg_instr_t){"STH", "$X", 1, 0},
    (sg_instr_t){"STL", "$X", 1, 0},
    (sg_instr_t){"STZ", "$X", 1, 0},

    (sg_instr_t){"LDA", "$Y", 1, 0},
    (sg_instr_t){"LDB", "$Y", 1, 0},
    (sg_instr_t){"LDD", "$Y", 1, 0},
    (sg_instr_t){"LDX", "$Y", 1, 0},
    (sg_instr_t){"LDY", "$Y", 1, 0},
    (sg_instr_t){"LDH", "$Y", 1, 0},
    (sg_instr_t){"LDL", "$Y", 1, 0},
    (sg_instr_t){"LDS", "$Y", 1, 0},
    (sg_instr_t){"STA", "$Y", 1, 0},
    (sg_instr_t){"STB", "$Y", 1, 0},
    (sg_instr_t){"STD", "$Y", 1, 0},
    (sg_instr_t){"STX", "$Y", 1, 0},
    (sg_instr_t){"STY", "$Y", 1, 0},
    (sg_instr_t){"STH", "$Y", 1, 0},
    (sg_instr_t){"STL", "$Y", 1, 0},
    (sg_instr_t){"STZ", "$Y", 1, 0},

    (sg_instr_t){"LDA", "imm", 0, 0},
    (sg_instr_t){"LDB", "imm", 0, 0},
    (sg_instr_t){"LDD", "imm", 0, 0},
    (sg_instr_t){"LDX", "imm", 0, 0},
    (sg_instr_t){"LDY", "imm", 0, 0},
    (sg_instr_t){"LDH", "imm", 0, 0},
    (sg_instr_t){"LDL", "imm", 0, 0},
    (sg_instr_t){"LDS", "imm", 0, 0},
    (sg_instr_t){"SRA", NULL, 0, 0},
    (sg_instr_t){"SRB", NULL, 0, 0},
    (sg_instr_t){"SLA", NULL, 0, 0},
    (sg_instr_t){"SLB", NULL, 0, 0},
    (sg_instr_t){"NGA", NULL, 0, 0},
    (sg_instr_t){"NGB", NULL, 0, 0},
    (sg_instr_t){"INX", NULL, 0, 0},
    (sg_instr_t){"INY", NULL, 0, 0},

    (sg_instr_t){"ADA", "B", 0, 0},
    (sg_instr_t){"ADB", "A", 0, 0},
    (sg_instr_t){"SBA", "B", 0, 0},
    (sg_instr_t){"SBB", "A", 0, 0},
    (sg_instr_t){"ANA", "B", 0, 0},
    (sg_instr_t){"ANB", "A", 0, 0},
    (sg_instr_t){"ORA", "B", 0, 0},
    (sg_instr_t){"ORB", "A", 0, 0},
    (sg_instr_t){"EXA", "B", 0, 0},
    (sg_instr_t){"EXB", "A", 0, 0},
    (sg_instr_t){"PSH", "A", 1, 0},
    (sg_instr_t){"PSH", "B", 1, 0},
    (sg_instr_t){"PSH", "D", 1, 0},
    (sg_instr_t){"PSH", "X", 1, 0},
    (sg_instr_t){"PSH", "Y", 1, 0},
    (sg_instr_t){"PSH", "imm", 1, 0},

    (sg_instr_t){"ADA", "D", 0, 0},
    (sg_instr_t){"ADB", "D", 0, 0},
    (sg_instr_t){"SBA", "D", 0, 0},
    (sg_instr_t){"SBB", "D", 0, 0},
    (sg_instr_t){"ANA", "D", 0, 0},
    (sg_instr_t){"ANB", "D", 0, 0},
    (sg_instr_t){"ORA", "D", 0, 0},
    (sg_instr_t){"ORB", "D", 0, 0},
    (sg_instr_t){"EXA", "D", 0, 0},
    (sg_instr_t){"EXB", "D", 0, 0},
    (sg_instr_t){"POP", "A", 1, 0},
    (sg_instr_t){"POP", "B", 1, 0},
    (sg_instr_t){"POP", "D", 1, 0},
    (sg_instr_t){"POP", "X", 1, 0},
    (sg_instr_t){"POP", "Y", 1, 0},
    (sg_instr_t){"RET", NULL, 1, 1},

    (sg_instr_t){"ADA", "X", 0, 0},
    (sg_instr_t){"ADB", "X", 0, 0},
    (sg_instr_t){"SBA", "X", 0, 0},
    (sg_instr_t){"SBB", "X", 0, 0},
    (sg_instr_t){"ANA", "X", 0, 0},
    (sg_instr_t){"ANB", "X", 0, 0},
    (sg_instr_t){"ORA", "X", 0, 0},
    (sg_instr_t){"ORB", "X", 0, 0},
    (sg_instr_t){"EXA", "X", 0, 0},
    (sg_instr_t){"EXB", "X", 0, 0},
    (sg_instr_t){"JMP", "X", 0, 1},
    (sg_instr_t){"JMP", "Y", 0, 1},
    (sg_instr_t){"JMP", "imm", 0, 1},
    (sg_instr_t){"JSR", "X", 1, 1},
    (sg_instr_t){"JSR", "Y", 1, 1},
    (sg_instr_t){"JSR", "imm", 1, 1},

    (sg_instr_t){"ADA", "Y", 0, 0},
    (sg_instr_t){"ADB", "Y", 0, 0},
    (sg_instr_t){"SBA", "Y", 0, 0},
    (sg_instr_t){"SBB", "Y", 0, 0},
    (sg_instr_t){"ANA", "Y", 0, 0},
    (sg_instr_t){"ANB", "Y", 0, 0},
    (sg_instr_t){"ORA", "Y", 0, 0},
    (sg_instr_t){"ORB", "Y", 0, 0},
    (sg_instr_t){"EXA", "Y", 0, 0},
    (sg_instr_t){"EXB", "Y", 0, 0},
    (sg_instr_t){"JAZ", "X", 0, 1},
    (sg_instr_t){"JAZ", "Y", 0, 1},
    (sg_instr_t){"JAZ", "imm", 0, 1},
    (sg_instr_t){"JBZ", "X", 0, 1},
    (sg_instr_t){"JBZ", "Y", 0, 1},
    (sg_instr_t){"JBZ", "imm", 0, 1},

    (sg_instr_t){"ADA", "imm", 0, 0},
    (sg_instr_t){"ADB", "imm", 0, 0},
    (sg_instr_t){"SBA", "imm", 0, 0},
    (sg_instr_t){"SBB", "imm", 0, 0},
    (sg_instr_t){"ANA", "imm", 0, 0},
    (sg_instr_t){"ANB", "imm", 0, 0},
    (sg_instr_t){"ORA", "imm", 0, 0},
    (sg_instr_t){"ORB", "imm", 0, 0},
    (sg_instr_t){"EXA", "imm", 0, 0},
    (sg_instr_t){"EXB", "imm", 0, 0},
    (sg_instr_t){"JAN", "X", 0, 1},
    (sg_instr_t){"JAN", "Y", 0, 1},
    (sg_instr_t){"JAN", "imm", 0, 1},
    (sg_instr_t){"JBN", "X", 0, 1},
    (sg_instr_t){"JBN", "Y", 0, 1},
    (sg_instr_t){"JBN", "imm", 0, 1},

    (sg_instr_t){"JEQ", "X", 0, 1},
    (sg_instr_t){"JEQ", "Y", 0, 1},
    (sg_instr_t){"JEQ", "imm", 0, 1},
    (sg_instr_t){"JNE", "X", 0, 1},
    (sg_instr_t){"JNE", "Y", 0, 1},
    (sg_instr_t){"JNE", "imm", 0, 1},
    (sg_instr_t){"MSX", NULL, 0, 0},
    (sg_instr_t){"MSY", NULL, 0, 0},
    (sg_instr_t){"MXS", NULL, 0, 0},
    (sg_instr_t){"MYS", NULL, 0, 0},
    (sg_instr_t){"JGT", "X", 0, 1},
    (sg_instr_t){"JGT", "Y", 0, 1},
    (sg_instr_t){"JGT", "imm", 0, 1},
    (sg_instr_t){"JLS", "X", 0, 1},
    (sg_instr_t){"JLS", "Y", 0, 1},
    (sg_instr_t){"JLS", "imm", 0, 1},

    (sg_instr_t){"JCR", "X", 0, 1},
    (sg_instr_t){"JCR", "Y", 0, 1},
    (sg_instr_t){"JCR", "imm", 0, 1},
    (sg_instr_t){"JNC", "X", 0, 1},
    (sg_instr_t){"JNC", "Y", 0, 1},
    (sg_instr_t){"JNC", "imm", 0, 1},
    (sg_instr_t){"SW1", NULL, 0, 1},
    (sg_instr_t){"SW2", NULL, 0, 1},
    (sg_instr_t){"SW3", NULL, 0, 1},
    (sg_instr_t){"SW4", NULL, 0, 1},
    (sg_instr_t){"NOP", NULL, 0, 0},
    (sg_instr_t){"HLT", NULL, 0, 0},
    (sg_instr_t){"RST", NULL, 0, 1},
    (sg_instr_t){"MHL", NULL, 0, 0},
    (sg_instr_t){"MLH", NULL, 0, 0},
    (sg_instr_t){"THL", NULL, 0, 0},

    (sg_instr_t){"MAB", NULL, 0, 0},
    (sg_instr_t){"MAD", NULL, 0, 0},
    (sg_instr_t){"MAX", NULL, 0, 0},
    (sg_instr_t){"MAY", NULL, 0, 0},
    (sg_instr_t){"MBA", NULL, 0, 0},
    (sg_instr_t){"MBD", NULL, 0, 0},
    (sg_instr_t){"MBX", NULL, 0, 0},
    (sg_instr_t){"MBY", NULL, 0, 0},
    (sg_instr_t){"MDA", NULL, 0, 0},
    (sg_instr_t){"MDB", NULL, 0, 0},
    (sg_instr_t){"MDX", NULL, 0, 0},
    (sg_instr_t){"MDY", NULL, 0, 0},
    (sg_instr_t){"MXA", NULL, 0, 0},
    (sg_instr_t){"MXB", NULL, 0, 0},
    (sg_instr_t){"MXD", NULL, 0, 0},
    (sg_instr_t){"MXY", NULL, 0, 0},

    (sg_instr_t){"MYA", NULL, 0, 0},
    (sg_instr_t){"MYB", NULL, 0, 0},
    (sg_instr_t){"MYD", NULL, 0, 0},
    (sg_instr_t){"MYX", NULL, 0, 0},
    (sg_instr_t){"TAB", NULL, 0, 0},
    (sg_instr_t){"TAD", NULL, 0, 0},
    (sg_instr_t){"TAX", NULL, 0, 0},
    (sg_instr_t){"TAY", NULL, 0, 0},
    (sg_instr_t){"TBD", NULL, 0, 0},
    (sg_instr_t){"TBX", NULL, 0, 0},
    (sg_instr_t){"TBY", NULL, 0, 0},
    (sg_instr_t){"TDX", NULL, 0, 0},
    (sg_instr_t){"TDY", NULL, 0, 0},
    (sg_instr_t){"TXY", NULL, 0, 0},
    (sg_instr_t){"DEX", NULL, 0, 0},
    (sg_instr_t){"DEY", NULL, 0, 0}};

#endif