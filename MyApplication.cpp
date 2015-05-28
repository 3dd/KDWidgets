#include "MyApplication.hpp"

MyApplication::MyApplication(std::string nev)
{
    gout.set_title(nev);
    gout.open(SX,SY);
    gin.timer(40);
}
void MyApplication::futtatas()
{
    while(gin >> ev)
    {
        widget_kezel();
        programkod();
    }
}

void MyApplication::tab_focusalas(std::vector<Widgets*> widgets)
{
    int megvan = 0;
    for(int i = 1; i<widgets.size(); i++)
    {
        if(widgets[i]->get_focusalhato() && widgets[i]->get_focusban()) megvan = i;
    }
    int i = 0;
    while(i<widgets.size())
    {
        if(widgets[(i+megvan)%widgets.size()]->get_focusban()) widgets[(i+megvan)%widgets.size()]->set_focusban(false);
        else if(widgets[(i+megvan)%widgets.size()]->get_focusalhato() && !widgets[(i+megvan)%widgets.size()]->get_focusban())
        {
            widgets[(i+megvan)%widgets.size()]->set_focusban(true);
            i = widgets.size();
        }
        i++;
    }
}
void MyApplication::widget_kezel()
{
    if(ev.type == ev_timer)
    {
        gout << move_to(0,0) << color(120,120,120) << box(SX,SY);
        for(Widgets * w:widgets) w->rajzol();
        gout << refresh;
    }
    if(ev.button == btn_left)for(Widgets * w:widgets) w->set_focusban(false);
    for(Widgets * w:widgets) w->kezel(ev);
    if(ev.keycode == 9) MyApplication::tab_focusalas(widgets);
}
void MyApplication::create(Widgets * temp)
{
    widgets.push_back(temp);
}
