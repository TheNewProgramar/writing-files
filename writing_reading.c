#include <stdio.h>
#include <string.h>

int main() {
    FILE *pFile;
    char text[1024] = "";
    char line[256];
    char filename[256];
    int char_count = 0, word_count = 0, line_count = 0;
    
    // Ask for filename
    printf("Enter filename: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0';
    
    if (strlen(filename) == 0) {
        printf("Filename cannot be empty\n");
        return 1;
    }
    
    // Open file
    pFile = fopen(filename, "w");
    if (pFile == NULL) {
        printf("Error opening file '%s'\n", filename);
        return 1;
    }
    
    printf("Enter text (empty line to finish):\n");
    
    // Read multiple lines
    while (1) {
        if (fgets(line, sizeof(line), stdin) == NULL) {
            break;
        }
        
        // Remove newline
        line[strcspn(line, "\n")] = '\0';
        
        // Check for empty line
        if (strlen(line) == 0) {
            break;
        }
        
        // Write line to file
        fprintf(pFile, "%s\n", line);
        
        // Update statistics
        char_count += strlen(line);
        line_count++;
        
        // Count words in this line
        int in_word = 0;
        for (int i = 0; line[i] != '\0'; i++) {
            if (line[i] == ' ' || line[i] == '\t') {
                in_word = 0;
            } else if (in_word == 0) {
                in_word = 1;
                word_count++;
            }
        }
    }
    
    fclose(pFile);
    
    printf("\n✅ File '%s' was written successfully!\n", filename);
    printf("📊 Statistics:\n");
    printf("   - Characters: %d\n", char_count);
    printf("   - Words: %d\n", word_count);
    printf("   - Lines: %d\n", line_count);
    
    return 0;
}
