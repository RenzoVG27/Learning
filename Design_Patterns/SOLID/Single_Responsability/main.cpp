#include <iostream>
#include <string>
#include <vector>
#include <fstream>

struct Journal{
    private:
    std::string name;
    std::vector<std::string> entries;

    public:

    inline const std::string& getName() {return name;};
    inline const std::vector<std::string>& getEntries(){return entries;};

    Journal(const std::string& name):name(name){}

    void AddEntry(const std::string& entry){
        static int counter{0
        };
        entries.push_back(std::to_string(++counter)+ ". " + entry);
    }

    void Print(){
        std::cout<<"Journal: "<<name<<std::endl;
        for(const std::string& entry:entries){
            std::cout<<entry<<std::endl;
        }
    }

//This is not correct because the responsbility to save shuld be assigned to another class
    void Save(const std::string& filename){
        std::ofstream output ;
        output.open(filename);
        output<<"My Journey : "<<name<<std::endl;
        for(auto &e:entries){
            output<<e<<std::endl;
        }

        output.close();
    }

};

struct Persistance{
    static void Save(Journal & jour, const std::string& filename){
        std::ofstream output ;
        output.open(filename);
        output<<"My Journey : "<<jour.getName()<<std::endl;
        for(auto &e:jour.getEntries()){
            output<<e<<std::endl;
        }

        output.close();
    }
};

int main(){

    Journal myjournal("Renzo Journal");
    myjournal.AddEntry("Went to leave Caye to the kinder");
    myjournal.AddEntry("Went to buy some food to prepare the lunch");
    myjournal.AddEntry("Returned to home to study this course");

    myjournal.Print();

    Persistance::Save(myjournal,"fileJournal.txt");


    return 0;
}