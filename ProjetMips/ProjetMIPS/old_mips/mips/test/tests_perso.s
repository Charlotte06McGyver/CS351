ADD $7, $5, $2
SUB $8, $3, $2
MULT $5, $2
DIV $5, $2
AND $0, $31, $31
OR $31, $0, $2
XOR $4, $7, $31
ROTR $10, $7, $9
SRL $10, $7, $9
SLL $24, $25, $30
SLT $24, $25, $30
MFHI $9
MFLO $9
NOP
ADDI $31, $0, 65535
LW $10, 0($31)
SW $10, 0($31)
LUI $31, -32768
BEQ $31, $31, 65535
BNE $0, $0, -1
BGTZ $19, 89
BLEZ $20, 90
J 67108863
JAL 0

#EXPECTED_ASSEMBLY
# 00a23820
# 00624022
# 00a20018
# 00a2001a
# 03ff0024
# 0002f825
# 00ff2026
# 00275242
# 00075242
# 0019c780
# 033ec02a
# 00004810
# 00004812
# 00000000
# 201fffff
# 8fea0000
# afea0000
# 3c1f8000
# 13ffffff
# 1400ffff
# 1e600059
# 1a80005a
# 0bffffff
# 0c000000