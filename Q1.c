/*1.Write a C program to implement a hash function on student SAP-ID and categorize them in to their 10 families based on the last three digits.
 Example: Student with SAP-ID 5000423 belongs to family 9 and student with SAP-ID 5000425 belongs to family 2 based on last three digits.
*/
#include <stdio.h>

int main() {
    int sap_id, last_three, family;

    printf("Enter SAP-ID: ");
    scanf("%d", &sap_id);

    last_three = sap_id % 1000;

    family = last_three % 10;

    printf("Last 3 digits: %d\n", last_three);
    printf("Student belongs to Family: %d\n", family);

    return 0;
}


