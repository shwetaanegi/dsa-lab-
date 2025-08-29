#include <stdio.h>

int main() {
    int a[10] = {1, 2, 4, 5, 6}; 
    int n=5;
    int p ;
    
    printf("enter no: ");
    scanf("%d",&p);
    
   for (int i = p - 1; i < n - 1; i++) {
        a[i] = a[i + 1];
    }
    n--;
    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
