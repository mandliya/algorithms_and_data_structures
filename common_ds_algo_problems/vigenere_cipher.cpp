/**
 * Implements a program which encrypts and then decrypts text using Vigenère cipher.
 * The Vigenère cipher is a method of encrypting alphabetic text by using a series of interwoven Caesar ciphers based on the letters of a keyword.
 * Refer : https://en.wikipedia.org/wiki/Vigen%C3%A8re_cipher
 *
 * Enter the key for encrypting:bacon
 * Enter the plain text you want to encrypt:Meet me at the park at eleven am
 * Encrypted text: Negh zf av huf pcfx bt gzrwep oz
 * Decrypted text: Meet me at the park at eleven am
 */


#include <iostream>
#include <string>
#include <sstream>
#include <cctype>

std::string encrypt_data (std::string plain_text, std::string key)
{
    std::stringstream encrypted_stream;
    unsigned int text_len = plain_text.length();
    unsigned int key_len = key.length();
    unsigned int char_index = 0;
    unsigned int shift_len = 0;

    for (unsigned int i = 0; i < text_len; ++i)
    {
        if (isalpha(plain_text[i]))
        {
            // If current key char is uppercase, keyReferenceValue would be 'A', otherwise 'a'
            // We use keyReferenceValue to convert key char to ascii
            // 
            char keyReferenceValue = (isupper(key[char_index % key_len])) ? 'A' : 'a';
            
            // Similarly, we use referenceValue to convert plain text char to ascii, it would
            //
            char referenceValue = (isupper(plain_text[i])) ? 'A' : 'a';
            shift_len = key[char_index % key_len] - keyReferenceValue;
            encrypted_stream << char(((plain_text[i] - referenceValue + shift_len) % 26) + referenceValue);
            ++char_index;
        }
        else
        {
            // for non alpha chars, we don't encrypt and keep them as it is.
            encrypted_stream <<  plain_text[i];
        }
    }
    return encrypted_stream.str();
}

std::string decrypt_data(std::string encrypted_text, std::string key)
{
    std::stringstream decrypted_stream;
    unsigned int text_len = encrypted_text.length();
    unsigned int key_len = key.length();
    unsigned int char_index = 0;
    unsigned int shift_len = 0;
    
    for (unsigned int i = 0; i < text_len; ++i)
    {
        if (isalpha(encrypted_text[i]))
        {
            // If current key char is uppercase, keyReferenceValue would be 'A', otherwise 'a'
            // We use keyReferenceValue to convert key char to ascii
            // 
            char keyReferenceValue = (isupper(key[char_index % key_len])) ? 'A' : 'a';

            // Similarly, we use referenceValue to convert plain text char to ascii, it would
            //
            char referenceValue = (isupper(encrypted_text[i])) ? 'A' : 'a';
            shift_len = key[char_index % key_len] - keyReferenceValue;
            decrypted_stream << char((((encrypted_text[i] - referenceValue) + (26 - shift_len)) % 26) + referenceValue);
            ++char_index;
        }
        else
        {   
            // We don't encrypt non-alpha chars, so keeping them as it is.
            decrypted_stream << encrypted_text[i];
        }
    }
    return decrypted_stream.str();
}


int main()
{
    std::string plain_text, encrypted_text;
    std::string key;
    std::cout << "Enter the key for encrypting:";
    std::cin >> key;
    std::cin.clear();
    std::cin.sync();
    std::cin.ignore();
    std::cout << "Enter the plain text you want to encrypt:";
    std::getline(std::cin, plain_text);
    encrypted_text = encrypt_data(plain_text, key);
    std::cout << "Encrypted text: " << encrypted_text << std::endl;
    plain_text.clear();
    plain_text = decrypt_data(encrypted_text, key);
    std::cout << "Decrypted text: " << plain_text << std::endl;
    return 0;
}