# time_bank_app

## TECHNOLOGIES & TOOLS
- Code Editor: Visual Studio Code
- G++ Version: 13.2.0
- Version Control: Git

## INSTRUCTION
- Clone branch from origin/dev
- Pull requests have to be made into origin/dev branch
- Pull requests to origin/dev requires at least 2 code review approval before merging
- PR to origin/master require code review from the whole team before merging

## NAMING CONVENTION
### 1. Branch:
- [Purpose]-[FeatureName]-[DeveloperName]
- Example: `Dev-Login-Cuong`, `Test-BookSupporter-Cuong`, `Debug-FetchData-Cuong`

### 2. Variable:
- Camel Case
- Example: `variableName`

### 3. Function / Method
- Camel Case
- Example: `functionName()`, `methodName()`

### 4. Class
- Pascal Case
- Example: `ClassName {}`

## CODE FORMAT
### 1. Header & Footer
Follow the code order below:
```
// Define the header (in ".h file")
#ifndef _HEADER_H_
#define _HEADER_H_

// Include header file
#include "Header.h"
...

// Include libraries
#include <iostream>
...

// Using namespaces
using std::cin;
using std::cout;
using std::string;
using std::vector;
...

// Define constant variables
#define CONSTANT_VARIABLE 10
...

// Source code
...

// Endif of the define the header (in ".h file")
#endif
```

### 2. Class
```
class ParentClass {
    private:
        string name;
        int num;
        vector<int> numList;
    public:
        ParentClass(string nameVal = "", int numVal = 0, vector<int> numListVal = {})
        : name(nameVal), num(numVal), numList(numListVal) {
            // ParentClass Constructor...
        }

        // Other methods
        ...
};

class ChildClass : public ParentClass {
    public:
        ChildClass(string nameVal = "", int numVal = 0, vector<int> numListVal = {})
        : ParentClass(nameVal, numVal, numListVal) {
            // ChildClass Constructor...
        }
        // Other methods
        ...
};
```

The code format section might have some update later if necessary ...

## EXTRA NOTES
- Required to write your program in C++ programming language only.
- Need to demonstrate the OOP skills that you have learned in the course.
- Must thoroughly document your code using comments (// or /* … */).
- The Code should be separated logically into multiple source code (.cpp) and header (.h) files that overall have a single purpose, i.e. your code should be structured in a way that each file has a clear scope and goal. Make sure you use the header files and header guard correctly.
- For function / method, passing parameters by reference is preferred than pass by value for efficiency.
- Encourage to utilize the dynamic memory allocation knowledge.