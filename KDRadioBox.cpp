#include "KDRadioBox.hpp"

KDRadioBox::KDRadioBox(int fx,int fy,int x_meret,std::vector<std::string> menu_pontok)
    : Widgets(fx,fy,x_meret,0)
{
    focusalhato = true;
    ertek = -1;

    meret_y = menu_pontok.size()*22+3;

    for(int i = 0; i< menu_pontok.size(); i++)
    {
        radiobutton.push_back(new KDRadioSwitch(x+4,y+i*22+4,16,false));
        radiotext.push_back(new KDStaticText(x,y+i*22,20,x_meret,((menu_pontok.size()-1==i)?22+3:22),"    " + menu_pontok[i],false));
        radiotext[i]->set_back_col( genv::color(200,200,200) );
    }

    Widgets::focus_rajz();

    ujra_rajzol();
}
void KDRadioBox::rajzol()
{
    for(KDStaticText * temp:radiotext) temp->rajzol();
    for(int i = 0;i<radiobutton.size();i++) {if(i==ertek)radiobutton[i]->set_pipa(true); radiobutton[i]->rajzol();}

    genv::gout << genv::stamp(kep,x,y);

    if(focusban) genv::gout << genv::stamp(focus_poty,x-2,y-2);
}
void KDRadioBox::ujra_rajzol()
{
    kep.open(meret_x,meret_y);
    kep.transparent(true);

    kep << foreground_col << genv::move_to(0,0) << genv::line(0,meret_y);
    kep << genv::move_to(0,0) << genv::line(meret_x,0);
    kep << genv::move_to(meret_x-1,meret_y-1) << genv::line(0,-meret_y);
    kep << genv::move_to(meret_x-1,meret_y-1) << genv::line(-meret_x,0);
}
void KDRadioBox::kezel(genv::event ev)
{
    if(Widgets::get_egeralatt(ev))
    {
        focusban = true;
    }
    if(focusban)
    {
        if(ev.button == genv::btn_left)
        {
            for(int i = 0;i<radiobutton.size();i++) radiobutton[i]->set_pipa(false);
            ertek = -1;
        }

        for(int i = 0;i<radiobutton.size();i++)
        {
            radiobutton[i]->kezel(ev);
            if(radiobutton[i]->get_pipa()) ertek = i;

            radiobutton[i]->set_pipa(false);
            radiobutton[i]->set_focusban(false);
        }
        if(ev.keycode == genv::key_up){ ertek = (ertek > 0)?ertek-1:radiobutton.size()-1; }
        if(ev.keycode == genv::key_down || ev.keycode == 32) ertek = (++ertek)%radiobutton.size();
    }
}
