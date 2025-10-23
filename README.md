# Airgead Banking – CS210 Portfolio Reflection

## Summary of the Project
The *Airgead Banking* project is a financial calculator designed to help users visualize how their savings can grow over time. It takes an initial investment, optional monthly deposits, an annual interest rate, and a number of years, then displays a yearly breakdown of account balances. This project demonstrates my ability to use C++ to build interactive, data-driven applications that process user input, perform calculations, and present results in a clear and organized format.

## What I Did Well
I did particularly well with the structure and readability of the code. I used separate functions and classes to keep calculations and display logic organized, which made debugging and updates much easier. I also added clear prompts and formatted output tables that make the results user-friendly and professional-looking. My focus on input validation and logical flow helped ensure that the program runs smoothly and provides accurate results.

## Where I Could Improve
If I were to enhance this project, I would add input persistence (saving and loading user data) and possibly graphical output, such as charts that display balance growth over time. These improvements would make the program more engaging and user-friendly. I could also improve efficiency slightly by optimizing the loop structure that handles yearly calculations and by adding exception handling to make the program more secure against invalid input.

## Most Challenging Code
The most challenging part of the project was getting the compound interest formula to work correctly while also accounting for the timing of monthly deposits. I initially had small discrepancies in totals, but I resolved this by breaking the calculation into smaller, testable pieces and verifying the math at each step. Debugging tools in my IDE and resources like C++ documentation and Stack Overflow were invaluable in tracking down rounding issues and logic errors.

## Transferable Skills
From this project, I gained strong experience in modular design, object-oriented programming, and mathematical modeling using C++. These skills are directly transferable to other projects that involve data processing, financial modeling, or simulation. I also improved my ability to write clean, maintainable code — something I’ll apply across all future programming tasks.

## Maintainability, Readability, and Adaptability
I focused heavily on making the program readable by using consistent indentation, clear variable names, and in-line comments to explain key sections of code. The logic is organized into functions and classes that make the program easy to maintain or expand, such as by adding new financial features or switching to another output format like CSV or JSON. This modular design ensures that anyone viewing or using my code can quickly understand and adapt it.

# Airgead Banking — CS 210 Portfolio Submission

## Overview
Airgead Banking is a C plus plus console program that models investment growth. The user enters an initial deposit, an optional monthly deposit, an annual interest rate, and a number of years, the program then displays yearly balance tables, both without monthly deposits and with monthly deposits. This project demonstrates interactive input handling, correct compound interest calculations, formatted console output, and clean program structure using multiple source files.

## Repository structure
- `main.cpp` entry point, input, output, orchestration
- `InvestmentCalculator.h` class interface
- `InvestmentCalculator.cpp` class implementation

## How to build and run

### Option A, GCC or Clang from a terminal
Windows with MinGW w64, macOS, or Linux

```bash
# compile
g++ -std=c++17 -O2 main.cpp InvestmentCalculator.cpp -o AirgeadBanking

# run
./AirgeadBanking        # on Windows you can run AirgeadBanking.exe
