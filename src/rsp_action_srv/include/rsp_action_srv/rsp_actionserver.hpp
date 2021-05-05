#include <ros/ros.h>
#include <rsp_turtlebot_actions/rsp_turtlebot_movementAction.h>
#include <rsp_turtlebot_actions/rsp_turtlebot_confirmationAction.h>
#include <actionlib/server/simple_action_server.h>
#include <memory>
#include <std_msgs/String.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

class server{
	typedef actionlib::SimpleActionServer<rsp_turtlebot_actions::rsp_turtlebot_movementAction> As_movement;
	typedef actionlib::SimpleActionServer<rsp_turtlebot_actions::rsp_turtlebot_confirmationAction> As_confirmation;
	typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> Ac_movement;
	
private:

	std::unique_ptr<As_movement> as_movement;
	std::unique_ptr<Ac_movement> ac_movement;
	std::unique_ptr<As_confirmation> as_confirmation;
	
	ros::NodeHandle nh;
	ros::Subscriber sub_confirmation;
	
	std::string receiver_number;
	std::string desired_receiver_number;

public:

	server(ros::NodeHandle& nh);
	
	void goalCB_movement();
	void goalCB_confirmation();
	
	void subCB_confirmation(const std_msgs::String& receiver_num);

};
