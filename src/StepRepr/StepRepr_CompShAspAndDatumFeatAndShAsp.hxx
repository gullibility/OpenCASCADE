// Created on: 2015-08-11
// Created by: Irina KRYLOVA
// Copyright (c) 2015 OPEN CASCADE SAS
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

#ifndef _StepRepr_CompShAspAndDatumFeatAndShAsp_HeaderFile
#define _StepRepr_CompShAspAndDatumFeatAndShAsp_HeaderFile

#include <Standard.hxx>
#include <Standard_Type.hxx>

#include <StepRepr_ShapeAspect.hxx>

class StepRepr_CompShAspAndDatumFeatAndShAsp;
DEFINE_STANDARD_HANDLE(StepRepr_CompShAspAndDatumFeatAndShAsp, StepRepr_ShapeAspect)
//! Added for Dimensional Tolerances
class StepRepr_CompShAspAndDatumFeatAndShAsp : public StepRepr_ShapeAspect
{

public:
  
  Standard_EXPORT StepRepr_CompShAspAndDatumFeatAndShAsp();
  
  DEFINE_STANDARD_RTTI(StepRepr_CompShAspAndDatumFeatAndShAsp, StepRepr_ShapeAspect)
};
#endif // _StepRepr_CompShAspAndDatumFeatAndShAsp_HeaderFile
