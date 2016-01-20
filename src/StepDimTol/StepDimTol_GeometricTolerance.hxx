// Created on: 2003-06-04
// Created by: Galina KULIKOVA
// Copyright (c) 2003-2014 OPEN CASCADE SAS
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

#ifndef _StepDimTol_GeometricTolerance_HeaderFile
#define _StepDimTol_GeometricTolerance_HeaderFile

#include <Standard.hxx>
#include <Standard_Type.hxx>

#include <MMgt_TShared.hxx>
#include <StepDimTol_GeometricToleranceTarget.hxx>
class TCollection_HAsciiString;
class StepBasic_MeasureWithUnit;
class StepDimTol_GeometricToleranceTarget;
class StepRepr_ShapeAspect;


class StepDimTol_GeometricTolerance;
DEFINE_STANDARD_HANDLE(StepDimTol_GeometricTolerance, MMgt_TShared)

//! Representation of STEP entity GeometricTolerance
class StepDimTol_GeometricTolerance : public MMgt_TShared
{

public:

  
  //! Empty constructor
  Standard_EXPORT StepDimTol_GeometricTolerance();
  
  //! Initialize all fields (own and inherited) AP214
  Standard_EXPORT void Init (const Handle(TCollection_HAsciiString)& aName, const Handle(TCollection_HAsciiString)& aDescription, const Handle(StepBasic_MeasureWithUnit)& aMagnitude, const Handle(StepRepr_ShapeAspect)& aTolerancedShapeAspect);

    //! Initialize all fields (own and inherited) AP242
  Standard_EXPORT void Init (const Handle(TCollection_HAsciiString)& aName, const Handle(TCollection_HAsciiString)& aDescription, const Handle(StepBasic_MeasureWithUnit)& aMagnitude, const StepDimTol_GeometricToleranceTarget& aTolerancedShapeAspect);
  
  //! Returns field Name
  Standard_EXPORT Handle(TCollection_HAsciiString) Name() const;
  
  //! Set field Name
  Standard_EXPORT void SetName (const Handle(TCollection_HAsciiString)& Name);
  
  //! Returns field Description
  Standard_EXPORT Handle(TCollection_HAsciiString) Description() const;
  
  //! Set field Description
  Standard_EXPORT void SetDescription (const Handle(TCollection_HAsciiString)& Description);
  
  //! Returns field Magnitude
  Standard_EXPORT Handle(StepBasic_MeasureWithUnit) Magnitude() const;
  
  //! Set field Magnitude
  Standard_EXPORT void SetMagnitude (const Handle(StepBasic_MeasureWithUnit)& Magnitude);
  
  //! Returns field TolerancedShapeAspect
  //! Note: in AP214(203) type of this attribute can be only StepRepr_ShapeAspect
  Standard_EXPORT StepDimTol_GeometricToleranceTarget TolerancedShapeAspect() const;
  
  //! Set field TolerancedShapeAspect AP214
  Standard_EXPORT void SetTolerancedShapeAspect (const Handle(StepRepr_ShapeAspect)& TolerancedShapeAspect);

  //! Set field TolerancedShapeAspect AP242
  Standard_EXPORT void SetTolerancedShapeAspect (const StepDimTol_GeometricToleranceTarget& TolerancedShapeAspect);




  DEFINE_STANDARD_RTTI(StepDimTol_GeometricTolerance,MMgt_TShared)

protected:




private:


  Handle(TCollection_HAsciiString) theName;
  Handle(TCollection_HAsciiString) theDescription;
  Handle(StepBasic_MeasureWithUnit) theMagnitude;
  StepDimTol_GeometricToleranceTarget theTolerancedShapeAspect;


};







#endif // _StepDimTol_GeometricTolerance_HeaderFile
