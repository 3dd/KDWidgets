#ifndef KDSLIDER_HPP_INCLUDED
#define KDSLIDER_HPP_INCLUDED

#include "KDButton.hpp"

struct SliderButton : public KDButton
{
    int mettol;
    int meddig;

public:
    SliderButton(int mettol_,int meddig_,int fy,int y_meret)
        : KDButton(mettol_,fy,16,y_meret,1,"")
    {
        mettol = mettol_;
        meddig = meddig_;
    }
    void nyomva(genv::event ev)
    {
        if(lenyomva)
        {
            if(mettol < ev.pos_x-8 && ev.pos_x-8 < meddig) x = ev.pos_x-8;

            if(meddig < ev.pos_x-8) x = meddig;
            if(ev.pos_x != 0 && mettol > ev.pos_x-8) x = mettol;
        }
    }
};

class KDSlider : public Widgets
{
protected:
    int max_ertek;
    int ertek;

    SliderButton * slider;

public:
    KDSlider(int fx,int fy,int meret_x_,int max_ertek_);

    void rajzol();
    void ujra_rajzol();
    void kezel(genv::event ev);

    int get_ertek() {return ertek;}
    void set_ertek(int ertek_t);
};

#endif // KDSLIDER_HPP_INCLUDED
