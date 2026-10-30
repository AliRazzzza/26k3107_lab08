#include <stdio.h>
float getBill(float units, int type){
    if (type == 2){
        return units * 25;
    }
    if(units <= 100){
        return units * 15;
    }

    return 100 * 15 + (units - 100) * 20;
}
float getSurcharge(float bill) {
    if(bill > 5000){
        return bill * 0.05f;
    }

    return 0;
}

int main(){
    float units, bill, surcharge;
    int type;

    printf("Enter units consumed: ");
    scanf("%f", &units);
    printf("1. Domestic\n2. Commercial\nEnter category: ");
    scanf("%d", &type);
    if(units < 0 || (type != 1 && type != 2)){
        printf("Invalid input.\n");
        return 0;
    }

    bill = getBill(units, type);
    surcharge = getSurcharge(bill);
    printf("Units consumed: %.2f\n", units);
    printf("Bill amount: Rs. %.2f\n", bill);
    printf("Surcharge: Rs. %.2f\n", surcharge);
    printf("Final payable amount: Rs. %.2f\n", bill + surcharge);

    return 0;
}
