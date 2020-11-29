// Дано літерний рядок, який містить послідовність символів s[0], ..., s[n], ...  
// 1.   Вияснити, чи є серед цих символів пара сусідні букв "aa" або "bb" або "cc".  
// 2.   Замінити кожну пару сусідніх букв "aa" або "bb" або "cc" трійкою зірочок "***". 
//      Lab 8.1 Рекурсивний спосіб

#define _CRT_SECURE_NO_WARNINGS 
#include <iostream> 

using namespace std;

// c - previous character
bool Find_r(char* str, char c) {
    if (str[0] == 0) return false;
    if (str[0] == c) return true;
    return Find_r(str + 1, str[0]);
}

void Process_r(char* str, char* newStr, char &state, int &strPos, int &newStrPos) {
    if (str[strPos] == 0) {
        if (state == 'a') newStr[newStrPos++] = 'a';
        if (state == 'b') newStr[newStrPos++] = 'b';
        if (state == 'c') newStr[newStrPos++] = 'c';
        newStr[newStrPos++] = '\0';
        return;
    }

    switch (str[strPos]) {
    case 'a':
        if (state == 'a') {
            newStr[newStrPos++] = '*';
            newStr[newStrPos++] = '*';
            newStr[newStrPos++] = '*';
            state = ' ';
        }
        else {
            if (state == 'b') newStr[newStrPos++] = 'b';
            if (state == 'c') newStr[newStrPos++] = 'c';
            state = 'a';
        }
        break;
    case 'b':
        if (state == 'b') {
            newStr[newStrPos++] = '*';
            newStr[newStrPos++] = '*';
            newStr[newStrPos++] = '*';
            state = ' ';
        }
        else {
            if (state == 'a') newStr[newStrPos++] = 'a';
            if (state == 'c') newStr[newStrPos++] = 'c';
            state = 'b';
        }
        break;
    case 'c':
        if (state == 'c') {
            newStr[newStrPos++] = '*';
            newStr[newStrPos++] = '*';
            newStr[newStrPos++] = '*';
            state = ' ';
        }
        else {
            if (state == 'a') newStr[newStrPos++] = 'a';
            if (state == 'b') newStr[newStrPos++] = 'b';
            state = 'c';
        }
        break;
    default:
        if (state == 'a') newStr[newStrPos++] = 'a';
        if (state == 'b') newStr[newStrPos++] = 'b';
        if (state == 'c') newStr[newStrPos++] = 'c';
        newStr[newStrPos++] = str[strPos];
        state = ' ';
        break;
    }
    strPos++;

    Process_r(str, newStr, state, strPos, newStrPos);
    return;
}

int main() {
    char str[101];
    char newStr[151];

    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    bool changed = Find_r(str,  ' ');

    char state = ' ';
    int strPos = 0;
    int newStrPos = 0;
    
    Process_r(str, newStr, state, strPos, newStrPos);

    cout << "String: " << str << endl << endl;
    if (changed) {
        cout << "String was modified." << endl;
        cout << "Modified string (result): " << newStr << endl;
    }
    else {
        cout << "String was not modified." << endl;
    }

    return 0;
}