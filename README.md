# Lexical Analyzer in C

## Overview

This project implements a **Lexical Analyzer** in C that scans a C source file and classifies each token into its corresponding lexical category. It also performs basic lexical error detection and reports invalid tokens without terminating the analysis.

The analyzer reads the input source file character by character, identifies valid tokens, and displays their type along with the corresponding line number.

---

## Features

### Token Identification

- Keywords
- Identifiers
- Integer Constants
- Floating Point Constants
- Octal Constants
- Hexadecimal Constants
- Character Literals
- String Literals
- Operators
  - Arithmetic Operators
  - Increment/Decrement Operators
  - Relational Operators
  - Logical Operators
- Delimiters
- Preprocessor Directives
- Header Files

---

## Error Detection

The lexical analyzer also detects various lexical errors such as:

- Invalid Variable Declaration
- Invalid Float Values
- Invalid Octal Values
- Invalid Hexadecimal Values
- Invalid Character Literals
- Invalid String Literals
- Invalid Header Files
- Unmatched Parentheses `()`
- Unmatched Curly Braces `{}`

All errors are collected and displayed after lexical analysis is completed.

---

## Technologies Used

- C Programming
- File Handling
- String Manipulation
- Character Processing
- Standard C Library
- Modular Programming

---

## Project Structure

```
.
├── main.c          # Program entry point
├── lexical.c       # Lexical analysis functions
├── operators.c     # Operator identification
├── preprocess.c    # Preprocessor directive and bracket validation
├── main.h          # Function declarations and macros
├── test.c          # Sample input file for testing the code
└── README.md
```

---

## Sample Output

The analyzer displays tokens in the following format:

```
LINE      TOKEN                 TYPE
--------------------------------------------
4         int                   Keyword
4         main                  Identifier
4         (                     Delimiter
4         )                     Delimiter
5         {                     Delimiter
6         0xAA                  Hexadecimal
7         0127                  Octal
8         12.3f                 Float
9         "Hello"               String Literal
10        'A'                   Character Literal
```

If lexical errors are found:

```
Errors:

Line 7 : Error : Invalid Hexadecimal value.
Line 11 : Error : Invalid Octal value.
Line 18 : Error : Invalid Float value.
Line 23 : Error : Invalid String Literal.
Line 30 : Error : '(' opened but not closed.
```

---

## How to Compile

```bash
gcc *.c -o lexical_analyzer
```

---

## How to Run

```bash
./lexical_analyzer test.txt
```
