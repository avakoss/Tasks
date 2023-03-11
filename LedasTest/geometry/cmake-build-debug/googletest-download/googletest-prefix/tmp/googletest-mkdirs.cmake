# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Users/Aleksandra/CLionProjects/LedasTest/lab1_stub/geometry/cmake-build-debug/googletest-src"
  "C:/Users/Aleksandra/CLionProjects/LedasTest/lab1_stub/geometry/cmake-build-debug/googletest-build"
  "C:/Users/Aleksandra/CLionProjects/LedasTest/lab1_stub/geometry/cmake-build-debug/googletest-download/googletest-prefix"
  "C:/Users/Aleksandra/CLionProjects/LedasTest/lab1_stub/geometry/cmake-build-debug/googletest-download/googletest-prefix/tmp"
  "C:/Users/Aleksandra/CLionProjects/LedasTest/lab1_stub/geometry/cmake-build-debug/googletest-download/googletest-prefix/src/googletest-stamp"
  "C:/Users/Aleksandra/CLionProjects/LedasTest/lab1_stub/geometry/cmake-build-debug/googletest-download/googletest-prefix/src"
  "C:/Users/Aleksandra/CLionProjects/LedasTest/lab1_stub/geometry/cmake-build-debug/googletest-download/googletest-prefix/src/googletest-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/Aleksandra/CLionProjects/LedasTest/lab1_stub/geometry/cmake-build-debug/googletest-download/googletest-prefix/src/googletest-stamp/${subDir}")
endforeach()
