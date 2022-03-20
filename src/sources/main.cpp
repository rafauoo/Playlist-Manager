#include <bits/stdc++.h>
#include "playlist.h"
#include "interface.h"
using namespace std;

int main ()
{
    Playlist plds;
    Interface ui(plds);
    while (ui.breaks == false)
    {
        ui.write_menu();
        ui.input();
        ui.write_choice();
        ui.clear();
    }
}