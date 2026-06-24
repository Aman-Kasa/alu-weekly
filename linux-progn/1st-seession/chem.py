import dis

# ---------------------------------------------------------
# Function 1: Simple arithmetic construct
# ---------------------------------------------------------
def calculate_molarity(moles, volume_liters):
    return moles / volume_liters

# ---------------------------------------------------------
# Function 2: Loop construct
# ---------------------------------------------------------
def calculate_total_mass(atomic_masses):
    total = 0
    for mass in atomic_masses:
        total += mass
    return total

if __name__ == "__main__":
    # =========================================================
    # 1. Run the program and test it for correctness
    # =========================================================
    print("--- 1. Testing Functions for Correctness ---")
    
    # Testing Molarity: 2 moles in 0.5 Liters should be 4.0 M
    molarity_result = calculate_molarity(2, 0.5)
    print(f"Molarity (2 moles, 0.5 L): {molarity_result} M")
    
    # Testing Mass: H2O (approx 1.008 + 1.008 + 15.999 = 18.015)
    mass_result = calculate_total_mass([1.008, 1.008, 15.999])
    print(f"Total Mass (H2O): {mass_result} g/mol\n")


    # =========================================================
    # 2 & 4. Exploration Tools (id, type) & Memory Behavior
    # =========================================================
    print("--- 2 & 4. Investigating Memory Behavior ---")
    
    # A. Integer Interning (Small vs Large Integers)
    # Python pre-allocates small integers (-5 to 256) in memory.
    moles_a = 5
    moles_b = 5
    print(f"Type of moles_a: {type(moles_a)}")
    print(f"ID of moles_a (5): {id(moles_a)} | ID of moles_b (5): {id(moles_b)}")
    print(f"Are IDs the same? {moles_a is moles_b} (Python caches small ints)\n")

    # Large integers fall outside the cached range, so they often get unique memory addresses.
    large_val_a = 5000
    large_val_b = 5000
    print(f"ID of large_val_a: {id(large_val_a)} | ID of large_val_b: {id(large_val_b)}")
    print(f"Are IDs the same? {large_val_a is large_val_b} (Large ints are allocated separately)\n")

    # B. Mutable vs Immutable Data Types
    element_tuple = ("H", "O") # Tuple is Immutable
    element_list = ["H", "O"]  # List is Mutable

    print(f"Original Tuple ID: {id(element_tuple)}")
    element_tuple += ("C",) # Because tuples are immutable, this creates a completely new object in memory.
    print(f"New Tuple ID after adding 'C': {id(element_tuple)}\n")

    print(f"Original List ID: {id(element_list)}")
    element_list.append("C") # Because lists are mutable, the original object is modified in-place.
    print(f"List ID after appending 'C': {id(element_list)}\n")


    # =========================================================
    # 3. Compare different bytecodes for different constructs
    # =========================================================
    print("--- 3. Bytecode Comparison ---")
    
    print("Bytecode for calculate_molarity (Arithmetic Construct):")
    # Notice the BINARY_TRUE_DIVIDE instruction for the math operation
    dis.dis(calculate_molarity)
    
    print("\nBytecode for calculate_total_mass (Loop Construct):")
    # Notice the GET_ITER and FOR_ITER instructions that control the loop execution
    dis.dis(calculate_total_mass)
