#include <iostream>
#include <iomanip>
#include <vector>
#include <cstring>
#include "../include/bmp.hpp"
#include "../include/hough.hpp"

using namespace std;

int main(int argc, char *argv[]){

    BMP_image img{800, 600, BLACK};


    img.save_as("lines.bmp");

    return 0;
}