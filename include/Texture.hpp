



#ifndef Texture_HPP
#define Texture_HPP



#include "Vec2.hpp"


class EagleImage;

class TextureVertex {
public :
   EagleImage* tex;
   
   Vec2 uv;///double u,v;

///   TextureVertex(ALLEGRO_BITMAP* tex , Vec2 tuv);
   TextureVertex(EagleImage* texture , Vec2 tuv) :
         tex(texture),
         uv(tuv)
   {}

   
   
   
};

typedef TextureVertex TEXTEX;




#endif // Texture_HPP
