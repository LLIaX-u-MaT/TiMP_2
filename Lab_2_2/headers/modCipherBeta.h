#pragma once
#include <cctype>
#include <cmath>
#include <iostream>
#include <locale>
#include <vector>
#include <codecvt>
using namespace std;

class Cipher
{
private:
    int key;

public:
    Cipher() = delete; // Запрет на создание объекта без ключа
    Cipher(int key, const std::wstring& text);
    wstring encrypt(const wstring& text);
    wstring decrypt(const wstring& text);
    int getValidKey(const int& key, const std::wstring& text);
    std::wstring getValidOpenText(const std::wstring& s);
    std::wstring getValidCipherText(const std::wstring& s);
};
class cipher_error : public std::invalid_argument
{
public:
    explicit cipher_error(const std::string& what_arg)
        : std::invalid_argument(what_arg)
    {
    }

    explicit cipher_error(const char* what_arg)
        : std::invalid_argument(what_arg)
    {
    }
};