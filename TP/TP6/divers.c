#include <stdio.h>

int fibonacci (int n){

    int result = 0;

    if (n==0){
        result = 0;
    }

    else if (n==1){
        result = 1;
    }

    else {
        result = (fibonacci(n-1) + fibonacci(n-2));
    }

    return result;

}

/*
int pgcd(int a , int b){
    int r =0;
    while((b != 0)){  
        r = a%b;
#ifdef MISEAUPOINT 
    printf("valeur courante de b =  %d \n", b);
#endif 
        a=b;
        b=r; 
    }
    return a;
}
*/

int pgcd(int a, int b){

    int result = 0; 

    if (a==0){
        result = b;
    }

    if (b==0){
        result = a;
    }

    else {
        result = pgcd(b, a%b);
    }
    return result;
}

int palindrome (char *s, int N){

    int result = 0;

    if(N<=1){
        result = 1;
    }
    else {
        result = (s[0]==s[N-1] && palindrome(s+1, N-2));
    }

    return result;
}

int main(){

    printf("Fibonacci de %d = %d\n", 3, fibonacci(3));
    printf("PGCD : %d\n", pgcd(256, 365));
    printf("Palindrome : %d\n", palindrome("anna", 4));

}