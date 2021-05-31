# Extract from FindBoost.cmake

#
# Runs compiler with "-dumpversion" and parses major/minor
# version with a regex.
#
function(COMPILER_DUMPVERSION _OUTPUT_VERSION)
  exec_program(${CMAKE_CXX_COMPILER}
    ARGS ${CMAKE_CXX_COMPILER_ARG1} --version
    OUTPUT_VARIABLE _COMPILER_VERSION
  )
  string(REGEX REPLACE "^[^0-9]*([0-9]+)\\.[0-9]+\\.[0-9]+.*$" "\\1"
    _COMPILER_VERSION ${_COMPILER_VERSION})

  set(${_OUTPUT_VERSION} ${_COMPILER_VERSION} PARENT_SCOPE)
endfunction()

# GCC-specific implementation
function(COMPILER_DUMPVERSION_GCC _OUTPUT_VERSION)
  exec_program(${CMAKE_CXX_COMPILER}
    ARGS ${CMAKE_CXX_COMPILER_ARG1} --version
    OUTPUT_VARIABLE _COMPILER_VERSION
  )
  string(REGEX REPLACE "^.*[^0-9]*([0-9]+)\\.[0-9]+\\.[0-9]+.*$" "\\1"
    _COMPILER_VERSION ${_COMPILER_VERSION})

  set(${_OUTPUT_VERSION} ${_COMPILER_VERSION} PARENT_SCOPE)
endfunction()

# Guesses compiler prefix used in built library names
# Returns the guess by setting the variable pointed to by _ret
function(GUESS_COMPILER_PREFIX _ret)
  if(CMAKE_CXX_COMPILER_ID STREQUAL "Intel"
      OR CMAKE_CXX_COMPILER MATCHES "icl"
      OR CMAKE_CXX_COMPILER MATCHES "icpc")
    if(WIN32)
      set (_COMPILER "iw")
    else()
      set (_COMPILER "il")
    endif()
  elseif (GHSMULTI)
    set(_COMPILER "_ghs")
  elseif("x${CMAKE_CXX_COMPILER_ID}" STREQUAL "xMSVC")
    if(NOT CMAKE_CXX_COMPILER_VERSION VERSION_LESS 19)
      set(_COMPILER "vc14")
    else()
      message(FATAL_ERROR "MSVC ${CMAKE_CXX_COMPILER_VERSION} (${_COMPILER_VERSION}) is unsupported")
    endif()
	if ("${CMAKE_SIZEOF_VOID_P}" STREQUAL "8")
      set(_COMPILER "${_COMPILER}x64")
	elseif ("${CMAKE_SIZEOF_VOID_P}" STREQUAL "4")
      set(_COMPILER "${_COMPILER}x86")
    endif()
  elseif (BORLAND)
    set(_COMPILER "bcb")
  elseif(CMAKE_CXX_COMPILER_ID STREQUAL "SunPro")
    set(_COMPILER "sw")
  elseif(CMAKE_CXX_COMPILER_ID STREQUAL "XL")
    set(_COMPILER "xlc")
  elseif (MINGW)
    COMPILER_DUMPVERSION(_COMPILER_VERSION)
    set(_COMPILER "mgw${_COMPILER_VERSION}")
  elseif (UNIX)
    if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
      COMPILER_DUMPVERSION(_COMPILER_VERSION)
      set(_COMPILER "clang${_COMPILER_VERSION}_libstdcpp")
    elseif (CMAKE_COMPILER_IS_GNUCXX)
      COMPILER_DUMPVERSION_GCC(_COMPILER_VERSION)
      # Determine which version of GCC we have.
      if(APPLE)
        set(_COMPILER "xgcc${_COMPILER_VERSION}")
      else()
        set(_COMPILER "gcc${_COMPILER_VERSION}")
      endif()
    endif()
  else()
    set(_COMPILER "")
  endif()
  set(${_ret} ${_COMPILER} PARENT_SCOPE)
endfunction()
