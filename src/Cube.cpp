



#include "Cube.hpp"



std::vector<float> MakeCubeInside(float radius) {
   static const float r = 0.5f;
   static const float[NUM_FACE_DIRECTIONS][NUM_CORNERS][3] cube_verts = {
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



void QueueInsideFaceTriangles(FACE_DIRECTION d , Location loc , EagleColor col) {
   const float* face = GetInsideCubeFace(d);
   const Vec3D center[NUM_CORNERS] = {
      Vec3D(face[0] , face[1] , face[2]) + Vec3D(loc.x + 0.5f , loc.y + 0.5f , loc.z + 0.5f),
      Vec3D(face[3] , face[4] , face[5]) + Vec3D(loc.x + 0.5f , loc.y + 0.5f , loc.z + 0.5f),
      Vec3D(face[6] , face[7] , face[8]) + Vec3D(loc.x + 0.5f , loc.y + 0.5f , loc.z + 0.5f),
      Vec3D(face[9] , face[10] , face[11])
   };

   Vec3D n1 = GetNormal(center[0] , center[1] , center[2]);
   Vec3D n2 = GetNormal(center[2] , center[3] , center[0]);
   
   glColor4i(col.R() , col.G() , col.B() , col.A());
   glNormal3f(n1.x , n1.y , n1.z);
   glVertex3f(center[0].x , center[0].y , center[0].z);
   glVertex3f(center[1].x , center[1].y , center[1].z);
   glVertex3f(center[2].x , center[2].y , center[2].z);

   glNormal3f(n2.x , n2.y , n2.z);
   glVertex3f(center[2].x , center[2].y , center[2].z);
   glVertex3f(center[3].x , center[3].y , center[3].z);
   glVertex3f(center[0].x , center[0].y , center[0].z);
}







