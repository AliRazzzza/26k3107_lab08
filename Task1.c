#include <stdio.h>
void welcome(){
    printf("Welcome to the ATM\n");
}

void displayAmount(float amount){
    printf("Withdrawal amount: %.2f\n", amount);
}

float getWithdrawalLimit(){
    return 50000;
}

float calculateBalance(float balance, float amount){
    return balance - amount;
}

int checkWithdrawal(float balance, float amount, float limit)
{
    return amount > 0 && amount <= balance && amount <= limit;
}

int main(){
    float balance;
    float amount;
    float limit = getWithdrawalLimit();

    welcome();
    printf("Enter your balance: ");
    scanf("%f", &balance);
    printf("Withdrawal limit: %.2f\n", limit);
    printf("Enter withdrawal amount: ");
    scanf("%f", &amount);

    if(amount <= 0){
        printf("Invalid input\n");
        return 0;
    }

    displayAmount(amount);
    if(checkWithdrawal(balance, amount, limit)){
        balance = calculateBalance(balance, amount);
        printf("Withdrawal successful\n");
    }else{
        printf("Withdrawal rejected\n");
    }
    printf("Current balance: %.2f\n", balance);

    return 0;
}
