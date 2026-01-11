#ifndef CAN_INTERFACE
#define CAN_INTERFACE

#include <rclcpp/rclcpp.hpp>
#include <linux/can.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <unistd.h>
#include <cstring>
#include <string>

namespace can_interface 
{

    class CanInterfaceNode : public rclcpp::Node
    {
        public:
            explicit CanInterfaceNode(const rclcpp::NodeOptions & options = rclcpp::NodeOptions());
            virtual ~CanInterfaceNode();
        private:
            void initialize_can();
            void timer_callback();

            rclcpp::TimerBase::SharedPtr timer_;
            int socket_fd_;
            struct can_frame frame_;
            std::string can_interface_;
            uint32_t can_id_;
            int bitrate_;
            unsigned int cnt_;
    };

} // namespace can_interface
#endif // !CAN_INTERFACE