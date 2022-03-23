#include <bits/stdc++.h>
#include "playlist.h"
#include "interface.h"
using namespace std;

void call_interface(Playlist &p)
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

void argparse(Playlist &p, int argc, char* argv[])
{
    if (argc > 7)
    {
        for (int i = 7; i < argc; i++)
        {
            p.add_song(argv[i]);
        }
    }
    if (argc > 6)
    {
        p.set_play_type(argv[6]);
    }
    if (argc > 5)
    {
        p.set_duration(stoi(argv[5]));
    }
    if (argc > 4)
    {
        p.set_date_modified(argv[4]);
    }
    if (argc > 3)
    {
        p.set_date_created(argv[3]);
    }
    if (argc > 2)
    {
        p.set_author(argv[2]);
    }
    if (argc > 1)
    {
        cout << argv[1];
        p.set_name(argv[1]);
    }
}

int main (int argc, char* argv[])
{
    Playlist plds;
    if (argc == 1) call_interface(plds);
    else
    {
        argparse(plds, argc, argv);
        call_interface(plds);
    }
    return 0;
}