# Lexical Analyzer

## Authors
- Bolaños Guerrero Julián
- Castillo Soto Jacqueline
- Galindo Reyes Daniel Adrian
- Isidro Castro Karen Cristina
- Zurita Cámara Juan Pablo

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

