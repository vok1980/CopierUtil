
cmake_minimum_required (VERSION 2.8.4) 

project (Copier)

##add_subdirectory (./../../../Engine/library ./Engine_lib_bin ) 
##include_directories (./include)



AUX_SOURCE_DIRECTORY( src SRC )


add_executable (copier ${SRC})




