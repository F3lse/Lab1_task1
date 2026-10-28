#include <iostream>
#include <string>
#include "modAlphaCipher.h"

using namespace std;

void check(const string& Text, const string& key)
{
    try {
        string cipherText;
        string decryptedText;
        modAlphaCipher cipher(key);
        cipherText = cipher.encrypt(Text);
        decryptedText = cipher.decrypt(cipherText);

        cout << "Ключ: " << key << endl;
        cout << "Исходный текст:  " << Text << endl;
        cout << "Зашифрованный:   " << cipherText << endl;
        cout << "Расшифрованный:  " << decryptedText << endl;

        if (Text == decryptedText)
            cout << ">>> Результат: Ok\n\n";
        else
            cout << ">>> Результат: Err\n\n";
    }
    catch (const exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");

    
    string testText = "СЪЕШЬЖЕЕЩЁЭТИХМЯГКИХФРАНЦУЗСКИХБУЛОКДАВЫПЕЙЧАЮ";

    check(testText, "КЛЮЧ");
    check(testText, "ШИФРОВАНИЕ");
    check(testText, "АБВ");

    return 0;
}