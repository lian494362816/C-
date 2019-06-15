#include <iostream>
#include <fstream>

using namespace std;

static const char *file_name = "_tmp.txt";

int main(void)
{
    char data[100];
    int age;
    ofstream out_file;
    ifstream in_file;

    out_file.open(file_name);
    if (!out_file.is_open())
    {
        cout << "open fail" << file_name << endl;
        return -1;
    }

    cout << "Input your name:";
    cin.getline(data, 100);
    out_file << data << endl;

    cout << "Input your aga:";
    cin >> age;
    out_file << age << endl;

    out_file.close();


    in_file.open(file_name);
    if (!in_file.is_open())
    {
        cout << "open fail:" << file_name << endl;
        return -1;
    }

    cout << "Read form file:" << file_name << endl;
    in_file >> data;
    cout << "Name:" << data << endl;
    in_file >> age;
    cout << "Age:" << age << endl;

    in_file.close();

    return 0;
}
