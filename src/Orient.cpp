



#include "Orient.hpp"



const Vec3 UP(0,0,1);
const Vec3 RIGHT(1,0,0);
const Vec3 FORWARD(0,1,0);



Orient::Orient() : 
      theta(0,0,0),
      fw(FORWARD),
      rt(RIGHT),
      up(UP) 
{
} 



Orient::Orient(Vec3 angles) : 
      theta(),
      fw(FORWARD),
      rt(RIGHT),
      up(UP) 
{
   SetTheta(angles);
}



Orient::Orient(float yaw , float pitch , float roll) : 
      theta(Vec3(yaw,pitch,roll)),
      fw(FORWARD),
      rt(RIGHT),
      up(UP) 
{
   SetTheta(theta);
}



Orient::Orient(Vec3 forwardvec , Vec3 upvec) :
      theta(),
      fw(),
      rt(),
      up()
{
   fw = forwardvec;
   up = upvec;
   rt = CrossProduct(up , fw);
   up = CrossProduct(rt , fw);
   theta = CalcTheta(*this);
}



void Orient::CalcAxes() {

   Vec3 f = FORWARD;
   Vec3 r = RIGHT;
   Vec3 u = UP;

   /// Yaw rotates around the y axis pointing up
   
   f = Rotate3D(f , u , theta.yaw);
   r = Rotate3D(r , u , theta.yaw);
   
   /// Pitch rotates around the x axis pointing right
   
   f = Rotate3D(f , r , theta.pitch);
   u = Rotate3D(u , r , theta.pitch);
   
   /// Roll rotates around the z axis pointing forward
   
   r = Rotate3D(r , f , theta.roll);
   u = Rotate3D(u , f , theta.roll);
   
   fw = f;
   rt = r;
   up = u;
}



void Orient::Turn(Vec3 omega , double dt) {
   theta += omega*dt;
   CalcAxes();
}



void Orient::TurnLocal(Vec3 omega , double dt) {
   *this = LocalTurn(*this , omega , dt);
}



Orient LocalTurn(const Orient& o , Vec3 omega , double dt) {
   
   Vec3 theta = omega*dt;
   
   Orient o2 = o;
   Vec3& f = o2.fw;
   Vec3& r = o2.rt;
   Vec3& u = o2.up;

   /// Yaw rotates around the y axis pointing up
   
   f = Rotate3D(f , u , theta.yaw);
   r = Rotate3D(r , u , theta.yaw);
   
   /// Pitch rotates around the x axis pointing right
   
   f = Rotate3D(f , r , theta.pitch);
   u = Rotate3D(u , r , theta.pitch);
   
   /// Roll rotates around the z axis pointing forward
   
   r = Rotate3D(r , f , theta.roll);
   u = Rotate3D(u , f , theta.roll);

   o2.theta = CalcTheta(o);
   
   return o2;
}



Orient Orient::operator-(const Orient& o) {
   Orient orient;
   orient.SetTheta(this->theta - o.theta);
   return orient;
}



Vec3 CalcTheta(const Orient& o) {
   
   const Vec3& fw = o.fw;
///   const Vec3& rt = o.rt;
   const Vec3& up = o.up;
   
   double yaw = atan2(fw.y , fw.x);
   double pitch = atan2(fw.z , sqrt(fw.x*fw.x + fw.y*fw.y));
   
   Vec3 f = FORWARD;
   Vec3 r = RIGHT;
   Vec3 u = UP;

   /// Yaw rotates around the z axis pointing up
   
   f = Rotate3D(f , u , yaw);
   r = Rotate3D(r , u , yaw);
   
   /// Pitch rotates around the x axis pointing right
   
   f = Rotate3D(f , r , pitch);
   u = Rotate3D(u , r , pitch);
   
   /// We now have to calculate roll, this *should* be the angle between r and r2 or u and u2 - should be the same
   
//   Vec3 f2 = fw;
//   Vec3 r2 = rt;
   Vec3 u2 = up;

   double roll = atan2(DotProduct(u2 , r) , DotProduct(u2 , u));
   
   return Vec3(yaw,pitch,roll);
}



