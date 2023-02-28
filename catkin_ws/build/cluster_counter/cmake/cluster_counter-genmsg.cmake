# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "cluster_counter: 1 messages, 0 services")

set(MSG_I_FLAGS "-Icluster_counter:/home/ecofoxtrot/catkin_ws/src/cluster_counter/msg;-Isensor_msgs:/opt/ros/melodic/share/sensor_msgs/cmake/../msg;-Igeometry_msgs:/opt/ros/melodic/share/geometry_msgs/cmake/../msg;-Istd_msgs:/opt/ros/melodic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(cluster_counter_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/ecofoxtrot/catkin_ws/src/cluster_counter/msg/Fin.msg" NAME_WE)
add_custom_target(_cluster_counter_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "cluster_counter" "/home/ecofoxtrot/catkin_ws/src/cluster_counter/msg/Fin.msg" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(cluster_counter
  "/home/ecofoxtrot/catkin_ws/src/cluster_counter/msg/Fin.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/cluster_counter
)

### Generating Services

### Generating Module File
_generate_module_cpp(cluster_counter
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/cluster_counter
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(cluster_counter_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(cluster_counter_generate_messages cluster_counter_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/ecofoxtrot/catkin_ws/src/cluster_counter/msg/Fin.msg" NAME_WE)
add_dependencies(cluster_counter_generate_messages_cpp _cluster_counter_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(cluster_counter_gencpp)
add_dependencies(cluster_counter_gencpp cluster_counter_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS cluster_counter_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(cluster_counter
  "/home/ecofoxtrot/catkin_ws/src/cluster_counter/msg/Fin.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/cluster_counter
)

### Generating Services

### Generating Module File
_generate_module_eus(cluster_counter
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/cluster_counter
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(cluster_counter_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(cluster_counter_generate_messages cluster_counter_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/ecofoxtrot/catkin_ws/src/cluster_counter/msg/Fin.msg" NAME_WE)
add_dependencies(cluster_counter_generate_messages_eus _cluster_counter_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(cluster_counter_geneus)
add_dependencies(cluster_counter_geneus cluster_counter_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS cluster_counter_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(cluster_counter
  "/home/ecofoxtrot/catkin_ws/src/cluster_counter/msg/Fin.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/cluster_counter
)

### Generating Services

### Generating Module File
_generate_module_lisp(cluster_counter
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/cluster_counter
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(cluster_counter_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(cluster_counter_generate_messages cluster_counter_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/ecofoxtrot/catkin_ws/src/cluster_counter/msg/Fin.msg" NAME_WE)
add_dependencies(cluster_counter_generate_messages_lisp _cluster_counter_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(cluster_counter_genlisp)
add_dependencies(cluster_counter_genlisp cluster_counter_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS cluster_counter_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(cluster_counter
  "/home/ecofoxtrot/catkin_ws/src/cluster_counter/msg/Fin.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/cluster_counter
)

### Generating Services

### Generating Module File
_generate_module_nodejs(cluster_counter
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/cluster_counter
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(cluster_counter_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(cluster_counter_generate_messages cluster_counter_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/ecofoxtrot/catkin_ws/src/cluster_counter/msg/Fin.msg" NAME_WE)
add_dependencies(cluster_counter_generate_messages_nodejs _cluster_counter_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(cluster_counter_gennodejs)
add_dependencies(cluster_counter_gennodejs cluster_counter_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS cluster_counter_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(cluster_counter
  "/home/ecofoxtrot/catkin_ws/src/cluster_counter/msg/Fin.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/cluster_counter
)

### Generating Services

### Generating Module File
_generate_module_py(cluster_counter
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/cluster_counter
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(cluster_counter_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(cluster_counter_generate_messages cluster_counter_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/ecofoxtrot/catkin_ws/src/cluster_counter/msg/Fin.msg" NAME_WE)
add_dependencies(cluster_counter_generate_messages_py _cluster_counter_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(cluster_counter_genpy)
add_dependencies(cluster_counter_genpy cluster_counter_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS cluster_counter_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/cluster_counter)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/cluster_counter
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET sensor_msgs_generate_messages_cpp)
  add_dependencies(cluster_counter_generate_messages_cpp sensor_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/cluster_counter)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/cluster_counter
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET sensor_msgs_generate_messages_eus)
  add_dependencies(cluster_counter_generate_messages_eus sensor_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/cluster_counter)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/cluster_counter
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET sensor_msgs_generate_messages_lisp)
  add_dependencies(cluster_counter_generate_messages_lisp sensor_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/cluster_counter)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/cluster_counter
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET sensor_msgs_generate_messages_nodejs)
  add_dependencies(cluster_counter_generate_messages_nodejs sensor_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/cluster_counter)
  install(CODE "execute_process(COMMAND \"/usr/bin/python2\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/cluster_counter\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/cluster_counter
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET sensor_msgs_generate_messages_py)
  add_dependencies(cluster_counter_generate_messages_py sensor_msgs_generate_messages_py)
endif()
