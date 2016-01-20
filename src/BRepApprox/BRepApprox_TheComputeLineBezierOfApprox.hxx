// Created on: 1995-06-06
// Created by: Jean Yves LEBEY
// Copyright (c) 1995-1999 Matra Datavision
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

#ifndef _BRepApprox_TheComputeLineBezierOfApprox_HeaderFile
#define _BRepApprox_TheComputeLineBezierOfApprox_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <AppParCurves_SequenceOfMultiCurve.hxx>
#include <AppParCurves_MultiCurve.hxx>
#include <AppParCurves_MultiBSpCurve.hxx>
#include <Standard_Boolean.hxx>
#include <Approx_ParametrizationType.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <Approx_SequenceOfHArray1OfReal.hxx>
#include <TColStd_SequenceOfReal.hxx>
#include <AppParCurves_HArray1OfConstraintCouple.hxx>
#include <Standard_Integer.hxx>
#include <Standard_Real.hxx>
#include <AppParCurves_Constraint.hxx>
#include <math_Vector.hxx>
#include <TColStd_Array1OfReal.hxx>
class BRepApprox_TheMultiLineOfApprox;
class BRepApprox_TheMultiLineToolOfApprox;
class BRepApprox_MyGradientOfTheComputeLineBezierOfApprox;
class BRepApprox_ParLeastSquareOfMyGradientOfTheComputeLineBezierOfApprox;
class BRepApprox_ResConstraintOfMyGradientOfTheComputeLineBezierOfApprox;
class BRepApprox_ParFunctionOfMyGradientOfTheComputeLineBezierOfApprox;
class BRepApprox_Gradient_BFGSOfMyGradientOfTheComputeLineBezierOfApprox;
class AppParCurves_MultiCurve;
class AppParCurves_MultiBSpCurve;



class BRepApprox_TheComputeLineBezierOfApprox 
{
public:

  DEFINE_STANDARD_ALLOC

  
  Standard_EXPORT BRepApprox_TheComputeLineBezierOfApprox(const BRepApprox_TheMultiLineOfApprox& Line, const Standard_Integer degreemin = 4, const Standard_Integer degreemax = 8, const Standard_Real Tolerance3d = 1.0e-3, const Standard_Real Tolerance2d = 1.0e-6, const Standard_Integer NbIterations = 5, const Standard_Boolean cutting = Standard_True, const Approx_ParametrizationType parametrization = Approx_ChordLength, const Standard_Boolean Squares = Standard_False);
  
  Standard_EXPORT BRepApprox_TheComputeLineBezierOfApprox(const BRepApprox_TheMultiLineOfApprox& Line, const math_Vector& Parameters, const Standard_Integer degreemin = 4, const Standard_Integer degreemax = 8, const Standard_Real Tolerance3d = 1.0e-03, const Standard_Real Tolerance2d = 1.0e-06, const Standard_Integer NbIterations = 5, const Standard_Boolean cutting = Standard_True, const Standard_Boolean Squares = Standard_False);
  
  Standard_EXPORT BRepApprox_TheComputeLineBezierOfApprox(const math_Vector& Parameters, const Standard_Integer degreemin = 4, const Standard_Integer degreemax = 8, const Standard_Real Tolerance3d = 1.0e-03, const Standard_Real Tolerance2d = 1.0e-06, const Standard_Integer NbIterations = 5, const Standard_Boolean cutting = Standard_True, const Standard_Boolean Squares = Standard_False);
  
  Standard_EXPORT BRepApprox_TheComputeLineBezierOfApprox(const Standard_Integer degreemin = 4, const Standard_Integer degreemax = 8, const Standard_Real Tolerance3d = 1.0e-03, const Standard_Real Tolerance2d = 1.0e-06, const Standard_Integer NbIterations = 5, const Standard_Boolean cutting = Standard_True, const Approx_ParametrizationType parametrization = Approx_ChordLength, const Standard_Boolean Squares = Standard_False);
  
  Standard_EXPORT void Init (const Standard_Integer degreemin = 4, const Standard_Integer degreemax = 8, const Standard_Real Tolerance3d = 1.0e-03, const Standard_Real Tolerance2d = 1.0e-06, const Standard_Integer NbIterations = 5, const Standard_Boolean cutting = Standard_True, const Approx_ParametrizationType parametrization = Approx_ChordLength, const Standard_Boolean Squares = Standard_False);
  
