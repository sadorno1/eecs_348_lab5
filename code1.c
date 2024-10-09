/* 
# Name: Samantha Adorno
# KUID: 3147214
# LAB Assignment: 05
# Description: Give 12 monthly sales figures in an input file and generate reports 
*/

#include <stdio.h>
#include <stdlib.h>

#define MONTHS 12

// function declarations
void print_monthly_sales_report(const char* months[], double sales[]);
void print_sales_summary(const char* months[], double sales[]);
void print_six_month_moving_average(const char* months[], double sales[]);
void print_sales_report_descending(const char* months[], double sales[]);

int main() {
    // array of month names with uppercase first letter
    const char* months[MONTHS] = {"January", "February", "March", "April", "May", "June", 
                                  "July", "August", "September", "October", "November", "December"};
    double sales[MONTHS];
    
    // read sales data from file
    FILE *file = fopen("sales.txt", "r");
    if (file == NULL) {
        // file didn't open
        printf("Error: Could not open sales.txt\n");
        return 1;
    }

    // reading sales from file
    for (int i = 0; i < MONTHS; i++) {
        fscanf(file, "%lf", &sales[i]); // store sales data in array
    }
    fclose(file); // close the file after reading

    // generate the reports with proper case in headings
    printf("Monthly Sales Report For 2024\n");
    print_monthly_sales_report(months, sales);

    printf("\nSales Summary Report:\n");
    print_sales_summary(months, sales);

    printf("\nSix-Month Moving Average Report:\n");
    print_six_month_moving_average(months, sales);

    printf("\nSales Report (Highest To Lowest):\n");
    print_sales_report_descending(months, sales);

    return 0;
}

// function to print the monthly sales report
void print_monthly_sales_report(const char* months[], double sales[]) {
    printf("Month       Sales\n");
    for (int i = 0; i < MONTHS; i++) {
        printf("%-10s $%.2lf\n", months[i], sales[i]); // print month and sales
    }
}

// function to print sales summary (min, max, and average)
void print_sales_summary(const char* months[], double sales[]) {
    double min = sales[0], max = sales[0], sum = 0;
    int min_month = 0, max_month = 0;

    // calculate the sum, minimum, and maximum sales
    for (int i = 0; i < MONTHS; i++) {
        sum += sales[i];
        if (sales[i] < min) {
            min = sales[i]; // update minimum sales
            min_month = i;
        }
        if (sales[i] > max) {
            max = sales[i]; // update maximum sales
            max_month = i;
        }
    }

    double average = sum / MONTHS; // calculate the average sales

    // print the summary with capitalized first letters
    printf("Minimum Sales: $%.2lf (%s)\n", min, months[min_month]);
    printf("Maximum Sales: $%.2lf (%s)\n", max, months[max_month]);
    printf("Average Sales: $%.2lf\n", average);
}

// function to print the six-month moving average report
void print_six_month_moving_average(const char* months[], double sales[]) {
    // calculate and print the moving average for each 6-month period
    for (int i = 0; i <= MONTHS - 6; i++) {
        double sum = 0;
        for (int j = i; j < i + 6; j++) {
            sum += sales[j]; // sum sales over the 6-month period
        }
        double moving_average = sum / 6; // calculate the moving average

        // print in the format January-June, February-July, etc.
        printf("%s-%s $%.2lf\n", months[i], months[i + 5], moving_average);
    }
}

// function to print the sales report in descending order (highest to lowest)
void print_sales_report_descending(const char* months[], double sales[]) {
    // Create a temporary array to store month and sales pairs
    double temp_sales[MONTHS];
    const char* temp_months[MONTHS];

    // Copy sales and months to temporary arrays
    for (int i = 0; i < MONTHS; i++) {
        temp_sales[i] = sales[i];
        temp_months[i] = months[i];
    }

    // Sort sales in descending order using a simple bubble sort for now
    for (int i = 0; i < MONTHS - 1; i++) {
        for (int j = 0; j < MONTHS - i - 1; j++) {
            if (temp_sales[j] < temp_sales[j + 1]) {
                // Swap sales
                double temp = temp_sales[j];
                temp_sales[j] = temp_sales[j + 1];
                temp_sales[j + 1] = temp;

                // Swap corresponding months
                const char* temp_month = temp_months[j];
                temp_months[j] = temp_months[j + 1];
                temp_months[j + 1] = temp_month;
            }
        }
    }

    // Print sorted sales report
    printf("Month       Sales\n");
    for (int i = 0; i < MONTHS; i++) {
        printf("%-10s $%.2lf\n", temp_months[i], temp_sales[i]);
    }
}
