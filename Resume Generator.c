#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store student details
struct Student {
    char name[50];
    char email[50];
    char phone[15];
    char education[100];
    char skills[200];
    char experience[200];
    char projects[200];
    char domain[50];
};

// Function to suggest skills based on the chosen domain
void suggestSkills(char domain[], char suggestedSkills[]) {
    if (strcmp(domain, "Web Development") == 0) {
        strcpy(suggestedSkills, "HTML, CSS, JavaScript, React, Node.js");
    } else if (strcmp(domain, "Data Science") == 0) {
        strcpy(suggestedSkills, "Python, Machine Learning, Pandas, NumPy");
    } else if (strcmp(domain, "Cybersecurity") == 0) {
        strcpy(suggestedSkills, "Network Security, Cryptography, Penetration Testing");
    } else if (strcmp(domain, "Embedded Systems") == 0) {
        strcpy(suggestedSkills, "C, Embedded C, Microcontrollers, IoT");
    } else {
        strcpy(suggestedSkills, "General Problem Solving, Communication, Leadership");
    }
}

// Function to generate a resume file
void generateResume(struct Student s) {
    FILE *file = fopen("resume.txt", "w");
    if (file == NULL) {
        printf("Error creating resume file.\n");
        return;
    }

    fprintf(file, "--------------------------------------\n");
    fprintf(file, "           DIGITAL RESUME\n");
    fprintf(file, "--------------------------------------\n");
    fprintf(file, "Name: %s\n", s.name);
    fprintf(file, "Email: %s\n", s.email);
    fprintf(file, "Phone: %s\n", s.phone);
    fprintf(file, "Education: %s\n", s.education);
    fprintf(file, "Skills: %s\n", s.skills);
    fprintf(file, "Experience: %s\n", s.experience);
    fprintf(file, "Projects: %s\n", s.projects);
    
    char suggestedSkills[200];
    suggestSkills(s.domain, suggestedSkills);
    fprintf(file, "Suggested Skills to Learn: %s\n", suggestedSkills);

    fprintf(file, "--------------------------------------\n");
    
    fclose(file);
    printf("\nResume successfully generated as 'resume.txt'\n");
}

// Main function
int main() {
    struct Student s;
    
    printf("Enter your name: ");
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = 0; // Remove newline
    
    printf("Enter your email: ");
    fgets(s.email, sizeof(s.email), stdin);
    s.email[strcspn(s.email, "\n")] = 0;

    printf("Enter your phone number: ");
    fgets(s.phone, sizeof(s.phone), stdin);
    s.phone[strcspn(s.phone, "\n")] = 0;

    printf("Enter your highest education qualification: ");
    fgets(s.education, sizeof(s.education), stdin);
    s.education[strcspn(s.education, "\n")] = 0;

    printf("Enter your skills (comma-separated): ");
    fgets(s.skills, sizeof(s.skills), stdin);
    s.skills[strcspn(s.skills, "\n")] = 0;

    printf("Enter your experience (if any, else type 'None'): ");
    fgets(s.experience, sizeof(s.experience), stdin);
    s.experience[strcspn(s.experience, "\n")] = 0;

    printf("Enter your projects (comma-separated): ");
    fgets(s.projects, sizeof(s.projects), stdin);
    s.projects[strcspn(s.projects, "\n")] = 0;

    printf("Enter your domain (e.g., Web Development, Data Science, Cybersecurity): ");
    fgets(s.domain, sizeof(s.domain), stdin);
    s.domain[strcspn(s.domain, "\n")] = 0;

    // Generate resume
    generateResume(s);

    return 0;
}
