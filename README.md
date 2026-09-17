# Amethyst Accueil Employee Management & Payroll System

A terminal-based C application for managing employee records and producing payroll documents. I originally developed this project between November 2022 and April 2024 to combine file-based record management with payroll and accounting calculations.

## Features

- Add, display, search, update, and delete employee records
- Store employee data in a local text file
- Calculate standard pay, overtime, commission, and deductions
- Generate individual payslips
- Generate company-level payroll reports
- Provide a menu-driven terminal interface with ANSI color output

## Built with

- C (C99)
- Standard C file I/O
- Structs, functions, loops, conditionals, and text-file persistence

## Build and run

You need GCC or another C99-compatible compiler.

```bash
make
./amethyst_accueil
```

Without `make`:

```bash
gcc -std=c99 -Wall -Wextra -pedantic amethyst_accueil.c -o amethyst_accueil
./amethyst_accueil
```

The application creates and reads its data files in the directory from which it is run. Create an empty employee file before first use:

```bash
touch employee.txt
```

The demonstration access code is `5791`.

## Data format

Employee records are stored as comma-separated values in `employee.txt`:

```text
employee_id,first_name,last_name,sex,account_number,tax_registration_number
```

Generated payslips and reports are written to `payslip.txt` and `report.txt`.

## Portability note

The original program was written for a Windows-oriented C environment. This repository replaces the non-portable `conio.h`, `getch()`, and Windows console commands so the project compiles on macOS and Linux.

## Privacy

Do not commit real employee, bank-account, or tax-registration data. Runtime data and generated payroll files are excluded through `.gitignore`.

## Future improvements

- Validate all menu and payroll input
- Store passwords securely instead of using a demonstration code
- Split the program into separate source and header files
- Replace fixed-size record storage with dynamic allocation
- Add automated tests for payroll calculations and record operations

