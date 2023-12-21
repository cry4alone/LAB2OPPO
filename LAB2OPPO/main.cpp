// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include <vld.h>
#include "zan.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <clocale>
using namespace std;

int load(vector<Zan>& data, istream& ist)
{
    int size = 0;
    while (!ist.eof() && !cin.fail())
    {
        Zan newClass;
        newClass.load_txt(ist);
        data.push_back(newClass);
        size++;
    }
    return size;
}

void print_data(vector<Zan>& data, int size)
{
    for (int i = 0; i < size; i++)
    {
        data[i].print_txt(cout);
        cout << endl;
    }
}

int main()
{
    setlocale(0, "");
    vector <Zan> data;
    ifstream in("C:\\Users\\andre\\source\\repos\\LAB2OPPO\\LAB2OPPO\\in3.txt");
    if (!in.is_open())
    {
        cout << "Файл не открыт" << endl;
    }
    try
    {
        int size = load(data, in);
        print_data(data, size);
    }
    catch (runtime_error& err)
    {
        cout << err.what() << endl;
    }
    in.close();
    return 0;
}