#include <stdio.h>
int main(){
    float temp[2][3][4];
    float total, avg, highest;
    int count = 0, wardCount;
    for(int i = 0; i < 2; i++){
        printf("\nWard %d\n",i + 1);
        for(int j = 0; j < 3; j++){
            printf("Enter 4 temperatures for patient %d: ", j+1);
            for(int k = 0; k < 4; k++){
                scanf("%f", &temp[i][j][k]);
            }
        }
    }
    for(int i = 0; i < 2; i++){
        highest = temp[i][0][0];
        wardCount = 0;
        printf("\nWard %d results:\n", i+1);

        for(int j = 0; j < 3; j++){
            total = 0;
            for(int k = 0; k<4; k++){
                total += temp[i][j][k];
                if(temp[i][j][k] > 37.5f){
                    wardCount++;
                    count++;
                }
                if(temp[i][j][k] > highest){
                    highest = temp[i][j][k];
                }
            }
            avg = total / 4;
            printf("Patient %d average: %.2f C\n", j+1, avg);
            if(avg > 38){
                printf("Patient %d has an average above 38\n", j+1);
            }
        }
        printf("Readings above 37.5: %d\n", wardCount);
        printf("Highest temperature: %.2f C\n", highest);
    }
    printf("\nTotal readings above 37.5: %d\n", count);
    return 0;
}
