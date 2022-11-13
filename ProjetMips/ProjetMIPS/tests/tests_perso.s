# Instructions type R       EXPECTED_ASSEMBLY       EXPECTED_FINAL_STATE

ADD $7, $5, $2              # 00a23820              # $07:16   
SUB $8, $3, $2              # 00a23820              # $09:5
MULT $5, $2                 # 00a20018              # LO:55
DIV $5, $2                  # 00a2001a              # $10:0
AND
OR
XOR
ROTR
SLL
SRL
SLT
MFHI $9
MFLO
JR
NOP


#Instructions type I

ADDI $5, $0, 5
ADDI $2, $0, 11
ADDI $11, $10, 7
