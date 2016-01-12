#!/bin/bash

if [ "$1" == "clang" ]; then
  if [ "$2" == "64" ]; then
    export TCL_DIR="/System/Library/Frameworks"
    export TK_DIR="/System/Library/Frameworks"
    export FREETYPE_DIR="/opt/local/lib"
    export FREEIMAGE_DIR=""
    export GL2PS_DIR=""
    export TBB_DIR=""
    export VTK_DIR=""

    export BIN_PATH="/usr/local/bin"
    if [ "$BIN_PATH" != "" ]; then
      export PATH="${BIN_PATH}:${PATH}"
    fi

    export LIB_PATH="/usr/local/lib"
    if [ "$LIB_PATH" != "" ]; then
      if [ "$LD_LIBRARY_PATH" != "" ]; then
        export LD_LIBRARY_PATH="${LIB_PATH}:${LD_LIBRARY_PATH}"
      else
        export LD_LIBRARY_PATH="${LIB_PATH}"
      fi
    fi
    
    export OCCT_RESOURCE_PATH="${CASROOT}/src"
    if [ "/usr/local/share/opencascade-7.0.0.beta/resoures" != "" ]; then
      export OCCT_RESOURCE_PATH="/usr/local/share/opencascade-7.0.0.beta/resoures"
    fi

    # required for set default testing environment
    # and "Samples" window creation in DRAW
    export OCCT_SHARE_PATH="${CASROOT}"
    if [ "/usr/local/share/opencascade-7.0.0.beta" != "" ]; then
      export OCCT_SHARE_PATH="/usr/local/share/opencascade-7.0.0.beta"
    fi
  fi
fi

