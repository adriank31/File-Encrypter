#include <iostream>
#include <fstream>
#include <openssl/aes.h>
#include <openssl/rand.h>

// Function to generate a random AES key
void generateAESKey(unsigned char* key, int length) {
    if (!RAND_bytes(key, length)) {
        std::cerr << "Error generating random AES key." << std::endl;
        exit(EXIT_FAILURE);
    }
}

// Function to encrypt data using AES
void encryptAES(const unsigned char* key, const unsigned char* iv, const std::string& plaintext, std::string& ciphertext) {
    AES_KEY encryptKey;
    AES_set_encrypt_key(key, 128, &encryptKey);

    unsigned char buffer[AES_BLOCK_SIZE];
    int num = 0;
    int plaintextLen = plaintext.length();
    ciphertext.resize(plaintextLen + AES_BLOCK_SIZE);

    AES_cfb128_encrypt(reinterpret_cast<const unsigned char*>(plaintext.c_str()), reinterpret_cast<unsigned char*>(&ciphertext[0]), plaintextLen, &encryptKey, const_cast<unsigned char*>(iv), &num, AES_ENCRYPT);
}

// Function to decrypt data using AES
void decryptAES(const unsigned char* key, const unsigned char* iv, const std::string& ciphertext, std::string& plaintext) {
    AES_KEY decryptKey;
    AES_set_encrypt_key(key, 128, &decryptKey);

    unsigned char buffer[AES_BLOCK_SIZE];
    int num = 0;
    int ciphertextLen = ciphertext.length();
    plaintext.resize(ciphertextLen);

    AES_cfb128_encrypt(reinterpret_cast<const unsigned char*>(ciphertext.c_str()), reinterpret_cast<unsigned char*>(&plaintext[0]), ciphertextLen, &decryptKey, const_cast<unsigned char*>(iv), &num, AES_DECRYPT);
}

// Function to write binary data to a file
void writeToFile(const std::string& filename, const std::string& data) {
    std::ofstream file(filename, std::ios::out | std::ios::binary);
    if (!file) {
        std::cerr << "Error opening file for writing." << std::endl;
        exit(EXIT_FAILURE);
    }
    file.write(data.c_str(), data.size());
    file.close();
}

// Function to read binary data from a file
void readFromFile(const std::string& filename, std::string& data) {
    std::ifstream file(filename, std::ios::in | std::ios::binary);
    if (!file) {
        std::cerr << "Error opening file for reading." << std::endl;
        exit(EXIT_FAILURE);
    }
    file.seekg(0, std::ios::end);
    std::streampos size = file.tellg();
    file.seekg(0, std::ios::beg);
    data.resize(size);
    file.read(&data[0], size);
    file.close();
}

int main() {
    // Key and IV for AES
    unsigned char key[AES_BLOCK_SIZE];
    unsigned char iv[AES_BLOCK_SIZE];

    // Generate a random AES key
    generateAESKey(key, AES_BLOCK_SIZE);
    generateAESKey(iv, AES_BLOCK_SIZE);

    // Input plaintext
    std::string plaintext = "This is some very sensitive data that needs to be encrypted.";

    // Encrypt the plaintext
    std::string ciphertext;
    encryptAES(key, iv, plaintext, ciphertext);

    // Write the encrypted data to a file
    writeToFile("encrypted_data.bin", ciphertext);

    // Read the encrypted data from the file
    std::string readCiphertext;
    readFromFile("encrypted_data.bin", readCiphertext);

    // Decrypt the ciphertext
    std::string decryptedText;
    decryptAES(key, iv, readCiphertext, decryptedText);

    // Display the original and decrypted text
    std::cout << "Original Text: " << plaintext << std::endl;
    std::cout << "Decrypted Text: " << decryptedText << std::endl;

    return 0;
}
