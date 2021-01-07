#include "tgaimage.h"
#include "geometry.h"

constexpr int width = 100;
constexpr int height = 100;

const TGAColor white = { 255, 255, 255, 255 };

int main(){
  TGAImage image(width, height, TGAImage::RGB);
  image.set(30, 30, white); // dessine un gentil petit pixel blanc
  line(13, 20, 80, 40, image, white); // dessine une ligne
  image.write_tga_file("framebuffer.tga");
  return 0;
}
