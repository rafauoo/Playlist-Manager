#include <bits/stdc++.h>
#include "playlist.h"
using namespace std;

int main ()
{
    string a = "AAA";
    string b = "CCC";
    Playlist pl(a, b);
    pl.add_song("pierwsza");
    pl.add_song("druga");
    for (long unsigned int i = 0; i < pl.get_song_list().size(); i++)
    {
        cout << pl.get_song_list()[i] << endl;
    }
}