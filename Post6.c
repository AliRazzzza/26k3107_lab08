#include <stdio.h>
void checkLoan(int age, float salary, float payments) {
    float remaining = salary - payments;
    int eligible = 1;
    if (age < 21) {
        printf("Not eligible age must be 21\n");
        eligible = 0;
    }

    if (salary < 50000) {
        printf("Not eligible: Salary must be at least 50000\n");
        eligible = 0;
    }

    if (remaining < salary * 0.40f) {
        printf("Not eligible: Less than 40%% of salary remains\n");
        eligible = 0;
    }

    if (eligible) {
        printf("Eligible for a loan\n");
        printf("Remaining monthly income: %.2f\n", remaining);
        printf("Maximum loan amount: %.2f\n", remaining * 10);
    }
}

int main(){
    int age;
    float salary, payments;
    printf("Enter age: ");
    scanf("%d", &age);
    printf("Enter monthly salary: ");
    scanf("%f", &salary);
    printf("Enter existing monthly loan payments: ");
    scanf("%f", &payments);

    if (age < 0 || salary < 0 || payments < 0) {
        printf("Invalid input.\n");
        return 0;
    }

    checkLoan(age, salary, payments);
    return 0;
}
