#include <iostream>
#include <string>
#include <stack>
#include <cstdlib>
#include "FUNCTIONS.h"

using namespace std;


struct MusicTrack {
    string title;
    string artist;
    string genre;
    MusicTrack* next;
};
void clearScreen();
void insertTrack(MusicTrack*& head, MusicTrack track);
void browseMusic(const string categories[], MusicTrack* tracks[], stack<MusicTrack>& history, MusicTrack*& recentTracks);
void createPlaylist(stack<MusicTrack>& playlist, const string categories[], MusicTrack* chillTracks, MusicTrack* rockTracks,
                    MusicTrack* popTracks, MusicTrack* hip_hopTracks, MusicTrack* ReggaeTracks, MusicTrack* ClassicalTracks,
                    MusicTrack* JazzTracks, MusicTrack* CountryTracks, MusicTrack* R_and_BTracks, MusicTrack* KPopTracks);
void printPlaylist(stack<MusicTrack>& playlist, stack<MusicTrack>& history, MusicTrack*& recentTracks);
void deleteFromPlaylist(stack<MusicTrack>& playlist);
void deleteFromHistory(stack<MusicTrack>& history);
void playRecentTracks(MusicTrack* recentTracks, stack<MusicTrack>& history);
void printBrowsingHistory(stack<MusicTrack>& history, MusicTrack* recentTracks);




