#include "KDRadioSwitch.hpp"
#include <cmath>

KDRadioSwitch::KDRadioSwitch(int fx,int fy,int atmero,bool kezdo_ertek) : Widgets(fx,fy,atmero,atmero)
{
    pipalva = kezdo_ertek;
    focusalhato = true;

    pipalva_.open(meret_x-4,meret_y-4);
    pipalva_.transparent(true);
    for(int i = 0;i<meret_y-4;i++)
    {
        for(int j = 0;j<meret_x-4;j++)
        {
            float tav = sqrt(pow(meret_x/2-j-2,2) + pow(meret_y/2-i-2,2));
            if(tav <= meret_x/2-4) pipalva_ << genv::color(0,180,255) << genv::move_to(j,i) << genv::dot;
        }
    }

    hatter.open(meret_x,meret_y);
    hatter.transparent(true);
    for(int i = 0;i<meret_y;i++)
    {
        for(int j = 0;j<meret_x;j++)
        {
            float tav = sqrt(pow(meret_x/2-j,2) + pow(meret_y/2-i,2));
            if(tav <= meret_x/2) hatter << foreground_col << genv::move_to(j,i) << genv::dot;
            if(tav <= meret_x/2-1.1) hatter << background_col << genv::move_to(j,i) << genv::dot;
        }
    }

    Widgets::focus_rajz();

}
void KDRadioSwitch::rajzol()
{
    genv::gout << genv::stamp(hatter,x,y);
    if(pipalva) genv::gout << genv::stamp(pipalva_,x+2,y+2);

    if(focusban) genv::gout << genv::stamp(focus_poty,x-2,y-2);
}
void KDRadioSwitch::kezel(genv::event ev)
{
    if(Widgets::get_egeralatt(ev))
    {
        focusban = true;
        pipalva = !pipalva;
    }
    if(focusban)
    {
        if(ev.keycode == 32) pipalva = !pipalva;
    }
}
