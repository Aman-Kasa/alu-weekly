#include<stdio.h>

int main(){

int a=10;

long b=20;
int *p;
p = &a;

long *d;
d = &b;

printf("the value of a is %d\n", a);
printf("The address of a is %p\n", &a);
printf("The value of p is %p\n", p);
printf("the value of a is %d\n", *p);
printf("the size of a is %lu \n", sizeof(a));
printf("The size of p is %lu \n", sizeof(p));
printf("the size of b is %lu\n", sizeof(b));
printf("the size of d is %lu\n", sizeof(d));
return 0;
}
