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
    for (int i = 0; i < playlist.song_count(); i++)
    {
        cout << i << ". " << playlist.get_song_by_id(i) << endl;
    }
}

void Interface::write_manage_songs_menu()
{
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
            cout << "Song found on index " << index << ": " << name << endl;
            back();
            break;
        }
        case 6:
        {
            cout << "Song count: " << playlist.song_count() << endl;
            back();
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
    clear();
    cout << "What do you want to do?\n";
    cout << "1. See Songs in the Playlist\n";
    cout << "2. Manage Songs\n";
    cout << "3. Get Playlist Info\n";
    cout << "4. Set Playlist Info\n";
    cout << "5. Quit\n";
}

void Interface::get_info()
{
    cout << "Playlist Name..................... " << playlist.get_name() << endl;
    cout << "Playlist Author................... " << playlist.get_author() << endl;
    cout << "Playlist Creation Date............ " << playlist.get_date_created() << endl;
    cout << "Playlist Modification Date........ " << playlist.get_date_modified() << endl;
    cout << "Playlist Duration................. " << playlist.get_duration() << endl;
    cout << "Playlist Play Type................ " << playlist.get_play_type() << endl;
}

void Interface::write_set_info_menu()
{
    cout << "1. Set Playlist Name\n";
    cout << "2. Set Playlist Author\n";
    cout << "3. Set Playlist Creation Date\n";
    cout << "4. Set Playlist Modification Date\n";
    cout << "5. Set Playlist Duration\n";
    cout << "6. See Play Type\n";
    cout << "7. BACK\n";  
}

void Interface::set_info_menu()
{
    switch(choice)
    {
        case 1:
        {
            string new_name;
            cout << "Enter new playlist name:" << endl;
            cin >> new_name;
            playlist.set_name(new_name);
            cout << "Name changed successfully!" << endl;
            back();
            break;
        }
        case 2:
        {
            string new_author;
            cout << "Enter new playlist author:" << endl;
            cin >> new_author;
            playlist.set_author(new_author);
            cout << "Author changed successfully!" << endl;
            back();
            break;
        }
        case 3:
        {
            string new_cd;
            cout << "Enter new playlist creation date:" << endl;
            cin >> new_cd;
            playlist.set_date_created(new_cd);
            cout << "Creation date changed successfully!" << endl;
            back();
            break;
        }
        case 4:
        {
            string new_md;
            cout << "Enter new playlist modification date:" << endl;
            cin >> new_md;
            playlist.set_date_modified(new_md);
            cout << "Modification date changed successfully!" << endl;
            back();
            break;
        }
        case 5:
        {
            int new_dur;
            cout << "Enter new playlist duration" << endl;
            cin >> new_dur;
            playlist.set_duration(new_dur);
            cout << "Duration changed successfully!" << endl;
            back();
            break;
        }
        case 6:
        {
            string new_pt;
            cout << "Enter new play type (Random, Normal or User): " << endl;
            cin >> new_pt;
            try
            {
                playlist.set_play_type(new_pt);
                cout << "Play type set successfully!" << endl;
            }
            catch(const std::invalid_argument& e)
            {
                cout << e.what() << endl;
            }
            back();
            break;
        }
        default:
        {
            break;
        }
    }
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
            clear();
            write_playlist();
            back();
            break;
        }
        case 2:
        {
            clear();
            write_manage_songs_menu();
            input();
            clear();
            manage_songs_menu();
            break;
        }
        case 3:
        {
            clear();
            get_info();
            back();
            break;
        }
        case 4:
        {
            clear();
            write_set_info_menu();
            input();
            clear();
            set_info_menu();
            break;
        }
        case 5:
        {
            breaks = true;
            exit(0);
            break;
        }
        default:
        {
            breaks = true;
            exit(0);
            break;
        }
    }
}

