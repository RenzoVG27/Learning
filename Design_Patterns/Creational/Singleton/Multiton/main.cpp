#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <memory>

using namespace std;

enum class Importance{
    PRIMARY,
    SECONDARY,
    TERTIARY
};

template <typename T, typename Key = string>
class Multiton {

    static map<Key,shared_ptr<T>> instances;
    Multiton() = default;
    virtual ~Multiton() = default;

    public:

    static shared_ptr<T> get(Key key){
        if(const auto it = instances.find(key);
            it != instances.end()){
                return it->second;
            }

        instances[key] = make_shared<T>();
        return instances[key];
    }
};

template <typename T, typename Key>
map<Key,shared_ptr<T>> Multiton<T,Key>::instances;


class Printer
{
public:
  Printer()
  {
    ++Printer::totalInstanceCount;
    cout << "A total of " <<
      Printer::totalInstanceCount <<
      " instances created so far\n";
  }
private:
  static int totalInstanceCount;
};
int Printer::totalInstanceCount = 0;


int main(){
    typedef Multiton<Printer,Importance> mt;

    auto main = mt::get(Importance::PRIMARY);
    auto aux1 = mt::get(Importance::SECONDARY);
    auto aux2 = mt::get(Importance::SECONDARY);
    auto aux3 = mt::get(Importance::SECONDARY);

    return 0;
}