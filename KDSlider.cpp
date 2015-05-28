#include "KDSlider.hpp"

void KDSlider::set_ertek(int ertek_t)
{
    if(0 <= ertek_t && ertek_t <= max_ertek)
    {
        int tolas = meret_x/max_ertek;
        if(ertek_t != max_ertek) slider->set_x_y(x+tolas*ertek_t,y);
        else slider->set_x_y(x+meret_x-16,y);
    }
}
KDSlider::KDSlider(int fx,int fy,int meret_x_,int max_ertek_)
    : Widgets(fx,fy,meret_x_,25)
{
    focusalhato = true;
    max_ertek = max_ertek_;
    ertek = 0;
    slider = new SliderButton(fx,fx+meret_x_-16,fy,25);

    ujra_rajzol();

    Widgets::focus_rajz();
}
void KDSlider::kezel(genv::event ev)
{
    if(Widgets::get_egeralatt(ev))
    {
        focusban = true;
    }
    if(focusban)
    {
        slider->kezel(ev);
        slider->set_focusban(false);

        slider->nyomva(ev);
        ertek = (slider->get_x()-x)/float(meret_x-16) * max_ertek;
    }
}
void KDSlider::rajzol()
{
    genv::gout << genv::stamp(kep,x,y+5);

    slider->rajzol();

    if(focusban) genv::gout << genv::stamp(focus_poty,x-2,y-2);

}
void KDSlider::ujra_rajzol()
{
    kep.open(meret_x,10); kep.transparent(true);
    kep << genv::move_to(0,0) << genv::box(meret_x,10);
    kep << genv::color(50,50,50);
    kep << genv::move_to(0,0) << genv::line(0,10);
    kep << genv::move_to(0,0) << genv::line(meret_x,0);
    kep << genv::move_to(meret_x-1,9) << genv::line(0,-10);
    kep << genv::move_to(meret_x-1,9) << genv::line(-meret_x,0);

    int tolas = meret_x/max_ertek;
    for(int i = 0;i<max_ertek && tolas >= 2;i++)
    {
        kep << genv::move_to(tolas*i,4) << genv::box(1,4);
    }
}
