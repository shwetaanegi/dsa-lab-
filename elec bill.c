//wap to find electricity bill for the following data.
//unit are 1-100 , 101-300,above 300 for 3 , 5 and 6 per units.
#include <stdio.h>

int main() {
    int units;
    float bill;

    printf("Enter unit taken: ");
    scanf("%d", &units);

    if (units >=1 && units<= 100) {
        bill = units * 3;
    } 
    else if (units >=101 && units<= 300) {
        bill = units * 5;
    } 
    else if(units > 300) {
        bill = units * 6;
    }

    printf("Electricity Bill = Rs. %.f\n", bill);
    return 0;
}
