#pragma once
#include <vector>
#include <string>
#include <map>

class modAlphaCipher
{
private:
    // –усский алфавит из 33 букв (заглавные)
    std::string numAlpha = "јЅ¬√ƒ≈®∆«»… ЋћЌќѕ–—“”‘’÷„ЎўЏџ№Ёёя";
    std::map<char, int> alphaNum; // ассоциативный массив "символ -> номер"
    std::vector<int> key;         // ключ в числовом виде

    // ¬спомогательные методы преобразовани€
    std::vector<int> convert(const std::string& s); // строка - вектор
    std::string convert(const std::vector<int>& v); // вектор - строка

public:
    modAlphaCipher() = delete; // запрет конструктора
    explicit modAlphaCipher(const std::string& skey); // конструктор с ключом
    std::string encrypt(const std::string& open_text);
    std::string decrypt(const std::string& cipher_text);
};