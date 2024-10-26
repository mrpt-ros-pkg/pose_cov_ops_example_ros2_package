#include <geometry_msgs/msg/pose_with_covariance.hpp>
#include <pose_cov_ops/pose_cov_ops.h>
#include <rclcpp/rclcpp.hpp>

class PoseCovOpsExampleNode : public rclcpp::Node {
public:
  PoseCovOpsExampleNode() : Node("pose_cov_ops_example_node") {
    // Create two PoseWithCovariance messages
    geometry_msgs::msg::PoseWithCovariance pose1;
    geometry_msgs::msg::PoseWithCovariance pose2;

    // Initialize poses (for simplicity, set some example values)
    pose1.pose.position.x = 1.0;
    pose1.pose.position.y = 2.0;
    pose1.pose.position.z = 0.0;
    pose1.pose.orientation.w = 1.0;

    pose2.pose.position.x = 2.0;
    pose2.pose.position.y = 3.0;
    pose2.pose.position.z = 0.0;
    pose2.pose.orientation.w = 1.0;

    // Use a method from pose_cov_ops to combine these two poses
    geometry_msgs::msg::PoseWithCovariance result_pose;
    pose_cov_ops::compose(pose1, pose2, result_pose);

    // Print the result
    RCLCPP_INFO(this->get_logger(), "Result pose: x=%.2f, y=%.2f, z=%.2f",
                result_pose.pose.position.x, result_pose.pose.position.y,
                result_pose.pose.position.z);
  }
};

int main(int argc, char **argv) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<PoseCovOpsExampleNode>());
  rclcpp::shutdown();
  return 0;
}
