#include <iostream>
#include <string>
#include <fstream>
#include <map>

using namespace std;


class DatabaseInterface{ // this is inserted to make this code testable
    public:
    virtual int getPopulation(string city) = 0;
};

class DummyDatabase : public DatabaseInterface{//Dummy database to use fake values
    map <string, int> capitals;
    
    public:
    DummyDatabase(){
        capitals["alpha"] = 1;
        capitals["beta"] = 2;
        capitals["etha"] = 3;
        capitals["gamma"] = 4;
    }

    int getPopulation(string city){
        return capitals[city];
    }


};

class Database : public DatabaseInterface{//concrete impleemntatio of database
    Database(){
        ifstream ifs ("Capitals.txt");
        
        string s, s2;

        while(getline(ifs,s)){
            getline(ifs,s2);
            capitals[s] = stoi(s2);
        }
    }
    map <string, int> capitals;

    public:

    static Database & get(){
        static Database db;
        return db;
    }

    int getPopulation(string city){
        return capitals[city];
    }
};


int main(){
    string city{"Buenos Aires"};
    cout<<"Population of "<<city<<" is : "<<Database::get().getPopulation(city)<<endl;


/******************When the const pointer variable points to the value:*/
    int x = 10;
    int y = 30;

    cout<< &x<<", x1 = "<<x<<endl;

    int* const m = &x;

    *m= 20;

    cout<< m <<", m = "<<*m<<endl;
    cout<< &x<<", x2 = "<<x<<endl;

    //m = &y;//CTE because the address of m cant be changed


/******************When the pointer variable points to a const value:*/
    const int* m2 = &y;

    cout<< m2 <<", m2 = "<<*m2<<endl;

    y = 50;

    cout<< m2 <<", m2 = "<<*m2<<endl;

    //*m2 = 100; //CTE because the value of m2 cant be changed directly


/*******************When const pointer pointing to a const variable*/

const int* const i = &x;

// *i=10; //CTE Once Ptr(*i) value is assigned, later it can't be modified(Error)
//i = &y; // CTE the address of i can´t be modified
cout<< i <<", i = "<<*i<<endl;

    return 0;
}