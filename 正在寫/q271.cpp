#include <iostream> 
#include<string>

using namespace std;

int is_valid(const string& str, const int& pos) throw(bool)
{
    if(pos >= str.length())
        return 0;
    
    int valid = is_valid(str, pos+1);
    
    if(str[pos] >= 'p' && str[pos] <= 'z')
        return valid + 1;
    if(str[pos] == 'N')
    {
        if(valid < 1)
            throw false;
        else
            return valid;
    }
    if(str[pos] == 'C' || str[pos] == 'D' || str[pos] == 'I' || str[pos] == 'E')
    {
        if(valid < 2)
            throw false;
        else
            return valid - 1;
    }
}

bool parse(const string& str)
{
    try {
        return is_valid(str, 0) == 1;
    }
    catch(bool&) {
        return false;
    }
}

int main()
{
    string input;
    while(cin >> input)
        cout << (parse(input)? "YES" : "NO") << endl;
    return 0;
}