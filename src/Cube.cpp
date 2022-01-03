



#include "Cube.hpp"
#include "Vec3D.hpp"
#include "Eagle/backends/Allegro5Backend.hpp"
#include "allegro5/allegro_opengl.h"


std::vector<float> MakeCubeInside(float radius) {
   static const float r = 0.5f;
   static const float cube_verts[NUM_FACE_DIRECTIONS][NUM_CORNERS][3] = {
      {{ r,-r, r},{-r,-r, r},{-r, r, r},{ r, r, r}},/// FACE_UP - ceiling - aligned with north up
      {{-r, r,-r},{ r, r,-r},{ r, r, r},{-r, r, r}},/// FACE_N - north - aligned with up
      {{ r, r,-r},{ r,-r,-r},{ r,-r, r},{ r, r, r}},/// FACE_E - east - aligned with up
      {{-r, r,-r},{ r, r,-r},{ r,-r,-r},{-r,-r,-r}},/// FACE_DN - floor - aligned with south up
      {{ r,-r,-r},{-r,-r,-r},{-r,-r, r},{ r,-r, r}},/// FACE_S - south - aligned with up
      {{-r,-r,-r},{-r, r,-r},{-r, r, r},{-r,-r, r}} /// FACE_W - west - aligned with up
   };
   const float* v = &cube_verts[0][0][0];
   std::vector<float> store;
   store.resize(72 , 0.0f);
   for (size_t i = 0 ; i < (NUM_FACE_DIRECTIONS*NUM_CORNERS*3) ; ++i) {
      store[i] = v[i]*radius;
   }
   return store;
}



const std::vector<float> unitcubeinside = MakeCubeInside(1.0f);



const float* GetInsideCubeFace(FACE_DIRECTION d) {
   return &(unitcubeinside[(int)d*(NUM_CORNERS*3)]);
}



#include "GL/gl.h"

void QueueInsideFaceTrianglesTex(FACE_DIRECTION d , Location loc , EagleColor col , EagleImage* tex) {
   const float* face = GetInsideCubeFace(d);
   const Vec3D center[NUM_CORNERS] = {
      Vec3D(face[0] , face[1]  , face[2])  + Vec3D(loc.x + 0.5f , loc.y + 0.5f , loc.z + 0.5f),
      Vec3D(face[3] , face[4]  , face[5])  + Vec3D(loc.x + 0.5f , loc.y + 0.5f , loc.z + 0.5f),
      Vec3D(face[6] , face[7]  , face[8])  + Vec3D(loc.x + 0.5f , loc.y + 0.5f , loc.z + 0.5f),
      Vec3D(face[9] , face[10] , face[11]) + Vec3D(loc.x + 0.5f , loc.y + 0.5f , loc.z + 0.5f)
   };
   GLuint tid = al_get_opengl_texture(GetAllegroBitmap(tex));
   glEnable(GL_TEXTURE_2D);
   glBindTexture(GL_TEXTURE_2D , tid);
   Vec3D n1 = GetNormal(center[0] , center[1] , center[2]);
   Vec3D n2 = GetNormal(center[2] , center[3] , center[0]);
//   glBindTexture(GL_TEXTURE_2D , al_ogl
   glColor4i(col.R() , col.G() , col.B() , col.A());
   glNormal3f(n1.x , n1.y , n1.z);
   /// bl,br,tr
   glTexCoord2f(0.0f,1.0f);
   glVertex3f(center[0].x , center[0].y , center[0].z);
   glTexCoord2f(1.0f,1.0f);
   glVertex3f(center[1].x , center[1].y , center[1].z);
   glTexCoord2f(1.0f,0.0f);
   glVertex3f(center[2].x , center[2].y , center[2].z);

   glNormal3f(n2.x , n2.y , n2.z);
   /// tr,tl,bl
   glTexCoord2f(1.0f,0.0f);
   glVertex3f(center[2].x , center[2].y , center[2].z);
   glTexCoord2f(0.0f,0.0f);
   glVertex3f(center[3].x , center[3].y , center[3].z);
   glTexCoord2f(0.0f,1.0f);
   glVertex3f(center[0].x , center[0].y , center[0].z);
}



//void QueueInsideFaceTrianglesTex(FACE_DIRECTION d , Location loc , EagleColor col , EagleImage* tex) {
//   
//}



void DrawCubeInsides(Location loc , EagleColor face_colors[NUM_FACE_DIRECTIONS] , EagleImage* face_textures[NUM_FACE_DIRECTIONS]) {
   QueueInsideFaceTrianglesTex(FACE_DN , loc , face_colors[FACE_DN] , face_textures[FACE_DN]);
   QueueInsideFaceTrianglesTex(FACE_S  , loc , face_colors[FACE_S ] , face_textures[FACE_S]);
   QueueInsideFaceTrianglesTex(FACE_W  , loc , face_colors[FACE_W ] , face_textures[FACE_W]);
   QueueInsideFaceTrianglesTex(FACE_UP , loc , face_colors[FACE_UP] , face_textures[FACE_UP]);
   QueueInsideFaceTrianglesTex(FACE_N  , loc , face_colors[FACE_N ] , face_textures[FACE_N]);
   QueueInsideFaceTrianglesTex(FACE_E  , loc , face_colors[FACE_E ] , face_textures[FACE_E]);
}




