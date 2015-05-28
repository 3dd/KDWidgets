#ifndef KDBUTTON_HPP_INCLUDED
#define KDBUTTON_HPP_INCLUDED

#include "Widgets.hpp"

class KDButton : public Widgets
{
protected:
    std::string felirat;
    int betumeret;
    bool lenyomva;

    genv::canvas kep_lenyomva;

public:
    KDButton(int fx,int fy,int x_meret,int y_meret,int betu_merete,std::string felir);

    void rajzol();
    void ujra_rajzol();
    void kezel(genv::event ev);

    bool get_lenyomva() {return lenyomva;}
    virtual void nyomva(genv::event ev) = 0;
};

#endif // KDBUTTON_HPP_INCLUDED
