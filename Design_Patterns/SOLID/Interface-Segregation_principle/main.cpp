#include <iostream>

struct Document Doc;
/*
//This desing breaks the Interface Segregation principle
// because we need to implement more functions than what is needed
struct IMachine{
    virtual void print(Document &doc) = 0;
    virtual void scan(Document &doc) = 0;
    virtual void fax(Document &doc) = 0;
};

struct MFP : IMachine{
    void print(Document &doc){
        //Ok
    }

    void scan(Document &doc){
        // no needed
    }

    void fax(Document &doc){
        // no needed
    }
};

struct Scanner:IMachine{
    void print(Document &doc){
        //No needed
    }

    void scan(Document &doc){
        // Ok
    }

    void fax(Document &doc){
        // no needed
    }
};

*/


struct IPrinter{
    virtual void print(Document &doc) = 0;
};

struct MachineMFP:IPrinter{
    void print(Document &doc){
        //Ok
    }
};

struct IScanner{
    virtual void scan(Document &doc) = 0;
};

struct Scanner:IScanner{
    void scan(Document &doc){
        //ok
    }
};

struct IMachine:IPrinter,IScanner{};

struct Machine:IMachine{
    IPrinter &printer;
    IScanner &scanner;

    Machine(IPrinter &printer,IScanner &scanner):printer(printer),scanner(scanner){

    }

    void print(Document &doc) override{
        printer.print(doc);
    }

    void scan(Document &doc) override{
        scanner.scan(doc);
    }

    
};




int main(){

    return 0;
}