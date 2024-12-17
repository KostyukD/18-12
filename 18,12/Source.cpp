#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;


string toLowerCase(const string& str) 
{
    string lowerCaseStr = str;
    transform(lowerCaseStr.begin(), lowerCaseStr.end(), lowerCaseStr.begin(), ::tolower);
    return lowerCaseStr;
}


string removePunctuation(const string& str)
{
    string cleanStr;
    for (char ch : str)
    {
        if (isalpha(ch) || isdigit(ch) || ch == ' ') 
        {
            cleanStr += ch;
        }
    }
    return cleanStr;
}

int main() 
{
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");
    if (!inputFile.is_open())
    {
        cerr << "������ ��� �������� ����� ��� ������!" << endl;
        return 1;
    }
    if (!outputFile.is_open()) 
    {
        cerr << "������ ��� �������� ����� ��� ������!" << endl;
        return 1;
    }

    map<string, int> wordFrequency;
    string line, word;


    while (getline(inputFile, line))
    {
        line = toLowerCase(line);
        line = removePunctuation(line);
        istringstream iss(line);
        while (iss >> word) 
        {
            wordFrequency[word]++;
        }
    }


    outputFile << "��������� �������:\n";
    for (const auto& entry : wordFrequency) 
    {
        outputFile << entry.first << ": " << entry.second << endl;
    }


    string mostFrequentWord;
    int maxFrequency = 0;
    for (const auto& entry : wordFrequency)
    {
        if (entry.second > maxFrequency) 
        {
            mostFrequentWord = entry.first;
            maxFrequency = entry.second;
        }
    }
    outputFile << "\n�������� ����� ������������� �����: " << mostFrequentWord
        << " (����������� " << maxFrequency << " ���)" << endl;

    cout << "��������� ���������. ���������� �������� � ���� output.txt." << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
