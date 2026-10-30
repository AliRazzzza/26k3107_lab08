#include <stdio.h>
float getBase(float weight){
    if (weight <= 2) {
        return 200;
    }
    if (weight <= 5) {
        return 400;
    }
    return 700;
}
float getDistanceCharge(float distance){
    if (distance > 10) {
        return (distance - 10) * 20;
    }
    return 0;
}

float getDiscount(float total, int member){
    if (member == 1 && total > 1000) {
        return total * 0.10f;
    }
    return 0;
}
int main(){
    float weight, distance, base, extra, total, discount;
    int member;

    printf("Enter weight in kg: ");
    scanf("%f", &weight);
    printf("Enter distance in km: ");
    scanf("%f", &distance);
    printf("Member? (1 = Yes, 0 = No): ");
    scanf("%d", &member);

    if (weight <= 0 || distance < 0 ||
        (member != 0 && member != 1)) {
        printf("Invalid input.\n");
        return 0;
    }
    base = getBase(weight);
    extra = getDistanceCharge(distance);
    total = base + extra;
    discount = getDiscount(total, member);
    printf("Base charges: %.2f\n", base);
    printf("Distance charges: %.2f\n", extra);
    printf("Discount: %.2f\n", discount);
    printf("Final amount: %.2f\n", total - discount);
    return 0;
}
