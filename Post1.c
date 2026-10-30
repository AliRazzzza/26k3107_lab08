#include <stdio.h>
int main(){
    int Studentmarks[2][3][4], sectionT[2] = {0};
    int bestst;
    int r, c, total= 0, count = 0, highest1 = 0, highest2 = 0, best = 0;
    float avg1;
    for(int i = 0; i < 2; i++){
        printf("\nSection %d\n", i+1);
        for (r = 0; r < 3; r++) {
            printf("Enter 4 marks for student %d: ", r + 1);
            for (c = 0; c < 4; c++) {
                scanf("%d", &Studentmarks[i][r][c]);
            }
        }

    }
    
    for(int i =0; i < 2; i++){
        printf("\nSection %d\n", i+ 1);
        for (r = 0; r < 3; r++) {
            total = 0;
            for (c = 0; c < 4; c++) {
                total += Studentmarks[i][r][c];
            }
            avg1 = total / 4.0f;
            sectionT[i] += total;
            printf("Student %d: Total = %d, Average = %.2f\n", r + 1, total, avg1);
            if (avg1 >= 50) {
                count++;
            }
            if (total > best) {
                best = total;
                bestst = r + 1;
            }
        }
        printf("Highest-scoring student: %d\n", bestst);
    }
    printf("\nStudents with average of atleast 50: %d", count);
    if(sectionT[0] > sectionT[1]){
        printf("\nSection 1 has the highest average");
    } else if(sectionT[0] < sectionT[1]){
        printf("\nSection 2 has the highest average");
    }
  return 0;
}
