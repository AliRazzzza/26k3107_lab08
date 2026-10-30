#include <stdio.h>
float getBonus(float basic, int years){
    if (years > 5) {
        return basic * 0.15f;
    }

    if (years >= 3) {
        return basic * 0.10f;
    }

    return basic * 0.05f;
}

float getTax(float salary) {
    if (salary > 100000) {
        return salary * 0.05f;
    }

    return 0;
}
int main(){
    float basic, bonus, salary, tax;
    int years;
    printf("Enter basic salary: ");
    scanf("%f", &basic);
    printf("Enter years of service: ");
    scanf("%d", &years);
    if (basic < 0 || years < 0) {
        printf("Invalid input.\n");
        return 0;
    }
    bonus = getBonus(basic, years);
    salary = basic + bonus;
    tax = getTax(salary);
    printf("Basic salary: Rs. %.2f\n", basic);
    printf("Bonus: Rs. %.2f\n", bonus);
    printf("Tax: Rs. %.2f\n", tax);
    printf("Final salary: Rs. %.2f\n", salary - tax);
    return 0;
}
