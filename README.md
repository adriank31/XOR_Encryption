<div id="badges"> <a href="https://www.linkedin.com/in/adrian-korwel-83226a300/"> <img src="https://img.shields.io/badge/LinkedIn-blue?style=for-the-badge&logo=linkedin&logoColor=white" alt="LinkedIn Badge"/> </a> </div>


# Overview
This is a simple XOR-based encryption program written in C that allows users to obfuscate (encrypt) and de-obfuscate (decrypt) messages using a password as a key. 
<br>
The program demonstrates a rolling XOR cipher, where each character of the input message is XOR'd with a corresponding character of the user-provided password.

# Features
Accepts a password from the user (maximum 50 characters) as the encryption key.
<br>
Accepts a message from the user (maximum 500 characters) to be encrypted.
<br>
Applies XOR encryption to the message using the password.
<br>
Displays the message in HEX format before and after encryption for debugging purposes.
<br>
Decrypts the message by applying the XOR function again, proving that XOR is reversible.
<br>
Ensures safe input handling and prevents empty inputs.

# How It Works

The user enters a password (up to 50 characters) that acts as the encryption key.
<br>
The user inputs a message (up to 500 characters) to be encrypted.
<br>
The program converts the original message into a HEX representation for debugging.
<br>
The program applies the XOR encryption (mangling) process and displays the obfuscated message.
<br>
The obfuscated message is converted to HEX output for debugging.
<br>
The program decrypts the message by applying XOR again, restoring the original message.
<br>
The decrypted message is displayed in HEX to confirm that encryption and decryption worked correctly.

# Compilation and Execution
<br>
# Compile the Program
Use GCC or any C compiler to compile the program:
<br>
![123](https://github.com/user-attachments/assets/74c2a688-8086-478c-8cfb-325fa6a1b108)




# Run the Program
![enecryption1](https://github.com/user-attachments/assets/7eaf7a73-436c-4ca1-b12a-5f4d57af310a)

<br>

# Example Usage
<br>
Enter your password (Limit is 50 characters): mysecretkey
<br>
Enter your message: Hello, XOR Encryption!

<br>
<br>
Original: Hello, XOR Encryption!
<br>
Original Message in HEX output: 48 65 6C 6C 6F 2C 20 58 4F 52 20 45 6E 63 72 79 70 74 69 6F 6E 21

<br>
<br>
Mangling (Obfuscated): %∟▼      ♀^E,$7Y(↨►↨→☻◄↔♦♂X
<br>
Manging Obfuscated Message in HEX output: 1A 4F 23 56 0F 32 79 14 6D 51 2A 64 39 50 1E 48 5F 3C 26 12 7F

<br>
<br>
Demangling (Original): Hello, XOR Encryption!
<br>
Decrypted Message in HEX output: 48 65 6C 6C 6F 2C 20 58 4F 52 20 45 6E 63 72 79 70 74 69 6F 6E 21

# Security Considerations
This program does not use cryptographic best practices. XOR encryption is not secure for sensitive data as it is vulnerable to frequency analysis and known-plaintext attacks.
<br>
The program does not use a cryptographic hash or key derivation function (KDF).
<br>
If the password is weak, brute-force attacks can easily reveal the original message.
<br>
For stronger encryption, consider using AES-256 or HMAC-SHA256 instead of XOR.

# Possible Improvements

Use a cryptographic hash (SHA-256) of the password to derive a strong key.
<br>
Introduce a salt to prevent predictable encryption.
<br>
Implement AES-256 encryption instead of XOR.
<br>
Add Base64 encoding for readable encrypted messages.

# License

This project is licensed under the MIT License. Feel free to use and modify the code for educational purposes.

# Author

Created by Adrian Korwel. Feel free to contribute to this project by submitting pull requests!
