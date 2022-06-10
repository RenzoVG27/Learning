#pragma once

#include <string>
#include <ostream>

#include "field.hpp"


class CodeBuilder
{
    string className;
    vector<field> fields;
public:
  CodeBuilder(const string& class_name):className(class_name)
  {

      // todo
  }

  CodeBuilder& add_field(const string& name, const string& type)
  {
      fields.push_back(field{name,type});
      return *this;
  }

  friend ostream& operator<<(ostream& os, const CodeBuilder& obj)
  {
      os<<"class "<<obj.className<<endl<<"{"<<endl;
      
      for(auto &f:obj.fields){
          os<<"  "<<f<<endl;
      }
      os<<"}"<<endl;

      return os;

    // todo
  }
};