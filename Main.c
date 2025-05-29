#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 50
#define MAX_CLASS 20
#define MAX_DATE 12

// Color codes
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

typedef struct {
    int roll_no;
    char name[MAX_NAME];
    char class_name[MAX_CLASS];
} Student;

typedef struct {
    int roll_no;
    char date[MAX_DATE];
    char status; // 'P' for Present, 'A' for Absent
} Attendance;

void add_student();
void view_students();
void search_student();
void update_student();
void delete_student();
void mark_attendance();
void view_attendance();
void save_student(Student s);
void save_attendance(Attendance a);
void print_main_menu();

int main() {
    int choice;
    while (1) {
        system(CLEAR);
        print_main_menu();
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1: add_student(); break;
            case 2: view_students(); break;
            case 3: search_student(); break;
            case 4: update_student(); break;
            case 5: delete_student(); break;
            case 6: mark_attendance(); break;
            case 7: view_attendance(); break;
            case 0:
                printf(RED "\nExiting the program... Goodbye!\n" RESET);
                exit(0);
            default:
                printf(RED "Invalid choice! Please try again.\n" RESET);
        }

        printf("\nPress Enter to return to the main menu...");
        getchar();
    }
    return 0;
}

void print_main_menu() {
    printf(CYAN "========================================================================================================================================================================\n" RESET);
 printf(YELLOW
    "                  _____ _             _            _             _   _                 _                         _____           _                 \n"
    "                 / ____| |           | |          | |       /\\  | | | |               | |                       / ____|         | |                \n"
    "                | (___ | |_ _   _  __| | ___ _ __ | |_     /  \\ | |_| |_ ___ _ __   __| | __ _ _ __   ___ ___  | (___  _   _ ___| |_ ___ _ __ ___  \n"
    "                 \\___ \\| __| | | |/ _` |/ _ \\ '_ \\| __|   / /\\ \\| __| __/ _ \\ '_ \\ / _` |/ _` | '_ \\ / __/ _ \\  \\___ \\| | | / __| __/ _ \\ '_ ` _ \\ \n"
    "                 ____) | |_| |_| | (_| |  __/ | | | |_   / ____ \\ |_| ||  __/ | | | (_| | (_| | | | | (_|  __/  ____) | |_| \\__ \\ ||  __/ | | | | |\n"
    "                |_____/ \\__|\\__,_|\\__,_|\\___|_| |_|\\__| /_/    \\_\\__|\\__\\___|_| |_|\\__,_|\\__,_|_| |_|\\___\\___| |_____/ \\__, |___/\\__\\___|_| |_| |_|\n"
    "                                                                                                                        __/ |                          \n"
    "                                                                                                                       |___/                           \n"
    RESET);
    printf(CYAN "========================================================================================================================================================================\n" RESET);

    printf(YELLOW "  1. Add Student\n" RESET);
    printf(YELLOW "  2. View Students\n" RESET);
    printf(YELLOW "  3. Search Student\n" RESET);
    printf(YELLOW "  4. Update Student\n" RESET);
    printf(YELLOW "  5. Delete Student\n" RESET);
    printf(YELLOW "  6. Mark Attendance\n" RESET);
    printf(YELLOW "  7. View Attendance\n" RESET);
    printf(RED    "  0. Exit\n" RESET);
    printf(CYAN "------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n" RESET);
    printf("Enter your choice: ");
}

void add_student() {
    system(CLEAR);
    Student s;
    printf(YELLOW "----------- Add Student -----------\n" RESET);
    printf("Enter roll number: ");
    scanf("%d", &s.roll_no);
    getchar();
    printf("Enter name: ");
    fgets(s.name, MAX_NAME, stdin);
    s.name[strcspn(s.name, "\n")] = 0;
    printf("Enter class: ");
    fgets(s.class_name, MAX_CLASS, stdin);
    s.class_name[strcspn(s.class_name, "\n")] = 0;
    save_student(s);
    printf(GREEN "\nStudent added successfully!\n" RESET);
}

void save_student(Student s) {
    FILE *fp = fopen("students.dat", "ab");
    fwrite(&s, sizeof(Student), 1, fp);
    fclose(fp);
}

