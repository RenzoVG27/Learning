#include <iostream>
#include <string>
#include <vector>


enum class Color{Red,Green,Blue};
enum class Size{Small,Medium,Large};

template <typename T> struct AndSpecification;

struct Product{
    std::string name;
    Color color;
    Size size;
};

struct FilterOld{
    std::vector <Product*> by_color(std::vector<Product*> items,Color color){
        std::vector<Product*> result;
        for(auto &item:items){
            if(item->color == color)
                result.push_back(item);
        }
        return result;
    }

    std::vector <Product*> by_size(std::vector<Product*> items,Size size){
        std::vector<Product*> result;
        for(auto &item:items){
            if(item->size == size)
                result.push_back(item);
        }
        return result;
    }

    std::vector <Product*> by_size_color(std::vector<Product*> items,Size size,Color color){
        std::vector<Product*> result;
        for(auto &item:items){
            if(item->size == size && item->color == color)
                result.push_back(item);
        }
        return result;
    }

};

template <typename T> struct Specification{

    virtual bool Is_Satisfied(T* product) = 0;

    AndSpecification<T> operator&&(Specification<T> &&spec){
        return AndSpecification<T>(*this,spec);
    }

};

template <typename T> struct AndSpecification :Specification<T>{

    std::vector<Specification<T>*> Specifications;

    AndSpecification(Specification<T> &first,Specification<T> &second){
        Specifications.push_back(&first);
        Specifications.push_back(&second);
    }

    bool Is_Satisfied(T* product){
        for(auto &spec:Specifications){
            if(spec->Is_Satisfied(product)==false)
                return false;
        }
        return true;
    }

    AndSpecification operator&&(Specification<T> &&spec){
        Specifications.push_back(spec);
    }

};


template <typename T> struct Filter{
    virtual std::vector<T*> filter(std::vector<T*> items,Specification<T> &spec) = 0;
};

struct BetterFilter:Filter<Product>{

    std::vector<Product*> filter(std::vector<Product*> items,Specification<Product> &spec){
        
        std::vector<Product *> result;
        for(auto &item:items){
            if(spec.Is_Satisfied(item))
                result.push_back(item);
        }
        return result;
    }
    
};

struct ColorSpecification:Specification<Product>{
    Color color;

    ColorSpecification( Color &&color):color(color){

    }

    bool Is_Satisfied(Product* product){
        return product->color==color;
    }


};

struct SizeSpecification:Specification<Product>{
    Size size;

    SizeSpecification( Size &&size):size(size){

    }

    bool Is_Satisfied(Product* product){
        return product->size==size;
    }


};




int main(){
    Product prod1{"Apple",Color::Green,Size::Medium};
    Product prod2{"Tree",Color::Green,Size::Large};
    Product prod3{"Grape",Color::Blue,Size::Small};

    std::vector<Product*> items{&prod1,&prod2,&prod3};

    FilterOld filter;
    
    for(auto&item : filter.by_color(items,Color::Blue))
        std::cout<<item->name<<" is Blue"<<std::endl;

        for(auto&item : filter.by_size(items,Size::Large))
        std::cout<<item->name<<" is Large"<<std::endl;

    for(auto&item : filter.by_size_color(items,Size::Medium,Color::Green))
        std::cout<<item->name<<" is Large and blue"<<std::endl;


        ColorSpecification green(Color::Green);

        BetterFilter filter2;

        for(auto&item : filter2.filter(items,green))
            std::cout<<item->name<<" is Green -> new filter"<<std::endl;


        auto greenlarge = ColorSpecification(Color::Green) && SizeSpecification(Size::Large);

        for(auto&item : filter2.filter(items,greenlarge))
            std::cout<<item->name<<" is Green and large -> new filter"<<std::endl;




    return 0;
}