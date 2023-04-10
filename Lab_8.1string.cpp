#include <iostream>
#include <string>
using namespace std;
int Count(const string s)
{
int k = 0;
size_t pos = 0;
while ((pos=s.find("NO", pos)) != -1)
{
pos++;
k++;
}
pos = 0;
while ((pos=s.find("ON", pos)) != -1)
{
pos++;
k++;
}
return k;
}
string Change(string& s)
{
size_t pos = 0;
while ((pos=s.find("NO", pos)) != -1)
s.replace(pos, 2, "***");
pos = 0;
while ((pos=s.find("ON", pos)) != -1)
s.replace(pos, 2, "***");
return s;
}
int main()
{
string str;
cout << "Enter string:" <<< endl;
getline (cin, str);
cout << "String contained " << Count(str) << " groups of 'NO' or 'ON' << endl;
string dest=Change(str);
cout << "Modified string (param) : " << str << endl;
cout << "Modified string (result): " << dest << endl;
return 0;
}