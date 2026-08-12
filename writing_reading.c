#include <stdio.h>
#include <string.h>


int main() {

    FILE *pFile = fopen("output.txt", "w");

    char text[1024] = "";

    printf("Write: ");
    fgets(text, sizeof(text), stdin);

    if(pFile == NULL){

        printf("Error opening file\n");

        return 1;

    }

    fprintf(pFile, "%s", text);

    printf("File was written successfully!\n");

    fclose(pFile);

    return 0;
}
