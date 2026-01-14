/**
*
* Solution to course project # 11
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2025/2026
*
* @author Nikola Stoyanov
* @idnumber 3MI0600561* @compiler VS
*
* <file with helper function implementations>
*
*/

#include "helpers.h"
#include <iostream>

int myStrLen(const char* str)
{
    if (!str)
        return 0;

    unsigned result = 0;

    while (*str)
    {
        result++;
        str++;
    }

    return result;
}

void myStrCopy(char* dest, const char* str)
{
    if (!str)
        return;

    while (*str)
    {
        *dest = *str;
        dest++;
        str++;
    }

    *dest = '\0';
}

void myStrCat(char* dest, const char* str)
{
    if (!dest || !str)
        return;

    int firstLen = myStrLen(dest);
    dest += firstLen;
    myStrCopy(dest, str);
}

int keepInRange(int min, int max, int value)
{
    if (value > max)
        return max;
    if (value < min)
        return min;

    return value;
}

int getLength(int num)
{
    int res = 0;
    do
    {
        num /= 10;
        res++;
    } while (num);
    return res;
}


void inputUserName(char name[])
{
    std::cin.ignore(100, '\n');
    std::cout << "Enter username: ";
    std::cin >> name;
}
