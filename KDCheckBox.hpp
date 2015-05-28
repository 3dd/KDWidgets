#ifndef KDCHECKBOX_HPP_INCLUDED
#define KDCHECKBOX_HPP_INCLUDED

#include "Widgets.hpp"

class KDCheckBox : public Widgets
{
protected:
    bool pipalva;
    genv::canvas pipalva_;

public:
    KDCheckBox(int fx,int fy,int sx,int sy,bool kezdo_ertek);

    void rajzol();
    void ujra_rajzol();
    void kezel(genv::event ev);

    void set_pipa(bool temp) {pipalva = temp;}
    bool get_pipa() {return pipalva;}
};

#endif // KDCHECKBOX_HPP_INCLUDED
