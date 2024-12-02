/*Jutinut Ratanamongkonkul 6609650228*/

#include <stdio.h>
#include <string.h>

#define MAX_COURSES 10
#define MAX_STUDENTS 100
#define MAX_NAME_LEN 50

typedef struct {
    char courseCode[10];
    char courseName[MAX_NAME_LEN];
    int credits;
} Course;

typedef struct {
    char studentID[10];
    char name[MAX_NAME_LEN];
    Course registeredCourses[MAX_COURSES];
    int courseCount;
} Student;

Course courses[MAX_COURSES];
Student students[MAX_STUDENTS];
int courseCount = 0, studentCount = 0;


void addCourse() {
    if (courseCount >= MAX_COURSES) {
        printf("Cannot add more courses. Limit reached.\n");
        return;
    }
    printf("Enter Course Code: ");
    scanf("%s", courses[courseCount].courseCode);
    getchar();
    printf("Enter Course Name: ");
    fgets(courses[courseCount].courseName, MAX_NAME_LEN, stdin);
    courses[courseCount].courseName[strcspn(courses[courseCount].courseName, "\n")] = '\0';
    printf("Enter Credits: ");
    scanf("%d", &courses[courseCount].credits);
    courseCount++;
    printf("Course added successfully.\n");
}

void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Cannot add more students. Limit reached.\n");
        return;
    }
    printf("Enter Student ID: ");
    scanf("%s", students[studentCount].studentID);
    printf("Enter Student Name: ");
    getchar();
    fgets(students[studentCount].name, MAX_NAME_LEN, stdin);
    students[studentCount].name[strcspn(students[studentCount].name, "\n")] = '\0';
    students[studentCount].courseCount = 0;
    studentCount++;
    printf("Student added successfully.\n");
}

void registerCourse() {
    char studentID[10], courseCode[10];
    printf("Enter Student ID: ");
    scanf("%s", studentID);
    printf("Enter Course Code to Register: ");
    scanf("%s", courseCode);


    int studentIndex = -1,i;
    for (i = 0; i < studentCount; i++) {
        if (strcmp(students[i].studentID, studentID) == 0) {
            studentIndex = i;
            break;
        }
    }
    if (studentIndex == -1) {
        printf("Student ID not found.\n");
        return;
    }

    int courseIndex = -1;
    for (i = 0; i < courseCount; i++) {
        if (strcmp(courses[i].courseCode, courseCode) == 0) {
            courseIndex = i;
            break;
        }
    }
    if (courseIndex == -1) {
        printf("Course Code not found.\n");
        return;
    }

    
    if (students[studentIndex].courseCount < MAX_COURSES) {
        students[studentIndex].registeredCourses[students[studentIndex].courseCount] = courses[courseIndex];
        students[studentIndex].courseCount++;
        printf("Course registered successfully.\n");
    } else {
        printf("Student cannot register more courses.\n");
    }
}

void displayStudentCourses() {
    char studentID[10];
    printf("Enter Student ID: ");
    scanf("%s", studentID);

    
    int studentIndex = -1,i;
    for (i = 0; i < studentCount; i++) {
        if (strcmp(students[i].studentID, studentID) == 0) {
            studentIndex = i;
            break;
        }
    }
    if (studentIndex == -1) {
        printf("Student ID not found.\n");
        return;
    }

    printf("Courses registered by %s:\n", students[studentIndex].name);
    printf("Course Code\tCourse Name\t\tCredits\n");
    for (i = 0; i < students[studentIndex].courseCount; i++) {
        printf("%s\t\t%-20s\t%d\n",
               students[studentIndex].registeredCourses[i].courseCode,
               students[studentIndex].registeredCourses[i].courseName,
               students[studentIndex].registeredCourses[i].credits);
    }
}

void saveData() {
    FILE *file = fopen("registration_data.txt", "w");
    if (!file) {
        printf("Error saving data.\n");
        return;
    }
    fprintf(file, "%d\n", courseCount);
    int i,j;
    for (i = 0; i < courseCount; i++) {
        fprintf(file, "%s\n%s\n%d\n",
                courses[i].courseCode,
                courses[i].courseName,
                courses[i].credits);
    }
    fprintf(file, "%d\n", studentCount);
    for (i = 0; i < studentCount; i++) {
        fprintf(file, "%s\n%s\n%d\n",
                students[i].studentID,
                students[i].name,
                students[i].courseCount);
        for (j = 0; j < students[i].courseCount; j++) {
            fprintf(file, "%s\n", students[i].registeredCourses[j].courseCode);
        }
    }
    fclose(file);
    printf("Data saved successfully.\n");
}

void loadData() {
    FILE *file = fopen("registration_data.txt", "r");
    if (file == NULL) {
        printf("No data to load.\n");
        return;
    }
	int i,j;
    fscanf(file, "%d\n", &courseCount);
    for (i = 0; i < courseCount; i++) {
        fgets(courses[i].courseCode, 10, file);
        courses[i].courseCode[strcspn(courses[i].courseCode, "\n")] = '\0';
        fgets(courses[i].courseName, MAX_NAME_LEN, file);
        courses[i].courseName[strcspn(courses[i].courseName, "\n")] = '\0';
        fscanf(file, "%d\n", &courses[i].credits);
    }

    fscanf(file, "%d\n", &studentCount);
    for (i = 0; i < studentCount; i++) {
        fgets(students[i].studentID, 10, file);
        students[i].studentID[strcspn(students[i].studentID, "\n")] = '\0';
        fgets(students[i].name, MAX_NAME_LEN, file);
        students[i].name[strcspn(students[i].name, "\n")] = '\0';
        fscanf(file, "%d\n", &students[i].courseCount);
        for (j = 0; j < students[i].courseCount; j++) {
            fgets(students[i].registeredCourses[j].courseCode, 10, file);
            students[i].registeredCourses[j].courseCode[strcspn(students[i].registeredCourses[j].courseCode, "\n")] = '\0';
        }
    }
    fclose(file);
    printf("Data loaded successfully.\n");
}


int main() {
    int choice;
    do {
        printf("\n===== Course Registration System =====\n");
        printf("1. Add New Course\n");
        printf("2. Add New Student\n");
        printf("3. Register Course for Student\n");
        printf("4. Display Student's Registered Courses\n");
        printf("5. Save Data\n");
        printf("6. Load Data\n");
        printf("7. Exit\n");
        printf("Select an option (1-7): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addCourse(); break;
            case 2: addStudent(); break;
            case 3: registerCourse(); break;
            case 4: displayStudentCourses(); break;
            case 5: saveData(); break;
            case 6: loadData(); break;
            case 7: printf("Exiting program. Goodbye!\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);
    return 0;
}

