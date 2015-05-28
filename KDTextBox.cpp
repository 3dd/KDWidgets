#include "KDTextBox.hpp"

#include <iostream>
using namespace std;

KDTextBox::KDTextBox(int fx,int fy,int x_meret,std::string felir) : Widgets(fx,fy,x_meret,23)
{
    if(felir != "") felirat = " " + felir + ": ";
    else felirat = " ";
    focusalhato = true;

    villogas = 0;
    kurzor_pos = 0;
    hossz = 0;

    Widgets::focus_rajz();

    ujra_rajzol();
}
void KDTextBox::rajzol()
{
    genv::gout << genv::stamp(kep,x,y);

    if(focusban) genv::gout << genv::stamp(focus_poty,x-2,y-2);
}
void KDTextBox::ujra_rajzol()
{
    kep.open(meret_x,meret_y);
    kep.transparent(true);

    kep << background_col << genv::move_to(0,0) << genv::box(meret_x,meret_y);
    kep << foreground_col;
    kep << genv::move_to(0,0) << genv::line(0,meret_y);
    kep << genv::move_to(0,0) << genv::line(meret_x,0);
    kep << genv::move_to(meret_x-1,meret_y-1) << genv::line(0,-meret_y);
    kep << genv::move_to(meret_x-1,meret_y-1) << genv::line(-meret_x,0);

    kep.load_font("LiberationSans-Regular.ttf",20,true);
    if(felirat != "")
    {
        hossz = kep.twidth(" ") + kep.twidth(felirat);
        kep << genv::color(255,255,255) << genv::move_to(1,1) << genv::box(hossz-2,meret_y-2);
        kep << genv::color(50,50,50) << genv::move_to(kep.twidth(" "),0) << genv::text(felirat);
    }

    int kurzor_hossz = hossz;
    for(int i = 0; i<abc.size(); i++)
    {
        std::string temp = "";
        temp += abc[i];
        if(hossz > 0) kep << genv::color(50,50,50) << genv::move_to(hossz,0) << genv::text(temp);
        hossz += kep.twidth(temp);

        if(kurzor_pos-1 == i) kurzor_hossz = hossz;
    }

    std::string temp = "";
    if(kurzor_pos == abc.size()) temp += "  ";
    else if(abc.size() != 0) temp += abc[kurzor_pos];
    if(focusban && villogas < 12) kep << genv::color(0,180,255) << genv::move_to(kurzor_hossz,meret_y-6) << genv::box(kep.twidth(temp),2);
}
void KDTextBox::kezel(genv::event ev)
{
    if(Widgets::get_egeralatt(ev))
    {
        focusban = true;
    }
    if(focusban)
    {
        if(hossz+15 < meret_x && 32 <= ev.keycode && ev.keycode <= 255)
        {
            if(abc.size() == kurzor_pos) abc.push_back(ev.keycode);
            else abc.insert(abc.begin()+kurzor_pos,ev.keycode);
            kurzor_pos++;
        }
        if(ev.keycode == 8 && abc.size() > 0)
        {
            abc.erase(abc.begin()+kurzor_pos-1);
            if(kurzor_pos > 0)kurzor_pos--;
        }
        if(ev.keycode == 65541 && abc.size() != kurzor_pos) abc.erase(abc.begin()+kurzor_pos);

        if(ev.keycode == genv::key_left && kurzor_pos > 0) kurzor_pos--;
        if(ev.keycode == genv::key_right && kurzor_pos < abc.size()) kurzor_pos++;

        if(ev.type == genv::ev_timer) villogas = (++villogas)%24;

        ujra_rajzol();
    }
}
