#include "modAlphaCipher.h"
#include <stdexcept>

modAlphaCipher::modAlphaCipher(const std::string& skey)
{
    if (skey.empty()) {
        throw std::invalid_argument("Ключ не может быть пустым");
    }
    //  size_t чтобы избежать C4267
    for (size_t i = 0; i < numAlpha.size(); i++) {
        alphaNum[numAlpha[i]] = static_cast<int>(i);
    }

    for (char c : skey) {
        if (alphaNum.find(c) == alphaNum.end()) {
            throw std::invalid_argument("Недопустимый символ в ключе");
        }
    }
    key = convert(skey);
}

inline std::vector<int> modAlphaCipher::convert(const std::string& s)
{
    std::vector<int> result;
    result.reserve(s.length());
    for (char c : s) {
        result.push_back(alphaNum[c]);
    }
    return result;
}

inline std::string modAlphaCipher::convert(const std::vector<int>& v)
{
    std::string result;
    result.reserve(v.size());
    for (int i : v) {
        // int в size_t 
        result.push_back(numAlpha[static_cast<size_t>(i)]);
    }
    return result;
}

std::string modAlphaCipher::encrypt(const std::string& open_text)
{
    std::vector<int> work = convert(open_text);

    //  int чтобы избежать смешивания типов в формуле
    int keySize = static_cast<int>(key.size());
    int alphaSize = static_cast<int>(alphaNum.size());

    for (size_t i = 0; i < work.size(); i++) {
        work[i] = (work[i] + key[i % keySize]) % alphaSize;
    }
    return convert(work);
}

std::string modAlphaCipher::decrypt(const std::string& cipher_text)
{
    std::vector<int> work = convert(cipher_text);

    int keySize = static_cast<int>(key.size());
    int alphaSize = static_cast<int>(alphaNum.size());

    for (size_t i = 0; i < work.size(); i++) {
        // alphaSize чтобы гарантированно избежать отрицательных значений
        work[i] = (work[i] + alphaSize - key[i % keySize]) % alphaSize;
    }
    return convert(work);
}