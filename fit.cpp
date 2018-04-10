#include <iostream>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

double average_20(int i, vector <double> h)
{
    double average_20=0;
    for(int j=0;j<20;j++)
    {
        average_20+= h[i+j];
    }
    return average_20/20;
}

int main()
{
    ifstream inFile;
    inFile.open("raw-exp.txt");

    if (!inFile) {
        cerr << "Unable to open file";
        exit(1);
    }

    double H_cont = 40; //Container Height
    double H = 27; //Set height
    double eps = 0.0001;

    vector <double> h;
    vector <double> t;


    int i=1;
    double K, T= 0;
    double val;
    while (inFile>>val)
    {
        //val = (H_cont-val)/H;
        h.push_back(val);
        t.push_back(0.05*i);
        i++;
    }
    cout<<"h.size "<<h.size()<<endl;

    
    for(int i=0;i<h.size()-22;i++)
    {
        if(abs(average_20(i, h)-average_20(i+1, h))<eps)
        {
            cout<<"i:"<<i<<endl;
            K = average_20(i,h);
            cout<<"K: "<<K<<endl;
            break;
        }
    }

    for(int i=0;i<h.size()-22;i++)
    {
        if((.638*K-average_20(i+1,h))<eps)
        {
            T = t[i+1];
            cout<<"T: "<<T<<endl;
            break;
        }
    }
    return 0;
}


