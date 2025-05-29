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
