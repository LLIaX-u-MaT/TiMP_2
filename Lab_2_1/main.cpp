#include "modAlphaCipher.h"

using namespace std;
void check(const wstring& Text, const wstring& key, const bool destructCipherText=false)
{
    try {
        wstring cipherText;
        wstring decryptedText;
        modAlphaCipher cipher(key);
        cipherText = cipher.encrypt(Text);
        if(destructCipherText)
            cipherText.front() = tolower(cipherText.front());
        decryptedText = cipher.decrypt(cipherText);
        wcout << L"Ключ = " << key << endl;
        wcout << L"Текст: " << Text << endl;
        wcout << L"Зашифрованный текст: " << cipherText << endl;
        wcout << L"Расшифрованный текст: " << decryptedText << endl;
    } catch(const cipher_error& e) {
        cerr << "Ошибка: " << e.what() << endl;
    }
}
int main(int argc, char** argv)
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    wcout << L"Некорректный ключ зашифрования" << endl;
    check(L"Быстроногая лисица прыгает на ленивого пса", L"АБ0Б1");
    wcout << endl;
    wcout << L"Текст является числом, пустой вывод" << endl;
    check(L"1337", L"Пример");
    wcout << endl;
    wcout << L"Корректное зашифрование текста" << endl;
    wcout << L"(удаление пробелов и преобразование всех букв в прописные)" << endl;
    check(L"Быстроногая лисица прыгает на ленивого пса", L"АБВГ");
    wcout << endl;
    wcout << L"Порча» зашифрованного текста изменением первого символа с прописного на строчный" << endl;
    check(L"Быстроногая лисица прыгает на ленивого пса", L"АБВГ", true);
    wcout << endl;
    return 0;
}
