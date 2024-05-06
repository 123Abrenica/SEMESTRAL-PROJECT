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


void clearScreen() {
    system("cls");
}


void insertTrack(MusicTrack*& head, MusicTrack track) {
    MusicTrack* newNode = new MusicTrack;
    newNode->title = track.title;
    newNode->artist = track.artist;
    newNode->genre = track.genre;
    newNode->next = head;
    head = newNode;
}


void browseMusic(const string categories[], MusicTrack* tracks[], stack<MusicTrack>& history, MusicTrack*& recentTracks) {
    int categoryIndex;
    int trackIndex;

    cout << "Categories:" << endl;
    for (int i = 0; i < 10; ++i) {
        cout << i + 1 << ". " << categories[i] << endl;
    }
    cout << "\nEnter the number of the category you want to browse: ";
    cin >> categoryIndex;

    clearScreen();
    if (categoryIndex >= 1 && categoryIndex <= 10) {
        cout << "\nMusic in " << categories[categoryIndex - 1] << " Category:" << endl;
        MusicTrack* selectedTracks = tracks[categoryIndex - 1];

        for (int i = 0; i < 10; ++i) {
            cout << i + 1 << ". " << selectedTracks[i].title << " by " << selectedTracks[i].artist << endl;
        }
        cout << "\nEnter the number of the track you want to play: ";
        cin >> trackIndex;

        if (trackIndex >= 1 && trackIndex <= 10) {
            MusicTrack selectedTrack = selectedTracks[trackIndex - 1];
            history.push(selectedTrack);
            insertTrack(recentTracks, selectedTrack);
            cout << "\nNow playing: " << selectedTrack.title << " from " << categories[categoryIndex - 1] << " category." << endl;
        } else {
            cout << "Invalid track selection." << endl;
        }
    } else {
        cout << "Invalid category selection." << endl;
    }
}


