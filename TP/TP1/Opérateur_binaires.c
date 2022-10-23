#include <stdio.h>

int main() {
int i = 2, j = 3, k = 4;
    printf("%d, %d, %d\n", i & j, i | 1, k | j);
    if ((i & k) || (i & j))
        printf("ok\n");
    return (0);
}
/* Ce programme fait des "ou" bit à bit et des "et" bit à bit
ce qui donne 2 = 010 , 3 = 011, 4 = 100
010 & 011 = 001 , 010 | 001 = 011, 100 | 011 = 111

(i & k) || (i & j) -> le || regarde si l'une des 2 exprétions est vrai donc 1.
Donc si le "et" bit à bit des exprésion donne 001

*/
