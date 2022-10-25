#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct r_type {
  char opcode[6];//6 bits
  char rs[5];//5 bits
  char rt[5];//5 bits
  char rd[5];//5 bits
  char sa[5];//5 bits
  char fonction[6];//6 bits

}R_type;

R_type Add = {.opcode = "000000", .sa = "00000", .fonction = "100000"};
R_type Sub = {.opcode = "000000", .sa = "00000", .fonction = "100010"};
R_type Mult = {.opcode = "000000", .rd = "00000", .sa = "00000", .fonction = "011000"};
R_type Div = {.opcode = "000000", .rd = "00000", .sa = "00000", .fonction = "011010"};
R_type And = {.opcode = "000000", .sa = "00000", .fonction = "100100"};
R_type Or = {.opcode = "000000", .sa = "00000", .fonction = "100101"};
R_type Xor = {.opcode = "000000", .sa = "00000", .fonction = "100110"};
R_type Rotr = {.opcode = "000000", .rs = "0000", .fonction = "000010"}; //instruction spéciale
R_type Sll = {.opcode = "000000", .rs = "00000", .fonction = "000000"};
R_type Srl = {.opcode = "000000", .rs = "0000", .fonction = "000010"}; //instruction spéciale
R_type Slt = {.opcode = "000000", .sa = "00000", .fonction = "101010"};
R_type Mfhi = {.opcode = "000000", .rs = "00000", .rt = "00000", .sa =  "00000", .fonction = "010000"};
R_type Mflo = {.opcode = "000000", .rs = "00000", .rt = "00000", .sa =  "00000", .fonction = "010010"};
R_type Jr = {.opcode = "000000", .rt = "00000", .rd = "00000", .fonction = "001000"};
R_type Nop = {.opcode = "000000", .rs = "00000", .rt = "00000", .rd = "00000", .sa = "00000", .fonction = "000000"};

typedef struct i_type {
  char opcode[6];//6 bits
  char rs[5];//5 bits
  char rt[5];//5 bits
  char immediate[16];//16 bits

}I_type;

I_type Addi = {.opcode = "001000"};
I_type Lw = {.opcode = "100011"};
I_type Sw = {.opcode = "101011"};
I_type Lui = {.opcode = "001111", .rs = "00000"};
I_type Beq = {.opcode = "000100"};
I_type Bne = {.opcode = "000101"};
I_type Bgtz = {.opcode = "000111", .rt = "00000"};
I_type Blez = {.opcode = "000110", .rt = "00000"};

typedef struct j_type{
  char opcode[6];//6 bits
  char rs[26];//26 bits

}J_type;

J_type J = {.opcode = "000010"};
J_type Jal = {.opcode = "000011"};

typedef struct special_type{
  char opcode[6];
  char code[20];
  char fonction[6];
}Special;

Special Syscall = {.opcode = "000000", .fonction = "001100"};
