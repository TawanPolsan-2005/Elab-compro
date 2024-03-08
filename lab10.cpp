#include <iostream>
#include <string>
using namespace std;

class MusicPlaylist
{
    private:
    string songs[20];
    int track;
    int pos;
    int i = 0;

    public:




    void add(string song)
    {
        songs[i++] = song;
    }

    int setCurrentTrack(int position)
    {
        track = position;
    }
    string play()
    {
        return songs[track - 1];
    }

   
};

int main()
{
    MusicPlaylist mp;
    mp.add("Shape of You");
    mp.add("That's What I Like");
    mp.add("Humble");
    mp.setCurrentTrack(1);
    cout << mp.play() << endl; // แสดงเพลงลำดับที่ 1 คือ Shape of You

   
  
}