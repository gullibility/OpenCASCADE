// Created on: 2000-07-03
// Created by: Andrey BETENEV
// Copyright (c) 2000-2014 OPEN CASCADE SAS
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

#ifndef _StepRepr_NextAssemblyUsageOccurrence_HeaderFile
#define _StepRepr_NextAssemblyUsageOccurrence_HeaderFile

#include <Standard.hxx>
#include <Standard_Type.hxx>

#include <StepRepr_AssemblyComponentUsage.hxx>


class StepRepr_NextAssemblyUsageOccurrence;
DEFINE_STANDARD_HANDLE(StepRepr_NextAssemblyUsageOccurrence, StepRepr_AssemblyComponentUsage)

//! Representation of STEP entity NextAssemblyUsageOccurrence
class StepRepr_NextAssemblyUsageOccurrence : public StepRepr_AssemblyComponentUsage
{

public:

  
  //! Empty constructor
  Standard_EXPORT StepRepr_NextAssemblyUsageOccurrence();




  DEFINE_STANDARD_RTTI(StepRepr_NextAssemblyUsageOccurrence,StepRepr_AssemblyComponentUsage)

protected:




private:




};







#endif // _StepRepr_NextAssemblyUsageOccurrence_HeaderFile
