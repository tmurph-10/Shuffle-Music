#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct SongInfo {
    string artist[25];
    string song[25];
    int num[25];
};
int main() {
    string playlistName;
    cout << "What do you want to name your playlist?" << endl;
    getline(cin, playlistName);
    cout << "Scanning file to shuffle playlist..." << endl;
    cout << endl;
    ifstream fin;
    fin.open("SongAndArtist.txt");
    string songName = "";
    string artistName = "";
    string answer;
    SongInfo fullPlaylist;
    int songNum = 1;
    int totalSongs = 0;
    string songNames[25];
    while (getline(fin, songName)) {
        getline(fin, songName);
        getline(fin, artistName);
        fullPlaylist.artist[songNum] = artistName;
        fullPlaylist.song[songNum] = songName;
        fullPlaylist.num[songNum] = songNum;
        songName = "";
        artistName = "";
        songNum++;
        totalSongs++;
    }
    fin.close();
    //Randomizing every song//
    int numbers[totalSongs];
    srand(time(0));
    int possibleNum = 0;
    bool numAlreadyUsed = false;
    int slotsFilled = 0;
    int i = 0;
    while (i < totalSongs) {
        possibleNum = 1 + (rand()%totalSongs);
        for (int x = 0; x < slotsFilled + 1; x++) {
            if (possibleNum == numbers[x]) {
                numAlreadyUsed = true;
                break;
            }
        }
        if (!numAlreadyUsed) {
            numbers[i] = possibleNum;
            i++;
            slotsFilled++;
        }
        possibleNum = 0;
        numAlreadyUsed = false;
    }
    //Output by numbers in arrray//
    int songToOutput = 1;
    int j = 0;
    cout << setw(20) << playlistName << endl;
    while (j < totalSongs) {
        int specificNum = fullPlaylist.num[songToOutput];
        while (numbers[j] != specificNum) {
            specificNum = specificNum + 1;
        }
        cout << "Artist: " << fullPlaylist.artist[specificNum] << endl;
        cout << "Song: " << fullPlaylist.song[specificNum] << endl;
        cout << endl;
        songToOutput = 1;
        j++;
    }
    return 0;
}