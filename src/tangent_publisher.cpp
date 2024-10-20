#include <chrono>
#include <functional>
#include <memory>
#include <cmath>
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

using namespace std::chrono_literals;

class TangentPublisher : public rclcpp::Node{
    public:
        TangentPublisher():Node("tangent_publisher"), count_(0.0){
            rmw_publisher_t= this->create_publisher<std_msgs::msg::String>("tangent_topic",10);
            timer_=this->create_wall_timer(
                500ms, std::bind(&TangentPublisher::publish_tangent,this));
            }

    private:
        void publish_tangent(){
            auto message = std_msgs::msg::String();
                double x1 = count_;
                double x2 = count_+0.5;
                double tan_x1 = std::tan(x1);
                double tan_x2 = std::tan(x2);

                message.data = "Tangent x1: " + std::to_string(tan_x1)+" \\ Tangent x2: " + std::to_string(tan_x2);
                RCLCPP_INFO(this->get_logger(), "Publishing: '%s'",message.data.c_str());
                rmw_publisher_t->publish(message);
                count_+=0.1;
            }
        rclcpp::TimerBase::SharedPtr timer_;
        rclcpp::Publisher<std_msgs::String>::Shared Ptr rmw_publisher_t;
        double count_;
        
};

int main(int argc, char * argv[]){
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<TangentPublisher>());
    rclcpp::shutdown;
    return 0;
}
