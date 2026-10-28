#include <iostream>
#include <string>
#include <windows.h> 
#include "modAlphaCipher.h"

using namespace std;

bool isValid(const string& s)
{
    string rusAlpha = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    if (s.empty()) return false;
    for (char c : s) {
        if (rusAlpha.find(c) == string::npos)
            return false;
    }
    return true;
}

int main()
{
    // ПЕРЕКЛЮЧЕНИЯ КОНСОЛИ НА 1251
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string key;
    string text;
    unsigned op;

    cout << "Введите ключ (заглавные русские буквы): ";
    cin >> key;

    if (!isValid(key)) {
        cerr << "Некорректный ключ!\n";
        return 1;
    }

    modAlphaCipher cipher(key);
    cout << "Ключ успешно загружен.\n";

    do {
        cout << "\nВведите операцию (0-выход, 1-зашифровать, 2-расшифровать): ";
        cin >> op;

        if (op > 2) {
            cout << "Недопустимая операция.\n";
        }
        else if (op > 0) {
            cout << "Введите текст: ";
            cin >> text;

            if (isValid(text)) {
                if (op == 1) {
                    cout << "Зашифрованный текст: " << cipher.encrypt(text) << endl;
                }
                else {
                    cout << "Расшифрованный текст: " << cipher.decrypt(text) << endl;
                }
            }
            else {
                cout << "Операция отменена: некорректный текст.\n";
            }
        }
    } while (op != 0);

    return 0;
}