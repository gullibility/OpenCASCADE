#include "stdafx.h"

#include "Sample2D_Image.h"

IMPLEMENT_STANDARD_HANDLE(Sample2D_Image,AIS_TexturedShape)
IMPLEMENT_STANDARD_RTTIEXT(Sample2D_Image,AIS_TexturedShape)

Sample2D_Image::Sample2D_Image(TCollection_AsciiString& aFileName,
                               const Quantity_Length X,
                               const Quantity_Length Y,
                               const Quantity_Factor aScale)
    :AIS_TexturedShape(TopoDS_Shape())
{
  myFilename = aFileName;
  myX = X;
  myY = Y;  
  myScale = aScale;
}
void Sample2D_Image::MakeShape()
{
  Handle(Graphic3d_Texture1D) anImageTexture = 
    new Graphic3d_Texture1Dsegment(myFilename);
  Standard_Real coeff = (Standard_Real)(anImageTexture->GetImage()->Height())/
    (anImageTexture->GetImage()->Width())*myScale;
  TopoDS_Edge E1 = BRepBuilderAPI_MakeEdge(gp_Pnt(myX,myY,0.), gp_Pnt(100*myScale+myX,myY,0.));
  TopoDS_Edge E2 = BRepBuilderAPI_MakeEdge(gp_Pnt(100*myScale+myX,myY,0.), gp_Pnt(100*myScale+myX,100*coeff+myY,0.));
  TopoDS_Edge E3 = BRepBuilderAPI_MakeEdge(gp_Pnt(100*myScale+myX,100*coeff+myY,0.), gp_Pnt(myX,100*coeff+myY,0.));
  TopoDS_Edge E4 = BRepBuilderAPI_MakeEdge(gp_Pnt(myX,100*coeff+myY,0.), gp_Pnt(myX,myY,0.));
  TopoDS_Wire anImageBounds = BRepBuilderAPI_MakeWire(E1,E2,E3,E4);
  myFace = BRepBuilderAPI_MakeFace(gp_Pln(gp_Pnt(0,0,0),gp_Dir(0,0,1)),anImageBounds);
}

void Sample2D_Image::SetContext(const Handle(AIS_InteractiveContext)& theContext) 
{
  if(theContext.IsNull() || theContext->CurrentViewer().IsNull()) return;
  AIS_InteractiveObject::SetContext(theContext);
  MakeShape();
  this->Set(TopoDS_Shape(myFace));
  this->SetTextureFileName(myFilename);

}



