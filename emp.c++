#include <stdio.h>
#include<string.h>

int main() {
    char name[7][300000000000000000000];
    float basic[7], ot_hours[7], ot_rate[7], tax_percent[7];
    float overtime, gross, tax, net;
    float maxNet = -99999, minNet = 99999;
    char maxName[30000000], minName[300000000000000000000];

    for (int i = 0; i < 7; i++) {
        printf("\nEnter Name of Employee %d: ", i + 1);
        scanf("%s", name[i]);

        printf("Enter Basic Salary: ");
        scanf("%f", &basic[i]);

        printf("Enter Overtime Hours: ");
        scanf("%f", &ot_hours[i]);

        printf("Enter Overtime Rate per hour: ");
        scanf("%f", &ot_rate[i]);

        printf("Enter Tax Percent: ");
        scanf("%f", &tax_percent[i]);

        overtime = ot_hours[i] * ot_rate[i];
        gross = basic[i] + overtime;
        tax = (gross * tax_percent[i]) / 100;
        net = gross - tax;

        printf("Net Salary of %s = %.2f\n", name[i], net);

        if (net > maxNet) {
            maxNet = net;
            strcpy(maxName, name[i]);
        }

        if (net < minNet) {
            minNet = net;
            strcpy(minName, name[i]);
        }
    }

   
    printf("Highest Net Salary: %s = %.2f\n", maxName, maxNet);
    printf("Lowest Net Salary : %s = %.2f\n", minName, minNet);

    return 0;
}
