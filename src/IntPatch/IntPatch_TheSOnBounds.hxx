// Created on: 1992-05-06
// Created by: Jacques GOUSSARD
// Copyright (c) 1992-1999 Matra Datavision
// Copyright (c) 1999-2014 OPEN CASCADE SAS
//
// This file is part of Open CASCADE Technology software library.
//
// This library is free software; you can redistribute it and/or modify it under
// the terms of the GNU Lesser General Public License version 2.1 as published
// by the Free Software Foundation, with special exception defined in the file
// OCCT_LGPL_EXCEPTION.txt. Consult the file LICENSE_LGPL_21.txt included in OCCT
// distribution for complete text of the license and disclaimer of any warranty.
//
// Alternatively, this file may be used under the terms of Open CASCADE
// commercial license or contractual agreement.

#ifndef _IntPatch_TheSOnBounds_HeaderFile
#define _IntPatch_TheSOnBounds_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <Standard_Boolean.hxx>
#include <IntPatch_SequenceOfSegmentOfTheSOnBounds.hxx>
#include <IntPatch_SequenceOfPathPointOfTheSOnBounds.hxx>
#include <Standard_Real.hxx>
#include <Standard_Integer.hxx>
class StdFail_NotDone;
class Standard_OutOfRange;
class Standard_ConstructionError;
class Adaptor3d_HVertex;
class Adaptor2d_HCurve2d;
class IntPatch_HCurve2dTool;
class IntPatch_HInterTool;
class Adaptor3d_TopolTool;
class IntPatch_ArcFunction;
class IntPatch_ThePathPointOfTheSOnBounds;
class IntPatch_SequenceOfPathPointOfTheSOnBounds;
class IntPatch_SequenceNodeOfSequenceOfPathPointOfTheSOnBounds;
class IntPatch_TheSegmentOfTheSOnBounds;
class IntPatch_SequenceOfSegmentOfTheSOnBounds;
class IntPatch_SequenceNodeOfSequenceOfSegmentOfTheSOnBounds;



class IntPatch_TheSOnBounds 
{
public:

  DEFINE_STANDARD_ALLOC

  
  Standard_EXPORT IntPatch_TheSOnBounds();
  
  Standard_EXPORT void Perform (IntPatch_ArcFunction& F, const Handle(Adaptor3d_TopolTool)& Domain, const Standard_Real TolBoundary, const Standard_Real TolTangency, const Standard_Boolean RecheckOnRegularity = Standard_False);
  
    Standard_Boolean IsDone() const;
  
    Standard_Boolean AllArcSolution() const;
  
    Standard_Integer NbPoints() const;
  
    const IntPatch_ThePathPointOfTheSOnBounds& Point (const Standard_Integer Index) const;
  
    Standard_Integer NbSegments() const;
  
    const IntPatch_TheSegmentOfTheSOnBounds& Segment (const Standard_Integer Index) const;




protected:





private:



  Standard_Boolean done;
  Standard_Boolean all;
  IntPatch_SequenceOfSegmentOfTheSOnBounds sseg;
  IntPatch_SequenceOfPathPointOfTheSOnBounds spnt;


};

