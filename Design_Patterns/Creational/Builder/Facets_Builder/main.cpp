#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "Person.hpp"
#include "PersonBuilder.hpp"
#include "PersonLiveBuilder.hpp"
#include "PersonJobBuilder.hpp"

using namespace std;

int main(){

  Person person = Person::create().lives().at("Surco").age(31);

  cout<<person<<endl;

  return 0;
}