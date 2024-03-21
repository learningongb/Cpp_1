// Задание 3. Валидация IP-адреса

#include <iostream>

std::string getAddrPart(std::string addr, int number)
{
    std::string part;
    int currentNumber = 0;

    for (int i = 0; i < addr.length() && currentNumber <= number; i++)
    {
        if (addr[i] == '.')
            currentNumber++;
        else if (currentNumber == number)
            part += addr[i];
    }

    return part;
}

int digitFromChar(char c)
{
    if (c == '1')
        return 1;
    else if (c == '2')
        return 2;
    else if (c == '3')
        return 3;
    else if (c == '4')
        return 4;
    else if (c == '5')
        return 5;
    else if (c == '6')
        return 6;
    else if (c == '7')
        return 7;
    else if (c == '8')
        return 8;
    else if (c == '9')
        return 9;
    else
        return 0;
}

int convertToInt(std::string string)
{
    int result = 0;
    for (int i = 0; i < string.length(); i++)
    {
        result = result * 10 + digitFromChar(string[i]);
    }
    return result;
}

bool checkOnlyDigits(std::string part)
{
    for (int i = 0; i < part.length(); i++)
    {
        if (part[i] < '0' || part[i] > '9')
            return false;
    }
    return true;
}

bool checkAddrPart(std::string part)
{
    if (part.length() == 0)
    {
        std::cout << "Не заполнена группа цифр\n";
        return false;
    }
    if (part[0] == '0')
    {
        std::cout << "Группа цифр содержит лидирующий 0\n";
        return false;
    }
    if (!checkOnlyDigits(part))
    {
        std::cout << "Группа цифр содержит недопустимые символы\n";
        return false;
    }
    int partAsInt = convertToInt(part);
    if (partAsInt > 255)
    {
        std::cout << "Недопустимый диапазон\n";
        return false;
    }
    return true;
}

int main()
{
    std::string addr;
    std::cout << "Введите IP: ";
    std::cin >> addr;

    bool valid = true;
    for (int i = 0; i < 4; i++)
    {
        if (!checkAddrPart(getAddrPart(addr, i)))
        {
            std::cout << "Ошибка при проверке " << i + 1 << " группы цифр\n";
            valid = false;
        }
    }
    if (valid)
        std::cout << "Адрес корректный\n";

    return 0;
}