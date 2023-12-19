



#ifndef Prism_HPP
#define Prism_HPP


#include "Mesh.hpp"
#include "SpatialInfo.hpp"



class Prism {
   
protected :
   Mesh mesh;
   
   SpatialInfo info;
   
   double w;
   double h;
   double d;
   
   unsigned int vtlf,vtrf,vbrf,vblf,vtrb,vbrb,vblb,vtlb;
   unsigned int nright,nleft,nfront,nback,ntop,nbottom;
   E tright,tleft,tfront,tback,ttop,tbottom;

   void CreateMesh();
   void CreateMesh() {
      mesh.ClearAll();
      
      /// 8 vertices
      vtrf = mesh.AddVertex(TopRightFront());
      vtlf = mesh.AddVertex(TopLeftFront());
      vblf = mesh.AddVertex(BotLeftFront());
      vbrf = mesh.AddVertex(BotRightFront());
      vtlb = mesh.AddVertex(TopLeftBack());
      vtrb = mesh.AddVertex(TopRightBack());
      vbrb = mesh.AddVertex(BotRightBack());
      vblb = mesh.AddVertex(BotLeftBack());

      /// 24 texture vertices
      /// Defer loading to another function
      
      /// 6 normals
      nright = AddNormal(Vec3(-1,0,0));
      nleft = AddNormal(Vec3(1,0,0));
      nfront = AddNormal(Vec3(0,1,0));
      nback = AddNormal(Vec3(0,-1,0));
      ntop = AddNormal(Vec3(0,0,-1));
      nbottom = AddNormal(Vec3(0,0,1);
      
      /// 12 edges
      
      /// right to left
      mesh.AddEdge(vtrf , vtlf);
      mesh.AddEdge(vtrb , vtlb);
      mesh.AddEdge(vbrf , vblf);
      mesh.AddEdge(vbrb , vblb);
      
      /// front to back
      mesh.AddEdge(vtrf , vtrb);
      mesh.AddEdge(vtlf , vtlb);
      mesh.AddEdge(vblf , vblb);
      mesh.AddEdge(vbrf , vbrb);
      
      /// top to bottom
      mesh.AddEdge(vtrf , vbrf);
      mesh.AddEdge(vtlf , vblf);
      mesh.AddEdge(vtrb , vbrb);
      mesh.AddEdge(vtlb , vblb);
   }

public :
   
   Prism();
   Prism(Vec3 center , double width , double height , double depth);
   
   TextureMesh(EagleImage* textures[NUM_FACE_DIRECTIONS]);
   TextureMesh(EagleImage* textures[NUM_FACE_DIRECTIONS]) {
      
   }
   
   inline double Width()  const {return w;}
   inline double Depth()  const {return d;}
   inline double Height() const {return h;}
   
   inline double LeftX()  const {return info.pos.x - w/2.0;}
   inline double RightX() const {return info.pos.x + w/2.0;}
   inline double BackY()  const {return info.pos.y + d/2.0;}
   inline double FrontY() const {return info.pos.y - d/2.0;}
   inline double TopZ()   const {return info.pos.z + h/2.0;}
   inline double BotZ()   const {return info.pos.z - h/2.0;}
   
   inline Vec3 TopLeftBack()   const {return Vec3(LeftX()  , BackY()  , TopZ() );}
   inline Vec3 TopLeftFront()  const {return Vec3(LeftX()  , FrontY() , TopZ() );}
   inline Vec3 TopRightBack()  const {return Vec3(RightX() , BackY()  , TopZ() );}
   inline Vec3 TopRightFront() const {return Vec3(RightX() , FrontY() , TopZ() );}
   inline Vec3 BotLeftBack()   const {return Vec3(LeftX()  , BackY()  , BotZ() );}
   inline Vec3 BotLeftFront()  const {return Vec3(LeftX()  , FrontY() , BotZ() );}
   inline Vec3 BotRightBack()  const {return Vec3(RightX() , BackY()  , BotZ() );}
   inline Vec3 BotRightFront() const {return Vec3(RightX() , FrontY() , BotZ() );}
   
   inline void SetCenter(Vec3 c) {info.pos = c;}
   inline void SetInfo(SpatialInfo i) {info = i;}
   
   inline Vec3 Center() const {return info.pos;}
   inline SpatialInfo Info() const {return info;}
   
   inline const Mesh& GetMesh() const {return unitcube.GetMesh();}
};




#endif // Prism_HPP
