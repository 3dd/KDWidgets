#ifndef WIDGETS_HPP_INCLUDED
#define WIDGETS_HPP_INCLUDED

#include "graphics.hpp"

class Widgets
{
protected:
    int x,y;
    int meret_x,meret_y;
    bool focusalhato,focusban;

    genv::canvas focus_poty;
    genv::canvas kep;

    genv::color foreground_col = genv::color(50,50,50);
    genv::color background_col = genv::color(255,255,255);

    void focus_rajz();

public:
    ///////////////////////////
    //------konstruktor------//
    ///////////////////////////
    Widgets(int fx,int fy,int merx,int mery);

    ///////////////////////////
    //----------szin---------//
    ///////////////////////////
    void set_fore_col(genv::color szin) {foreground_col = szin; ujra_rajzol();}
    void set_back_col(genv::color szin) {background_col = szin; ujra_rajzol();}


    ///////////////////////////////////
    //------focus tulajdonsagok------//
    ///////////////////////////////////
    bool get_focusalhato() {return focusalhato;}

    bool get_focusban() {return focusban;}
    void set_focusban(bool focus) {focusban = focus;}

    /////////////////////////////////////
    //------pozicio tulajdonsagok------//
    /////////////////////////////////////
    bool get_egeralatt(genv::event ev);
    void set_x_y(int fx,int fy) {x = fx; y = fy;}
    int get_x() {return x;}
    int get_y() {return y;}

    //////////////////////////////
    //----virutal fuggvenyek----//
    //////////////////////////////
    virtual void rajzol() = 0;
    virtual void kezel(genv::event ev) = 0;
    virtual void ujra_rajzol() = 0;
};


#endif // WIDGETS_HPP_INCLUDED
