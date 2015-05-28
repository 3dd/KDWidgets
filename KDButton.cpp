#include "KDButton.hpp"

KDButton::KDButton(int fx,int fy,int x_meret,int y_meret,int betu_merete,std::string felir) : Widgets(fx,fy,x_meret,y_meret)
{
    felirat = felir;
    betumeret = betu_merete;
    lenyomva = false;
    focusalhato = true;

    Widgets::focus_rajz();

    ujra_rajzol();
}
void KDButton::rajzol()
{
    if(!lenyomva) genv::gout << genv::stamp(kep,x,y);
    if(lenyomva) genv::gout << genv::stamp(kep_lenyomva,x,y);

    if(focusban) genv::gout << genv::stamp(focus_poty,x-2,y-2);
}
void KDButton::kezel(genv::event ev)
{
    if( get_egeralatt(ev) )
    {
        lenyomva = true;
    }
    if(ev.button == -genv::btn_left)
    {
        lenyomva = false;
    }
}
void KDButton::ujra_rajzol()
{
    kep.open(meret_x,meret_y);
    kep.transparent(true);
    kep.load_font("LiberationSans-Regular.ttf",betumeret,true);

    kep_lenyomva.open(meret_x,meret_y);
    kep_lenyomva.transparent(true);
    kep_lenyomva.load_font("LiberationSans-Regular.ttf",betumeret,true);

    if(kep.twidth(felirat) > meret_x) meret_x = kep.twidth(felirat) + kep.twidth(felirat)/2;

    kep << background_col;
    kep_lenyomva << genv::color(150,150,150);

    kep << genv::move_to(0,0) << genv::box(meret_x,meret_y);
    kep_lenyomva << genv::move_to(0,0) << genv::box(meret_x,meret_y);

    kep << foreground_col;
    kep << genv::move_to(0,0) << genv::line(0,meret_y);
    kep << genv::move_to(0,0) << genv::line(meret_x,0);
    kep << genv::move_to(meret_x-1,meret_y-1) << genv::line(0,-meret_y);
    kep << genv::move_to(meret_x-1,meret_y-1) << genv::line(-meret_x,0);

    kep_lenyomva << foreground_col;
    kep_lenyomva << genv::move_to(0,0) << genv::line(0,meret_y);
    kep_lenyomva << genv::move_to(0,0) << genv::line(meret_x,0);
    kep_lenyomva << genv::move_to(meret_x-1,meret_y-1) << genv::line(0,-meret_y);
    kep_lenyomva << genv::move_to(meret_x-1,meret_y-1) << genv::line(-meret_x,0);

    kep.load_font("LiberationSans-Regular.ttf",betumeret,true);
    kep_lenyomva.load_font("LiberationSans-Regular.ttf",betumeret,true);

    float tx = meret_x/2-kep.twidth(felirat)/2;
    float ty = meret_y/2-(kep.cascent() + kep.cdescent())/2;

    if(tx < 0) meret_x = kep.twidth(felirat)+kep.twidth(felirat)/2;
    if(ty < 0) meret_y = kep.cascent() + kep.cdescent();

    if(felirat != "") kep << genv::move_to(tx,ty) << genv::text(felirat);
    if(felirat != "") kep_lenyomva << genv::move_to(tx,ty) << genv::text(felirat);
}
