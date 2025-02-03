#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// unsigned char ensures we treat message[i] as a raw byte (0-255)
// Ensuring correct Byte-by-Byte Representation

// =============================================
// Dynamic Key based on user-provided password
// The password acts as a key to XOR the message
// Limit: 50 characters max
// =============================================
char name[50]; // Password (key) provided by the user
char message[500]; // Message to be obfuscated (encrypted)

// ---------------------------------------------
// Function: initial_password()
// Purpose: Gets the user's password (used as an XOR key).
// Ensures the password is valid and removes newline characters.
// ---------------------------------------------
void initial_password() {
    printf("Enter your password (Limit is 50 characters): "); // Prompt user for input
    fgets(name, sizeof(name), stdin); // Reads input including spaces; prevents overflow

    name[strcspn(name, "\n")] = 0; // Removes the newline character left by fgets()

    // Ensuring password is not empty
    if (strlen(name) == 0) {
        printf("Error: Password cannot be empty!\n");
        exit(1); // Exit the program if no password is provided
    }
}


// ---------------------------------------------
// Function: input_message()
// Purpose: Takes user input as a message to be obfuscated.
// Ensures the message is valid (not empty) and removes the newline character.
// ---------------------------------------------
void input_message() {
    printf("Enter your message: "); // Prompt the user for input

    fgets(message, sizeof(message), stdin); // Reads the input string, preventing buffer overflow

    message[strcspn(message, "\n")] = 0; // Removes the newline character left by fgets()

    // Ensuring message is not empty
    if (strlen(message) == 0) {
        printf("Error: Message cannot be empty!\n");
        exit(1); // Exit the program if no message is provided
    }
}


// ---------------------------------------------
// Function: mangle()
// Purpose: Obfuscates (encrypts) and de-obfuscates (decrypts) data using XOR.
// Parameters:
//  - char *data: Pointer to the message to be modified, pointer to char to make a string
//  - size_t len: Length of the message, since C doeesnt have a built in length function
// How It Works:
//  - Uses the password as an encryption key (rolling XOR).
//  - Each byte in `data` is XOR'd with a corresponding byte from `name` (password).
//  - Prints the obfuscated bytes in hexadecimal format for debugging.
// ---------------------------------------------
void mangle(char *data, size_t len) {
    for (size_t i = 0; i < len; i++) {
        data[i] ^= name[i % strlen(name)]; // XOR each byte with a rolling key
    }
    printf("\n"); // Move to the next line for readability
}


// ---------------------------------------------
// Function: main()
// Purpose: Controls program execution.
// 1. Takes a user-provided password to act as the XOR encryption key.
// 2. Accepts a message from the user to be obfuscated.
// 3. Obfuscates (mangles) the message before sending.
// 4. De-obfuscates (demangles) the message after receiving, proving reversibility.
// ---------------------------------------------
int main() {

    // Step 1: Get the user-provided password, which acts as the encryption key
    initial_password();


    // Step 2: Get the message to be obfuscated from the user
    input_message();


    // Step 3: Display the original message before encryption
    printf("Original: %s\n", message);


    // Step 4: Print the original message HEX value's before mangling data
    printf("Original Message in HEX output: ");
    for(size_t i = 0; i < strlen(message); i++){
        printf("%02x ", (unsigned char)message[i]); // Print Hex values of the original message
    }
    printf("\n"); // To print a new line
        


    // Step 5: Mangling (Encrypting) the message before sending
    mangle(message, strlen(message));
    printf("Mangling (Obfuscated): %s\n", message);
    printf("Manging Obfuscated Message in HEX output: "); // Prints the obfuscated message in HEX output
    for(size_t i = 0; i < strlen(message); i++){
        printf("%02x ", (unsigned char)message[i]); // Print Hex values of the obfuscated message
    }
    printf("\n"); // To print a new line
    

    // Step 6: Demangling (Decrypting) the message after receiving
    mangle(message, strlen(message));
    printf("Demangling (Original): %s\n", message);



    // Step 7: Debugging HEX output to detect a Null Byte(00)(\0) in the demangled message
    printf("Decrypted Message in HEX output:");
    for(size_t i = 0; i < strlen(message); i++){
        printf("%02x ", (unsigned char)message[i]); // Print Hex values of the decrypted message
    }
    printf("\n"); // To print a new line
        


    // Step 8: Program exits successfully
    return 0;

}
