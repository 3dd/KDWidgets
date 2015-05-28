#include "KDStatusBar.hpp"

using namespace std;
#include <iostream>

KDStatusBar::KDStatusBar(int fx,int fy,int meret_x,int max_ertek_,int kezdo_ertek) : Widgets(fx,fy,meret_x,23)
{
    focusalhato = false;
    max_ertek = max_ertek_;
    ertek = kezdo_ertek;

    ujra_rajzol();
}
void KDStatusBar::rajzol()
{
    genv::gout << genv::stamp(kep,x,y);
}
void KDStatusBar::ujra_rajzol()
{
    kep.open(meret_x,meret_y);
    kep.transparent(true);

    kep << genv::move_to(0,0) << background_col << genv::box(meret_x,meret_y);
    kep << genv::color(50,50,50);
    kep << genv::move_to(0,0) << genv::line(0,meret_y);
    kep << genv::move_to(0,0) << genv::line(meret_x,0);
    kep << genv::move_to(meret_x-1,meret_y-1) << genv::line(0,-meret_y);
    kep << genv::move_to(meret_x-1,meret_y-1) << genv::line(-meret_x,0);

    int bar = ertek/float(max_ertek) * (meret_x-2);
    kep << genv::move_to(1,1) << foreground_col << genv::box(bar,meret_y-2);
}
