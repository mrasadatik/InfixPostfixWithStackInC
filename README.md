# InfixPostfixWithStack

**East West University**  
**Course**: CSE207 - Data Structures  
**Instructor**: Dr. Hasan Mahmood Aminul Islam  
**Teaching Assistant**: Abdullah Al Tamim  

**Student**: Md Asaduzzaman Atik (2023-1-60-130)

---

## **Project Overview**

This project, **InfixPostfixWithStack**, implements a program that converts mathematical expressions from **infix notation** (e.g., `A + B * (C - D)`) to **postfix notation** (e.g., `A B C D - * +`) using a **stack-based approach**. The implementation adheres to modular programming practices and is organized into multiple files and folders for better structure and maintainability.

This is part of an assignment for the **CSE207 - Data Structures** course at East West University.

---

## **Assignment Details**

### **Problem Statement**
The program converts an infix expression into a postfix expression using a stack to handle operator precedence and parentheses.

### **Rules to Follow**
- **Precedence of Operators:**  
  `*` and `/` > `+` and `-`. Operators with the same precedence are evaluated **left-to-right**.
- **Parentheses:**  
  Parentheses override the precedence rules and ensure operations inside them are performed first.
- **Stack Usage:**  
  The stack is used to store operators and parentheses during conversion.

### **Input:**  
- A valid infix expression consisting of:
  - Operands: Single characters such as `A`, `B`, `C`, etc.
  - Operators: `+`, `-`, `*`, `/`.
  - Parentheses: `(` and `)`.
- Input is assumed to be correctly formatted, but the program includes additional validation.

### **Output:**  
The equivalent postfix expression.

---

### **Sample Input/Output**

| **Infix Expression (Input)** | **Postfix Expression (Output)** |
|-------------------------------|-----------------------------------|
| `A + B`                       | `A B +`                         |
| `A + B * C`                   | `A B C * +`                     |
| `(A + B) * (C - D)`           | `A B + C D - *`                 |
| `A + B * (C - D) / E`         | `A B C D - * E / +`             |

---

## **Folder Structure**

The project is structured as follows:

```plaintext
📁InfixPostfixWithStack
├── 📁include                # Header files
│   ├── conversion.h         # Conversion logic header
│   ├── helpers.h            # Helper functions header
│   ├── stack.h              # Stack operations header
│   └── validation.h         # Input validation header
├── 📁src                    # Source files
│   ├── conversion.c         # Conversion logic implementation
│   ├── helpers.c            # Helper functions implementation
│   ├── stack.c              # Stack operations implementation
│   └── validation.c         # Input validation implementation
├── InfixPostfixWithStack.cbp  # Code::Blocks project file
├── InfixPostfixWithStack.depend  # Dependency file for Code::Blocks
└── main.c                  # Main program file
```

---

## **How to Build and Run**

### **1. Prerequisites**
- A C compiler (e.g., `gcc` or MinGW).  
- Code::Blocks IDE or any other IDE supporting `.cbp` files.  

### **2. Steps to Run in Code::Blocks**
1. Open **Code::Blocks**.  
2. Open the project by loading the file **InfixPostfixWithStack.cbp**.  
3. Build the project:
   - Go to the **Build** menu and click on **Build**.  
4. Run the project:
   - Go to the **Build** menu and click on **Run**.  
5. Enter a valid infix expression when prompted. The program will output the corresponding postfix expression.

### **3. Command-Line Compilation**
To compile manually using `gcc`, navigate to the `InfixPostfixWithStack` directory and run the following command:

```bash
gcc -o postfix main.c src/*.c -Iinclude
```

Run the program:

```bash
./postfix
```

---

## **Features**

### **Validation**
- Ensures the infix expression:
  - Contains only valid characters (operands, operators, and parentheses).
  - Has balanced parentheses.
  - Does not contain consecutive operators.  

### **Stack-Based Conversion**
- Uses a dynamic stack implemented via a linked list to:
  - Handle operator precedence.
  - Temporarily store operators and parentheses during conversion.

### **Error Handling**
- Provides descriptive error messages for:
  - Invalid characters.
  - Unbalanced parentheses.
  - Memory allocation failures.

---

## **File Descriptions**

### **Header Files (`include/`)**
1. **`stack.h`**  
   - Declares functions for stack operations (`push`, `pop`, `peek`, etc.).  

2. **`helpers.h`**  
   - Declares utility functions for operator precedence and character classification.  

3. **`validation.h`**  
   - Declares functions for validating the infix expression.  

4. **`conversion.h`**  
   - Declares the main function to convert infix to postfix.  

### **Source Files (`src/`)**
1. **`stack.c`**  
   - Implements stack operations using a linked list.  

2. **`helpers.c`**  
   - Implements utility functions like checking operator precedence and character types.  

3. **`validation.c`**  
   - Implements input validation, including parentheses checking and operator placement.  

4. **`conversion.c`**  
   - Implements the core logic to convert an infix expression to postfix using a stack.  

### **Main File (`main.c`)**
- Handles user interaction and coordinates the execution of the program by invoking validation and conversion functions.  

---

## License

The code in this repository is open for **personal use**, **testing**, and **educational purposes** under the terms of the **MIT License**.

### Conditions

- You are free to use, modify, and distribute the code for **personal or educational purposes**.
- **Commercial use** of the code is prohibited unless explicit permission is granted by the author.
- This repository will **not** be updated further. Any modifications or improvements made based on this project should be tracked in a separate repository.
