# Lexical Analyzer

## Authors
- Bolaños Guerrero Julián
- Castillo Soto Jacqueline
- Galindo Reyes Daniel Adrian
- Isidro Castro Karen Cristina
- Zurita Cámara Juan Pablo

 ## Presentation Link
 [Presentation.pdf](https://github.com/user-attachments/files/16988640/presentacion_compressed.pdf)<br>
 [Repository Link](https://github.com/DanielGalindoDev/Team06)

## Introduction

A lexical analyzer is a fundamental phase in the process of compiling or interpreting programming languages. Its primary function is to convert a sequence of source code characters into a sequence of tokens—lexical units with meaning in the language. This step simplifies the input for the parser by dividing it into manageable tokens representing keywords, identifiers, numbers, operators, or delimiters.

## Problem to be Solved

The goal is to create a lexical analyzer capable of processing strings or complete files written in C language. It will segment the input into lexemes and assign appropriate tokens according to rules defined by a Deterministic Finite Automaton (DFA). This analyzer will identify elements such as keywords, operators, identifiers, and symbols, which are essential for further source code analysis. The expected outcome is a list of lexemes with their respective tokens.

## Theoretical Framework

### Justification

- **Theoretical Foundation**:
  - **Finite Automata (DFA/NFA)**: Efficient for scanning input and recognizing lexical patterns, enabling linear time processing of tokens.
  - **Regular Expressions**: Useful for defining token patterns like constants and literals, and can be converted into DFA for efficient tokenization.

- **Practical Application**:
  - **Programming Languages**: Essential for converting human-readable code into machine-executable instructions.
  - **Text Processing Tools**: Useful for interpreters, configuration file processors, and custom scripting languages.

- **Comprehensive Token Recognition**:
  - Recognizes literals, constants, keywords, operators, punctuation, special characters, and identifiers.

- **Efficiency and Performance**:
  - Utilizes DFA for efficient single-pass processing with O(n) time complexity, suitable for large codebases.

- **Educational and Research Value**:
  - Provides insights into automata theory, compiler construction, and robust error handling.

- **Token Counting and Data Insights**:
  - Offers insights into code complexity, operator frequency, and variable usage patterns.

### Theoretical Models

1. **Formal Languages and Regular Grammars**:
  - **Regular Expressions**: Define patterns for tokens.
  - **Regular Grammars**: Generate regular languages for token rules.

2. **Finite Automata**:
  - **Deterministic Finite Automata (DFA)**: Efficient with a single transition per state and input symbol.
  - **Nondeterministic Finite Automata (NFA)**: Can be converted to DFA through determinization.

3. **Algorithm for Constructing DFA from Regular Expressions**:
  - **NFA Construction**: From a regular expression.
  - **Determinization**: Conversion of NFA to DFA.
  - **Minimization**: Optimizing DFA by reducing states.

4. **Transition Tables**:
  - Used for efficient token recognition in finite automata.

5. **Complexity Theory**:
  - Lexical analysis operates in O(n) time complexity.

6. **Lexical Errors and Extended Automata**:
  - Handles unrecognized sequences with an error state.

7. **Symbol Table and Hash Table Theory**:
  - Efficient identifier storage and lookup.

## Dependencies

- **C Compiler**: Required for compiling the lexical analyzer.
- **Files**:
  - `lex.c`: Contains lexical analyzer functions.
  - `lex.h`: Header file with function and data structure declarations.
  - `test.c`: Main program for processing C files.

## Installation Guide

1. **Download Files**: Obtain `lex.c`, `lex.h`, and `test.c` from the GitHub repository Team06.
2. **Compile**: Use `gcc` to compile the files:
    ```bash
    gcc -o a.out test.c lex.c
    ```
3. **Executable**: The result will be `a.out` (Linux/macOS) or `a.exe` (Windows).

## Usage

1. **Run the Analyzer**:
    ```bash
    ./a.out path/to/CodeTest.c
    ```
2. **Output**: Displays tokens and their types in the console.

## Considerations

- **Comment Structure**: Multi-line comments are not handled.
- **Special Characters**: Complex sequences and non-ASCII characters are not supported.
- **Multi-line Strings**: May not be correctly handled.
- **Numeric Constant Suffixes**: Not explicitly addressed.
# Architecture and Design

The design of this project consists of a series of states. First, the lexical analyzer will access a text file containing the code to be analyzed. Subsequently, this text will be processed by a module where the code elements are checked using a finite automaton. Additionally, the tokens found during this process will be recorded.

## Automaton

To accept or reject statements, regular expressions are used to determine the structure of tokens in the code, including compound tokens such as identifiers, strings, special characters, and escape sequences. Regular expressions define patterns to be recognized and must be conformed to a grammar that provides a formal and generalized structure to understand how these patterns are grouped and structured. This grammar helps organize and classify tokens, simplify and optimize the analysis process, and facilitate implementation in code.

The automaton is composed of 37 states, with `q0` as the initial state and 20 final states.

### Identifiers

This part of the finite automaton accepts strings representing the program's identifiers. It includes regular expressions for identifiers that start with uppercase letters followed by uppercase or lowercase letters, numbers, underscores, or end of a sentence. Another expression handles identifiers starting with a slash, followed by uppercase letters, lowercase letters, numbers, or underscores.

Regular Expressions:
- `[a-z][a-z]*[a-zA-Z0-9_$]`
- `[A-Z|_|$][a-zA-Z0-9_$]*`
- `_[a-zA-Z0-9_$]*`
- `$[a-zA-Z0-9_$]*`

### Punctuation

All grouping and punctuation symbols accepted by the C language are reviewed in the lexical part of the code. These characters transition to an accepting state regardless of whether their corresponding closing symbol is present later.

Regular Expression:
- `[ \[\]\(\)\{\}\,;:\? ]`

### Strings

Strings in C language must be enclosed in double quotes. A string starts with a double quote and ends with a double quote. Inside, it can contain any ASCII symbol, including letters, numbers, and punctuation symbols.

Regular Expression:
- `"[^"]*"`

### Operators

The automaton identifies arithmetic, logical, and comparison operators, both simple and compound. Arithmetic symbols are accepted, and an assignment operator may follow them, but an assignment symbol is not accepted without a preceding arithmetic operator. Logical and comparison operators can be compound and may be followed by more comparison or assignment operators, but an assignment symbol is not accepted without a preceding comparison operator.

Regular Expressions:
- Arithmetic Operators: `[=|\*/%!^\][=]? \+[+=]? -[-=>]?`
- Logical and Comparison Operators: `&[&=]? \|[\|]? <(<)?(=)? >(>)?(>)?(=)? ~`

### Escape Characters and ASCII Notation

Escape characters must be enclosed in single quotes and preceded by a slash (`\`). The valid escape sequences include `b`, `n`, `r`, `t`, `v`, `a`, `f`, `‘`, `”`, `?`. ASCII code can also be represented, composed of three numbers or letters.

Regular Expression for Escape Characters:
- `'\\[bnrtvaf‘“?]'`

Example for ASCII Code:
- `'\077'` corresponds to the character `?` in the ASCII table.
<br>
### Identifiers<br>
  <img width="690" alt="Captura de pantalla 2024-09-12 a la(s) 10 33 18 p m" src="https://github.com/user-attachments/assets/62091ed4-0bdb-4ef8-a328-0c5524533415"><br>
### Punctuation<br>
  <img width="459" alt="Captura de pantalla 2024-09-12 a la(s) 10 33 55 p m" src="https://github.com/user-attachments/assets/3e2af2fc-70f9-4a15-874c-cd92697f0a2f"><br>
### Strings<br>
<img width="669" alt="Captura de pantalla 2024-09-12 a la(s) 10 34 17 p m" src="https://github.com/user-attachments/assets/0546c766-96fa-409b-ab0c-2d2b07d2c3a9"><br>
### Operators<br>
  <img width="1199" alt="Captura de pantalla 2024-09-12 a la(s) 10 34 50 p m" src="https://github.com/user-attachments/assets/f87b3701-61e6-46f2-8a30-5ef57abe354e"><br>
### Escape Characters and ASCII Notation<br>
  <img width="1059" alt="Captura de pantalla 2024-09-12 a la(s) 10 35 22 p m" src="https://github.com/user-attachments/assets/33599b42-3072-4f5d-bf1a-4ae0c77622f5"><br>
<br><br><br>
# Implementation

The project was implemented using three files: two `.c` files and one `.h` header file. The architecture followed is described as follows:

## File: `test.c`

This file is responsible for executing the lexical analyzer and essentially serves as the main function of our library. It handles both input files and strings entered via the console. The input is processed line by line and sent to a lexical analyzer function located in another file. This file also prints the tokens and the total token count. Key components of this file include:

- Use of the `fgets` function.
- A `while` loop that processes the input file.
- Utilization of standard C libraries.

## File: `lex.c`

This file defines the behavior of the library, including the lexer, the automata in the form of state matrices, and functions for transitions, classification, and token printing. The key structures and functions in this file include:

- `printTokenInfo()`: Prints the information of the tokens passed to it.
- `lexicalAnalyzer()`: Contains the logic for handling states, line breaks, categorizing, and tokenizing lexemes.
- `isKeyWord()`: Receives a lexeme and determines if it is a keyword.
- `categorizeLexeme()`: Categorizes any lexeme and assigns its corresponding token.
- `const char FA[][97]`: Transition matrix that generates all the code for the automata specified; this is the main core of the program.

## File: `lex.h`

This header file defines data types used in `lex.c`, such as `token`, `tokens_info`, and the general `lexertype` structure. It also includes the function prototypes for the functions implemented in `lex.c`.

