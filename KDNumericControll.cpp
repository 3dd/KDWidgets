#include "KDNumericControll.hpp"

struct FelButton : public KDButton
{
    float * ertek;
    int * max_;
    float * dif;
public:
    FelButton(float * dif_,float * ertek_,int * max__,int fx,int fy,int x_meret,int y_meret,int betu_merete,std::string felir)
        : KDButton(fx,fy,x_meret,y_meret,betu_merete,felir)
    {
        ertek = ertek_;
        max_ = max__;
        dif = dif_;
    }
    void nyomva(genv::event ev)
    {
        if(lenyomva && ev.button == genv::btn_left && *max_ > *ertek)
        {
            *ertek += *dif;
        }
    }
};
struct LeButton : public KDButton
{
    float * ertek;
    int * min_;
    float * dif;
public:
    LeButton(float * dif_,float * ertek_,int * min__,int fx,int fy,int x_meret,int y_meret,int betu_merete,std::string felir)
        : KDButton(fx,fy,x_meret,y_meret,betu_merete,felir)
    {
        ertek = ertek_;
        min_ = min__;
        dif = dif_;
    }
    void nyomva(genv::event ev)
    {
        if(lenyomva && ev.button == genv::btn_left && *min_ < *ertek)
        {
            *ertek -= *dif;
        }
    }
};

KDNumericControll::KDNumericControll(int fx,int fy,int x_meret,int kezdo_ertek,int min_,int max_,float lepeskoz)
    : Widgets(fx,fy,x_meret,23)
{
    ertek = kezdo_ertek;
    minimum = min_;
    maximum = max_;
    dif = lepeskoz;
    focusalhato = true;

    gombok.push_back(new FelButton(&dif,&ertek,&maximum,x+4*meret_x/5,y,meret_x/5,23,18,">"));
    gombok.push_back(new LeButton(&dif,&ertek,&minimum,x+3*meret_x/5,y,meret_x/5,23,18,"<"));

    gombok[0]->set_back_col(genv::color(0,180,255));
    gombok[0]->set_fore_col(genv::color(50,50,50));

    gombok[1]->set_back_col(genv::color(0,180,255));
    gombok[1]->set_fore_col(genv::color(50,50,50));

    Widgets::focus_rajz();

    ujra_rajzol();
}
void KDNumericControll::rajzol()
{
    genv::gout << genv::stamp(kep,x,y);

    gombok[0]->rajzol();
    gombok[1]->rajzol();

    if(focusban) genv::gout << genv::stamp(focus_poty,x-2,y-2);
}
void KDNumericControll::kezel(genv::event ev)
{
    if(Widgets::get_egeralatt(ev))
    {
        focusban = true;
    }
    if(focusban)
    {
        for(KDButton * temp:gombok)
        {
            temp->kezel(ev);
            temp->set_focusban(false);
        }

        gombok[0]->nyomva(ev);
        gombok[1]->nyomva(ev);

        if(ev.keycode == genv::key_pgup && ertek < maximum) ertek++;
        if(ev.keycode == genv::key_pgdn && ertek > minimum) ertek--;

        ujra_rajzol();
    }
}
void KDNumericControll::ujra_rajzol()
{
    kep.open(meret_x,meret_y);
    kep.transparent(true);
    kep.load_font("LiberationSans-Regular.ttf",int(meret_y*0.9),true);

    kep << background_col << genv::move_to(0,0) << genv::box(meret_x,meret_y);
    kep << foreground_col;
    kep << genv::move_to(0,0) << genv::line(0,meret_y);
    kep << genv::move_to(0,0) << genv::line(meret_x,0);
    kep << genv::move_to(meret_x-1,meret_y-1) << genv::line(0,-meret_y);
    kep << genv::move_to(meret_x-1,meret_y-1) << genv::line(-meret_x,0);

    std::stringstream ss;
    ss << ertek;
    kep << foreground_col << genv::move_to(0,0) << genv::text(" " + ss.str());
}
