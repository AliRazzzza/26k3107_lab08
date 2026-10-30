#include <stdio.h>
int isEven(int n){
    return n % 2 == 0;
}
int isPalindrome(int n) {
    int temp = n;
    long long reverse = 0;
    while (temp > 0) {
        reverse = reverse * 10 + temp % 10;
        temp /= 10;
    }
    return reverse == n;
}
int isPrime(int n){
    if (n < 2) {
        return 0;
    }
    for (int i = 2; i <= n / i; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}
int main(){
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("enter a positive integer\n");
        return 0;
    }
    if (isEven(n)) {
        printf("Even number\n");
    } else {
        printf("Odd number\n");
    }

    if (isPalindrome(n)) {
        printf("Palindrome\n");
    } else {
        printf("Not a palindrome\n");
    }

    if (isPrime(n)) {
        printf("Prime number\n");
    } else {
        printf("Not a prime number\n");
    }
    return 0;
}
