#ifndef KDSTATUSBAR_HPP_INCLUDED
#define KDSTATUSBAR_HPP_INCLUDED

#include "Widgets.hpp"

class KDStatusBar : public Widgets
{
protected:
    int max_ertek;
    float ertek;

public:
    KDStatusBar(int fx,int fy,int meret_x,int max_ertek_,int kezdo_ertek);

    void rajzol();
    void kezel(genv::event ev) { }

    void set_ertek(int ertek_) { ertek = ertek_; ujra_rajzol(); }
    int get_ertek() {return ertek;}

    void ujra_rajzol();
};

#endif // KDSTATUSBAR_HPP_INCLUDED
