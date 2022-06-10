#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;


struct TAG{
    string value, text;
    vector<TAG> children;
    vector<pair<string,string>> attributes;

   
    friend std::ostream& operator<<(std::ostream& os, const TAG& tag){
      os << "<" << tag.value;

      for (const auto& att : tag.attributes)
        os << " " << att.first << "=\"" << att.second << "\"";

      if (tag.children.size() == 0 && tag.text.length() == 0)
      {
        os << "/>" << std::endl;
      } 
      else
      {
        os << ">" << std::endl;

        if (tag.text.length())
          os << tag.text << std::endl;

        for (const auto& child : tag.children)
          os << child;

        os << "</" << tag.value << ">" << std::endl;
      }

      return os;
    }

    protected:

     TAG (const string& value,const string& text):value(value),text(text){
         cout<<"Constru"<<endl;
    }

    TAG(const string &value, const vector<TAG> &children):value{value},children{children}{
        cout<<"Contru children"<<endl;
    }


};

struct P: TAG{
    P(const string& text):TAG{"p",text}{

    }
    P(initializer_list<TAG> children):TAG{"p",children}{
        cout<<"Constrcutor P: Children size = "<<children.size()<<endl;
    }
};

struct IMG:TAG{

    explicit IMG(const string& url):TAG{"img",""}{
        attributes.emplace_back(make_pair("src",url));
        cout<<"Constrcutor IMG"<<endl;
    }

};




int main(){

    
    cout<<P{
            IMG{"www.pokemon.com"},
            IMG{"www.softeare.com"}
            }<<endl;


    return 0;
}