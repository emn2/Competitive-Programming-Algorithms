#include <stdio.h>

//Euclidean GCD Algorithm

int iterativeGCD(int a, int b){
  int c = a + b;
    while(c > 0){
        if(a % c == 0 && b % c == 0)
          return c;
        c--;
    }
    return 1;
}

int recursiveGCD(int a, int b){
    if(b == 0) return a;
    return recursiveGCD(b, a%b);
}


int main(){
    int a, b;
    scanf("%d %d', &a, &b);
    
    printf("Greatest Common Divisor: %d\n", recursiveGCD(a, b));
    printf("Greatest Common Divisor: %d\n", iterativeGCD(a, b));
    
    return 0;
}
