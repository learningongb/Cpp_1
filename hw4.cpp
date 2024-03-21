// Задание 4. Оценка результатов игры в крестики-нолики

#include <iostream>

char checkString(std::string str)
{
    if (str[0] != '.' && str[0] == str[1] && str[0] == str[2])
    {
        return str[0];
    }
    return '.';
}

char checkColumn(std::string str1, std::string str2, std::string str3, int index)
{
    if (str1[index] != '.' && str1[index] == str2[index] && str1[index] == str3[index])
    {
        return str1[index];
    }
    return '.';
}

int getCountSymbol(std::string str1, std::string str2, std::string str3, char symbol)
{
    int count = 0;
    for (int i = 0; i < str1.length(); i++)
    {
        if (str1[i] == symbol)
            count++;
        if (str2[i] == symbol)
            count++;
        if (str3[i] == symbol)
            count++;
    }
    return count;
}

bool checkCountWinnerSteps(int countWinnerSteps, int countLooserSteps)
{
    return countWinnerSteps == countLooserSteps || countWinnerSteps - countLooserSteps == 1;
}

int main()
{
    std::string str1, str2, str3;
    std::cout << "Введите 3 строки, содержащие значения X или O. Если поле пустое, то .\n";
    std::cin >> str1;
    std::cin >> str2;
    std::cin >> str3;

    if (str1.length() != 3 || str2.length() != 3 || str3.length() != 3)
    {
        std::cout << "Некорректно описано игровое поле\n";
        std::cout << "Incorrect.\n";
        return 0;
    }

    int countX = getCountSymbol(str1, str2, str3, 'X');
    int countY = getCountSymbol(str1, str2, str3, 'O');
    if (countX + countY + getCountSymbol(str1, str2, str3, '.') != 9)
    {
        std::cout << "Используются некорректные символы\n";
        std::cout << "Incorrect.\n";
        return 0;
    }

    int winCount = 0;
    char winSymbol;
    char currentWinSymbol;

    currentWinSymbol = checkString(str1);
    winSymbol = currentWinSymbol != '.' ? currentWinSymbol : winSymbol;
    winCount += currentWinSymbol != '.' ? 1 : 0;

    currentWinSymbol = checkString(str2);
    winSymbol = currentWinSymbol != '.' ? currentWinSymbol : winSymbol;
    winCount += currentWinSymbol != '.' ? 1 : 0;

    currentWinSymbol = checkString(str3);
    winSymbol = currentWinSymbol != '.' ? currentWinSymbol : winSymbol;
    winCount += currentWinSymbol != '.' ? 1 : 0;

    for (int i = 0; i < 3; i++)
    {
        currentWinSymbol = checkColumn(str1, str2, str3, i);
        winSymbol = currentWinSymbol != '.' ? currentWinSymbol : winSymbol;
        winCount += currentWinSymbol != '.' ? 1 : 0;
    }

    if (str1[0] != '.' && str1[0] == str2[1] && str1[0] == str3[2])
    {
        winCount++;
        winSymbol = str1[0];
    }
    if (str1[2] != '.' && str1[2] == str2[1] && str1[2] == str3[0])
    {
        winCount++;
        winSymbol = str1[0];
    }

    if (winCount == 1)
    {
        if (winSymbol == 'X' ? checkCountWinnerSteps(countX, countY) : checkCountWinnerSteps(countY, countX))
        {
            std::cout << winSymbol << " победил!\n";
            std::cout << (winSymbol == 'X' ? "Petya" : "Vanya") << " won\n";
            {
            }
        }
        else
        {
            std::cout << "Победил " << winSymbol << ", но в описании игровой позиции есть ошибки. Победа не засчитывается.\n";
            std::cout << "Incorrect.\n";
        }
    }
    else if (winCount > 1)
    {
        std::cout << "Ошибка! На поле отмечено несколько победных ходов!\n";
        std::cout << "Incorrect.\n";
    }
    else
    {
        if (countX + countY == 9)
        {
            std::cout << "Nobody.\n";
        }
        else if (checkCountWinnerSteps(countX, countY) || checkCountWinnerSteps(countY, countX))
        {
            std::cout << "Игра не доиграна.\n";
            std::cout << "Nobody.\n";
        }
        else
        {
            std::cout << "Игровая позиция записана не правильно.\n";
            std::cout << "Incorrect.\n";
        }
    }
    return 0;
}