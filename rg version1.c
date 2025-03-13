#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Structure for Resume
typedef struct {
    char name[MAX], email[MAX], phone[MAX], education[MAX];
    char skills[MAX][MAX], experience[MAX][MAX], projects[MAX][MAX];
    char certifications[MAX][MAX], hobbies[MAX][MAX], languages[MAX][MAX];
    int skillCount, expCount, projCount, certCount, hobbyCount, langCount;
    char objective[MAX], jobSuggestion[MAX];
} Resume;

Resume r;

// AI Job Matching
void ai_job_suggestion() {
    if (strstr(r.skills[0], "C Programming") || strstr(r.skills[1], "Python")) {
        strcpy(r.jobSuggestion, "Software Developer / AI Engineer");
    } else if (strstr(r.skills[0], "Web Development") || strstr(r.skills[1], "JavaScript")) {
        strcpy(r.jobSuggestion, "Full Stack Developer / Frontend Engineer");
    } else {
        strcpy(r.jobSuggestion, "Data Scientist / AI Researcher");
    }
}

// AI-Based Career Objective
void improve_objective() {
    if (strlen(r.objective) == 0) {
        strcpy(r.objective, "A highly motivated individual with a passion for innovation and problem-solving.");
    }
}

// Function to add multiple inputs
void add_entry(char arr[MAX][MAX], int *count, char *title) {
    printf("\nEnter number of %s: ", title);
    scanf("%d", count);
    getchar();

    for (int i = 0; i < *count; i++) {
        printf("Enter %s %d: ", title, i + 1);
        fgets(arr[i], MAX, stdin);
        arr[i][strcspn(arr[i], "\n")] = 0;
    }
}

// Get Resume Details
void get_resume_details() {
    printf("\n---- Enter Resume Details ----\n");
    printf("Enter Name: ");
    fgets(r.name, MAX, stdin);
    printf("Enter Email: ");
    fgets(r.email, MAX, stdin);
    printf("Enter Phone: ");
    fgets(r.phone, MAX, stdin);
    printf("Enter Education: ");
    fgets(r.education, MAX, stdin);
    printf("Enter Career Objective (leave blank for AI suggestion): ");
    fgets(r.objective, MAX, stdin);

    r.name[strcspn(r.name, "\n")] = 0;
    r.email[strcspn(r.email, "\n")] = 0;
    r.phone[strcspn(r.phone, "\n")] = 0;
    r.education[strcspn(r.education, "\n")] = 0;
    r.objective[strcspn(r.objective, "\n")] = 0;

    improve_objective();
    add_entry(r.skills, &r.skillCount, "skills");
    add_entry(r.experience, &r.expCount, "experience");
    add_entry(r.projects, &r.projCount, "projects");
    add_entry(r.certifications, &r.certCount, "certifications");
    add_entry(r.hobbies, &r.hobbyCount, "hobbies");
    add_entry(r.languages, &r.langCount, "languages");

    ai_job_suggestion();
}

// Save Resume to File
void save_resume() {
    FILE *file = fopen("resume.txt", "w");
    if (file == NULL) {
        printf("Error saving file!\n");
        return;
    }

    fprintf(file, "===========================================\n");
    fprintf(file, "           AI-Powered Resume\n");
    fprintf(file, "===========================================\n");
    fprintf(file, "Name          : %s\n", r.name);
    fprintf(file, "Email         : %s\n", r.email);
    fprintf(file, "Phone         : %s\n", r.phone);
    fprintf(file, "Education     : %s\n", r.education);

    fprintf(file, "\n----------- Skills -----------\n");
    for (int i = 0; i < r.skillCount; i++) {
        fprintf(file, "- %s\n", r.skills[i]);
    }

    fprintf(file, "\n----------- Experience -----------\n");
    for (int i = 0; i < r.expCount; i++) {
        fprintf(file, "- %s\n", r.experience[i]);
    }

    fprintf(file, "\n----------- Projects -----------\n");
    for (int i = 0; i < r.projCount; i++) {
        fprintf(file, "- %s\n", r.projects[i]);
    }

    fprintf(file, "\n----------- Certifications -----------\n");
    for (int i = 0; i < r.certCount; i++) {
        fprintf(file, "- %s\n", r.certifications[i]);
    }

    fprintf(file, "\n----------- Hobbies -----------\n");
    for (int i = 0; i < r.hobbyCount; i++) {
        fprintf(file, "- %s\n", r.hobbies[i]);
    }

    fprintf(file, "\n----------- Languages -----------\n");
    for (int i = 0; i < r.langCount; i++) {
        fprintf(file, "- %s\n", r.languages[i]);
    }

    fprintf(file, "\n----------- Career Objective -----------\n");
    fprintf(file, "%s\n", r.objective);
    fprintf(file, "\n----------- AI Job Suggestion -----------\n");
    fprintf(file, "%s\n", r.jobSuggestion);

    fclose(file);
    printf("\nResume saved to 'resume.txt' successfully!\n");
}

// Auto-Open Resume File
void open_resume_file() {
    printf("\nOpening resume file...\n");
    save_resume();

#ifdef _WIN32
    system("notepad resume.txt");
#else
    system("xdg-open resume.txt || open resume.txt");
#endif
}

// Main Menu
int main() {
    int choice;
    while (1) {
        printf("\n---- AI-Powered Resume Builder ----\n");
        printf("1. Create Resume\n2. Save Resume\n3. View Resume (Auto-Open File)\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1: get_resume_details(); break;
            case 2: save_resume(); break;
            case 3: open_resume_file(); break;
            case 4: exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
