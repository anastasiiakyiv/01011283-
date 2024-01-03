#include <iostream>
#include <string>
#include <cctype>
using namespace std;

std::string decodeToAB(const std::string& encodedText)
{
    std::string decodedText = "";
    std::string temp = "";

    for (char c : encodedText)
    {
        if (!isalpha(c))
        {
            decodedText += c;
            continue;
        }

        if (islower(c))
        {
            temp += 'a';
        }

        else if (isupper(c))
        {
            temp += 'b';
        }

        if (temp.length() == 5)
        {
            decodedText += temp + " ";
            temp = "";
        }
    }

    if (!temp.empty())
    {
        decodedText += temp;
    }

    return decodedText;
}

std::string decodeFromAB(const std::string& encodedText)
{
    std::string decodedText = "";
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    std::string baconianCipher[26] =
    {
        "aaaaa", "aaaab", "aaabb", "aabbb", "abbbb", "bbbbb", "bbbba", "bbbab", "bbabb", "babbb",
        "abbba", "bbbaa", "bbaab", "baabb", "aabba", "abbab", "bbaba", "babab", "ababb", "babba",
        "abbaa", "bbaaa", "baaab", "aaaba", "aabab", "ababa"
    };

    std::string temp = "";
    for (char c : encodedText)
    {
        if (isalpha(c))
        {
            temp += c;
        }

        else if (c == ' ')
        {
            for (int i = 0; i < 26; ++i)
            {
                if (temp == baconianCipher[i])
                {
                    decodedText += alphabet[i];
                    break;
                }
            }
            temp = "";
        }

        else
        {
            decodedText += c;
        }
    }

    for (int i = 0; i < 26; ++i)
    {
        if (temp == baconianCipher[i])
        {
            decodedText += alphabet[i];
            break;
        }
    }

    return decodedText;
}

int main()
{
    std::string text = "wELcOMe To The HOtEL caLiFORNIa SUcH A LoVeLY PLaCE sucH a LO";

    std::string decodedToAB = decodeToAB(text);
    std::cout << "Decoded text to AB symbols: " << decodedToAB << std::endl;

    std::string decodedText = decodeFromAB(decodedToAB);
    std::cout << "Decoded text: " << decodedText << std::endl;

    return 0;
}