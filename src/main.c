#include <stdio.h>

#define MAX_STUDENTS 100
#define MAX_ROOMS 30
#define ROOM_CAPACITY 3

int rollNo[MAX_STUDENTS];
char name[MAX_STUDENTS][50];
int roomNo[MAX_STUDENTS];
float feeDue[MAX_STUDENTS];
int feePaid[MAX_STUDENTS];
int studentCount = 0;

int roomOccupied[MAX_ROOMS];

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

void allocateRoom(void) {
    int roll, room, index = -1;

    if (studentCount == 0) {
        printf("No students found. Add a student first.\n");
        return;
    }

    printf("Enter Roll No of student: ");
    scanf("%d", &roll);

    for (int i = 0; i < studentCount; i++) {
        if (rollNo[i] == roll) {
            index = i;
        }
    }

    if (index == -1) {
        printf("Student not found.\n");
        return;
    }

    if (roomNo[index] != 0) {
        printf("This student already has Room %d.\n", roomNo[index]);
        return;
    }

    printf("Enter Room No (1-%d): ", MAX_ROOMS);
    scanf("%d", &room);

    if (room < 1 || room > MAX_ROOMS) {
        printf("Invalid room number.\n");
    } else if (roomOccupied[room - 1] >= ROOM_CAPACITY) {
        printf("Room %d is full.\n", room);
    } else {
        roomNo[index] = room;
        roomOccupied[room - 1]++;
        printf("Room %d allocated to %s.\n", room, name[index]);
    }
}

void viewOccupancyStatus(void) {
    printf("\n%-10s %-12s %-10s\n", "Room No", "Occupied", "Status");
    for (int i = 0; i < MAX_ROOMS; i++) {
        printf("%-10d %d/%-10d ", i + 1, roomOccupied[i], ROOM_CAPACITY);
        if (roomOccupied[i] == 0) {
            printf("Empty\n");
        } else if (roomOccupied[i] < ROOM_CAPACITY) {
            printf("Available\n");
        } else {
            printf("Full\n");
        }
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
                allocateRoom();
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
                viewOccupancyStatus();
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