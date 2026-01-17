/**
*
* Solution to course project # 11
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2025/2026
*
* @author Nikola Stoyanov
* @idnumber 3MI0600561* @compiler VC
*
* <file with helper function definitions>
*
*/

#ifndef HELPERS_H
#define HELPERS_H

int myStrLen(const char* str);
void myStrCopy(char* dest, const char* str);
void myStrCat(char* dest, const char* str);
int keepInRange(int min, int max, int value);
int getLength(int num);
void inputUserName(char username[]);
#endif