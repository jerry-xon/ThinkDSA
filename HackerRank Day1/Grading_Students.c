#include <stdio.h>

void gradingStudents(int grades[], int n) {
    for (int i = 0; i < n; i++) {
        
        if (grades[i] >= 38) {
           
            int nextMultipleOf5 = ((grades[i] / 5) + 1) * 5;
            
            if (nextMultipleOf5 - grades[i] < 3) {
                grades[i] = nextMultipleOf5; 
            }
        }
        printf("%d\n", grades[i]);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int grades[n];
    
 
    for (int i = 0; i < n; i++) {
        scanf("%d", &grades[i]);
    }
    

    gradingStudents(grades, n);
    
    return 0;
}
