<div id = "badges">
  <a href = "https://www.linkedin.com/in/adrian-korwel-83226a300/">
    <img src = "https://img.shields.io/badge/LinkedIn-blue?style=for-the-badge&logo=linkedin&logoColor=white" alt="LinkedIn Badge"/>
  </a>

# What is an AES Encryption Tool
The AES Encryption Tool is a utility designed to securely encrypt and decrypt sensitive data using the Advanced Encryption Standard (AES). This tool provides functionality for generating random AES keys and initialization vectors (IVs), encrypting data, decrypting data, and saving encrypted content to binary files for secure storage or transmission. It’s built for applications requiring confidentiality and integrity, such as securing sensitive user data or transferring confidential files.


# Key Features
- Generates secure, random AES keys and IVs using OpenSSL’s random byte generation.
- Uses AES CFB (Cipher Feedback) mode for secure and efficient data encryption and decryption.
- Provides utilities to write encrypted data to a file and read it back for decryption.
- Works seamlessly on Linux, macOS, and Windows systems.
- End-to-end encryption and decryption in a single program with minimal user input.

# Installation Using Git
 - Clone the Repository:
   ![image](https://github.com/user-attachments/assets/70fb76a0-7976-4cbb-a2f7-855a08c9f979)
 - Install OpenSSL:
   Ensure you have OpenSSL installed, as it is required for random key generation and encryption.
 - Compile the Program:
   Use a C++ compiler (e.g., g++) to build the program:
   ![image](https://github.com/user-attachments/assets/c61b5a56-80e9-4c95-93d1-6392caa30550)


# Usage
  - Encrypt and Save Data:
    Input plaintext data and save the encrypted content to a file named encrypted_data.bin.


  - Decrypt and Verify:
      Read the encrypted content from the file, decrypt it, and verify the output matches the original plaintext.
![image](https://github.com/user-attachments/assets/929b9288-306d-46ff-965c-4740061bfe41)


# Example Output
 - Example Output:
![image](https://github.com/user-attachments/assets/2c390fc2-ea70-4489-b682-1c8d415f30ab)


# Legal Disclaimer
Usage of this tool for unauthorized encryption or decryption of third-party data is strictly prohibited. It is the user’s responsibility to comply with all applicable laws. The developers assume no liability for misuse of this program. Use responsibly and for authorized purposes only.
