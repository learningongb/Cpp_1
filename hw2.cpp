// Задание 2. Проверка корректности email-адреса

#include <iostream>

std::string getPartEmail(std::string email, bool first)
{
    bool isFirstPart = true;
    std::string part = "";
    for (int i = 0; i < email.length(); i++)
    {
        if (email[i] == '@' && first)
            break;
        if (email[i] == '@')
            isFirstPart = false;

        else if (first == isFirstPart)
            part += email[i];
    }
    return part;
}

int countAt(std::string email)
{
    int count = 0;
    for (int i = 0; i < email.length(); i++)
        if (email[i] == '@')
            count++;
    return count;
}

std::string getCommonAlphabit()
{
    std::string alphabit = "";
    for (char c = 'a'; c <= 'z'; c++)
    {
        alphabit += c;
    }
    for (char c = 'A'; c <= 'Z'; c++)
    {
        alphabit += c;
    }
    for (char c = '0'; c <= '9'; c++)
    {
        alphabit += c;
    }
    alphabit += '-';
    alphabit += '.';
    return alphabit;
}

bool checkPart(std::string part, std::string alphabit)
{
    if (part.length() == 0)
    {
        std::cout << "Адрес должен содержать 2 не пустых части, разделенных символом \"@\"";
        return false;
    }
    else if (part[0] == '.' || part[part.length()] == '.')
    {
        std::cout << "Части адреса не могут начинаться и заканчиваться символом \".\"";
        return false;
    }

    for (int i = 0; i < part.length(); i++)
    {
        if (part[i] == '.' && part[i + 1] == '.')
        {
            std::cout << "Адрес содержит две точки подряд\n";
            return false;
        }
        else
        {
            bool incorrect = true;
            for (int j = 0; j < alphabit.length(); j++)
                if (part[i] == alphabit[j])
                {
                    incorrect = false;
                    break;
                }
            if (incorrect)
            {
                std::cout << "Адрес содержит недопустимый символ \"" << part[i] << "\"\n";
                return false;
            }
        }
    }
    return true;
}

bool checkFirstPart(std::string part)
{
    if (part.length() > 64)
    {
        std::cout << "Длина первой части адреса превышает 64 символа\n";
        return false;
    }
    std::string alphabit = getCommonAlphabit();
    alphabit += "!#$%&'*+-/=?^_{|}~`";
    return checkPart(part, alphabit);
}

bool checkSecondPart(std::string part)
{
    if (part.length() > 63)
    {
        std::cout << "Длина второй части адреса превышает 63 символа\n";
        return false;
    }
    return checkPart(part, getCommonAlphabit());
}

int main()
{

    std::string email;
    std::cout << "Введите e-mail: ";
    std::getline(std::cin, email);

    if (countAt(email) != 1)
        std::cout << "Адрес должен содержать 1 символ @\n";
    else if (!checkFirstPart(getPartEmail(email, true)))
        std::cout << "Первая часть адреса не соответствует стандарту\n";
    else if (!checkSecondPart(getPartEmail(email, true)))
        std::cout << "Вторая часть адреса не соответствует стандарту\n";
    else
        std::cout << "Адрес корректный\n";
    return 0;
}