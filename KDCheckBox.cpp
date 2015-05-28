#include "KDCheckBox.hpp"

KDCheckBox::KDCheckBox(int fx,int fy,int sx,int sy,bool kezdo_ertek) : Widgets(fx,fy,sx,sy)
{
    pipalva = kezdo_ertek;
    focusalhato = true;

    pipalva_.open(meret_x-6,meret_y-6);
    pipalva_.transparent(true);
    for(int i = 0;i<(meret_y-6);i++)
    {
        for(int j = 0;j<(meret_x-6)/2;j++)
        {
            pipalva_ << genv::color(0,180,255) << genv::move_to(2*j+(i%2),i) << genv::dot;
        }
    }
    pipalva_ << genv::color(0,0,0) << genv::move_to(meret_x/4,meret_y/2) << genv::line(meret_x/4,meret_y/4);
    pipalva_ << genv::color(0,0,0) << genv::line(meret_x/4,-3*meret_y/4);

    Widgets::focus_rajz();

    ujra_rajzol();
}
void KDCheckBox::rajzol()
{
    genv::gout << genv::stamp(kep,x,y);
    if(pipalva) genv::gout << genv::stamp(pipalva_,x+3,y+3);

    if(focusban) genv::gout << genv::stamp(focus_poty,x-2,y-2);
}
void KDCheckBox::kezel(genv::event ev)
{
    if(Widgets::get_egeralatt(ev))
    {
        focusban = true;
        pipalva = !pipalva;
    }
}
void KDCheckBox::ujra_rajzol()
{
    kep.open(meret_x,meret_y);
    kep.transparent(true);

    kep << genv::move_to(0,0) << background_col << genv::box(meret_x,meret_y);
    kep << foreground_col << genv::move_to(0,0) << genv::line(0,meret_y);
    kep << genv::move_to(0,0) << genv::line(meret_x,0);
    kep << genv::move_to(meret_x-1,meret_y-1) << genv::line(0,-meret_y);
    kep << genv::move_to(meret_x-1,meret_y-1) << genv::line(-meret_x,0);
}
