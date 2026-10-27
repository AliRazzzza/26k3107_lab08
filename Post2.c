#include <stdio.h>

int main(){
    int sales[2][3][4], branchTotal[2] = {0}, weekTotal[4] = {0};
    int total, best, bestProduct, bestWeek = 0;
    int r,c;
    for(int i = 0; i < 2; i++){
        printf("\nBranch %d\n", i+1);
        for(r = 0; r < 3; r++){
            printf("Enter sales for product %d over 4 weeks: ", r+ 1);
            for(c = 0; c < 4; c++){
                scanf("%d", &sales[i][r][c]);
            }
        }
    }

    for(int i = 0; i < 2; i++){
        best = -1;
        bestProduct = 0;
        printf("\nBranch %d results:\n",i+1);
        for(r = 0; r < 3; r++){
            total = 0;
            for(c = 0; c < 4; c++){
                total += sales[i][r][c];
                weekTotal[c] += sales[i][r][c];
            }
            branchTotal[i] += total;
            printf("Product %d total: %d\n",r+1, total);
            if(total > best){
                best = total;
                bestProduct = r;
            }
        }

        printf("Highest selling product: %d\n", bestProduct+1);
        printf("Branch total: %d\n", branchTotal[i]);
    }
    for(c= 1; c < 4; c++){
        if(weekTotal[c] > weekTotal[bestWeek]){
            bestWeek = c;
        }
    }

    printf("\nWeek with highest sales: %d\n", bestWeek + 1);
    if(branchTotal[0] > branchTotal[1]){
        printf("Highest Branch is 1");
    }else{
        printf("Highest branch is 2");
    }

    return 0;
}