  Standard_EXPORT void Perform (const BRepApprox_TheMultiLineOfApprox& Line);
  
  Standard_EXPORT void SetDegrees (const Standard_Integer degreemin, const Standard_Integer degreemax);
  
  Standard_EXPORT void SetTolerances (const Standard_Real Tolerance3d, const Standard_Real Tolerance2d);
  
  Standard_EXPORT void SetConstraints (const AppParCurves_Constraint firstC, const AppParCurves_Constraint lastC);
  
  Standard_EXPORT Standard_Boolean IsAllApproximated() const;
  
  Standard_EXPORT Standard_Boolean IsToleranceReached() const;
  
  Standard_EXPORT void Error (const Standard_Integer Index, Standard_Real& tol3d, Standard_Real& tol2d) const;
  
  Standard_EXPORT Standard_Integer NbMultiCurves() const;
  
  Standard_EXPORT const AppParCurves_MultiCurve& Value (const Standard_Integer Index = 1) const;
  
  Standard_EXPORT AppParCurves_MultiCurve& ChangeValue (const Standard_Integer Index = 1);
  
  Standard_EXPORT const AppParCurves_MultiBSpCurve& SplineValue();
  
  Standard_EXPORT void Parametrization (Approx_ParametrizationType& partype) const;
  
  Standard_EXPORT const TColStd_Array1OfReal& Parameters (const Standard_Integer Index = 1) const;




protected:





private:

  
  Standard_EXPORT Standard_Boolean Compute (const BRepApprox_TheMultiLineOfApprox& Line, const Standard_Integer fpt, const Standard_Integer lpt, math_Vector& Para, Standard_Real& TheTol3d, Standard_Real& TheTol2d);
  
  Standard_EXPORT Standard_Boolean ComputeCurve (const BRepApprox_TheMultiLineOfApprox& Line, const Standard_Integer firspt, const Standard_Integer lastpt);
  
  Standard_EXPORT void Parameters (const BRepApprox_TheMultiLineOfApprox& Line, const Standard_Integer firstP, const Standard_Integer LastP, math_Vector& TheParameters) const;
  
  Standard_EXPORT Standard_Real SearchFirstLambda (const BRepApprox_TheMultiLineOfApprox& Line, const math_Vector& Para, const math_Vector& V, const Standard_Integer index) const;
  
  Standard_EXPORT Standard_Real SearchLastLambda (const BRepApprox_TheMultiLineOfApprox& Line, const math_Vector& Para, const math_Vector& V, const Standard_Integer index) const;
  
  Standard_EXPORT void FirstTangencyVector (const BRepApprox_TheMultiLineOfApprox& Line, const Standard_Integer index, math_Vector& V) const;
  
  Standard_EXPORT void LastTangencyVector (const BRepApprox_TheMultiLineOfApprox& Line, const Standard_Integer index, math_Vector& V) const;


  AppParCurves_SequenceOfMultiCurve myMultiCurves;
  AppParCurves_MultiCurve TheMultiCurve;
  AppParCurves_MultiBSpCurve myspline;
  Standard_Boolean alldone;
  Standard_Boolean tolreached;
  Approx_ParametrizationType Par;
  Handle(TColStd_HArray1OfReal) myParameters;
  Handle(TColStd_HArray1OfReal) myfirstParam;
  Approx_SequenceOfHArray1OfReal myPar;
  TColStd_SequenceOfReal Tolers3d;
  TColStd_SequenceOfReal Tolers2d;
  Handle(AppParCurves_HArray1OfConstraintCouple) myConstraints;
  Standard_Integer mydegremin;
  Standard_Integer mydegremax;
  Standard_Real mytol3d;
  Standard_Real mytol2d;
  Standard_Real currenttol3d;
  Standard_Real currenttol2d;
  Standard_Boolean mycut;
  Standard_Boolean mysquares;
  Standard_Integer myitermax;
  AppParCurves_Constraint myfirstC;
  AppParCurves_Constraint mylastC;
  Standard_Integer myMultiLineNb;
  Standard_Boolean myIsClear;


};







#endif // _BRepApprox_TheComputeLineBezierOfApprox_HeaderFile
