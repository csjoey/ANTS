#include "Pixelmap.hpp"
Pixelmap::Pixelmap(int width, int height, int pixelsize,void* setbg){
    this->width = width;
    this->height = height;
    // Allocate pixel array
    this->pixeldata = malloc(width*height*pixelsize);
    this->pixelsize = pixelsize;
    // Allocate bg color
    this->bgcolor = malloc(pixelsize);
    // Check if bg should be set
    if(setbg == NULL){
        return;
    }else{
        memcpy(this->bgcolor,setbg,pixelsize);
    }
    // Set pixelmap to bg color
    for(int index = 0; index < width * height; index++){
        memcpy(this->pixeldata+(index*pixelsize),setbg,pixelsize);
    }
}
Pixelmap::~Pixelmap(){
    free(this->pixeldata);
    free(this->bgcolor);
}

void Pixelmap::setPixel(int x, int y, void* colorVal){
    y = this->height - y;
    memcpy(this->pixeldata + this->pixelsize * (x + (this->width * y)),colorVal,this->pixelsize);
}