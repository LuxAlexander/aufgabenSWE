#include <stdio.h>
#include <string.h>

/* ============================================================================
 * Name : anonymityCopy.c
 * Author : Alexander Lux
 * Version : 1.0
 * Description : Let the user input two files in the command line and a word to crypt. Add the second file to the first.
 * ============================================================================ */

void replaceWord(char *buffer, const char *word) {
    char temp[1024];
    char *pos, *start = buffer;
    temp[0] = '\0';

    int word_len = strlen(word);
    // Create a new string of '*' of the same length as the word
    char stars[word_len + 1];
    for (int i = 0; i < word_len; i++) {
        stars[i] = '*';
    }
    stars[word_len] = '\0';

    while ((pos = strstr(start, word)) != NULL) {
        strncat(temp, start, pos - start);  // Copy up to the key
        strcat(temp, stars);              // Insert new word
        start = pos + word_len;      // Move past old word
    }

    strcat(temp, start);  // Append remaining content
    strcpy(buffer, temp); // Copy modified content back to buffer
}

int main(int argc, char *argv[])  {
    FILE *fp=NULL;
    FILE *fp2=NULL;
    char buffer[1024];

    fp=fopen(argv[1],"r");
    fp2=fopen(argv[2],"a");

    if(fp==NULL|| fp2==NULL) {
        printf("Error in opening files\n");
        return -1;
    }

    unsigned long int bytesRead = fread(buffer, 1, sizeof(buffer) - 1, fp);
    buffer[bytesRead] = '\0';  // Null-terminate the buffer
    fclose(fp);

    replaceWord(buffer, argv[3]);  // Replace the keyword with "*"

    fwrite(buffer, 1, strlen(buffer), fp2);
    fclose(fp2);

    printf("File updated successfully!\n");

    return 0;
}