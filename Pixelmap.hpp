#include <cstdlib>
#include <cstring>
class Pixelmap{
    public:
    // Methods
    Pixelmap(int width,int height,int pixelsize, void * setbg = NULL);
    ~Pixelmap();

    void setPixel(int xCord, int yCord, void * colorVal);
    void movePixNorth(int x,int y);
    void movePixNorthEast(int x,int y);
    void movePixEast(int x,int y);
    void movePixSouthEast(int x,int y);
    void movePixSouth(int x,int y);
    void movePixSouthWest(int x,int y);
    void movePixWest(int x,int y);
    void movePixNorthWest(int x,int y);





    // Variables
    int width;
    int height;

    void * bgcolor;
    void * pixeldata;
    int pixelsize;


    private:


};