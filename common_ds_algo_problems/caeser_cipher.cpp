/*
 * Encrypts a plain text to decrypts an encrypted text back to plain using Caeser Cipher.
 * It is a type of substitution cipher in which each letter in the plaintext is replaced by a
 * letter some fixed number of positions down the alphabet. For example, with a left shift of 3,
 * D would be replaced by A, E would become B, and so on.
 * The method is named after Julius Caesar, who used it in his private correspondence
 * Enter plain text:the brown fox jumped over the lazy dog
 * Enter shift length:24
 * Encrypted text:rfc zpmul dmv hskncb mtcp rfc jyxw bme
 * Decrypted text:the brown fox jumped over the lazy dog
 */

#include <iostream>
#include <string>
#include <sstream>

char caeser_encrypt(char c, int shift_length);
char caeser_decrypt(char c, int shift_length);

int main()
{
    std::string plain_text, encrypted_text;
    int shift_length;
    std::cout << "Enter plain text:";
    std::getline(std::cin, plain_text);
    std::cout << "Enter shift length:";
    std::cin >> shift_length;
    std::stringstream ss;

    unsigned int text_length = plain_text.length();

    // Encrypt the text
    //
    for (unsigned int i = 0; i < text_length; ++i)
    {
        ss << caeser_encrypt(plain_text[i], shift_length);
    }

    encrypted_text = ss.str();
    std::cout << "Encrypted text:" << encrypted_text << std::endl;

    // Reset the stream
    //
    ss.str(std::string());
    
    // Decrypt the text again
    //
    for (unsigned int i = 0; i < text_length; ++i)
    {
        ss << caeser_decrypt(encrypted_text[i], shift_length);
    }

    std::cout << "Decrypted text:" << ss.str() << std::endl;
    return 0;
}

char caeser_encrypt(char c, int shift_length)
{
    if (c >= 'A' && c <= 'Z')
    {
        return (((c - 'A' + shift_length) % 26) + 'A');
    }
    else if (c >= 'a' && c <= 'z')
    {
        return (((c - 'a' + shift_length) % 26) + 'a');
    }
    
    // In case of non-alpha characters, return as it is.
    return c;
}

char caeser_decrypt(char c, int shift_length)
{
    if (c >= 'A' && c <= 'Z')
    {
        return (((c - 'A' + (26 - shift_length)) % 26) + 'A');
    }
    else if (c >= 'a' && c <= 'z')
    {
        return (((c - 'a' + (26 - shift_length)) % 26) + 'a');
    }
    
    // In case of non-alpha characters, return as it is.
    return c;
}