void createPlaylist(stack<MusicTrack>& playlist, const string categories[], MusicTrack* chillTracks, MusicTrack* rockTracks,
                    MusicTrack* popTracks, MusicTrack* hip_hopTracks, MusicTrack* ReggaeTracks, MusicTrack* ClassicalTracks,
                    MusicTrack* JazzTracks, MusicTrack* CountryTracks, MusicTrack* R_and_BTracks, MusicTrack* KPopTracks) {

    const int NUM_TRACKS_PER_CATEGORY = 10;

    int trackIndex;
    int categoryIndex;
    int choice;

    do {
        cout << "\t\t\t\t\t\t\t  ---------------------------------" << endl;
        cout << "\t\t\t\t\t\t\t  |1. Add music to your playlist  |" << endl;
        cout << "\t\t\t\t\t\t\t  |2. Exit                        |" << endl;
        cout << "\t\t\t\t\t\t\t  ---------------------------------\n" << endl;
        cout << "\t\t\t\t\t\t\t  Enter your choice: ";
        cin >> choice;
        clearScreen();

        switch (choice) {
            case 1: {
                cout << "Select tracks to add to your playlist:" << endl;
                cout << "\nCategories:" << endl;
                for (int i = 0; i < 10; ++i) {
                    cout << i + 1 << ". " << categories[i] << endl;
                }
                cout << "\nEnter the number of the category you want to add in your playlist (or 0 to finish): ";
                cin >> categoryIndex;
                clearScreen();
                if (categoryIndex >= 1 && categoryIndex <= 10) {
                    cout << "\nMusic in " << categories[categoryIndex - 1] << " Category:" << endl;
                    MusicTrack* tracks;
                    switch (categoryIndex) {
                        case 1:
                            tracks = chillTracks;
                            break;
                        case 2:
                            tracks = rockTracks;
                            break;
                        case 3:
                            tracks = popTracks;
                            break;
                        case 4:
                            tracks = hip_hopTracks;
                            break;
                        case 5:
                            tracks = ReggaeTracks;
                            break;
                        case 6:
                            tracks = ClassicalTracks;
                            break;
                        case 7:
                            tracks = JazzTracks;
                            break;
                        case 8:
                            tracks = CountryTracks;
                            break;
                        case 9:
                            tracks = R_and_BTracks;
                            break;
                        case 10:
                            tracks = KPopTracks;
                            break;
                    }

                    for (int i = 0; i < NUM_TRACKS_PER_CATEGORY; ++i) {
                        cout << i + 1 << ". " << tracks[i].title << " - " << tracks[i].artist << endl;
                    }

                    cout << "\nEnter the number of the track you want to add (or 0 to return to category selection): ";
                    cin >> trackIndex;
                    if (trackIndex == 0) {
                        cout << "Returning to main menu..." << endl;
                    } else if (trackIndex >= 1 && trackIndex <= NUM_TRACKS_PER_CATEGORY) {
                        MusicTrack selectedTrack = tracks[trackIndex - 1];
                        playlist.push(selectedTrack);
                        cout << "\nTrack added to playlist!" << endl;
                    } else {
                        cout << "\nInvalid track number. Please try again." << endl;
                    }
                } else if (categoryIndex != 0) {
                    cout << "\nInvalid category number. Please try again." << endl;
                }
                break;
            }
            case 2:
                cout << "Returning to main menu..." << endl;
                break;
            default:
                cout << "\nInvalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 2);
}


void printPlaylist(stack<MusicTrack>& playlist, stack<MusicTrack>& history, MusicTrack*& recentTracks) {
    int choice1;

    do {
        cout << "Your Playlist:" << endl;
        int trackNumber = 1;
        stack<MusicTrack> temp = playlist;
        while (!temp.empty()) {
            MusicTrack track = temp.top();
            cout << trackNumber << ". " << track.title << " by " << track.artist << endl;
            temp.pop();
            trackNumber++;
        }
        cout << "\t\t\t\t\t\t\t  ---------------------------------" << endl;
        cout << "\t\t\t\t\t\t\t  |1. Delete from My PlayLists    |" << endl;
        cout << "\t\t\t\t\t\t\t  |2. Play My PlayLists           |" << endl;
        cout << "\t\t\t\t\t\t\t  |3. Exit                        |" << endl;
        cout << "\t\t\t\t\t\t\t  ---------------------------------\n" << endl;
        cout << "\t\t\t\t\t\t\t  Enter your choice: ";
        cin >> choice1;

        switch (choice1) {
            case 1:
                clearScreen();
                deleteFromPlaylist(playlist);
                break;
            case 2:
                if (trackNumber == 1) {
                    cout << "Your playlist is empty." << endl;
                    return;
                }

                int choice;
                cout << "\nEnter the number of the track you want to play (or 0 to go back): ";
                cin >> choice;

                if (choice == 0) {
                    return;
                }

                if (choice >= 1 && choice <= trackNumber - 1) {
                    stack<MusicTrack> tempPlaylist = playlist;
                    for (int i = 1; i < choice; ++i) {
                        tempPlaylist.pop();
                    }
                    MusicTrack selectedTrack = tempPlaylist.top();
                    clearScreen();
                    cout << "\nNow playing: " << selectedTrack.title << " by " << selectedTrack.artist << endl << endl;

                    history.push(selectedTrack);

                    insertTrack(recentTracks, selectedTrack);

                } else {
                    cout << "Invalid track selection." << endl;
                }
                break;

            case 3:
                break;
        }
    } while (choice1 != 3);
}


void deleteFromPlaylist(stack<MusicTrack>& playlist) {
    if (playlist.empty()) {
        cout << "Playlist is empty." << endl;
        return;
    }

    int trackNumber = 1;
    int trackNumberToDelete;

    // Display tracks in the playlist
    cout << "\nSelect the track number you want to delete from the playlist:\n" << endl;
    stack<MusicTrack> tempPlaylist = playlist;
    while (!tempPlaylist.empty()) {
        MusicTrack track = tempPlaylist.top();
        cout << trackNumber << ". " << track.title << " by " << track.artist << endl;
        tempPlaylist.pop();
        trackNumber++;
    }

    // Prompt user for track number to delete
    cout << "\nEnter track number: ";
    cin >> trackNumberToDelete;

    // Check if track number is valid
    if (trackNumberToDelete < 1 || trackNumberToDelete > trackNumber - 1) {
        cout << "Invalid track number." << endl;
        return;
    }

    // Create a temporary stack to hold tracks before the deleted track
    stack<MusicTrack> tempStack;
    while (trackNumberToDelete > 1) {
        tempStack.push(playlist.top());
        playlist.pop();
        trackNumberToDelete--;
    }

    // Pop the deleted track
    playlist.pop();

    // Rebuild the playlist by pushing tracks back from the temporary stack
    while (!tempStack.empty()) {
        playlist.push(tempStack.top());
        tempStack.pop();
    }
    clearScreen();
    cout << "\nTrack successfully deleted from the playlist.\n" << endl;
}


void deleteFromHistory(stack<MusicTrack>& history) {

    int trackNumber = 1;
    int trackNumberToDelete;

    if (history.empty()) {
        cout << "Browsing history is empty." << endl;
        return;
    }

    cout << "\nSelect the track number you want to delete from browsing history:\n" << endl;

    stack<MusicTrack> tempHistory = history;

    while (!tempHistory.empty()) {
        MusicTrack track = tempHistory.top();
        cout << trackNumber << ". " << track.title << " by " << track.artist << endl;
        tempHistory.pop();
        trackNumber++;
    }

    cout << "\nEnter track number: ";
    cin >> trackNumberToDelete;


    if (trackNumberToDelete < 1 || trackNumberToDelete > trackNumber - 1) {
        cout << "Invalid track number." << endl;
        return;
    }

    stack<MusicTrack> tempStack;


    while (trackNumberToDelete > 1 && !history.empty()) {
        tempStack.push(history.top());
        history.pop();
        trackNumberToDelete--;
    }


    if (!history.empty()) {
        history.pop();
    } else {
        cout << "Invalid track number." << endl;
        return;
    }


    while (!tempStack.empty()) {
        history.push(tempStack.top());
        tempStack.pop();
    }

    cout << "\nTrack successfully deleted from browsing history." << endl;

}


void playRecentTracks(MusicTrack* recentTracks, stack<MusicTrack>& history) {
    cout << "Recent Tracks:" << endl;
    MusicTrack* current = recentTracks;
    int trackNumber = 1;
    while (current != nullptr) {
        cout << trackNumber << ". " << current->title << " by " << current->artist << endl;
        current = current->next;
        trackNumber++;
    }
    if (trackNumber == 1) {
        cout << "No recent tracks." << endl;
        return;
    }
    int trackIndex;
    cout << "\nEnter the number of the track you want to play (or 0 to go back): ";
    cin >> trackIndex;
    clearScreen();

    if (trackIndex == 0) {
        return; // Go back to previous menu
    }

    if (trackIndex >= 1 && trackIndex <= trackNumber - 1) {
        current = recentTracks;
        for (int i = 1; i < trackIndex; ++i) {
            current = current->next;
        }
        cout << "\nNow playing: " << current->title << " by " << current->artist << endl;

        history.push(*current);
    } else {
        cout << "Invalid track selection." << endl;
    }
}


void printBrowsingHistory(stack<MusicTrack>& history, MusicTrack* recentTracks) {

    int choice;
    do {

        cout << "\nBrowsing History:" << endl;
        int trackNumber = 1;

        stack<MusicTrack> tempHistory = history;

        while (!tempHistory.empty()) {
            MusicTrack track = tempHistory.top();
            cout << trackNumber << ". " << track.title << " by " << track.artist << endl;
            tempHistory.pop();
            trackNumber++;
        }
        cout << "\t\t\t\t\t\t\t  ---------------------------------" << endl;
        cout << "\t\t\t\t\t\t\t  |1. Delete From Browsing History|" << endl;
        cout << "\t\t\t\t\t\t\t  |2. Play Recent tracks          |" << endl;
        cout << "\t\t\t\t\t\t\t  |3. Exit                        |" << endl;
        cout << "\t\t\t\t\t\t\t  ---------------------------------\n" << endl;
        cout << "\t\t\t\t\t\t\t  Enter your choice: ";
        cin >> choice;
        clearScreen();


        switch (choice){
            case 1:
                deleteFromHistory(history);
                break;
            case 2:
                 playRecentTracks(recentTracks, history);
                 break;
            case 3:
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 3);
}
