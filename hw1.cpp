// Задание 1. Шифр Цезаря

#include <iostream>

std::string encrypt_caesar(std::string string, int key)
{
    int offset = key % 26;
    std::string newString = "";

    for (int i = 0; i < string.length(); i++)
    {
        if (string[i] >= 'A' && string[i] <= 'Z')
        {
            if (offset > 0 && string[i] + offset > 'Z')
            {
                newString += string[i] + offset - 'Z' + 'A' - 1;
            }
            else if (offset < 0 && string[i] + offset < 'A')
            {
                newString += string[i] + offset + 'Z' - 'A' + 1;
            }
            else
            {
                newString += string[i] + offset;
            }
        }
        else if (string[i] >= 'a' && string[i] <= 'z')
        {
            if (offset > 0 && string[i] + offset > 'z')
            {
                newString += string[i] + offset - 'z' + 'a' - 1;
            }
            else if (offset < 0 && string[i] + offset < 'a')
            {
                newString += string[i] + offset + 'z' - 'a' + 1;
            }
            else
            {
                newString += string[i] + offset;
            }
        }
        else
        {
            newString += string[i];
        }
    }
    return newString;
}

std::string decrypt_caesar(std::string string, int key)
{
    return encrypt_caesar(string, -key);
}

int main()
{
    std::string string;
    std::cout << "Введите строку: ";
    std::getline(std::cin, string);

    int key;
    std::cout << "Введите ключ (смещение): ";
    std::cin >> key;

    std::string encrypt_string = encrypt_caesar(string, key);
    std::cout << "Зашифрованная строка:\n";
    std::cout << encrypt_string << std::endl;

    std::cout << "Расшифрованная строка:\n";
    std::cout << decrypt_caesar(encrypt_string, key) << std::endl;

    return 0;
}
