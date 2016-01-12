#!/bin/bash


if [ -e "${aScriptPath}/custom_clang_64.sh" ]; then
  source "${aScriptPath}/custom_clang_64.sh" "$1" "$2" 
fi

