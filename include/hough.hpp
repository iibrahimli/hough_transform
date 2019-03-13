#ifndef __HOUGH_HPP
#define __HOUGH_HPP

#include <vector>
#include "bmp.hpp"

#define PI             3.1415f
#define VOTE_THRESHOLD 0.9
#define EDGE_THRESHOLD 150


// basic Hough transform class
class hough_transform{

    hough_transform() = delete;


    hough_transform(const BMP_image& img, int r_nsteps, int theta_nsteps)
    : _img(img), _r_nsteps(r_nsteps), _theta_nsteps(theta_nsteps)
    {
        _accumulator = new int[sizeof *_accumulator * _r_nsteps * _theta_nsteps];
    }


    ~hough_transform(){
        delete[] _accumulator;
    }


    std::vector<std::pair<float, float>> get_lines(){

        for(int i = 0; i<_img.info_h.width; ++i){
            for(int j = 0; j < _img.info_h.height; ++j){
                if(_img.ploc(i, j).r > EDGE_THRESHOLD ||
                   _img.ploc(i, j).g > EDGE_THRESHOLD ||
                   _img.ploc(i, j).b > EDGE_THRESHOLD)
                    for(float th = -PI/2; th < PI/2; th += PI/_theta_nsteps){
                        
                    }
            }
        }

        return _lines;
    }


private:

    const BMP_image&                     _img;
    int                                  _r_nsteps;
    int                                  _theta_nsteps;
    float                                  _vote_th;
    std::vector<std::pair<float, float>> _lines;
    int                                 *_accumulator;


    // easy accumulator access. _accloc(r, theta) = theta'th cell on r'th row
    //     theta
    //     ______
    //    |  |  |
    // r  _______
    //    |  |  |
    //    -------
    inline int& _accloc(int r, int theta){
        return _accumulator[r*_theta_nsteps + theta];
    }

};


#endif