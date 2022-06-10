#include "PersonBuilder.hpp"
#include "PersonJobBuilder.hpp"
#include "PersonLiveBuilder.hpp"
#include "Person.hpp"

PersonJobBuilder PersonBuilderBase::work() const{
    return PersonJobBuilder(per);
}

PersonLiveBuilder PersonBuilderBase::lives() const{
    return PersonLiveBuilder(per);
}