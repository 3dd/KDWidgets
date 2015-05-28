#ifndef KDRADIOSWITCH_HPP_INCLUDED
#define KDRADIOSWITCH_HPP_INCLUDED

#include "Widgets.hpp"

class KDRadioSwitch : public Widgets
{
protected:
    bool pipalva;
    genv::canvas pipalva_;
    genv::canvas hatter;

public:
    KDRadioSwitch(int fx,int fy,int atmero,bool kezdo_ertek);

    void rajzol();
    void ujra_rajzol() {};
    void kezel(genv::event ev);

    void set_pipa(bool temp) {pipalva = temp;}
    bool get_pipa() {return pipalva;}
};

#endif // KDRADIOSWITCH_HPP_INCLUDED
