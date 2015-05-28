#include "KDMenu.hpp"

using namespace std;
#include <iostream>

void KDMenu::mozgat(int gorget)
{
    for(int i = 0;i<menupontok.size();i++)
    {
        menupontok[i]->set_x_y(menupontok[i]->get_x(),menupontok[i]->get_y()+gorget);
    }
    ujra_rajzol();
}

KDMenu::KDMenu(int fx,int fy,int x_meret,int y_meret,std::vector<std::string> menu_pontok)
    : Widgets(fx,fy,x_meret,y_meret)
{
    focusalhato = true;
    meret_y = int(meret_y/20)*20;
    ertek = -1;

    for(int i = 0;i<menu_pontok.size();i++)
    {
        menupontok.push_back(new KDStaticText(x+8,y+20*i,18,meret_x-10,20,menu_pontok[i],false));
        menupontok[i]->set_back_col( genv::color(200,200,200) );
    }

    Widgets::focus_rajz();

    ujra_rajzol();
}
void KDMenu::rajzol()
{
    for(int i = 0;i<menupontok.size();i++)if(y <= menupontok[i]->get_y() && menupontok[i]->get_y() < y+meret_y )menupontok[i]->rajzol();

    genv::gout << genv::stamp(kep,x,y);

    if(focusban) genv::gout << genv::stamp(focus_poty,x-2,y-2);
}
void KDMenu::ujra_rajzol()
{
    kep.open(meret_x,meret_y);
    kep.transparent(true);

    kep << foreground_col;
    kep << genv::move_to(0,0) << genv::line(0,meret_y);
    kep << genv::move_to(0,0) << genv::line(meret_x,0);
    kep << genv::move_to(meret_x-1,meret_y-1) << genv::line(0,-meret_y);
    kep << genv::move_to(meret_x-1,meret_y-1) << genv::line(-meret_x,0);

    for(int i = 0;i<menupontok.size();i++)
    {
        if(0 < i && i < meret_y/20) kep << genv::color(240,240,240) << genv::move_to(1,i*20) << genv::line(meret_x-2,0);
        if(y <= menupontok[i]->get_y() && menupontok[i]->get_y() < y+meret_y )
        {
            if(i == ertek) menupontok[i]->set_back_col( genv::color(0,180,255) );
        }
    }

    if(menupontok.size() != 0)
    {
        float bar = ((meret_y/20)/float(menupontok.size())*meret_y);
        kep << foreground_col << genv::move_to(meret_x-1,((meret_y/20)/float(menupontok.size())*(y-menupontok[0]->get_y())))
            << genv::box(-3,bar);
    }
}
void KDMenu::kezel(genv::event ev)
{
    if(x <= ev.pos_x && ev.pos_x <= x+meret_x && y <= ev.pos_y && ev.pos_y <= y+meret_y)
    {
        if(ev.button == genv::btn_wheelup && !menupontok.empty() && menupontok[0]->get_y() < y) mozgat(20);
        if(ev.button == genv::btn_wheeldown && !menupontok.empty() && menupontok[menupontok.size()-1]->get_y() >= y+meret_y) mozgat(-20);
    }

    if(Widgets::get_egeralatt(ev))
    {
        focusban = true;
    }
    if(focusban)
    {
        if(ev.button == genv::btn_left)
        {
            if(ertek >= 0) menupontok[ertek]->set_back_col( genv::color(200,200,200) );
            for(int i = 0;i<menupontok.size();i++)if(menupontok[i]->get_egeralatt(ev)) { ertek = i; ujra_rajzol(); }
        }

        if(ev.keycode == genv::key_pgup && !menupontok.empty() && menupontok[0]->get_y() < y) mozgat(20);
        if(ev.keycode == genv::key_pgdn && !menupontok.empty() && menupontok[menupontok.size()-1]->get_y() >= y+meret_y) mozgat(-20);
        if(ev.keycode == genv::key_up && ertek > 0)
        {
            if(menupontok[ertek]->get_y() <= y) mozgat(20);
            ertek--;
            ujra_rajzol();
        }
        if(ev.keycode == genv::key_down && ertek < menupontok.size()-1)
        {
            ertek++;
            if(menupontok[ertek]->get_y() >= y+meret_y) mozgat(-20);
            ujra_rajzol();
        }
    }
}
void KDMenu::add_element(std::string temp_)
{
    if(temp_!="" && ertek != -1 || ertek < menupontok.size()-1)
    {
        menupontok.push_back(new KDStaticText(x+8,menupontok[menupontok.size()-1]->get_y() + 20,18,meret_y-10,20,menupontok[menupontok.size()-1]->get_string(),false));
        for(int i = menupontok.size()-2;menupontok.size() >= 2 && i>=ertek;i--)
        {
            menupontok[i]->set_string(menupontok[i-1]->get_string());
        }
        menupontok[ertek]->set_string(temp_);
    }
    else if(temp_!="")
    {
        int dy = y;
        if(menupontok.size()) dy = menupontok[menupontok.size()-1]->get_y() + 20;
        menupontok.push_back(new KDStaticText(x+1,dy,18,meret_x-2,20,temp_,false));
    }

    menupontok[menupontok.size()-1]->set_back_col( genv::color(200,200,200) );

    ujra_rajzol();
}
void KDMenu::del_element()
{
    if(menupontok.size())
    {
        if(ertek != -1 || ertek < menupontok.size()-1)
        {
            for(int i = ertek; i < menupontok.size()-1; i++)
            {
                menupontok[i]->set_string(menupontok[i+1]->get_string());
            }
            menupontok.pop_back();
        }
        else
        {
            menupontok.pop_back();
        }
        if(ertek > 0)ertek--;
        if(menupontok.size() == 0) ertek = -1;
        if(menupontok[0]->get_y() < y) mozgat(20);
        ujra_rajzol();
    }
}
