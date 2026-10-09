#include <stdio.h>

int main(void) {
    int choice;

    do {
        printf("\n===== Hostel Room Management System =====\n");
        printf("1. Add Student\n");
        printf("2. Allocate Room\n");
        printf("3. Search Student\n");
        printf("4. Update Student Record\n");
        printf("5. Delete Student Record\n");
        printf("6. View All Students\n");
        printf("7. View Occupancy Status\n");
        printf("8. Fee Tracking\n");
        printf("9. Generate Report\n");
        printf("0. Save and Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Add Student selected.\n");
                break;
            case 2:
                printf("Allocate Room selected.\n");
                break;
            case 3:
                printf("Search Student selected.\n");
                break;
            case 4:
                printf("Update Student Record selected.\n");
                break;
            case 5:
                printf("Delete Student Record selected.\n");
                break;
            case 6:
                printf("View All Students selected.\n");
                break;
            case 7:
                printf("View Occupancy Status selected.\n");
                break;
            case 8:
                printf("Fee Tracking selected.\n");
                break;
            case 9:
                printf("Generate Report selected.\n");
                break;
            case 0:
                printf("Saving and exiting...\n");
                break;
            default:
                printf("Invalid choice, try again.\n");
        }
    } while (choice != 0);

    return 0;
}