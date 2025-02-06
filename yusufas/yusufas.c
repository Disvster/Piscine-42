#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // For getenv() and snprintf()

void print_hidden_file(const char *directory, const char *filename) {
    char filepath[256]; // Adjust size as needed
    FILE *file;

    // Construct the full file path
    snprintf(filepath, sizeof(filepath), "%s/%s", directory, filename);

    // Open the file
    file = fopen(filepath, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    // Infinite loop to print the file content repeatedly
    while (1) {
        // Rewind the file to the beginning for each iteration
        rewind(file);

        // Read and print the file content
        char ch;
        while ((ch = fgetc(file)) != EOF) {
            putchar(ch);
        }

        // Optional: Add a small delay to avoid flooding the terminal
        sleep(1);
    }

    // Close the file (this will never be reached due to the infinite loop)
    fclose(file);
}

int main() {
    // Get the home directory
    const char *home_dir = getenv("HOME");
    if (home_dir == NULL) {
        fprintf(stderr, "Error: HOME environment variable not set.\n");
        return 1;
    }

    // Construct the directory path (~/. is the hidden directory in the home directory)
    char directory[256];
    snprintf(directory, sizeof(directory), "%s/.", home_dir);

    // File name
    const char *filename = ".yusufas";

    // Call the function to print the file content infinitely
    print_hidden_file(directory, filename);

    return 0;
}
