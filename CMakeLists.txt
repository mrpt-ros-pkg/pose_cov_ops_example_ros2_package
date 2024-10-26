cmake_minimum_required(VERSION 3.8)
project(pose_cov_ops_example)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(pose_cov_ops REQUIRED)
find_package(rclcpp REQUIRED)


# Add the executable
add_executable(pose_cov_ops_example_node src/pose_cov_ops_example.cpp)

# Link the pose_cov_ops library
ament_target_dependencies(pose_cov_ops_example_node rclcpp pose_cov_ops)

# Install the executable
install(TARGETS
  pose_cov_ops_example_node
  DESTINATION lib/${PROJECT_NAME})


if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
