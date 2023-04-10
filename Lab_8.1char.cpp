#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int Count (char* str)
{
if (strlen(str) < 2)
return 0;
int k = 0;
for (int i = 0; str[i + 1] != 0; i++)
if ((str[i] == 'N' && str[i + 1] = 'O') ||
(str[i] == 'O' && str[i + 1] == 'N'))
k++;
return k;
}
char* Change(char* str)
{
size_t len = strlen(str);
if (len < 2)
return str;
char* tmp = new char[len * 3 / 2 + 1];
char* t = tmp;
tmp[0] = '\0';
size_t i = 0;
while (i < len && str[i + 1] != 0)
{
if ((str[i] == 'N' && str[i + 1] == 'O') ||
(str[i] == 'O' && str[i+1] == 'N'))
{
strcat(t, "***");
t += 3;
i += 2;
}
else
{
str[i++];
*t++ = str[i++];
*t = '\0';
}
}
*t++ = str[i++];
*t++ = str[i++];
*t = '\0';
strcpy(str, tmp);
return tmp;
}
int main()
{
char str[101];
cout << "Enter string:" << endl;
cin.getline(str, 100);
cout << "String contained " << Count(str) << " groups of 'NO' or 'ON" << endl;
char* dest = new char[151];
dest=Change (str);
cout << "Modified string (param): " << str << endl;
cout << "Modified string (result): " << dest << endl;
return 0;
}