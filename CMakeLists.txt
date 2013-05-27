
cmake_minimum_required (VERSION 2.8.4) 

project (Copier)

message ( "boost root = ${BOOST_ROOT}" )

##add_subdirectory (./../../../Engine/library ./Engine_lib_bin ) 
##include_directories (./include)

include_directories ( ${BOOST_ROOT} )
link_directories( ${BOOST_ROOT}/stage/lib )


AUX_SOURCE_DIRECTORY( src SRC )


add_executable (copier ${SRC})


