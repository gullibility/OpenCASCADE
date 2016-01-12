#!/bin/bash

if [ "$COMPILER" == "clang" ]; then
  if [ "$ARCH" == "64" ]; then
    export TCL_DIR="/System/Library/Frameworks"
    export TK_DIR="/System/Library/Frameworks"
    export FREETYPE_DIR="/opt/local/lib"
    export FREEIMAGE_DIR=""
    export GL2PS_DIR=""
    export TBB_DIR=""
    export VTK_DIR=""
  fi
fi

