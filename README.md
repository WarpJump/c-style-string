# My implementation of c-style-string
## Description
Library and tests for my c-string library, decoration, protection and debug macroses in addition to it.

## Usage
Available simple autotest which can be compilated via
```
g++ main.cpp mystring.cpp -o main.out
```
After compilation executable file can be loanched with ./main.out. Program will automatically run the tests of all basic string functions, and create a file with recorded logs, each message will be duplicated in the terminal. There is a test that shows a nonfatal error to demonstrate capabilities of my assertion system.