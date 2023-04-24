#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    // Check for correct command-line argument count
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Convert the command-line argument to an integer
    int k = atoi(argv[1]) % 26;

    // Define the alphabet array
    char ALPHABET[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // Get input from the user
    char input[1000];
    printf("plaintext: ");
    fgets(input, 1000, stdin);

    // Iterate through each character in the input
    for (int i = 0, n = strlen(input); i < n; i++)
    {
        // If the character is a letter, shift it by k positions
        if (isalpha(input[i]))
        {
            // Find the index of the character in the alphabet array
            char *letter = strchr(ALPHABET, toupper(input[i]));
            int index = letter - ALPHABET;

            // Shift the index by k positions
            int shifted_index = (index + k) % 26;

            // Convert the shifted index back to a character
            char shifted_letter = islower(input[i]) ? tolower(ALPHABET[shifted_index]) : ALPHABET[shifted_index];

            // Replace the original character with the shifted character
            input[i] = shifted_letter;
        }
    }

    // Print the cipher
    printf("ciphertext: %s\n", input);
    return 0;
}
