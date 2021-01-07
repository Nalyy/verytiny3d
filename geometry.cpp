#include "geometry.h"


void line(int x0, int y0, int x1, int y1, TGAImage &image, const TGAColor &color){
  bool steep = false;
  int dx = x1 - x0;
  int dy = y1 - y0;

  if (std::abs(dx) < std::abs(dy)){
    std::swap(x0, y0);
    std::swap(x1, y1);
    steep = true;
  }

  // Always draw the line left to right
  if (x0 > x1) {
    std::swap(x0, x1);
    std::swap(y0, y1);
  }

  dx = x1 - x0;
  dy = y1 - y0;

  int derror3 = 2*std::abs(dy);
  int error3 = 0;

  int y = y0;

  for (int x=x0; x <= x1; x++){
      if (steep)
        image.set(y, x, color);
      else
        image.set(x, y, color);

      error3 += derror3;
      if (error3 > dx){
        y+= (dy>0? 1: -1);
        error3 -= 2*dx;
      }
    }// end of for loop

}
