// ���� ������� �����, ���� ������ ����������� ������� s[0], ..., s[n], ...  
// 1.   ��������, �� � ����� ��� ������� ���� ����� ���� "aa" ��� "bb" ��� "cc".  
// 2.   ������� ����� ���� ������ ���� "aa" ��� "bb" ��� "cc" ������ ������ "***". 
//      Lab 8.1 ����������� �����

#define _CRT_SECURE_NO_WARNINGS 
#include <iostream> 

using namespace std;

void Process_r(char* str, char* newStr, bool &changed, char &state, int &strPos, int &newStrPos) {
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
            changed = true;
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
            changed = true;
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
            changed = true;
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

    Process_r(str, newStr, changed, state, strPos, newStrPos);
    return;
}

int main() {
    char str[101];
    char newStr[151];
    bool changed = false;

    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    char state = ' ';
    int strPos = 0;
    int newStrPos = 0;
    
    Process_r(str, newStr, changed, state, strPos, newStrPos);

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