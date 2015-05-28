#include "MyApplication.hpp"

const int SX = 1000;
const int SY = 600;

class Proba : public MyApplication
{

public:
    Proba() : MyApplication("Proba")
    {

    }
    void programkod()
    {

    }
};

int main()
{
    Proba pr;
    pr.futtatas();
    return 0;
}
