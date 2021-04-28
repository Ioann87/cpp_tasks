#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

const int MAXLEN = 512;

void memmory_clear(char* str_ptr);
//task 1
void replace_tab(char* str_ptr);
void remove_space_before(char* str_ptr);
void remove_space_between(char* str_ptr);
void remove_space_after(char* str_ptr, int& len);
void word_counter(char* str_ptr, int& counter, int& len);
//task 2
void check_palindrome(char* palindrome, int& len, bool& check);

int main()
{
    // Task 1: remove all tab and space
    char* str_ptr = nullptr;
    str_ptr = new char[MAXLEN];
    // input
    puts("Enter a string:");
    fgets(str_ptr, MAXLEN, stdin);
    // len of string
    int len = 0;
    len = strlen(str_ptr);
    cout << "Length before = " << len << endl;
    cout << endl;

    // functions to delete spaces
    replace_tab(str_ptr);
    remove_space_before(str_ptr);
    remove_space_between(str_ptr);

    len = strlen(str_ptr);
    remove_space_after(str_ptr, len);

    len = strlen(str_ptr);
    cout << "Length after = " << len << endl;
    cout << str_ptr << endl;
    // function to count word
    int word = 0;
    word_counter(str_ptr, word, len);
    cout << word << " words in string." << endl;
    cout << endl;
    //-------------------------------------------------
    // Task 2: palindrome string
    char* palindrome = nullptr;
    palindrome = new char[MAXLEN];
    // input
    puts("Enter a word:");
    fgets(palindrome, MAXLEN, stdin);

    len = strlen(palindrome);

    bool check = false;

    check_palindrome(palindrome, len, check);

    if (check) {
        cout << "Palindrome" << endl;
    } else {
        cout << "It is not palindrome" << endl;
    }
    // memmory cleaner
    memmory_clear(str_ptr);
    memmory_clear(palindrome);
    system("pause");
    return 0;
}
// task 1-----------------------------------------------------------
void memmory_clear(char* str_ptr)
{
    delete[] str_ptr;
    return;
}

void replace_tab(char* str_ptr)
{
    int i = 0;
    while (str_ptr[i] != '\0') {
        if (str_ptr[i] == '\t') {
            str_ptr[i] = ' ';
        }
        i++;
    }
    return;
}

void remove_space_before(char* str_ptr)
{
    int i = 0;
    int j = 0;
    while (str_ptr[0] == ' ') {
        if (str_ptr[i + 1] != ' ') {
            while (str_ptr[j] != '\0') {
                str_ptr[j] = str_ptr[i + 1];
                j++;
                i++;
            }
        } else {
            i++;
        }
    }
    return;
}

void remove_space_between(char* str_ptr)
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (str_ptr[k] != '\0') {
        if (str_ptr[k] == ' ') {
            while (str_ptr[i + 1] == ' ') {
                if (str_ptr[i + 2] != ' ') {
                    while (str_ptr[j] != '\0') {
                        str_ptr[j] = str_ptr[i + 1];
                        j++;
                        i++;
                    }
                    i = k;
                    j = k;
                } else {
                    i++;
                }
            }
        }
        k++;
        i++;
        j++;
    }
    return;
}

void remove_space_after(char* str_ptr, int& len)
{
    int j = len - 2;
    while (str_ptr[j] != '\0') {
        if (str_ptr[j] == ' ') {
            str_ptr[j] = str_ptr[j + 1];
            j++;
        }
        j++;
    }
    return;
}

void word_counter(char* str_ptr, int& word, int& len)
{
    for (int i = 0; i <= len; i++) {
        if (str_ptr[i] == ' ' || str_ptr[i] == '\0') {
            word++;
        }
    }
    return;
}
// task 2-----------------------------------------------------------
void check_palindrome(char* palindrome, int& len, bool& check)
{
    int i = 0;
    int j = len - 2;

    while (i != len - 2) {
        if (palindrome[i] == palindrome[j]) {
            check = true;
        } else {
            check = false;
        }
        i++;
        j--;
    }
    return;
}
