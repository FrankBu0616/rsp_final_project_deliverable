#include <ros/ros.h>
#include <dynamic_reconfigure/server.h>
#include <rsp_reconfiguration/rsp_reconfigConfig.h>
#include <std_msgs/String.h>
#include <memory>
#include <actionlib/client/simple_action_client.h>
#include <rsp_turtlebot_actions/rsp_turtlebot_movementAction.h>
#include <rsp_turtlebot_actions/rsp_turtlebot_confirmationAction.h>

class server{

	typedef dynamic_reconfigure::Server<rsp_reconfiguration::rsp_reconfigConfig> reconfigure_server;
	typedef actionlib::SimpleActionClient<rsp_turtlebot_actions::rsp_turtlebot_movementAction> Ac_movement;
	typedef actionlib::SimpleActionClient<rsp_turtlebot_actions::rsp_turtlebot_confirmationAction> Ac_confirmation;

private:

	reconfigure_server reconfig_server;
	reconfigure_server::CallbackType server_callback;

	std::unique_ptr<Ac_movement> ac_movement;
	std::unique_ptr<Ac_confirmation> ac_confirmation;
	
	ros::NodeHandle nh;
  	ros::Publisher pub_confirmation;

	std_msgs::String receiver_num;

public:

	server(ros::NodeHandle& nh);
	
	void callback(rsp_reconfiguration::rsp_reconfigConfig& config, uint32_t level);

};
