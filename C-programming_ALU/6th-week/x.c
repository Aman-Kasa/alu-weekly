#include<stdio.h>

int main(){
int a = 10;
int b = 20;
int *p;

p = &a;
*p = 14;

p = &b;
*p = 25;

return 0;
}


