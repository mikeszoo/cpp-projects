#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
int main()
{
    string csvFile = "csvFile.csv";
    string htmlFile = "htmlFile.html";

    ifstream csvFileOpen(csvFile);
    ofstream htmlFileOpen(htmlFile);

    if(!csvFileOpen.is_open())
    {
        cerr << "Blad: Nie mozna otworzyc pliku" << csvFile << endl;
        return 1;
    }
    if (!htmlFileOpen.is_open())
    {
        cerr << "Blad: Nie mozna otworzyc pliku" << htmlFile << endl;
        return 1;
    }

    htmlFileOpen << "<!DOCTYPE html>\n<html>\n<head>\n<title>Tabela CSV</title>\n</head>\n<body>\n<table border=\"1\">\n";

    string line;
    while (getline(csvFileOpen, line))
    {
        string field;

        htmlFileOpen << "<tr>\n";
        stringstream ss(line);

        while (getline(ss,field,','))
        {
            htmlFileOpen << "<td>" << field << "</td>"; 
        }
        
        htmlFileOpen << "</tr>\n";
    }
    htmlFileOpen << "</table>\n</body>\n</html>";

    csvFileOpen.close();
    htmlFileOpen.close();

    cout << "Konwersja zakonczona pomyslnie." << endl;

}
