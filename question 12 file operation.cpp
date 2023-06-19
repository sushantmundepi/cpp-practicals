#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string inputFile, outputFile;
    cout << "Enter the input file name: ";
    cin >> inputFile;
    cout << "Enter the output file name: ";
    cin >> outputFile;

    ifstream input(inputFile);

    ofstream output(outputFile);

    char c;
    while (input.get(c))
    {
        if (!isspace(c))
        {
            output.put(c);
        }
    }

    input.close();
    output.close();

    cout << "Contents of " << inputFile << " copied to " << outputFile << " after removing whitespaces." << endl;

    return 0;
}
