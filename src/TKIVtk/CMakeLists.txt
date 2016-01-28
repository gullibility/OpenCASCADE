project(TKIVtk)

set (TOOLKIT_MODULES
  IVtk
  IVtkOCC
  IVtkVTK
  IVtkTools
)

if (WIN32)
  list( APPEND USED_LIBS ${VTK_LIBRARY_NAMES} )
else()
  foreach(VTK_LIB_NAME ${VTK_LIBRARY_NAMES})
  if(APPLE)
    string(REPLACE ".lib" ".dylib" VTK_LIB_NAME ${VTK_LIB_NAME})
  elseif(UNIX)
    string(REPLACE ".lib" ".so" VTK_LIB_NAME ${VTK_LIB_NAME})
  endif()
    list( APPEND USED_LIBS "lib${VTK_LIB_NAME}")
  endforeach()
endif()

OCCT_INCLUDE_CMAKE_FILE (adm/cmake/occt_toolkit)
