#include <stdio.h>
void welcome(){
    printf("Welcome to our shop!\n");
}

void showMenu(){
    printf("\n1. Notebook - 250\n");
    printf("2. Pen      - 50\n");
    printf("3. Bag      - 2000\n");
    printf("4. Bottle   - 500\n");
    printf("5. Pencil   - 30\n");
}
int getprice(int choice){
    int prices[5] = {250, 50, 2000, 500, 30};

    return prices[choice - 1];
}
int itemprice(int price, int quantity){
    return price * quantity;
}

int calcsubtotal(int totals[]){
    int subtotal = 0;
    for(int i = 0; i < 5; i++){
        subtotal += totals[i];
    }

    return subtotal;
}
float calcdiscount(int subtotal){
    if(subtotal >= 5000){
        return subtotal * 0.10f;
    }
    return 0;
}

float calcbill(int subtotal, float discount){
    return subtotal - discount;
}
int continueshopping(){
    int answer;
    printf("Continue shopping? (1 = Yes, 0 = No): ");
    scanf("%d", &answer);

    if (answer == 0){
        return 0;
    }
    return answer == 1;
}

void receipt(int quantities[], int total[], int subtotal, float discount, float bill){
    char names[5][10] = {"Notebook", "Pen", "Bag", "Bottle", "Pencil"};

    for(int i = 0; i < 5; i++){
        if(quantities[i] > 0){
            printf("%-10s\t%d\t%d\t%d\n",
                   names[i], quantities[i], getprice(i + 1), total[i]);
        }
    }

    printf("\nsubtotal: %d\n", subtotal);
    printf("discount: %.2f\n", discount);
    printf("final bill: %.2f\n", bill);
}

int main(){
    int quantities[5] = {0};
    int total[5] = {0};
    int choice, quantity;
    welcome();

    do{
        showMenu();
        printf("Choose an item(1-5): ");

        if(scanf("%d", &choice) != 1){
            printf("Invalid input.\n");
            return 0;
        }

        if(choice < 1 || choice > 5){
            printf("Invalid choice\n");
            continue;
        }
        printf("Enter quantity: ");

        if(scanf("%d", &quantity) != 1){
            printf("Invalid input.\n");
            return 0;
        }

        if(quantity <= 0){
            printf("Quantity too low\n");
            continue;
        }
        quantities[choice - 1] += quantity;
        total[choice - 1] += itemprice(getprice(choice), quantity);

    }while(continueshopping());

    int subtotal = calcsubtotal(total);
    float discount = calcdiscount(subtotal);
    float bill = calcbill(subtotal, discount);

    receipt(quantities, total, subtotal, discount, bill);
    return 0;
}
