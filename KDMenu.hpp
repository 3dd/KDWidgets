#ifndef KDMENU_HPP_INCLUDED
#define KDMENU_HPP_INCLUDED

#include <vector>

#include "KDStaticText.hpp"

class KDMenu : public Widgets
{
protected:
    int ertek;
    std::vector<KDStaticText*> menupontok;

    void mozgat(int gorget);

public:
    KDMenu(int fx,int fy,int x_meret,int y_meret,std::vector<std::string> menu_pontok);

    void rajzol();
    void ujra_rajzol();
    void kezel(genv::event ev);

    int get_ertek() {return ertek;}
    std::string get_ertek_str() {if(ertek != -1) return menupontok[ertek]->get_string();}

    void add_element(std::string temp);
    void del_element();
    void clc_element() { menupontok.clear(); }
};

#endif // KDMENU_HPP_INCLUDED
