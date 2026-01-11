#include "rclcpp/rclcpp.hpp"
#include "can_msgs/msg/frame.hpp"
#include "std_msgs/msg/string.hpp"
#include <cstdint>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <linux/can.h>
#include <linux/can/raw.h>
#include <net/if.h>
#include <thread>
#include <atomic>
#include <functional>

class CanInterfaceNode : public rclcpp::Node
{
public:
    CanInterfaceNode() : Node("can_interface_node")
    {
        //声明参数
        this->declare_parameter<std::string>("can_interface", "can0");
        this->declare_parameter<int>("bitrate", 1000000);
        this->declare_parameter<double>("sample_point",0.666);
        this->declare_parameter<int>("restart_ms",100);

        //获取参数
        std::string can_interface = this->get_parameter("can_interface").as_string();
        int bitrate = this->get_parameter("bitrate").as_int();
        double sample_point = this->get_parameter("sample_point").as_double();
        int restart_ms = this->get_parameter("restart_ms").as_int();

        // //初始化CAN接口
        // if(!init_can_interface(can_interface, bitrate, sample_point, restart_ms))
        // {
        //     RCLCPP_ERROR(this->get_logger(), "Failed to initialize CAN interface");
        //     rclcpp::shutdown();
        //     return;
        // }

        //创建订阅者，接收ROS2消息并发送到CAN总线
    }
};


int main(int argc, char ** argv)
{
  

  printf("can_interface init OK\n");
  return 0;
}