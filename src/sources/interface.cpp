#include <bits/stdc++.h>
#include <stdio.h>
#include "playlist.h"
#include "interface.h"
using namespace std;

Interface::Interface(Playlist& pla)
{
    playlist = pla;
    breaks = false;
    choice = 0;
}

void Interface::clear()
{
    for (int i = 0; i < 100; i++)
        cout << endl;
}

void Interface::write_playlist()
{
    clear();
    for (int i = 0; i < playlist.song_count(); i++)
    {
        cout << i << ". " << playlist.get_song_by_id(i) << endl;
    }
    back();
}

void Interface::write_manage_songs_menu()
{
    clear();
    cout << "1. Add Song\n";
    cout << "2. Remove Song\n";
    cout << "3. Rename Song\n";
    cout << "4. Search Song by name\n";
    cout << "5. Search Song by ID\n";
    cout << "6. See the Song Count\n";
    cout << "7. BACK\n";
}

void Interface::manage_songs_menu()
{
    clear();
    switch(choice)
    {
        case 1:
        {
            string name;
            cout << "Enter song name that you want to add: " << endl;
            cin >> name;
            playlist.add_song(name);
            cout << "Song added successfully!" << endl;
            back();
            break;
        }
        case 2:
        {
            string name;
            cout << "Enter song name that you want to remove: " << endl;
            cin >> name;
            try
            {
                playlist.remove_song(name);
                cout << "Song removed!" << endl;
            }
            catch(const std::invalid_argument& e)
            {
                cout << e.what() << endl;
            }
            back();
            break;
        }
        case 3:
        {
            string name;
            string name2;
            cout << "Enter song name that you want to rename: " << endl;
            cin >> name;
            cout << "Enter new song name: " << endl;
            cin >> name2;
            try
            {
                playlist.rename_song(name, name2);
                cout << "Song renamed!" << endl;
            }
            catch(const std::invalid_argument& e)
            {
                cout << e.what() << endl;
            }
            back();
            break;
        }
        case 4:
        {
            string name;
            cout << "Enter song name that you want to find: " << endl;
            cin >> name;
            try
            {
                int index = playlist.search_song(name);
                cout << "Song found on index: " << index << endl;
            }
            catch(const std::invalid_argument& e)
            {
                cout << e.what() << endl;
            }
            back();
            break;
        }
        case 5:
        {
            int index;
            cout << "Enter song index that you want to find: " << endl;
            cin >> index;
            if (index > playlist.song_count())
            {
                cout << "Index not found!" << endl;
                back();
                break;
            }
            string name = playlist.get_song_by_id(index);
            cout << "Song found on index: " << index << endl;
            back();
            break;
        }
        case 6:
        {
            cout << "Song count: " << playlist.song_count() << endl;
            back();
            break;
        }
        case 7:
        {
            break;
        }
        default:
        {
            break;
        }
    }
}

void Interface::back()
{
    cout << "Type anything to go back..." << endl;
    cin.get();
    cin.get();
}
void Interface::write_menu()
{
    cout << "What do you want to do?\n";
    cout << "1. See songs in playlist\n";
    cout << "2. Manage Songs\n";
    cout << "3. Quit\n";
}

void Interface::input()
{
    int a;
    cin >> a;
    choice = a;
}

void Interface::write_choice()
{
    switch(choice)
    {
        case 1:
        {
            write_playlist();
            break;
        }
        case 2:
        {
            write_manage_songs_menu();
            input();
            manage_songs_menu();
            break;
        }
        case 3:
        {
            breaks = true;
            exit(0);
        }
        default:
        {
            exit(0);
            break;
        }
    }
}

