#Ne pas commencer par une ligne 
JAL 0
J 67108863
BLEZ $20, 0
BGTZ $19, 89
BNE $0, $0, -1
BEQ $31, $31, 65535
LUI $31, -32768
SW $10, 0($31)
LW $10, 0($31)
ADDI $31, $0, 65535
NOP
MFLO $9
MFHI $9
SLT $24, $25, $30
SLL $24, $25, $30
SRL $10, $7, $9
ROTR $10, $7, $9
OR $4, $7, $31
ADD $31, $5, $2