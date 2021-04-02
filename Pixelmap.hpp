#include <cstdlib>
#include <cstring>
class Pixelmap{
    public:
    Pixelmap(int width,int height,int pixelsize, void * setbg = NULL);
    ~Pixelmap();
    void * pixeldata;
    int pixelsize;


    private:


};