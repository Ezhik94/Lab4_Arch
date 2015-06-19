//
// Created by m3sc4 on 02.06.15.
//

#ifndef DIJKSTRA_ALGO_H
#define DIJKSTRA_ALGO_H

#include <vector>
#include <stdio.h>
#include <limits.h>


using namespace std;

class Morze
{
    public:
        vector<string> InputData;

        Morze(vector<string> InputData)
        {
            this->InputData = InputData;
        }

        vector<string> Tranform()
        {
            vector<string> converted {};

            string morseCode[] = {".-", "-...", "-.-.", "-..", ".", "..-.",
                                  "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---",
                                  ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-",
                                  "-.--", "--.."};
            char ch;
            string morseWord = "";

            for(unsigned int i=0; i < InputData.size(); i++)
            {
                if(isalpha(InputData[i][0]))
                {
                    ch = InputData[i][0];
                    ch = toupper(ch);
                    string tmp = "";
                    tmp += morseCode[ch - 'A'];
                    converted.push_back(tmp);
                };
            }
            for(int i = 0; i < converted.size(); i++)
                cout << converted[i];
            cout << endl;
            return converted;
        }

};

#endif
