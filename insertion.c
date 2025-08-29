#include <stdio.h>

int main() {
    int a[10] = {1, 2, 4, 5, 6}; 
    int n = 5;                       
    int num, p;

    printf("Enter to insert: ");
    scanf("%d", &num);

    printf("Enter position to insert: ");
    scanf("%d", &p);
   
   for(int i=n;i>=p;i--)
   {
       a[i+1]=a[i];
   }
    a[p] = num; 
    n++;       

    printf("Array : ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
   

    return 0;
}
