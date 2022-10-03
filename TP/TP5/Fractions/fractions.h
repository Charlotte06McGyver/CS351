
typedef struct{
    int num;
    int den;
}Fraction;

int pgcd(int a , int b);
Fraction reduire(Fraction f);
void addFraction(Fraction f1, Fraction f2);
void subFraction(Fraction f1, Fraction f2);
void mulFraction(Fraction f1, Fraction f2);
void divFraction(Fraction f1, Fraction f2);