#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

string ReadFile()
{
    string line;
    ifstream txt("D:\word.txt");
    getline(txt, line);
    txt.close();
    return line;
}

vector<string> decode(string line)
{
    istringstream input{ line };
    vector<string> words;

    while (!input.eof())
    {
        string temp;
        input >> temp;
        words.push_back(temp);
    }

    for (int i = 0; i < words.size(); i++)
    {
        rotate(words[i].begin(), words[i].begin() + (words[i].length() - 3), words[i].end());
        cout << words[i] << " ";
    }

    return words;
}

int main()
{
    decode(ReadFile());
}