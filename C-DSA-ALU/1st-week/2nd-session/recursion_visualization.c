#include <stdio.h>

int sum_recursive(int n) {
  if (n == 0) {
    return 0;
  } else {
    return n + sum_recursive(n - 1);
  }
}

int main() {
  int num;
  printf("Enter a positive integer: ");
  scanf("%d", &num);

  if (num < 0) {
      printf("Please enter a non-negative integer.\n");
      return 1;
  }
    
  int sum = sum_recursive(num);
  printf("Sum of numbers from 1 to %d: %d\n", num, sum);
  return 0;
}
