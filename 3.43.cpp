#include <iostream>
#include <string>

bool isPalindrome(const std::string& s)
{
    int left = 0;
    int right = s.length() - 1;

    while (left < right)
    {
        if (s[left] != s[right])
        {
            return false;
        }
        left++;
        right--;
    }

    return true;
}

std::string findNonPalindromeSubstring(const std::string& s)
{
    int n = s.length();
    for (int len = n; len >= 2; len--)
    {
        for (int i = 0; i <= n - len; i++)
        {
            std::string substring = s.substr(i, len);
            if (!isPalindrome(substring))
            {
                return substring;
            }
        }
    }

    return "NO SOLUTION";
}

int main()
{
    std::string s;
    std::cout << "Введите строку: ";
    std::cin >> s;

    std::string result = findNonPalindromeSubstring(s);
    std::cout << "Наибольшая по длине подстрока, не являющаяся палиндромом: " << result << std::endl;

    return 0;
}