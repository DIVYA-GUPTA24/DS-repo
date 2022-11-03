#include <iostream>
using namespace std;
int validvariable(string s)
{

    int i = 0;
    int flag = 1;
    if (s[i] == '_' || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
    {
        int i = 1;
        while (s[i] != '\0')
        {
            if (s[i] == '_' || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || s[i] == '$' || (s[i] >= '0' && s[i] <= '9'))
            {
                i++;
            }
            else
            {
                flag = 0;
                break;
            }
        }
    }
    else
    {
        flag = 0;
    }
    if (flag == 1 && i < 32)
    {
        cout << "valid";
    }
    else
    {
        cout << "invalid";
    }
}

int main()
{
    string s;
    cin >> s;
    validvariable(s);
}
