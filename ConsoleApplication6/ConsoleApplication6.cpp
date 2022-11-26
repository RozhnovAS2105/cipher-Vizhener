//Шифр Виженера
#include <iostream>
#include <string>
using namespace std;

class Vigenere
{
public:
    string key;

    Vigenere(string key)
    {
        for (int i = 0; i < key.size(); ++i)
        {
            if (key[i] >= 'A' && key[i] <= 'Z')
                this->key += key[i];
            else if (key[i] >= 'a' && key[i] <= 'z')
                this->key += key[i] + 'A' - 'a';
        }
    }

    string encrypt(string text)//зашифровать
    {
        string out;

        for (int i = 0, j = 0; i < text.length(); ++i)
        {
            char c = text[i];

            if (c >= 'a' && c <= 'z')
                c += 'A' - 'a';
            else if (c < 'A' || c > 'Z')
                continue;

            out += (c + key[j] - 2 * 'A') % 26 + 'A';
            j = (j + 1) % key.length();
        }

        return out;
    }

    string decrypt(string text)//расшифровать
    {
        string out;

        for (int i = 0, j = 0; i < text.length(); ++i)
        {
            char c = text[i];

            if (c >= 'a' && c <= 'z')
                c += 'A' - 'a';
            else if (c < 'A' || c > 'Z')
                continue;

            out += (c - key[j] + 26) % 26 + 'A';
            j = (j + 1) % key.length();
        }

        return out;
    }

    void show()const
    {
        cout << "Ключ: " << key << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    Vigenere cipher("caesar");//ключ

    string original = "come join us";//входной текст
    string encrypted = cipher.encrypt(original);
    string decrypted = cipher.decrypt(encrypted);

    cout << "Входной текст: " << original << endl;
    cipher.show();
    cout << "Зашифрованное: " << encrypted << endl;
    cout << "Расшифрованное: " << decrypted << endl;
}