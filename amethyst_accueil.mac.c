/*
 Programmer: Robyn Sterling of 602-B
 
 Course: CS
 
 Format: This program is a combination of a database and an accounting styling format.
 
 Description: It will allow the user to manage a set of employees and records, given the ability to do
 things from searching, display, adding, removing and updating...the user will also have the ability to compute
 an individual's customized pay slip as well as a company's report, by inputting a minimal amount of data. These
 pieces of data will all be recorded in separate files, for ease of data allocation.
 
 Program Start Date: November 24, 2022
 
 Program End Date: April 7, 2024
 */
 
 //Libraries
 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
 #include <stdbool.h>
 #include <time.h>
 #include <unistd.h>

 // Function prototypes
 void menu(void);
 void employf(void);
 void PAYSLIP(void);
 void report(void);
 void goodbye(void);
 
 //Constants
 #define t_emp 6//defining size of primary array
 #define MAX_LINE_SIZE 100 // Maximum size of a line in the file
 
 //declaration and initialization of variables
 typedef struct
 {
  int id;
  char fname[50];
  char lname[50];
  char sex;
  int acc;
  int trn;
 } employ;
 
 //Global Variables
 int total_ud, total_hw;//due to the simplicity of these variables, data leakages are not at risk
 float total_np, total_com, total_td;//due to the simplicity of these variables, data leakages are not at risk
 FILE *file, *file2, *file3, *file4;//declaring three files
 //declaring elements of the structure, "employ" to be set in the array, "EMP" with an array size of, "t_emp".
 employ EMP [t_emp];
 
 
 //Algorithm/Function for color graphic
 void mor () {
   printf("\033[0;35m");
 }
 
 //Algorithm/Function for color graphic.2 and BG color graphic
 void mor_alt_BG (){
     printf ("\033[1;95m");
     printf ("\033[47m");
 }
 
 //Algorithm that welcomes the user to the system
 void welcome (){
     mor_alt_BG ();//calls to the background graphic function
     printf ("ËšËš Welcome to the Amethyst Accueil System ËšËš\n");
     printf("  ___  ___  ___  ____ ______ __  __ _  _  __  ______\n");
     printf(" // \\\\ ||\\\\//|| ||    | || | ||  || \\\\// (( \\ | || |\n");
     printf(" ||=|| || \\/ || ||==    ||   ||==||  )/   \\\\    ||  \n");
     printf(" || || ||    || ||___   ||   ||  || //   \\_))   ||  \n");
     printf("                                                    \n");
     printf(" // \\\\  //    //   || || ||    || ||                \n");
     printf(" ||=|| ((    ((    || || ||==  || ||                \n");
     printf(" || ||  \\\\__  \\\\__ \\\\_// ||___ || ||__|             \n");
     printf("                                                    \n");
 
     printf("       ____      \n");
     printf("      (|   \\     \n");
     printf("       |    | _  \n");
     printf("      _|    ||/  \n");
     printf("CASA  (/\\___/ |__/  PIEDRAS PRECIOSAS\n");
 
 
 
 }
 
 //Algorithm that wishes the user off the system
 void goodbye (){
     mor_alt_BG ();//calls to the background graphic function
     printf ("Thank you for using the Amethyst Accueil Distribution Firm Ltd system...Goodbye!");
 
         printf("  ___  ___  ___  ____ ______ __  __ _  _  __  ______\n");
     printf(" // \\\\ ||\\\\//|| ||    | || | ||  || \\\\// (( \\ | || |\n");
     printf(" ||=|| || \\/ || ||==    ||   ||==||  )/   \\\\    ||  \n");
     printf(" || || ||    || ||___   ||   ||  || //   \\_))   ||  \n");
     printf("                                                    \n");
     printf(" // \\\\  //    //   || || ||    || ||                \n");
     printf(" ||=|| ((    ((    || || ||==  || ||                \n");
     printf(" || ||  \\\\__  \\\\__ \\\\_// ||___ || ||__|             \n");
     printf("                                                    \n");
 
     printf("       ____      \n");
     printf("      (|   \\     \n");
     printf("       |    | _  \n");
     printf("      _|    ||/  \n");
     printf("CASA  (/\\___/ |__/  PIEDRAS PRECIOSAS\n");
 }
 //Algorithm/Function that clears screem
 void WIPE (){
     printf("\033[2J\033[H");//implements a clear screen
 }
 
 void clearInputBuffer() {
     int c;
     while ((c = getchar()) != '\n' && c != EOF);
 }
 
 //Algorithm/Function for Passcode implementation
 void password (void)
 {//begins the password function
 
      //declaration and initialization of variables
      int ent_pass;
      int x = 0;
 
 
     printf("   _                  _    __       \n");
     printf(" _//                 ' )  /         \n");
     printf(" /   __ _,  o ____    /  /_   _  __ \n");
     printf("/___(_)(_)_<_/ / <_  (__//_)_</_/ (_\n");
     printf("        /|                          \n");
     printf("       |/                           \n");
 
      mor();//implements text color as purple
      printf ("Enter the secret code to gain access to the system\n");//prompts the user to enter a secret code
      scanf ("%d", &ent_pass);//reads the secret code entered
      WIPE ();//calls to the WIPE function
 
         if (ent_pass == 5791)
         {//begins the if statement
             printf ("You've been granted access\a\n");//outputs a success message
             menu();//calls to the menu function
         }//ends the if statement
 
         else
         {//begins the else of the if statement
             WIPE ();//calls to the WIPE function
             printf ("Incorrect Secret Code...Try Again!\n");//outputs a failure message
             printf ("You have three attempts\n");//outputs the amount of attempts the user has to gain access to the system
 
             for (x = 1;x <= 3 && ent_pass != 5791; x++)//gives the user three attempts to enter the system through loop
             {//begins the for loop
 
                 printf ("\nRe-enter the secret code\n");//prompts the user to re-enter the secret code
                 scanf ("%d", &ent_pass);//reads the entered secret code
                 WIPE ();//calls to the WIPE function
 
                     if(ent_pass == 5791)//if this condition is determined to be true, the user gains entry into the system
                     {//begins the if statement
                      printf ("You've been granted access\a\n");//prompts success message
                      menu();//calls to the menu function after entering the correct code
                     }//ends the if statement
 
                     if(ent_pass != 5791)//if this condition is determined to be true, the user is denied of entry into the system
                     {//begins the if statement
                      printf ("Remaining Attempts: %d \n",3-x);//calculates the amount of attempts the user has left after each loop
                      printf ("Access Status = Not Granted\n");//displays the user with their periodic access status
                     }//ends the if statement
 
             }//ends the for loop
 
         }//ends the else of the if statement
 
 }//ends the password function
 
 //Algorithm/Function that prompts menu
 void menu(void)
 {//begins the menu function
 
     //declaration and initialization of variables
     int opt;
 
     do
     {//begins do...while loop
 
 
         printf ("___________________________________________________________________Main Menu\n");
             printf("   __                                     __                  _   \n");
     printf("  /  )           _/_ /            _/_    /  )                //  \n");
     printf(" /--/ ______  _  /  /_  __  , _   /     /--/ _. _. . . _  o //   \n");
     printf("/  (_/ / / <_</_<__/ /_/ (_/_/_)_<__   /  (_(__(__(_/_</_<_</_   \n");
     printf("                          /                                        \n");
 
 
 
         //prints the main menu with options to the user
         printf ("\nFrom the menu below, pick a number that corresponds with your desired option\n");
         printf ("Manage Employees............................................................1\n");
         printf ("Print Pay Slip..............................................................2\n");
         printf ("Print Report................................................................3\n");
         printf ("If you wish to exit the system, enter 0\n\n");
         scanf ("%d", &opt);//reads the option inputted by the user
         WIPE ();//calls to the WIPE function
 
             switch (opt)
             {//begin of switch statement
 
                 case 1: printf ("You've selected option 1: Manage Employees\n");//outputs the option the user had selected
                 employf();//calls to the manage employee function
                 break;
 
                 case 2: printf ("You've selected option 2: Print Pay Slip\n");//outputs the option the user had selected
                 PAYSLIP();//calls to the payslip function
                 break;
 
                 case 3: printf ("You've selected option 3: Print Report\n");//outputs the option the user had selected
                 report();//calls to the report function
                 break;
 
                 case 0: goodbye();//calls to the goodbye function
                         exit (0);
 
                 default: printf ("Invalid Choice\n");
             }//end of switch statement
 
 
     }while (opt >1 || opt <5);//end of do...while loop; this iteration will repeatedly prompt the menu until the user decides to exit the system with the terminator 0
 
 }//end of the menu function
 
 // getCurrentDate Function Definition - Gets the current date of Report Production
 void getCurrentDate(char *date) {
     time_t t = time(NULL);
     struct tm *tm = localtime(&t);
     strftime(date, 20, "%Y-%m-%d", tm);
 }
 
 
 //Payslip Function Definition - Prints Pay Slip of Each Employee
 void PAYSLIP (void)
 {//begin of payslip function
     char date[20];
     getCurrentDate(date);
 
 
     //declaration and initialization of variables
     int hrs_wrk, ov_hrs, units_dis, empid;
     float bas_pay, g_p, ot, com, net_p;
     float ss_tax, st_inc_tax, NHT, pen, insur, t_deduc;
     char cho [10];
     const float bas_hrly_r = 65.00;
     const int bas_hrs = 40;
     const float over_r = 1.5;
 
     printf ("For which employee would you like to print the payslip?\n");
     scanf ("%d", &empid);
 
     file = fopen ("employee.txt", "r");
     if (file == NULL){
         printf ("An error occurred while opening the file. \n");
         return;
     }
 
     while (fscanf(file, "%d,%49[^,],%49[^,],%c,%d,%d\n", &EMP[0].id, EMP[0].fname, EMP[0] .lname, &EMP[0].sex, &EMP[0].acc, &EMP[0].trn) == 6) {
         if (EMP[0].id == empid) { // If the ID matches the search ID, update the record
 
         printf("\nProcessing for Employee ID: %d\n", EMP[0].id);//displays to the user the ID for which the payslip is being generated for
         printf ("Enter the number of hours worked by the employee\n");//prompts the user to enter the amount of hours worked by the employee
         scanf ("%d", &hrs_wrk);
         total_hw = total_hw + hrs_wrk;
 
         if (hrs_wrk > bas_hrs)//this condition of the if statement is based on the assumption that the worker had worked overtime
         {
             ov_hrs = hrs_wrk - bas_hrs;
             ot = ov_hrs * over_r * bas_hrly_r;
             bas_pay = bas_hrly_r * bas_hrs;
         }
         else if (hrs_wrk == bas_hrs)//this condition of the if statement is based on the assumption that the worker had worked no overtime
         {
             ov_hrs = hrs_wrk - bas_hrs;
             ot = 00.00;
             bas_pay = bas_hrly_r * bas_hrs;
         }
         else if (hrs_wrk < bas_hrs)//this condition of the if statement is based on the assumption that the worker had worked below the average work hours
         {
             ov_hrs = 0;
             ot = 00.00;
             bas_pay = bas_hrly_r * hrs_wrk;
         }
 
         fflush(stdin);
 
         printf ("Enter the number of units distributed by the employee\n");//prompts the user to enter the amount of units the worker had distributed
         scanf ("%d", &units_dis);
         total_ud = total_ud + units_dis;
 
         //Calculate Commission
         if (units_dis >= 200  && units_dis <250)//this condition rewards the worker with the lowest amount of commission, if they distributed between 200 and 249
         {
             com = 50.00;
             total_com = total_com + com;
         }
             else if(units_dis >=250 && units_dis<300)//this condition rewards the worker with the second lowest amount of commission, if they distributed between 250 and 299
             {
             com = 100.00;
             total_com = total_com + com;
             }
                 else if (units_dis >=300 && units_dis<400)//this condition rewards the worker with the third lowest amount of commission, if they distributed between 300 and 399
                 {
                     com = 150.00;
                     total_com = total_com + com;
                 }
                     else if (units_dis >= 400)//this condition rewards the worker with the highest amount of commission, if they distributed anything higher or equivalent to 400
                     {
                         com = 200.00;
                         total_com = total_com + com;
                     }
                         else //this condition rewards the worker with no commission, if no other conditions were met
                         {
                             com = 00.00;
                             total_com = total_com + com;
                         }
 
         g_p = com + ot + bas_pay;//calculates the gross pay of the employee
 
         //calculates the deductions
         ss_tax = g_p * 0.01;
         st_inc_tax = g_p * 0.07;
         NHT = g_p * 0.04;
         pen = g_p * 0.25;
         insur = g_p * 0.03;
         t_deduc = ss_tax + st_inc_tax + NHT + pen + insur;//sums up the total amount of deductions
         total_td = total_td + t_deduc;//totals the total deductions of each employee
 
         net_p = g_p - t_deduc;//calculates the net pay of the employee
         total_np = total_np + net_p;//totals the net pay of each employee
         WIPE ();//calls to the WIPE function
 
         printf ("\nWould you like to print the employee's pay slip, Yes or No?\n");
         scanf ("%s", cho);
 
         WIPE ();
             if (strcmp (cho, "Yes")==0)
             {
             printf ("Pay Slip being created...wait...\n");
             sleep (5);//pauses the system for roughly 5 seconds
             printf ("\n|======================Amethyst Accueil - Distribution Firm Ltd================================\n");
             printf ("\n|______________________________________________________________________________________________\n");
             printf ("\n|__________________________________Pay Slip for ID: %d_________________________________________\n", EMP[0].id);
             printf ("\n|______________________________________________________________________________________________\n");
             printf ("\n|Earnings       |        Hours          |        Rate            |           Current           \n");
             if (hrs_wrk > bas_hrs){
             printf ("\n|Standard Pay   |        %d             |        %.2f            |           %.2f              \n", bas_hrs,bas_hrly_r,bas_pay);
             }
             else{
             printf ("\n|Standard Pay   |        %d             |        %.2f            |           %.2f              \n", hrs_wrk,bas_hrly_r,bas_pay);
             }
             printf ("\n|Overtime Pay   |        %d             |        %.2f            |           %.2f              \n", ov_hrs, over_r,ot);
             printf ("\n|Commission     |                       |                        |           %.2f              \n", com);
             printf ("\n|Gross Pay      |                       |                        |           %.2f              \n", g_p);
             printf ("\n|==============================================================================================\n");
             printf ("\n|Deductions                             |                     Current                          \n");
             printf ("\n|Social Security Tax                    |                      %.2f                            \n", ss_tax);
             printf ("\n|State Income Tax                       |                      %.2f                            \n", st_inc_tax);
             printf ("\n|NHT                                    |                      %.2f                            \n", NHT);
             printf ("\n|Pension Tax                            |                      %.2f                            \n", pen);
             printf ("\n|Insurance Tax                          |                      %.2f                            \n", insur);
             printf ("\n|Total Deductions                       |                      %.2f                            \n", t_deduc);
             printf ("\n|Net Pay                                |                      %.2f                            \n", net_p);
             printf ("\n|______________________________________________________________________________________________\n");
 
             file3 = fopen ("payslip.txt", "a");
             if (file3 == NULL)
             {
                 printf ("An error has occurred while opening this file\n");
                 return;
             }
 
             fprintf (file3, "\n|====================================================================================Date: %s\n", date);
             fprintf (file3, "\n|======================Amethyst Accueil - Distribution Firm Ltd================================\n");
             fprintf (file3, "\n|______________________________________________________________________________________________\n");
             fprintf (file3, "\n|__________________________________Pay Slip for ID: %d_________________________________________\n", EMP[0].id);
             fprintf (file3, "\n|______________________________________________________________________________________________\n");
             fprintf (file3, "\n|Earnings       |        Hours          |        Rate            |           Current           \n");
             fprintf (file3, "\n|Standard Pay   |        %d             |        %.2f            |           %.2f              \n", bas_hrs,bas_hrly_r,bas_pay);
             fprintf (file3, "\n|Standard Pay   |        %d             |        %.2f            |           %.2f              \n", hrs_wrk,bas_hrly_r,bas_pay);
             fprintf (file3, "\n|Overtime Pay   |        %d             |        %.2f            |           %.2f              \n", ov_hrs, over_r,ot);
             fprintf (file3, "\n|Commission     |                       |                        |           %.2f              \n", com);
             fprintf (file3, "\n|Gross Pay      |                       |                        |           %.2f              \n", g_p);
             fprintf (file3, "\n|==============================================================================================\n");
             fprintf (file3, "\n|Deductions                             |                     Current                          \n");
             fprintf (file3, "\n|Social Security Tax                    |                      %.2f                            \n", ss_tax);
             fprintf (file3, "\n|State Income Tax                       |                      %.2f                            \n", st_inc_tax);
             fprintf (file3, "\n|NHT                                    |                      %.2f                            \n", NHT);
             fprintf (file3, "\n|Pension Tax                            |                      %.2f                            \n", pen);
             fprintf (file3, "\n|Insurance Tax                          |                      %.2f                            \n", insur);
             fprintf (file3, "\n|Total Deductions                       |                      %.2f                            \n", t_deduc);
             fprintf (file3, "\n|Net Pay                                |                      %.2f                            \n", net_p);
             fprintf (file3, "\n|______________________________________________________________________________________________\n");
 
             fclose (file3);
 
             printf ("Press enter to proceed\n");
             getchar();
             }
             else if (strcmp (cho, "No")==0)
             {
                 printf ("To proceed, press enter...\n");
             }
 
             else
             {
                 printf ("Invalid Response...Proceeding...Press enter\n");
             }
             getchar();
         }
     }
     printf("Press enter to continue...\n");
     clearInputBuffer();
     getchar();
     WIPE ();
     printf ("\nPress the enter key to go back to the menu\n");
     getchar();
 }
 
 //Report Function Definition - Prints the report
 void report (void){
 
     char ans [10];
     char date[20];
     getCurrentDate(date);
 
     WIPE ();
     printf ("Would you like to print the Report, Yes or No?\n");
     scanf ("%9s", ans);
 
     if (strcmp(ans, "Yes")==0){
         printf ("+++++++++++++++++++++++++++++=Amethyst Accueil Distributing Firm Ltd.+++++++++++++++++++++++++++\n");
         printf ("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
         printf ("++++++++++++++++++++++++++++++++++++++++R E P O R T+++++++++++++++++++++++++++++++++++++++++++++\n");
         printf ("The total amount of units distributed is                                                       %d\n", total_ud);
         printf ("The total amount of hours worked by employees is:                                              %d\n", total_hw);
         printf ("The sum of net pays distributed to employees is:                                               %.2f\n", total_np);
         printf ("The sum of commissions awarded to employees is:                                                %.2f\n", total_com);
         printf ("The sum of deductions subtracted from Employee's Gross Pays is:                                %.2f\n", total_td);
         printf("Press enter to continue...\n");
         clearInputBuffer();
         getchar();
 
         // Creating and writing to file4
         FILE *file4 = fopen("report.txt", "w");
         if (file4 == NULL) {
             printf("An error has occurred while opening file4\n");
             return;
     }
 
         fprintf(file4, "Date: %s\n", date);
         fprintf(file4, "Total Units Distributed: %d\n", total_ud);
         fprintf(file4, "Total Hours Worked: %d\n", total_hw);
         fprintf(file4, "Total Net Pays Distributed: %.2f\n", total_np);
         fprintf(file4, "Total Commissions Awarded: %.2f\n", total_com);
         fprintf(file4, "Total Deductions: %.2f\n", total_td);
         fclose(file4);
 
         printf("Press enter to continue...\n");
         getchar();
     }
     WIPE();//calls to the wipe function
 
 }
 
 
 void employf(void)
 {
 
     fflush (stdin);
 
     int sel, search_num;
     bool foundb = false;
     int found = 0;
     char line[MAX_LINE_SIZE];
 
 
     do{//the menu2.0 function prompt resides here; it stems off of the first option being "Manage Employees"
 
             printf("   __                                     __                  _   \n");
     printf("  /  )           _/_ /            _/_    /  )                //  \n");
     printf(" /--/ ______  _  /  /_  __  , _   /     /--/ _. _. . . _  o //   \n");
     printf("/  (_/ / / <_</_<__/ /_/ (_/_/_)_<__   /  (_(__(__(_/_</_<_</_   \n");
     printf("                          /                                        \n");
     printf ("___________________________________________________________________Employee Menu\n");
 
 
          printf("\n    _|      _|  _|_|_|_|  _|      _|  _|    _|\n");
     printf("    _|_|  _|_|  _|        _|_|    _|  _|    _|\n");
     printf("    _|  _|  _|  _|_|_|    _|  _|  _|  _|    _|\n");
     printf("    _|      _|  _|        _|    _|_|  _|    _|\n");
     printf("    _|      _|  _|_|_|_|  _|      _|    _|_|  \n");
 
 
             printf("\n");
     printf("+------------------------------------------------------------+\n");
     printf("| Select an option                                           |\n");
     printf("+------------------------------------------------------------+\n");
     printf("| 1. Display Employees                                       |\n");
     printf("+------------------------------------------------------------+\n");
     printf("| 2. Update Employee                                         |\n");
     printf("+------------------------------------------------------------+\n");
     printf("| 3. Search for an Employee                                  |\n");
     printf("+------------------------------------------------------------+\n");
     printf("| 4. Delete Employee                                         |\n");
     printf("+------------------------------------------------------------+\n");
     printf("| 5. Add Employee                                            |\n");
     printf("+------------------------------------------------------------+\n");
     printf("| 0. Return to the main menu                                 |\n");
     printf("+------------------------------------------------------------+\n");
         scanf  ("%d", &sel);//scans the selection the user inputs after being shown menu2.0
         WIPE ();//calls to the WIPE function
 
             switch (sel)
             {
             case 1: printf ("Selected Option: 1...Display Employees\n");
 
                 file = fopen("employee.txt", "r"); // Open file in read mode
 
                 if (file == NULL) {
                     printf("An error has occurred while opening the file\n");
                     return;
                 }
 
                 printf("Employee records:\n");
 
                 // Read and display each line in the file
                 while (fgets(line, MAX_LINE_SIZE, file) != NULL) {
                     printf("%s", line);
                 }
 
                 fclose(file);
                 break;
 
             case 2: printf ("Selected Option 2: Update Employee\n");
 
                 file = fopen("employee.txt", "r"); // Open original file in read mode
                     if (file == NULL) {
                         printf("Error opening file.\n");
                         return;
                     }
 
                     file2 = fopen("copy.employee.txt", "w"); // Open temporary file in write mode
                     if (file2 == NULL) {
                         printf("Error opening file.\n");
                         fclose(file);
                         return;
                     }
 
                     printf("\nEnter the ID of the Employee to update: \n");
                     scanf("%d", &search_num);
 
                     // Loop through each record in the original file
                     while (fscanf(file, "%d,%49[^,],%49[^,],%c,%d,%d\n", &EMP[0].id, EMP[0].fname, EMP[0] .lname, &EMP[0].sex, &EMP[0].acc, &EMP[0].trn) == 6) {
                         if (EMP[0].id == search_num) { // If the ID matches the search ID, update the record
 
                             printf("Employee found:\n");
                             printf("ID: %d\nFirst Name: %s\nLast Name: %s\nSex: %c\nAccount Number: %d\nTRN: %d\n",
                                 EMP[0].id, EMP[0].fname, EMP[0].lname, EMP[0].sex, EMP[0].acc, EMP[0].trn);
 
                             printf("Enter new first name of Employee:\n");
                             scanf(" %49s", EMP[0].fname);
                             printf("Enter new last name for Employee:\n");
                             scanf(" %49s", EMP[0].lname);
                             printf("Enter new sex of Employee:\n");
                             scanf(" %c", &EMP[0].sex);
                             printf("Enter new Employee's Account Number:\n");
                             scanf("%d", &EMP[0].acc);
                             printf("Enter New Employee's Tax Registration Number:\n");
                             scanf("%d", &EMP[0].trn);
                             found = true; // Set found flag to true
                         }
                         fprintf(file2, "%d,%s,%s,%c,%d,%d\n",EMP[0] .id, EMP[0].fname, EMP[0].lname, EMP[0].sex, EMP[0].acc, EMP[0].trn);
                     }
 
                     fclose(file);  // Close the original file
                     fclose(file2); // Close the temporary file
 
                     if (found) {
                         // Replace the original file with the temporary file
                         remove("employee.txt");
                         rename("copy.employee.txt", "employee.txt");
                         printf("Record updated successfully.\n");
                     } else {
                         printf("Record doesn't seem to exist.\n");
                         remove("copy.employee.txt"); // Remove the temporary file
                     }
 
             break;
 
             case 3:printf ("Selected Option 3...Search for an Employee\n");
 
                     file = fopen("employee.txt", "r");//opens original file in read mode
 
                     printf("Enter the employee ID to search for: ");
                     scanf("%d", &search_num);
                     clearInputBuffer();
 
                     if (file == NULL) {
                         printf("An error has occurred while opening the file\n");
                         return;
                     }
 
                     // Read and search each line in the file
                     while (fgets(line, sizeof(line), file) != NULL) {
                         sscanf(line, "%d,%49[^,],%49[^,],%c,%d,%d", &EMP[0].id, EMP[0].fname, EMP[0].lname, &EMP[0].sex, &EMP[0].acc, &EMP[0].trn);
                         if (EMP[0].id == search_num) {
                             printf("Employee found:\n");
                             printf("ID: %d\nFirst Name: %s\nLast Name: %s\nSex: %c\nAccount Number: %d\nTRN: %d\n",
                                    EMP[0].id, EMP[0].fname, EMP[0].lname, EMP[0].sex, EMP[0].acc, EMP[0].trn);
                             foundb = true;
                             break;
                         }
                     }
 
                     if (!foundb) {
                         printf("Employee with ID %d not found\n", search_num);
                     }
 
                     fclose(file);
 
             break;
 
 
             case 4: printf ("Selected Option 4...Delete Employee\n");
 
                     file = fopen("employee.txt", "r"); // Open original file in read mode
                     if (file == NULL) {
                         printf("Error opening file.\n");
                         return;
                     }
 
                     file2 = fopen("copy.employee.txt", "w"); // Open temporary file in write mode
                     if (file2 == NULL) {
                         printf("Error opening file.\n");
                         fclose(file);
                         return;
                     }
 
                     printf("Enter the ID of the Employee to delete: \n");
                     scanf("%d", &search_num);
 
                     // Loop through each record in the original file
                     while (fscanf(file, "%d,%49[^,],%49[^,],%c,%d,%d\n", &EMP[0].id, EMP[0].fname, EMP[0].lname, &EMP[0].sex, &EMP[0].acc, &EMP[0].trn) == 6) {
                         if (EMP[0].id == search_num) { // If the ID matches the search ID, skip writing this record to the temporary file
                             printf("Employee found and deleted:\n");
                             printf("ID: %d\nFirst Name: %s\nLast Name: %s\nSex: %c\nAccount Number: %d\nTRN: %d\n",
                                 EMP[0].id, EMP[0].fname, EMP[0].lname, EMP[0].sex, EMP[0].acc, EMP[0].trn);
                             foundb = true; // Set found flag to true
                         } else {
                             fprintf(file2, "%d,%s,%s,%c,%d,%d\n", EMP[0].id, EMP[0].fname, EMP[0].lname, EMP[0].sex, EMP[0].acc, EMP[0].trn);
                         }
                     }
 
                     fclose(file);  // Close the original file
                     fclose(file2); // Close the temporary file
 
                     if (foundb) {
                         // Replace the original file with the temporary file
                         remove("employee.txt");
                         rename("copy.employee.txt", "employee.txt");
                         printf("Record deleted successfully.\n");
                     } else {
                         printf("Record doesn't seem to exist.\n");
                         remove("copy.employee.txt"); // Remove the temporary file
                     }
 
          break;
 
 
          case 5: printf ("Selected Option: 5...Add Employee\n");
 
                     file = fopen("employee.txt", "a"); // Open file in append mode
 
                     if (file == NULL) {
                         printf("An error has occurred while opening this file\n");
                         return;
                     }
 
                     for (int i = 0; i < t_emp; i++) {
                         printf("Enter the employee's ID: \n");
                         scanf("%d", &EMP[i].id);
                         clearInputBuffer();
 
                         printf("Enter the employee's first name: \n");
                         scanf("%s", EMP[i].fname);
                         clearInputBuffer();
 
                         printf("Enter the employee's last name: \n");
                         scanf("%s", EMP[i].lname);
                         clearInputBuffer();
 
                         printf("Enter the employee's sex: \n");
                         scanf(" %c", &EMP[i].sex);
                         clearInputBuffer();
 
                         printf("Enter the employee's account number: \n");
                         scanf("%d", &EMP[i].acc);
                         clearInputBuffer();
 
                         printf("Enter the employee's TRN: \n");
                         scanf("%d", &EMP[i].trn);
                         clearInputBuffer();
 
                         fprintf(file, "%d,%s,%s,%c,%d,%d\n",
                                 EMP[i].id,
                                 EMP[i].fname,
                                 EMP[i].lname,
                                 EMP[i].sex,
                                 EMP[i].acc,
                                 EMP[i].trn);
 
                         printf("Employee record successfully stored\n");
 
                         // Ask if the user wants to add another employee
                         if (i < t_emp - 1) {
                             char choice;
                             printf("Do you want to add another employee? (y/n): ");
                             scanf(" %c", &choice);
                             if (choice != 'y' && choice != 'Y')
                                 break;
                         }
                     }
 
                     fclose(file);
 
 
             break;
 
             case 0: menu();//takes the user back to the menu function
             break;
 
             default: printf ("Invalid Choice\n");//prints error message, if the user inputs any other option that didn't exist on the menu
             break;
 
             }//end switch selection
 
         }while (sel>1 || sel<5);//end of do...while loop for menu
 }
 
 // Function prototype Declaration
 int main (void)
 
 {//begin of driver function
     welcome();//calls to the welcome function
     printf ("\nPress enter to continue...waiting\n");
     getchar();
     WIPE ();//calls to the WIPE function
 
     mor ();//calls to color function
     password();//calls to password function
     WIPE();//calls to clear screen function
 }//end of driver function
 
 
