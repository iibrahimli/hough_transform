#include <iostream>
#include <iomanip>
#include <vector>
#include <cstring>
#include "../include/bmp.hpp"
#include "../include/hough.hpp"

using namespace std;

int main(int argc, char *argv[]){

    BMP_image img{800, 600, BLACK};

    for(float k = -1; k < 1; k += 0.0001) img.draw_line(k, 100, pixel((k+1)*127/2, (k+1)/2*255, 100));
    for(float k = -1; k < 1; k += 0.0001) img.draw_line(k, 500, pixel(200+(k+1)*50/2, 100, (k+1)/2*255));
    for(float k = -1; k < 1; k += 0.0001) img.draw_line(k, 300, pixel((k+1)*255/2, (k+1)/2*127, 100));

    img.save_as("lines.bmp");

    return 0;
}