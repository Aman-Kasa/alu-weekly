/* ============================================================
 * Employee Management System
 * Demonstrates dynamic memory allocation, resizable arrays,
 * and correct cleanup of nested heap allocations in C.
 * ============================================================ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 2

typedef struct {
    int id;
    char name[50];
    char department[30];
    float salary;
} Employee;

typedef struct {
    Employee* employees;
    int count;
    int capacity;
} EmployeeList;

/* ---------- Function prototypes ---------- */
EmployeeList* createList(void);
int addEmployee(EmployeeList* list, int id, const char* name, const char* dept, float salary);
int removeEmployee(EmployeeList* list, int id);
void displayEmployees(const EmployeeList* list);
void freeList(EmployeeList* list);

/* ============================================================
 * createList
 * Allocates the EmployeeList "header" (ONE struct) and,
 * separately, a contiguous array of Employee structs to hold
 * the records (an ARRAY allocation). These are two distinct
 * heap blocks: the array pointer is stored inside the header,
 * so this is a "nested allocation".
 * ============================================================ */
EmployeeList* createList(void) {
    EmployeeList* list = malloc(sizeof(EmployeeList));          /* single struct */
    if (!list) {
        fprintf(stderr, "createList: failed to allocate EmployeeList\n");
        return NULL;
    }

    list->employees = malloc(sizeof(Employee) * INITIAL_CAPACITY); /* array */
    if (!list->employees) {
        fprintf(stderr, "createList: failed to allocate employee array\n");
        free(list);
        return NULL;
    }

    list->count = 0;
    list->capacity = INITIAL_CAPACITY;

    printf("[DEBUG] createList: list=%p employees=%p capacity=%d\n",
           (void*)list, (void*)list->employees, list->capacity);

    return list;
}

/* ============================================================
 * addEmployee
 * Appends a new employee, doubling the array's capacity with
 * realloc() whenever it fills up. Returns 1 on success, 0 on
 * failure: NULL list, NULL name/department, duplicate id, or
 * a failed realloc.
 * ============================================================ */
int addEmployee(EmployeeList* list, int id, const char* name, const char* dept, float salary) {
    if (!list) {
        fprintf(stderr, "addEmployee: list is NULL\n");
        return 0;
    }
    if (!name || !dept) {
        fprintf(stderr, "addEmployee: name/department cannot be NULL\n");
        return 0;
    }

    for (int i = 0; i < list->count; i++) {
        if (list->employees[i].id == id) {
            fprintf(stderr, "addEmployee: id %d already exists\n", id);
            return 0;
        }
    }

    if (list->count == list->capacity) {
        int newCapacity = list->capacity * 2;
        Employee* resized = realloc(list->employees, sizeof(Employee) * newCapacity);
        if (!resized) {
            fprintf(stderr, "addEmployee: realloc failed, list unchanged\n");
            return 0;
        }
        list->employees = resized;
        list->capacity = newCapacity;
        printf("[DEBUG] addEmployee: resized capacity to %d (employees=%p)\n",
               list->capacity, (void*)list->employees);
    }

    Employee* e = &list->employees[list->count];
    e->id = id;
    strncpy(e->name, name, sizeof(e->name) - 1);
    e->name[sizeof(e->name) - 1] = '\0';
    strncpy(e->department, dept, sizeof(e->department) - 1);
    e->department[sizeof(e->department) - 1] = '\0';
    e->salary = salary;

    list->count++;
    return 1;
}

/* ============================================================
 * removeEmployee
 * Finds the employee with the given id and shifts later
 * elements left by one to close the gap. Returns 1 if found
 * and removed, 0 if the list is empty or the id isn't present.
 * ============================================================ */
int removeEmployee(EmployeeList* list, int id) {
    if (!list || list->count == 0) return 0;

    for (int i = 0; i < list->count; i++) {
        if (list->employees[i].id == id) {
            for (int j = i; j < list->count - 1; j++) {
                list->employees[j] = list->employees[j + 1];
            }
            list->count--;
            return 1;
        }
    }
    return 0;
}

/* ============================================================
 * displayEmployees
 * Read-only traversal; takes a const pointer since it never
 * modifies the list.
 * ============================================================ */
void displayEmployees(const EmployeeList* list) {
    if (!list || list->count == 0) {
        printf("  (no employees to display)\n");
        return;
    }
    printf("  %-4s %-20s %-15s %-10s\n", "ID", "Name", "Department", "Salary");
    printf("  %-4s %-20s %-15s %-10s\n", "--", "----", "----------", "------");
    for (int i = 0; i < list->count; i++) {
        printf("  %-4d %-20s %-15s %-10.2f\n",
               list->employees[i].id,
               list->employees[i].name,
               list->employees[i].department,
               list->employees[i].salary);
    }
}

/* ============================================================
 * freeList
 * Must free the INNER array before the OUTER struct.
 * Freeing `list` first would lose the only pointer to
 * `list->employees`, permanently leaking that block.
 * ============================================================ */
void freeList(EmployeeList* list) {
    if (!list) return;
    printf("[DEBUG] freeList: freeing employees=%p then list=%p\n",
           (void*)list->employees, (void*)list);
    free(list->employees);   /* inner allocation first */
    free(list);               /* then the outer struct  */
}

/* ============================================================
 * main - exercises the required testing scenarios
 * ============================================================ */
int main(void) {
    printf("=== Test 1: Basic functionality (add 5, display) ===\n");
    EmployeeList* list = createList();
    addEmployee(list, 1, "Alice Johnson", "Engineering", 75000.00f);
    addEmployee(list, 2, "Bob Smith",     "Marketing",   62000.00f);
    addEmployee(list, 3, "Carol Davis",   "Engineering", 81000.00f);
    addEmployee(list, 4, "David Lee",     "Sales",       58000.00f);
    addEmployee(list, 5, "Eve Martinez",  "HR",          67000.00f);
    displayEmployees(list);
    printf("  count=%d capacity=%d\n\n", list->count, list->capacity);

    printf("=== Test 2: Resize beyond initial capacity ===\n");
    addEmployee(list, 6, "Frank Wright", "Engineering", 90000.00f);
    addEmployee(list, 7, "Grace Kim",    "Finance",     72000.00f);
    addEmployee(list, 8, "Henry Chen",   "Sales",       61000.00f);
    addEmployee(list, 9, "Ivy Patel",    "Marketing",   65000.00f);
    displayEmployees(list);
    printf("  count=%d capacity=%d\n\n", list->count, list->capacity);

    printf("=== Test 3: Edge cases ===\n");
    EmployeeList* emptyList = createList();
    printf("  remove from empty list  -> %d (expected 0)\n",
           removeEmployee(emptyList, 1));
    printf("  remove non-existent id 999 -> %d (expected 0)\n",
           removeEmployee(list, 999));
    printf("  remove existing id 3    -> %d (expected 1)\n",
           removeEmployee(list, 3));
    printf("  add with NULL name      -> %d (expected 0)\n",
           addEmployee(list, 10, NULL, "Sales", 50000.00f));
    displayEmployees(list);
    printf("\n");

    printf("=== Cleanup ===\n");
    freeList(list);
    freeList(emptyList);
    printf("done.\n");

    return 0;
}
