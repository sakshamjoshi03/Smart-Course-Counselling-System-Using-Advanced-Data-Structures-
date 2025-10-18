// Run using 
// gcc main.c auth_course_mgmt.c recommend_traverse.c interaction_seat.c search_retrieve.c -o project -Wall -Wextra -mconsole
// Compile Using
// ./project

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// === Include all headers ===
#include "auth_course_mgmt.h"
#include "interaction_seat.h"
#include "recommend_traverse.h"
#include "search_retrieve.h"

// === Function Declarations ===
void adminMenu();
void studentMenu();

int main() {
    int choice;

    while (1) {
        printf("\n==========================================\n");
        printf(" SMART COURSE COUNSELLING SYSTEM\n");
        printf("==========================================\n");
        printf("1. Admin Login\n");
        printf("2. Student Portal\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                adminMenu();
                break;
            case 2:
                studentMenu();
                break;
            case 3:
                printf("Thank you for using Smart Counselling System!\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}

// ===================================================
// ================ ADMIN MENU =======================
// ===================================================
void adminMenu() {
    int choice;
    char code[CODE_LEN], name[NAME_LEN];

    while (1) {
        printf("\n------ ADMIN MENU ------\n");
        printf("1. Add Course\n");
        printf("2. Remove Course\n");
        printf("3. View All Courses\n");
        printf("4. Setup Course Graph (for Recommendations)\n");
        printf("5. Return to Main Menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Course Code: ");
                scanf("%s", code);
                printf("Enter Course Name: ");
                scanf(" %[^\n]", name);
                addCourse(code, name);
                printf("Course added successfully!\n");
                break;

            case 2:
                printf("Enter Course Code to Remove: ");
                scanf("%s", code);
                removeCourse(code);
                printf("Course removed if existed.\n");
                break;

            case 3:
                printf("\nAll Courses:\n");
                displayAllCourses();
                break;

            case 4: {
                int n, edges;
                printf("Enter total number of courses in recommendation graph: ");
                scanf("%d", &n);
                initGraph(n);
                printf("Enter %d course names:\n", n);
                for (int i = 0; i < n; i++) {
                    printf("Course %d: ", i + 1);
                    scanf("%s", courseNames[i]);
                }

                printf("Enter number of prerequisite relationships: ");
                scanf("%d", &edges);
                for (int i = 0; i < edges; i++) {
                    char a[NAME_LEN], b[NAME_LEN];
                    printf("Enter pair (PreReq Dependent): ");
                    scanf("%s %s", a, b);
                    int u = getCourseIndexByName(a);
                    int v = getCourseIndexByName(b);
                    if (u == -1 || v == -1)
                        printf("Invalid course name!\n");
                    else
                        addEdge(u, v);
                }
                printf("Graph setup complete!\n");
                break;
            }

            case 5:
                return;

            default:
                printf("Invalid choice.\n");
        }
    }
}

// ===================================================
// ================ STUDENT MENU =====================
// ===================================================
void studentMenu() {
    int choice;
    CourseLL *studentCourses = NULL;
    Queue *seatQueue = createQueue(5);
    BSTNode *root = NULL;
    char name[NAME_LEN];

    while (1) {
        printf("\n------ STUDENT PORTAL ------\n");
        printf("1. View All Available Courses\n");
        printf("2. Select Course\n");
        printf("3. Drop Course\n");
        printf("4. View My Courses\n");
        printf("5. View Recommended Courses\n");
        printf("6. Search Course (BST)\n");
        printf("7. Return to Main Menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayAllCourses();
                break;

            case 2: {
                int id;
                printf("Enter course ID (number): ");
                scanf("%d", &id);
                printf("Enter course name: ");
                scanf(" %[^\n]", name);
                studentCourses = addCourseLL(studentCourses, id, name);
                enqueue(seatQueue, id);
                root = insert(root, name);
                printf("Course selected!\n");
                break;
            }

            case 3: {
                int id;
                printf("Enter course ID to drop: ");
                scanf("%d", &id);
                studentCourses = removeCourseLL(studentCourses, id);
                printf("Course dropped if it existed.\n");
                break;
            }

            case 4:
                printf("Your Selected Courses:\n");
                displayCoursesLL(studentCourses);
                printf("Seat Queue:\n");
                displayQueue(seatQueue);
                break;

            case 5:
                printf("\n--- Course Recommendations ---\n");
                recommendAllCourses();
                printf("\nEnter a course name to see direct next courses: ");
                scanf(" %[^\n]", name);
                {
                    int idx = getCourseIndexByName(name);
                    if (idx != -1)
                        recommendNext(idx);
                    else
                        printf("Course not found in graph!\n");
                }
                break;

            case 6:
                printf("Enter course name to search: ");
                scanf(" %[^\n]", name);
                if (search(root, name))
                    printf("Course '%s' found!\n", name);
                else
                    printf("Course not found!\n");
                printf("\nAll courses in sorted order:\n");
                inorderBst(root);
                break;

            case 7:
                return;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
