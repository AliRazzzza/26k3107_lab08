#include <stdio.h>
void showMenu(){
    printf("\n1. Check balance\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. Exit\n");
    printf("Enter choice: ");
}
float deposit(float balance, float amount) {
    if (amount <= 0) {
        printf("Deposit must be positive\n");
    } else {
        balance += amount;
        printf("Updated balance: %.2f\n", balance);
    }
    return balance;
}
float withdraw(float balance, float amount){
    if (amount <= 0) {
        printf("Withdrawal must be positive\n");
    } else if (amount > 10000) {
        printf("Maximum withdrawal is 10000 per transaction\n");
    } else if (amount > balance) {
        printf("Insufficient balance\n");
    } else {
        balance -= amount;
        printf("Updated balance: %.2f\n", balance);
        if (balance < 5000) {
            printf("Warning low balance\n");
        }
    }
    return balance;
}
int main(){
    float balance = 20000, amount;
    int choice;
    do {
        showMenu();

        if (scanf("%d", &choice) != 1) {
            return 0;
        }

        switch (choice) {
            case 1:
                printf("Current balance: %.2f\n", balance);
                break;

            case 2:
                printf("Enter deposit amount: ");

                if (scanf("%f", &amount) != 1) {
                    return 0;
                }

                balance = deposit(balance, amount);
                break;

            case 3:
                printf("Enter withdrawal amount: ");

                if (scanf("%f", &amount) != 1) {
                    return 0;
                }

                balance = withdraw(balance, amount);
                break;

            case 4:
                printf("Thank you\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while(choice != 4);
    return 0;
}
