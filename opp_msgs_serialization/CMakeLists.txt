cmake_minimum_required(VERSION 2.8.3)
project(opp_msgs_serialization)

add_compile_options(-std=c++14)

find_package(catkin REQUIRED COMPONENTS
  noether_msgs
  roscpp
  opp_msgs
  eigen_conversions
  geometry_msgs
  sensor_msgs
  std_msgs
  roscpp_serialization
)

find_package(yaml-cpp REQUIRED)

# Prevents certain runtime errors in Ubuntu 18.04
add_definitions(${PCL_DEFINITIONS})

catkin_package(
  INCLUDE_DIRS
    include
  CATKIN_DEPENDS
    eigen_conversions
    geometry_msgs
    sensor_msgs
    std_msgs
    roscpp_serialization
    noether_msgs
    roscpp
    opp_msgs
  DEPENDS
    YAML_CPP
)

###########
## Build ##
###########

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  ${YAML_CPP_INCLUDE_DIRS}
)

#############
## Install ##
#############

install(DIRECTORY include/${PROJECT_NAME}/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
)

#############
## Testing ##
#############

if(CATKIN_ENABLE_TESTING)
  find_package(rostest REQUIRED)
  catkin_add_gtest(${PROJECT_NAME}_test
    test/serialization_test.cpp
  )
  target_link_libraries(${PROJECT_NAME}_test
    ${catkin_LIBRARIES}
    yaml-cpp
  )
endif()
