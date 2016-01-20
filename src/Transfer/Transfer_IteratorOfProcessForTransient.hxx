// Created on: 1992-02-03
// Created by: Christian CAILLET
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

#ifndef _Transfer_IteratorOfProcessForTransient_HeaderFile
#define _Transfer_IteratorOfProcessForTransient_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <TColStd_HSequenceOfTransient.hxx>
#include <Transfer_TransferIterator.hxx>
#include <TColStd_MapTransientHasher.hxx>
#include <Standard_Boolean.hxx>
class Standard_NoSuchObject;
class Standard_Transient;
class Transfer_ProcessForTransient;
class Transfer_TransferMapOfProcessForTransient;
class Transfer_IndexedDataMapNodeOfTransferMapOfProcessForTransient;
class Transfer_ActorOfProcessForTransient;
class Transfer_Binder;



class Transfer_IteratorOfProcessForTransient  : public Transfer_TransferIterator
{
public:

  DEFINE_STANDARD_ALLOC

  
  Standard_EXPORT Transfer_IteratorOfProcessForTransient(const Standard_Boolean withstarts);
  
  Standard_EXPORT void Add (const Handle(Transfer_Binder)& binder);
  
  Standard_EXPORT void Add (const Handle(Transfer_Binder)& binder, const Handle(Standard_Transient)& start);
  
  Standard_EXPORT void Filter (const Handle(TColStd_HSequenceOfTransient)& list, const Standard_Boolean keep = Standard_True);
  
  Standard_EXPORT Standard_Boolean HasStarting() const;
  
  Standard_EXPORT const Handle(Standard_Transient)& Starting() const;




protected:





private:



  Handle(TColStd_HSequenceOfTransient) thestarts;


};







#endif // _Transfer_IteratorOfProcessForTransient_HeaderFile
