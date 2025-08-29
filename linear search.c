#include <stdio.h>

int main() {
    int a[10] = {1, 2, 4, 5, 6};
    int n = 5;
    int num, found;

    printf("Enter no: ");
    scanf("%d", &num);

    for (int i = 0; i < n; i++) {
        if (a[i] == num) {
            printf("found at %d", i + 1);
            break;  
        }
    }
    return 0;
}
