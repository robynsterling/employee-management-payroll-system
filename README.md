# Amethyst Accueil Employee Management and Payroll System

A terminal-based C application for managing employee records and producing payroll documents. I originally developed the project between November 2022 and April 2024 as part of my CAPE Computer Science coursework.

The system combines file-based employee record management with payroll and accounting calculations. This repository contains the original Windows implementation and a portable version adapted for macOS and Linux.

## Features

* Add, display, search, update, and delete employee records
* Store employee information using text-file persistence
* Calculate standard pay, overtime, commission, and deductions
* Generate individualized employee payslips
* Generate company-level payroll reports
* Record the creation date of reports and payslips
* Provide password-controlled access
* Present a menu-driven terminal interface with colored output

## Repository contents

| File                         | Description                                                            |
| ---------------------------- | ---------------------------------------------------------------------- |
| `amethyst_accueil.c`         | Portable version for macOS and Linux                                   |
| `amethyst_accueil_windows.c` | Original Windows-oriented implementation                               |
| `PROJECT_DOCUMENTATION.docx` | Project requirements, system design, diagrams, testing, and evaluation |
| `Makefile`                   | Build instructions for the portable version                            |
| `.gitignore`                 | Prevents generated and private data from being committed               |

## Built with

* C using the C99 standard
* Standard C file input and output
* Structs and arrays
* Functions, loops, and conditional logic
* CSV-style text-file persistence
* ANSI terminal formatting in the portable version

## Build and run on macOS or Linux

You need GCC or another C99-compatible compiler.

Using the provided Makefile:

```bash
make
./amethyst_accueil
```

Without `make`:

```bash
gcc -std=c99 -Wall -Wextra -pedantic amethyst_accueil.c -o amethyst_accueil
./amethyst_accueil
```

Create an empty employee-data file before first use:

```bash
touch employee.txt
```

## Windows version

The original Windows source code is preserved in:

```text
amethyst_accueil_windows.c
```

It was developed in a Windows-oriented C environment and uses features such as `conio.h`, `getch()`, and Windows console commands. It should be compiled using a compatible Windows compiler, such as MinGW GCC.

```bash
gcc -std=c99 amethyst_accueil_windows.c -o amethyst_accueil_windows
amethyst_accueil_windows.exe
```

## Demonstration access

The demonstration access code is:

```text
5791
```

This access code is included only for demonstration purposes and should not be treated as secure authentication.

## Data format

Employee records are stored in `employee.txt` using the following comma-separated format:

```text
employee_id,first_name,last_name,sex,account_number,tax_registration_number
```

Generated payslips and reports are written to:

```text
payslip.txt
report.txt
```

These runtime files are excluded from the repository through `.gitignore`.

## Project documentation

`PROJECT_DOCUMENTATION.docx` contains the complete development process, including:

* Problem definition and project objectives
* Functional and non-functional requirements
* Software development methodology
* Data-flow and entity-relationship diagrams
* Structured and HIPO charts
* Data dictionary
* Interface designs
* Test plan and results
* Error-handling analysis
* Evaluation and proposed improvements

## Portability

The original program was created for a Windows-oriented environment. The portable version replaces non-portable features such as `conio.h`, `getch()`, `system("cls")`, and `system("pause")` so the application can compile and run on macOS and Linux.

## Privacy

Do not commit real employee names, bank-account numbers, tax-registration numbers, payslips, or payroll reports. Runtime employee and payroll files are excluded through `.gitignore`.

## Future improvements

* Strengthen validation for menu and payroll input
* Replace the demonstration access code with secure authentication
* Split the program into separate source and header files
* Replace fixed-size record storage with dynamic allocation
* Add automated tests for payroll calculations and record operations
* Improve the interface while retaining terminal compatibility
