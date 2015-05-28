#ifndef KDNUMERICCONTROLL_HPP_INCLUDED
#define KDNUMERICCONTROLL_HPP_INCLUDED

#include "KDButton.hpp"
#include <sstream>
#include <vector>

class KDNumericControll : public Widgets
{
protected:
    float ertek;
    float dif;

    std::vector<KDButton*> gombok;
    int minimum;
    int maximum;

public:
    KDNumericControll(int fx,int fy,int x_meret,int kezdo_ertek,int min_,int max_,float lepeskoz);

    void rajzol();
    void ujra_rajzol();
    void kezel(genv::event ev);

    int get_ertek() {return ertek;}
    void set_button_col(genv::color temp) { gombok[0]->set_back_col(temp); gombok[1]->set_back_col(temp); }
};

#endif // KDNUMERICCONTROLL_HPP_INCLUDED
