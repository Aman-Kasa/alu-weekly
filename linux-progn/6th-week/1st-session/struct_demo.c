#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    float salary;
} Employee;

typedef struct {
    char street[100];
    char city[50];
    char zipcode[10];
} Address;

typedef struct {
    int id;
    char name[50];
    Address* address;  // Pointer to dynamically allocated address
    float salary;
} EmployeeWithAddress;

int main() {
    // Dynamic allocation for a single Employee
    Employee* emp = malloc(sizeof(Employee));
    if (emp == NULL) {
        fprintf(stderr, "Memory allocation for single Employee failed\n");
        exit(1);
    }
    emp->id = 1;
    strcpy(emp->name, "Alice");
    emp->salary = 60000.0f;

    printf("Single Employee:\nID: %d, Name: %s, Salary: %.2f\n\n",
           emp->id, emp->name, emp->salary);

    // Allocate array of 10 employees
    int count = 10;
    Employee* employees = calloc(count, sizeof(Employee));
    if (employees == NULL) {
        fprintf(stderr, "Memory allocation for employees array failed\n");
        free(emp);
        exit(1);
    }

    // Initialize first employee in the array
    employees[0].id = 2;
    strcpy(employees[0].name, "John Doe");
    employees[0].salary = 50000.0f;

    printf("First Employee in Array:\nID: %d, Name: %s, Salary: %.2f\n\n",
           employees[0].id, employees[0].name, employees[0].salary);

    // Allocate employee with nested address
    EmployeeWithAddress* empWithAddr = malloc(sizeof(EmployeeWithAddress));
    if (empWithAddr == NULL) {
        fprintf(stderr, "Memory allocation for EmployeeWithAddress failed\n");
        free(emp);
        free(employees);
        exit(1);
    }

    empWithAddr->address = malloc(sizeof(Address));
    if (empWithAddr->address == NULL) {
        fprintf(stderr, "Memory allocation for Address failed\n");
        free(empWithAddr);
        free(emp);
        free(employees);
        exit(1);
    }

    // Initialize employee with address
    empWithAddr->id = 3;
    strcpy(empWithAddr->name, "Bob Smith");
    empWithAddr->salary = 70000.0f;
    strcpy(empWithAddr->address->street, "123 Main St");
    strcpy(empWithAddr->address->city, "Metropolis");
    strcpy(empWithAddr->address->zipcode, "12345");

    printf("Employee with Address:\nID: %d, Name: %s, Salary: %.2f\n",
           empWithAddr->id, empWithAddr->name, empWithAddr->salary);
    printf("Address: %s, %s, %s\n",
           empWithAddr->address->street,
           empWithAddr->address->city,
           empWithAddr->address->zipcode);

    // Free allocated memory
    free(empWithAddr->address);
    free(empWithAddr);
    free(employees);
    free(emp);

    return 0;
}
