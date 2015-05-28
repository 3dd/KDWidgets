#include "Widgets.hpp"

bool Widgets::get_egeralatt(genv::event ev)
{
    if(ev.button == genv::btn_left && x <= ev.pos_x && ev.pos_x <= x+meret_x && y <= ev.pos_y && ev.pos_y <= y+meret_y) return true;
    else return false;
}

Widgets::Widgets(int fx,int fy,int merx,int mery)
    : x(fx), y(fy), meret_x(merx), meret_y(mery)
{
    focusalhato = false;
    focusban = false;
}
void Widgets::focus_rajz()
{
    focus_poty.open(meret_x+4,meret_y+4); focus_poty.transparent(true);

    for(int j = 0; j<meret_x+4 || j<meret_y+4; j++)
    {
        if(j<meret_x+4 && j%7-2>0) focus_poty << genv::move_to(j,0) << genv::dot << genv::move_to(j,meret_y+3) << genv::dot;
        if(j<meret_y+4 && j%7-2>0) focus_poty << genv::move_to(0,j) << genv::dot << genv::move_to(meret_x+3,j) << genv::dot;
    }
}
