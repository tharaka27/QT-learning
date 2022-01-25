#include <QCoreApplication>
#include <iostream>
#include <ostream>
#include "logtail.h"


using namespace std;

class myInt{
private:
    int _i;
    int _j;

public:
    myInt(int i, int j):_i(i),_j(j){}

    myInt operator +(myInt& c){
        return myInt(_i + c._i , _j+ c._j);
    }


    ostream& operator<<(ostream& os)
    {
        os << "i: " << _i << " j: " << _j ;
        return os;
    }


    friend ostream& operator<<(ostream& os, const myInt &d);


    void print()
    {
        std::cout << "i: " << _i << " j: " << _j << std::endl;
    }

};

ostream& operator<<(ostream& os, const myInt &d)
{
    os << "Hello world 2 i: " << d._i << " j: " << d._j << std::endl;
    return os;
}

int main(int argc, char *argv[])
{
    /*
    cout << "Hello world" << endl;
    myInt com(4,5);
    myInt com2(4,5);
    myInt com3 = com + com2;
    //com3.operator <<(std::cout);
    std::cout << com3;
    //com3.print();
    */
    //QCoreApplication app(argc, argv);
    //ArgumentList al;

    //LogWindow lw("debug");
    //lw.setWindowTitle("logtail demo");
    //QString filename;
    //if (al.size() > 1) filename = al[1];

    //std::cout << "current path is " << QDir::currentPath().toStdString() << std::endl;
    //QDir::setCurrent("/home");
    //std::cout << "current path is " << QDir::currentPath().toStdString() << std::endl;
    LogTail tail("");
    //lw.show();
    //return app.exec();
    return 0;

}

