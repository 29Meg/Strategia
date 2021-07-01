#include "Gra.h"


int main()
{
   
    srand(static_cast<unsigned>(time(0)));

    // objekt gry
    Gra gra;

    //pętla gry
    while (gra.running() )
    {
        gra.update();
        gra.render();

    }

    //koniec
    return 0;

}