int main() {

    string categories[10] = {"Chill", "Rock", "Pop", "Hip Hop", "Reggae", "Classical", "Jazz", "Country", "R&B", "K-pop"};


    MusicTrack chillTracks[10] = {
        {"At My Worst", "Pink Sweat$", "Chill"},
        {"Snow On The Beach", "Taylor Swift, Lana Del Rey", "Chill"},
        {"Stuck with U", "Ariana Grande, Justin Bieber", "Chill"},
        {"This Love", "Taylor Swift", "Chill"},
        {"Glimpse of Us", "joji", "Chill"},
        {"Pelikula", "Janine, Arthur Nery", "Chill"},
        {"Leonora", "Sugarcane", "Chill"},
        {"Nahuhulog", "Jed Baruelo", "Chill"},
        {"Tahanan", "Adie", "Chill"},
        {"Kisame", "rhodessa", "Chill"},
    };

    MusicTrack rockTracks[10] = {
        {"Iris", "The Goo Goo Dolls", "Rock"},
        {"I'll Be There For You", "Bon Jovi", "Rock"},
        {"Runaway", "Bon Jovi", "Rock"},
        {"Always", "Bon Jovi", "Rock"},
        {"Bed of Roses", "Bon Jovi", "Rock"},
        {"Halik", "kamikazee", "Rock"},
        {"Tayo Na Lang Dalawa", "Mayonnaise", "Rock"},
        {"Bagsakan", "Parokya ni Edgar", "Rock"},
        {"Banal na Aso Santong Kabayo", "Yano", "Rock"},
        {"Lakas Tama", "Siakol", "Rock"},
    };

    MusicTrack popTracks[10] = {
        {"End of Beginning", "Djo", "Pop"},
        {"Take A Chance With Me", "NIKI", "Pop"},
        {"Love You Like A Love Song", "Selena Gomez", "Pop"},
        {"Peaches", "Justin Bieber, Daniel Caesar, Giveon", "Pop"},
        {"Sugar", "Maroon 5", "Pop"},
        {"Tingin", "Cup of Joe, Janine", "Pop"},
        {"Pantropiko", "BINI", "Pop"},
        {"Salamin", "BINI", "Pop"},
        {"Na Na Na", "BINI", "Pop"},
        {"Gento", "SB19", "Pop"},
    };

    MusicTrack hip_hopTracks[10] = {
        {"Drop It Like It's Hot", "Snoop Dog, Pharrell Williams", "Hip Hop"},
        {"Loyal", "Chris Brown, Lil Wayne & Tyga", "Hip Hop"},
        {"Ice on My Baby", "Yung Bleu, Kevin Gates", "Hip Hop"},
        {"Trap Queen", "Fetty Wap", "Hip Hop"},
        {"All Girls Are The Same", "Juice WRLD", "Hip Hop"},
        {"Sa Susunod Na Lang", "PDL, Skusta Clee, Yuridope", "Hip Hop"},
        {"Simpleng Tao", "Gloc-9", "Hip Hop"},
        {"BMW", "Because, Leslie", "Hip Hop"},
        {"Sandali", "Because", "Hip Hop"},
        {"Hayaan Mo Sila", "Ex Battalion, O.C. Dawgs", "Hip Hop"},
};

    MusicTrack ReggaeTracks[10] = {
        {"I Can See Clearly Now", "Jimmy Cliff", "Reggae"},
        {"Is This Love", "Bob Marley & The Wailers", "Reggae"},
        {"Three Little Birds", "Bob Marley & The Wailers", "Reggae"},
        {"Let's Do It Again", "J Boog", "Reggae"},
        {"Ehu Girl", "Kolohe Kai", "Reggae"},
        {"Bilog Na Naman Ang Buwan", "Tropical Depression", "Reggae"},
        {"Kung Ika'y Akin", "Chocolate Factory", "Reggae"},
        {"Kapayapaan", "Tropical Depression", "Reggae"},
        {"Usok", "Lolita & The Boys", "Reggae"},
        {"Lintik", "Brownman Revival", "Reggae"},
    };

    MusicTrack ClassicalTracks[10] = {
        {"How Deep Is Your Love", "Bee Gees", "Classical"},
        {"Making Love Out of Nothing At All", "Air Supply", "Classical"},
        {"Wonderful Tonight", "Eric Clapton", "Classical"},
        {"On The Wings Of Love", "Jeffrey Osborne", "Classical"},
        {"Where Do Broken Hearts Go", "Whitney Houston", "Classical"},
        {"Kahit Maputi Na Ang Buhok Ko", "Rey Valera", "Classical"},
        {"Anak", "Freddie Aguilar", "Classical"},
        {"Ikaw Ang Aking Mahal", "VST & Company", "Classical"},
        {"Awitin Mo at Isasayaw Ko", "VST & Company", "Classical"},
        {"Kung Kailangan Mo Ako", "Rey Valera", "Classical"},

    };

    MusicTrack JazzTracks[10] = {
        {"Fly Me To The Moon", "Frank Sinatra, Count Basie", "Jazz"},
        {"What A Wonderful World", "Louis Armstrong", "Jazz"},
        {"Sh-Boom", "The Crew Cuts", "Jazz"},
        {"You've Got a Friend in Me", "Randy Newman", "Jazz"},
        {"It's Been a Long, Long Time", "Kitty Kallen, Harry James", "Jazz"},
        {"Para Sa Akin", "Sitti", "Jazz"},
        {"Pwede Ba", "Lola Amour", "Jazz"},
        {"Panalangin", "APO Hiking Society", "Jazz"},
        {"Binibini", "Brownman Revival", "Jazz"},
        {"Ikaw Pa Rin", "Tito Mina", "Jazz"},
    };

    MusicTrack CountryTracks[10] = {
        {"Everything I Own", "Bread", "Country"},
        {"Remember When", "Alan Jackson", "Country"},
        {"We Danced", "Brad Paisley", "Country"},
        {"Hotel California", "Eagles", "Country"},
        {"Love Will Keep Us Alive", "Eagles", "Country"},
        {"Tunay Na Pag-ibig", "April Boy", "Country"},
        {"Iniibig Kita", "Roel Cortez", "Country"},
        {"Katarungan", "Freddie Aguilar", "Country"},
        {"Minamahal Kita", "Freddie Aguilar", "Country"},
        {"Sa Mata Makikita", "Roel Cortez", "Country"},
     };

    MusicTrack R_and_BTracks[10] = {
        {"Miss Independent", "Ne-Yo", "R&B"},
        {"My Boo", "USHER, Alicia Keys", "R&B"},
        {"Dilemma", "Nelly, Kelly Rownland", "R&B"},
        {"Because Of You", "Ne-Yo", "R&B"},
        {"Mad", "Ne-Yo", "R&B"},
        {"Nakakamiss", "Smugglaz, Curse One, Dello, Flict G", "R&B"},
        {"Masaya Ako Sayo", "Curse One, Yumi", "R&B"},
        {"Filipina Girl", "Billy Crawford, Marcus Davis, James Reid", "R&B"},
        {"Shake It Off", "Mariah Carey", "R&B"},
        {"Love", "Keyshia Cole", "R&B"},
    };

    MusicTrack KPopTracks[10] = {
        {"Cupid", "FIFTY FIFTY", "K-pop"},
        {"Super Shy", "NewJeans", "K-pop"},
        {"What is Love", "TWICE", "K-pop"},
        {"As If It's Your Last", "BLACKPINK", "K-pop"},
        {"FAKE LOVE", "BTS", "K-pop"},
        {"Love Scenario", "iKON", "K-pop"},
        {"Darari", "Tresure", "K-pop"},
        {"Love Shot", "EXO", "K-pop"},
        {"Smart", "LE SSERAFIM", "K-pop"},
        {"POP!", "Nayeon", "K-pop"},
    };


    stack<MusicTrack> history;

    stack<MusicTrack> playlist;

    MusicTrack* recentTracks = nullptr;

    int choice;
    do {
        cout << "\t\t\t\t\t\t\t  ---------------------------------" << endl;
        cout << "\t\t\t\t\t\t\t  |    WELCOME TO SOUND SAFARI    |" << endl;
        cout << "\t\t\t\t\t\t\t  |-------------------------------|" << endl;
        cout << "\t\t\t\t\t\t\t  |1. Browse Music                |" << endl;
        cout << "\t\t\t\t\t\t\t  |2. Display Browsing History    |" << endl;
        cout << "\t\t\t\t\t\t\t  |3. Create to PlayList          |" << endl;
        cout << "\t\t\t\t\t\t\t  |4. Display PlayList            |" << endl;
        cout << "\t\t\t\t\t\t\t  |5. Exit                        |" << endl;
        cout << "\t\t\t\t\t\t\t  ---------------------------------\n" << endl;
        cout << "\t\t\t\t\t\t\t  Enter your choice: ";
        cin >> choice;
        clearScreen();

        switch (choice){

            case 1:
                browseMusic(categories, new MusicTrack*[10]{chillTracks, rockTracks, popTracks, hip_hopTracks,
                            ReggaeTracks, ClassicalTracks, JazzTracks, CountryTracks, R_and_BTracks,
                            KPopTracks}, history, recentTracks);
                break;

            case 2:
                printBrowsingHistory(history, recentTracks);
                break;

            case 3:
                createPlaylist(playlist, categories, chillTracks, rockTracks, popTracks, hip_hopTracks,
                               ReggaeTracks, ClassicalTracks, JazzTracks, CountryTracks, R_and_BTracks,
                               KPopTracks);
                break;
            case 4:
                printPlaylist(playlist, history, recentTracks);
                break;
            case 5:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 5);


    MusicTrack* current = recentTracks;
    while (current != nullptr) {
        MusicTrack* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
