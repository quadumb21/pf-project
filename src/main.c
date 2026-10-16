#include <stdio.h>

#define MAX_STUDENTS 100

int rollNo[MAX_STUDENTS];
char name[MAX_STUDENTS][50];
int roomNo[MAX_STUDENTS];
float feeDue[MAX_STUDENTS];
int feePaid[MAX_STUDENTS];
int studentCount = 0;

void addStudent(void) {
    if (studentCount >= MAX_STUDENTS) {
        printf("Cannot add more students, hostel is full.\n");
        return;
    }

    printf("Enter Roll No: ");
    scanf("%d", &rollNo[studentCount]);

    printf("Enter Name: ");
    scanf("%s", name[studentCount]);

    roomNo[studentCount] = 0;      // not allocated yet
    feeDue[studentCount] = 0;
    feePaid[studentCount] = 0;

    studentCount++;
    printf("Student added successfully.\n");
}

void viewAllStudents(void) {
    if (studentCount == 0) {
        printf("No students found.\n");
        return;
    }

    printf("\n%-10s %-20s %-10s\n", "Roll No", "Name", "Room No");
    for (int i = 0; i < studentCount; i++) {
        printf("%-10d %-20s %-10d\n", rollNo[i], name[i], roomNo[i]);
    }
}

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
                addStudent();
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
                viewAllStudents();
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