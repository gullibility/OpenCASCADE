// Created on: 1999-11-26
// Created by: Andrey BETENEV
// Copyright (c) 1999 Matra Datavision
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

#ifndef _StepBasic_ActionRequestSolution_HeaderFile
#define _StepBasic_ActionRequestSolution_HeaderFile

#include <Standard.hxx>
#include <Standard_Type.hxx>

#include <MMgt_TShared.hxx>
class StepBasic_ActionMethod;
class StepBasic_VersionedActionRequest;


class StepBasic_ActionRequestSolution;
DEFINE_STANDARD_HANDLE(StepBasic_ActionRequestSolution, MMgt_TShared)

//! Representation of STEP entity ActionRequestSolution
class StepBasic_ActionRequestSolution : public MMgt_TShared
{

public:

  
  //! Empty constructor
  Standard_EXPORT StepBasic_ActionRequestSolution();
  
  //! Initialize all fields (own and inherited)
  Standard_EXPORT void Init (const Handle(StepBasic_ActionMethod)& aMethod, const Handle(StepBasic_VersionedActionRequest)& aRequest);
  
  //! Returns field Method
  Standard_EXPORT Handle(StepBasic_ActionMethod) Method() const;
  
  //! Set field Method
  Standard_EXPORT void SetMethod (const Handle(StepBasic_ActionMethod)& Method);
  
  //! Returns field Request
  Standard_EXPORT Handle(StepBasic_VersionedActionRequest) Request() const;
  
  //! Set field Request
  Standard_EXPORT void SetRequest (const Handle(StepBasic_VersionedActionRequest)& Request);




  DEFINE_STANDARD_RTTI(StepBasic_ActionRequestSolution,MMgt_TShared)

protected:




private:


  Handle(StepBasic_ActionMethod) theMethod;
  Handle(StepBasic_VersionedActionRequest) theRequest;


};







#endif // _StepBasic_ActionRequestSolution_HeaderFile
