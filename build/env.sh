#!/bin/bash

aScriptPath=${BASH_SOURCE%/*}; if [ -d "${aScriptPath}" ]; then cd "$aScriptPath"; fi; aScriptPath="$PWD";

export CASROOT="/Users/adamupdegrove/Documents/Software/SimVascular/testocctbuilding/Code/ThirdParty/opencascade/simvascular_opencascade"

if [ "${CASROOT}" == "" ]; then
  export CASROOT="${aScriptPath}"
fi

# Read script arguments
shopt -s nocasematch
export CASDEB="";
if [[ "$1" == "debug" ]]; then export CASDEB="d"; fi
if [[ "$1" == "d" ]]; then export CASDEB="d"; fi
if [[ "$1" == "relwithdeb" ]]; then export CASDEB="i"; fi
if [[ "$1" == "i" ]]; then export CASDEB="i"; fi
shopt -u nocasematch

export COMPILER="clang"

# ----- Set path to 3rd party and OCCT libraries -----
anArch=`uname -m`
if [ "$anArch" != "x86_64" ] && [ "$anArch" != "ia64" ]; then
  export ARCH="32";
else
  export ARCH="64";
fi

aSystem=`uname -s`
if [ "$aSystem" == "Darwin" ]; then
  export WOKSTATION="mac";
  export ARCH="64";
else
  export WOKSTATION="lin";
fi

# ----- Set local settings -----
if [ -e "${aScriptPath}/custom.sh" ]; then
  source "${aScriptPath}/custom.sh" "${COMPILER}" "${WOKSTATION}${ARCH}" "${CASDEB}"
fi

THRDPARTY_PATH=""
if [ "$TCL_DIR" != "" ]; then
  THRDPARTY_PATH="${TCL_DIR}:${THRDPARTY_PATH}"
fi

if [ "$TK_DIR" != "" ]; then
  THRDPARTY_PATH="${TK_DIR}:${THRDPARTY_PATH}"
fi

if [ "$FREETYPE_DIR" != "" ]; then
  THRDPARTY_PATH="${FREETYPE_DIR}:${THRDPARTY_PATH}"
fi

if [ "$FREEIMAGE_DIR" != "" ]; then
  THRDPARTY_PATH="${FREEIMAGE_DIR}:${THRDPARTY_PATH}"
fi

if [ "$GL2PS_DIR" != "" ]; then
  THRDPARTY_PATH="${GL2PS_DIR}:${THRDPARTY_PATH}"
fi

if [ "$TBB_DIR" != "" ]; then
  THRDPARTY_PATH="${TBB_DIR}:${THRDPARTY_PATH}"
fi

if [ "$VTK_DIR" != "" ]; then
  THRDPARTY_PATH="${VTK_DIR}:${THRDPARTY_PATH}"
fi

if [ "$TK_DIR" != "$TCL_DIR" ]; then
  if [ "$TK_DIR" != "" ]; then
    export TK_LIBRARY="${TK_DIR}/../lib/tk"
  fi
  if [ "$TCL_DIR" != "" ]; then
    export TCL_LIBRARY="${TCL_DIR}/../lib/tcl"
  fi
fi

BIN_PATH="${WOKSTATION}${ARCH}/${COMPILER}/bin${CASDEB}"
LIBS_PATH="${WOKSTATION}${ARCH}/${COMPILER}/lib${CASDEB}"

export PATH="/Users/adamupdegrove/Documents/Software/SimVascular/testocctbuilding/Code/ThirdParty/opencascade/simvascular_opencascade/build/${BIN_PATH}:${PATH}"

if [ "$LD_LIBRARY_PATH" != "" ]; then
  export LD_LIBRARY_PATH="/Users/adamupdegrove/Documents/Software/SimVascular/testocctbuilding/Code/ThirdParty/opencascade/simvascular_opencascade/build/${LIBS_PATH}:${THRDPARTY_PATH}:${LD_LIBRARY_PATH}"
else
  export LD_LIBRARY_PATH="/Users/adamupdegrove/Documents/Software/SimVascular/testocctbuilding/Code/ThirdParty/opencascade/simvascular_opencascade/build/${LIBS_PATH}:${THRDPARTY_PATH}"
fi

if [ "$WOKSTATION" == "mac" ]; then
  if [ "$DYLD_LIBRARY_PATH" != "" ]; then
    export DYLD_LIBRARY_PATH="${LD_LIBRARY_PATH}:${DYLD_LIBRARY_PATH}"
  else
    export DYLD_LIBRARY_PATH="${LD_LIBRARY_PATH}"
  fi
fi

# ----- Set envoronment variables used by OCCT -----
export CSF_LANGUAGE=us
export MMGT_CLEAR=1
export CSF_EXCEPTION_PROMPT=1
export CSF_SHMessage="${CASROOT}/src/SHMessage"
export CSF_MDTVTexturesDirectory="${CASROOT}/src/Textures"
export CSF_ShadersDirectory="${CASROOT}/src/Shaders"
export CSF_XSMessage="${CASROOT}/src/XSMessage"
export CSF_TObjMessage="${CASROOT}/src/TObj"
export CSF_StandardDefaults="${CASROOT}/src/StdResource"
export CSF_PluginDefaults="${CASROOT}/src/StdResource"
export CSF_XCAFDefaults="${CASROOT}/src/StdResource"
export CSF_TObjDefaults="${CASROOT}/src/StdResource"
export CSF_StandardLiteDefaults="${CASROOT}/src/StdResource"
export CSF_UnitsLexicon="${CASROOT}/src/UnitsAPI/Lexi_Expr.dat"
export CSF_UnitsDefinition="${CASROOT}/src/UnitsAPI/Units.dat"
export CSF_IGESDefaults="${CASROOT}/src/XSTEPResource"
export CSF_STEPDefaults="${CASROOT}/src/XSTEPResource"
export CSF_XmlOcafResource="${CASROOT}/src/XmlOcafResource"
export CSF_MIGRATION_TYPES="${CASROOT}/src/StdResource/MigrationSheet.txt"

# Draw Harness special stuff
if [ -e "${CASROOT}/src/DrawResources" ]; then
  export DRAWHOME="${CASROOT}/src/DrawResources"
  export CSF_DrawPluginDefaults="${CASROOT}/src/DrawResources"

  if [ -e "${CASROOT}/src/DrawResources/DrawDefault" ]; then
    export DRAWDEFAULT="${CASROOT}/src/DrawResources/DrawDefault"
  fi
fi

if [ -e "${CASROOT}/src/DrawResourcesProducts" ]; then
  export CSF_DrawPluginProductsDefaults="${CASROOT}/src/DrawResourcesProducts"
fi
