#include <rsp_reconfiguration/reconfig_server.hpp>

server::server(ros::NodeHandle& nh):nh(nh){

	server_callback = boost::bind(&server::callback, this, _1, _2);
	reconfig_server.setCallback(server_callback);

	ac_movement.reset(new Ac_movement("action_server_movement",true));
	ac_movement->waitForServer();
	ac_confirmation.reset(new Ac_confirmation("action_server_confirmation",true));
	ac_confirmation->waitForServer();
	
	pub_confirmation = nh.advertise<std_msgs::String>("receiver_confirmation", 10);

}

void server::callback(rsp_reconfiguration::rsp_reconfigConfig& config, uint32_t level){

	switch(level){
	case 1:{
		receiver_num.data = config.sender_req;
		pub_confirmation.publish(receiver_num);

		
		rsp_turtlebot_actions::rsp_turtlebot_movementGoal goal_receiver;
		goal_receiver.goal.room = config.sender_req;
		ac_movement->sendGoal(goal_receiver);
		bool res = ac_movement->waitForResult();

		if(res){
			rsp_turtlebot_actions::rsp_turtlebot_movementResult result = *(ac_movement->getResult());
			//ROS_INFO("%s",result.result.result);
			//std::cout<< result.result.result <<std::endl;
			ROS_INFO("Please confirm the package is received");
		}
		

		}break;
	case 2:{
		rsp_turtlebot_actions::rsp_turtlebot_movementGoal goal_home;
		goal_home.goal.room = "home";
		rsp_turtlebot_actions::rsp_turtlebot_confirmationGoal goal_conf;
		goal_conf.goal.room = config.receiver_conf;
		ac_confirmation->sendGoal(goal_conf);
		ac_confirmation->waitForResult();

		if(ac_confirmation->getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
			ROS_INFO("The package is received");
			ac_movement->sendGoal(goal_home);
		}
		ac_movement->waitForResult();
		if(ac_movement->getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
			ROS_INFO("The robot gets back to home position");
		}
		}break;
	case 4:
		receiver_num.data = config.sender_req_sim;
		pub_confirmation.publish(receiver_num);

		
		rsp_turtlebot_actions::rsp_turtlebot_movementGoal goal_receiver;
		goal_receiver.goal.room = config.sender_req;
		ac_movement->sendGoal(goal_receiver);
		bool res = ac_movement->waitForResult();

		if(res){
			rsp_turtlebot_actions::rsp_turtlebot_movementResult result = *(ac_movement->getResult());
			//ROS_INFO("%s",result.result.result);
			//std::cout<< result.result.result <<std::endl;
			ROS_INFO("Please confirm the package is received");
		}
		

		}break;
	case 8:
		
		break;
/*	case 16:
		
		break;
*/	
	}

}
