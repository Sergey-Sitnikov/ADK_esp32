# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/ssv/esp/esp-idf/components/bootloader/subproject"
  "/home/ssv/05.02.01/exceptions/build/bootloader"
  "/home/ssv/05.02.01/exceptions/build/bootloader-prefix"
  "/home/ssv/05.02.01/exceptions/build/bootloader-prefix/tmp"
  "/home/ssv/05.02.01/exceptions/build/bootloader-prefix/src/bootloader-stamp"
  "/home/ssv/05.02.01/exceptions/build/bootloader-prefix/src"
  "/home/ssv/05.02.01/exceptions/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/ssv/05.02.01/exceptions/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/ssv/05.02.01/exceptions/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
