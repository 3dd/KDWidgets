#ifndef KDTEXTBOX_HPP_INCLUDED
#define KDTEXTBOX_HPP_INCLUDED

#include "Widgets.hpp"
#include <vector>

class KDTextBox : public Widgets
{
protected:
    std::vector<char> abc;
    std::string felirat;
    int betumeret;

    int kurzor_pos;
    int villogas;
    int hossz;

public:
    KDTextBox(int fx,int fy,int x_meret,std::string felir);

    void rajzol();
    void ujra_rajzol();
    void kezel(genv::event ev);

    std::string get_string(){ std::string temp = ""; for(char t:abc) temp += t; return temp; }
    void clc_string() { abc.clear(); kurzor_pos = 0; ujra_rajzol(); }
};

#endif // KDTEXTBOX_HPP_INCLUDED
