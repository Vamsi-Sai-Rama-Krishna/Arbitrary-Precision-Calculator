# Arbitrary Precision Calculator

## **Overview**
The **Arbitrary Precision Calculator** is a **command-line-based calculator** that supports **large integer arithmetic** beyond standard data type limits. It is implemented using **Doubly Linked List** data structures to efficiently handle operations on numbers of arbitrary size.

This project resembles the **`bc` command**, a terminal-based calculator that provides precise results for even larger operand values.

---

## **Operations**
The project supports the following **arithmetic operations** for **large positive numbers**:
- Addition (`+`)
- Subtraction (`-`)
- Multiplication (`*`)
- Division (`/`)

---

## **Implementation Details**
- **Data Structure**: Doubly Linked List  
- **Language**: C  
- **Operations**: Addition, Subtraction, Multiplication, Division  
- **Precision**: No limitations on number size (except available memory)  

---

## **Usage -> Commands**

### **Commands passed through Command Line Arguments**
```bash
./a.out <operand-1> <operator> <operand-2>
```

### **Example:**
```bash
./a.out 987654323456786543234567 + 765433456787654334567876543345
```

**Output:**
```bash
Result : 765434444441977791354419777912
```

---

