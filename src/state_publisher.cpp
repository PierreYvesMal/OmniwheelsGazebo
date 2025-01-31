#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/joint_state.hpp>
#include <chrono>
#include <vector>

using namespace std::chrono_literals;

class StatePublisher : public rclcpp::Node {
public:
    StatePublisher() : Node("state_publisher") {
        joint_pub_ = this->create_publisher<sensor_msgs::msg::JointState>("joint_states", 10);
        timer_ = this->create_wall_timer(100ms, std::bind(&StatePublisher::publish_joint_states, this));
    }

private:
    void publish_joint_states() {
        auto msg = sensor_msgs::msg::JointState();
        msg.header.stamp = this->get_clock()->now();
        
        msg.name = {"wheel_1_joint", "wheel_2_joint", "wheel_3_joint"};
        msg.position = {wheel_1_pos_, wheel_2_pos_, wheel_3_pos_};
        msg.velocity = {0.0, 0.0, 0.0}; // Placeholder values
        msg.effort = {0.0, 0.0, 0.0};   // Placeholder values
        
        joint_pub_->publish(msg);
        
        // Simulating wheel rotation
        wheel_1_pos_ += 0.1;
        wheel_2_pos_ += 0.1;
        wheel_3_pos_ += 0.1;
    }
    
    rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr joint_pub_;
    rclcpp::TimerBase::SharedPtr timer_;
    
    double wheel_1_pos_ = 0.0;
    double wheel_2_pos_ = 0.0;
    double wheel_3_pos_ = 0.0;
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<StatePublisher>());
    rclcpp::shutdown();
    return 0;
}
