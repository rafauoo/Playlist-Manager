#include <bits/stdc++.h>
#include "playlist.h"
#include "interface.h"
using namespace std;

void call_interface(Playlist p)
{
    Interface ui(p);
    while (ui.breaks == false)
    {
        ui.write_menu();
        ui.input();
        ui.write_choice();
        ui.clear();
    }
}

int main (int argc, char* argv[])
{
    if (argc == 1)
    {
        Playlist plds;
        call_interface(plds);
    }
    else
    {
        Playlist plds;
        if (argc > 7)
        {
            for (int i = 7; i < argc; i++)
            {
                plds.add_song(argv[i]);
            }
        }
        if (argc > 6)
        {
            plds.set_play_type(argv[6]);
        }
        if (argc > 5)
        {
            plds.set_duration(stoi(argv[5]));
        }
        if (argc > 4)
        {
            plds.set_date_modified(argv[4]);
        }
        if (argc > 3)
        {
            plds.set_date_created(argv[3]);
        }
        if (argc > 2)
        {
            plds.set_author(argv[2]);
        }
        if (argc > 1)
        {
            plds.set_name(argv[1]);
        }
        call_interface(plds);
    }
    return 0;
}