**generateAESKey**: Generates a random AES key of the specified length using the RAND_bytes function from OpenSSL.

**encryptAES**: Encrypts the plaintext using the AES algorithm. It initializes the AES encryption key and uses AES_cfb128_encrypt for encryption.

**decryptAES**: Decrypts the ciphertext using the AES algorithm. It initializes the AES decryption key and uses AES_cfb128_encrypt for decryption (with the AES_DECRYPT flag).

**writeToFile**: Writes binary data to a file.

**readFromFile**: Reads binary data from a file.

**main**: This is where the key and IV are generated, the plaintext is encrypted, the encrypted data is written to a file, read back, and then decrypted. Finally, it displays the original and decrypted text.
