#include <stdio.h>


int add(int *a, int *b, int *c) {
    int sum;
    sum=*a + *b + *c;
    return sum;
}

int main() {

    int x, y, z;

    printf("Enter the three integers: ");
    scanf("%d %d %d",&x,&y,&z);

    int sum; 
    sum=add(&x,&y,&z);
    printf("The sum of the three integers is: %d\n", sum);

    return 0;
}