#define TheVertex Handle(Adaptor3d_HVertex)
#define TheVertex_hxx <Adaptor3d_HVertex.hxx>
#define TheArc Handle(Adaptor2d_HCurve2d)
#define TheArc_hxx <Adaptor2d_HCurve2d.hxx>
#define TheArcTool IntPatch_HCurve2dTool
#define TheArcTool_hxx <IntPatch_HCurve2dTool.hxx>
#define TheSOBTool IntPatch_HInterTool
#define TheSOBTool_hxx <IntPatch_HInterTool.hxx>
#define Handle_TheTopolTool Handle(Adaptor3d_TopolTool)
#define TheTopolTool Adaptor3d_TopolTool
#define TheTopolTool_hxx <Adaptor3d_TopolTool.hxx>
#define TheFunction IntPatch_ArcFunction
#define TheFunction_hxx <IntPatch_ArcFunction.hxx>
#define IntStart_ThePathPoint IntPatch_ThePathPointOfTheSOnBounds
#define IntStart_ThePathPoint_hxx <IntPatch_ThePathPointOfTheSOnBounds.hxx>
#define IntStart_SequenceOfPathPoint IntPatch_SequenceOfPathPointOfTheSOnBounds
#define IntStart_SequenceOfPathPoint_hxx <IntPatch_SequenceOfPathPointOfTheSOnBounds.hxx>
#define IntStart_SequenceNodeOfSequenceOfPathPoint IntPatch_SequenceNodeOfSequenceOfPathPointOfTheSOnBounds
#define IntStart_SequenceNodeOfSequenceOfPathPoint_hxx <IntPatch_SequenceNodeOfSequenceOfPathPointOfTheSOnBounds.hxx>
#define IntStart_SequenceNodeOfSequenceOfPathPoint IntPatch_SequenceNodeOfSequenceOfPathPointOfTheSOnBounds
#define IntStart_SequenceNodeOfSequenceOfPathPoint_hxx <IntPatch_SequenceNodeOfSequenceOfPathPointOfTheSOnBounds.hxx>
#define IntStart_TheSegment IntPatch_TheSegmentOfTheSOnBounds
#define IntStart_TheSegment_hxx <IntPatch_TheSegmentOfTheSOnBounds.hxx>
#define IntStart_SequenceOfSegment IntPatch_SequenceOfSegmentOfTheSOnBounds
#define IntStart_SequenceOfSegment_hxx <IntPatch_SequenceOfSegmentOfTheSOnBounds.hxx>
#define IntStart_SequenceNodeOfSequenceOfSegment IntPatch_SequenceNodeOfSequenceOfSegmentOfTheSOnBounds
#define IntStart_SequenceNodeOfSequenceOfSegment_hxx <IntPatch_SequenceNodeOfSequenceOfSegmentOfTheSOnBounds.hxx>
#define IntStart_SequenceNodeOfSequenceOfSegment IntPatch_SequenceNodeOfSequenceOfSegmentOfTheSOnBounds
#define IntStart_SequenceNodeOfSequenceOfSegment_hxx <IntPatch_SequenceNodeOfSequenceOfSegmentOfTheSOnBounds.hxx>
#define Handle_IntStart_SequenceNodeOfSequenceOfPathPoint Handle(IntPatch_SequenceNodeOfSequenceOfPathPointOfTheSOnBounds)
#define Handle_IntStart_SequenceNodeOfSequenceOfPathPoint Handle(IntPatch_SequenceNodeOfSequenceOfPathPointOfTheSOnBounds)
#define Handle_IntStart_SequenceNodeOfSequenceOfSegment Handle(IntPatch_SequenceNodeOfSequenceOfSegmentOfTheSOnBounds)
#define Handle_IntStart_SequenceNodeOfSequenceOfSegment Handle(IntPatch_SequenceNodeOfSequenceOfSegmentOfTheSOnBounds)
#define IntStart_SearchOnBoundaries IntPatch_TheSOnBounds
#define IntStart_SearchOnBoundaries_hxx <IntPatch_TheSOnBounds.hxx>

#include <IntStart_SearchOnBoundaries.lxx>

#undef TheVertex
#undef TheVertex_hxx
#undef TheArc
#undef TheArc_hxx
#undef TheArcTool
#undef TheArcTool_hxx
#undef TheSOBTool
#undef TheSOBTool_hxx
#undef Handle_TheTopolTool
#undef TheTopolTool
#undef TheTopolTool_hxx
#undef TheFunction
#undef TheFunction_hxx
#undef IntStart_ThePathPoint
#undef IntStart_ThePathPoint_hxx
#undef IntStart_SequenceOfPathPoint
#undef IntStart_SequenceOfPathPoint_hxx
#undef IntStart_SequenceNodeOfSequenceOfPathPoint
#undef IntStart_SequenceNodeOfSequenceOfPathPoint_hxx
#undef IntStart_SequenceNodeOfSequenceOfPathPoint
#undef IntStart_SequenceNodeOfSequenceOfPathPoint_hxx
#undef IntStart_TheSegment
#undef IntStart_TheSegment_hxx
#undef IntStart_SequenceOfSegment
#undef IntStart_SequenceOfSegment_hxx
#undef IntStart_SequenceNodeOfSequenceOfSegment
#undef IntStart_SequenceNodeOfSequenceOfSegment_hxx
#undef IntStart_SequenceNodeOfSequenceOfSegment
#undef IntStart_SequenceNodeOfSequenceOfSegment_hxx
#undef Handle_IntStart_SequenceNodeOfSequenceOfPathPoint
#undef Handle_IntStart_SequenceNodeOfSequenceOfPathPoint
#undef Handle_IntStart_SequenceNodeOfSequenceOfSegment
#undef Handle_IntStart_SequenceNodeOfSequenceOfSegment
#undef IntStart_SearchOnBoundaries
#undef IntStart_SearchOnBoundaries_hxx




#endif // _IntPatch_TheSOnBounds_HeaderFile
