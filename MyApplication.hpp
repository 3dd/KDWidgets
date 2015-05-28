#ifndef MYAPPLICATION_HPP_INCLUDED
#define MYAPPLICATION_HPP_INCLUDED

#include "KDWidgets.hpp"
using namespace genv;

extern const int SX;
extern const int SY;

class MyApplication
{
    void tab_focusalas(std::vector<Widgets*> widgets);
    void widget_kezel();

protected:
    std::vector<Widgets*> widgets;
    event ev;

    void create(Widgets * temp);
    virtual void programkod() = 0;

public:
    MyApplication(std::string nev);
    void futtatas();
};

#endif // MYAPPLICATION_HPP_INCLUDED
