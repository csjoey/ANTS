#include "Pixelmap.hpp"
Pixelmap::Pixelmap(int width, int height, int pixelsize,void* setbg){
    this->pixeldata = malloc(width*height*pixelsize);
    this->pixelsize = pixelsize;
    if(setbg == NULL){
        return;
    }
    for(int index = 0; index < width * height; index++){
        memcpy(this->pixeldata+(index*pixelsize),setbg,pixelsize);
    }
}
Pixelmap::~Pixelmap(){
    free(this->pixeldata);
}