#include <iostream>
#include<sstream>  

using namespace std;

string toString(int);

int main()
{
    int monthLength[] = {31,29,31,30,31,30,31,31,30,31,30,31};
    int beginDay = 3;
    int dayCount; 
    int counter;
    string out = "int calendario[12][6][7] = {\n";
    for(int i=0; i<12; i++)
    {
        dayCount = 0;
        counter = dayCount; 
        out += "{\n";
        for(int j=0;j<6;j++)
        {
            out += "{";
            for(int k=0; k<7;k++)
            {
                int value=0;
                if(counter>= beginDay && dayCount < monthLength[i])
                {
                    dayCount++;
                    value = dayCount;
                }
                if(dayCount == monthLength[i])
                {
                    dayCount++; 
                    beginDay = (k==6) ? 0 : k+1;
                }
                out += (k==6) ? toString(value): toString(value)+",";
                counter++;
            }
            out += (j==5)? "}\n" : "},\n";
        }
        out += (i==11)? "}\n" : "},\n";
    }
    out += "};";
    cout << out;
    return 0;
}

string toString(int k)
{
    stringstream ss;  
    ss<<k;  
    string s;  
    ss>>s;
    return s;
}