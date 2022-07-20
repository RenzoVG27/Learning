#include <iostream>
#include <stdio.h>
#include <map>
#include <unordered_map>

using namespace std;

class CharsCounter
{
    public:
    CharsCounter(){
    }

    void SetString(string input)
    {
        this->input = input;
    }

    void Calculate (){
        for (int i=0;i<input.length();i++){
            auto it = chars.find(input.at(i));
            if( it != chars.end())
                it->second++;
            else
                chars.insert(make_pair(input[i],1));
        }
    }

    void PrintResults(){
        cout<<"_______________"<<endl;
        for(map <char,int>::iterator it = chars.begin();it!=chars.end();it++){
            cout<<"["<<it->first<<"] = "<<it->second<<endl;
        }
    }

    private:
    string input;
    map <char,int> chars;

};

void func( int rval[]){
    cout<<"val : "<<rval[2]<<endl;
}

int main(int argc, char const *argv[])
{
   string input = "Hello World";

   CharsCounter tool;
   tool.SetString(input);
   tool.Calculate();
   tool.PrintResults();


    return 0;
}
