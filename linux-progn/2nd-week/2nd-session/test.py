#!/usr/bin/env python3
import calculator

# These functions now run at C speed!
a, b = 10, 5

print(f"Add: {calculator.add(a, b)}")
print(f"Subtract: {calculator.subtract(a, b)}")
print(f"Multiply: {calculator.multiply(a, b)}")
print(f"Divide: {calculator.divide(a, b)}")
