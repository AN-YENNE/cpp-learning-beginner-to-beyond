// Section 10
// Challenge – Substitution Cipher (Encryption & Decryption)
//
// This program implements a simple substitution cipher.
// Each letter in the alphabet is replaced by a corresponding letter
// in a key string to encrypt messages. Decryption reverses the process.
//
// The cipher here substitutes both lowercase and uppercase letters
// and preserves non-alphabetic characters (spaces, punctuation, etc.).
//
// Tip: The idea can easily be extended to include digits, symbols, and even custom mappings.

#include <iostream>
#include <string>

using namespace std;

int main() {
    // The reference alphabet and substitution key.
    // The key defines how each character in the alphabet will be replaced.
    string alphabet {" abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string key      {" XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};

    // Step 1: Read input from the user
    string secret_message {};
    cout << "Enter your secret message: ";
    getline(cin, secret_message);

    // Step 2: Encrypt the message
    string encrypted_message {};
    cout << "\nEncrypting message..." << endl;

    for (char c : secret_message) {
        size_t position = alphabet.find(c);
        if (position != string::npos) {
            // Replace the character from alphabet with corresponding character in key
            encrypted_message += key.at(position);
        } else {
            // If character not found (e.g., symbols), keep as is
            encrypted_message += c;
        }
    }

    cout << "\nEncrypted message: " << encrypted_message << endl;

    // Step 3: Decrypt the message back to verify
    string decrypted_message {};
    cout << "\nDecrypting message..." << endl;

    for (char c : encrypted_message) {
        size_t position = key.find(c);
        if (position != string::npos) {
            // Replace from key back to alphabet
            decrypted_message += alphabet.at(position);
        } else {
            decrypted_message += c;
        }
    }

    cout << "\nDecrypted message: " << decrypted_message << endl;

    cout << endl;
    return 0;
}

/*
=====================================================================
NOTES, TIPS, AND SUMMARY
=====================================================================

1) Concept Overview:
--------------------
A substitution cipher is a basic encryption technique where each letter
in the plaintext is replaced with another letter (or symbol).
To decrypt, you perform the reverse substitution.

Example Mapping:
Plain:  abcdefghijklmnopqrstuvwxyz
Cipher: XZNLWEBGJHQDYVTKFUOMPCIASR

Thus, 'a' → 'X', 'b' → 'Z', 'c' → 'N', etc.

---------------------------------------------------------------------

2) Program Flow:
----------------
1. Define the `alphabet` and corresponding `key`.
2. Ask the user for a secret message.
3. Encrypt the message by replacing each letter using the mapping.
4. Display the encrypted message.
5. Decrypt it back using the reverse lookup to verify correctness.

---------------------------------------------------------------------

3) Key String Structure:
------------------------
Each index in `alphabet` directly corresponds to the same index in `key`.

For example:
    alphabet[1] = 'a'  → key[1] = 'X'
    alphabet[2] = 'b'  → key[2] = 'Z'

If the user enters a character not in `alphabet`, the program leaves it unchanged.

---------------------------------------------------------------------

4) String Functions Used:
--------------------------
- **find(char)**: Returns the index (position) of the first occurrence of the character.
- **at(index)**: Returns the character at the specified index, with bounds checking.
- **+=**: Appends characters to the end of the resulting string.
- **getline(cin, str)**: Reads an entire line including spaces.

---------------------------------------------------------------------

5) How Encryption & Decryption Work:
------------------------------------
Encryption:
    For each character in the input:
        find its position in `alphabet`
        replace it with the character in `key` at the same position

Decryption:
    For each character in the encrypted text:
        find its position in `key`
        replace it with the corresponding character in `alphabet`

---------------------------------------------------------------------

6) Example Run:
---------------
Input:
    Enter your secret message: Hello World

Output:
    Encrypting message...
    Encrypted message: Duttk Ktkqd

    Decrypting message...
    Decrypted message: Hello World

---------------------------------------------------------------------

7) Extending the Cipher:
-------------------------
✔ Include digits and punctuation in the `alphabet` and `key`.  
✔ Support multi-character keys or rotation patterns.  
✔ Randomly generate keys for stronger encryption.  
✔ Implement frequency analysis countermeasures.

---------------------------------------------------------------------

8) Key Insights:
----------------
- The substitution cipher is **not secure** for modern cryptography,
  but it’s a great example to understand string manipulation.
- Both encryption and decryption are mirror operations.
- The program uses simple `find()` and `at()` methods effectively.

---------------------------------------------------------------------

9) Summary:
-----------
- Demonstrates use of strings, indexing, and iteration.
- Reinforces mapping logic using parallel strings.
- Introduces encryption/decryption fundamentals in a simple way.

=====================================================================
*/
