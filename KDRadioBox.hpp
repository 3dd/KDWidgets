#ifndef KDRADIOBOX_HPP_INCLUDED
#define KDRADIOBOX_HPP_INCLUDED

#include <vector>

#include "KDRadioSwitch.hpp"
#include "KDStaticText.hpp"

class KDRadioBox : public Widgets
{
protected:
    int ertek;

    std::vector<KDRadioSwitch*> radiobutton;
    std::vector<KDStaticText*> radiotext;

public:
    KDRadioBox(int fx,int fy,int x_meret,std::vector<std::string> menu_pontok);

    void rajzol();
    void ujra_rajzol();
    void kezel(genv::event ev);

    int get_ertek() {return ertek;}
    std::string get_ertek_str() {if(ertek != -1) return radiotext[ertek]->get_string();}
};

#endif // KDRADIOBOX_HPP_INCLUDED
