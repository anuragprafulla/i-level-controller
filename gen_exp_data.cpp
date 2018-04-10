#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
    ofstream outFile;
    outFile.open("raw-exp.txt");

    if(!outFile)
    {
        cerr << "Unable to open file";
    }

    for(int i=0;i<3000;i++)
    {
        double y = 10*(1-exp(-0.05*i/20));
        outFile <<y<<"\n";
    }

    outFile.close();

    return 0;
}

