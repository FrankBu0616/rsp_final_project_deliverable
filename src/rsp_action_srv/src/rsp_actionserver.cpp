#include <rsp_action_srv/rsp_actionserver.hpp>

server::server(ros::NodeHandle& nh):nh(nh){
	
	as_movement.reset(new As_movement(nh, "action_server_movement",false));
	as_movement->registerGoalCallback(boost::bind(&server::goalCB_movement, this));
	as_movement->start();
	as_confirmation.reset(new As_confirmation(nh, "action_server_confirmation",false));
	as_confirmation->registerGoalCallback(boost::bind(&server::goalCB_confirmation, this));
	as_confirmation->start();
	ac_movement.reset(new Ac_movement("move_base",true));
	ac_movement->waitForServer();
	
	sub_confirmation = nh.subscribe("receiver_confirmation", 10, &server::subCB_confirmation, this);
	
}

void server::goalCB_movement(){

	rsp_turtlebot_actions::rsp_turtlebot_movementGoal goal = *(as_movement->acceptNewGoal());
	rsp_turtlebot_actions::rsp_turtlebot_movementFeedback feedback;
	rsp_turtlebot_actions::rsp_turtlebot_movementResult result;
	bool success;
	
	if (as_movement->isPreemptRequested() || !ros::ok()){
		as_movement->setPreempted();
		success = false;
	}
	
	move_base_msgs::MoveBaseGoal move_goal;
	move_goal.target_pose.header.frame_id = "map";
	move_goal.target_pose.header.stamp = ros::Time::now();
	
	if(goal.goal.room == "115"){
		move_goal.target_pose.pose.position.x = 8.50;
		move_goal.target_pose.pose.position.y = -6.71;
		move_goal.target_pose.pose.position.z = 0.0;
		move_goal.target_pose.pose.orientation.x = 0.0;
		move_goal.target_pose.pose.orientation.y = 0.0;
		move_goal.target_pose.pose.orientation.z = 0.14;
		move_goal.target_pose.pose.orientation.w = 0.989;
	}
	else if(goal.goal.room == "116" || goal.goal.room == "109"){
		move_goal.target_pose.pose.position.x = 6.741;
		move_goal.target_pose.pose.position.y = -6.98;
		move_goal.target_pose.pose.position.z = 0.0;
		move_goal.target_pose.pose.orientation.x = 0.0;
		move_goal.target_pose.pose.orientation.y = 0.0;
		move_goal.target_pose.pose.orientation.z = 0.107;
		move_goal.target_pose.pose.orientation.w = 0.994;
	} 
/*	else if(goal.goal.room == "109"){
		move_goal.target_pose.pose.position.x = 6.741;
		move_goal.target_pose.pose.position.y = -6.98;
		move_goal.target_pose.pose.position.z = 0.0;
		move_goal.target_pose.pose.orientation.x = 0.0;
		move_goal.target_pose.pose.orientation.y = 0.0;
		move_goal.target_pose.pose.orientation.z = 0.107;
		move_goal.target_pose.pose.orientation.w = 0.994;
	} */
	else if(goal.goal.room == "117"){
		move_goal.target_pose.pose.position.x = 1.617;
		move_goal.target_pose.pose.position.y = -7.533;
		move_goal.target_pose.pose.position.z = 0.0;
		move_goal.target_pose.pose.orientation.x = 0.0;
		move_goal.target_pose.pose.orientation.y = 0.0;
		move_goal.target_pose.pose.orientation.z = -0.017;
		move_goal.target_pose.pose.orientation.w = 0.999;
	}
	else if(goal.goal.room == "118" || goal.goal.room == "112"){
		move_goal.target_pose.pose.position.x = -0.381;
		move_goal.target_pose.pose.position.y = -7.732;
		move_goal.target_pose.pose.position.z = 0.0;
		move_goal.target_pose.pose.orientation.x = 0.0;
		move_goal.target_pose.pose.orientation.y = 0.0;
		move_goal.target_pose.pose.orientation.z = 0.104;
		move_goal.target_pose.pose.orientation.w = 0.994;
	}
/*	else if(goal.goal.room == "112"){
		move_goal.target_pose.pose.position.x = -0.381;
		move_goal.target_pose.pose.position.y = -7.732;
		move_goal.target_pose.pose.position.z = 0.0;
		move_goal.target_pose.pose.orientation.x = 0.0;
		move_goal.target_pose.pose.orientation.y = 0.0;
		move_goal.target_pose.pose.orientation.z = 0.104;
		move_goal.target_pose.pose.orientation.w = 0.994;
	}*/
	else if(goal.goal.room == "119"){
		move_goal.target_pose.pose.position.x = -5.364;
		move_goal.target_pose.pose.position.y = -8.213;
		move_goal.target_pose.pose.position.z = 0.0;
		move_goal.target_pose.pose.orientation.x = 0.0;
		move_goal.target_pose.pose.orientation.y = 0.0;
		move_goal.target_pose.pose.orientation.z = 0.015;
		move_goal.target_pose.pose.orientation.w = 0.999;
	}
	else if(goal.goal.room == "120"){
		move_goal.target_pose.pose.position.x = -7.867;
		move_goal.target_pose.pose.position.y = -8.66;
		move_goal.target_pose.pose.position.z = 0.0;
		move_goal.target_pose.pose.orientation.x = 0.0;
		move_goal.target_pose.pose.orientation.y = 0.0;
		move_goal.target_pose.pose.orientation.z = 0.170;
		move_goal.target_pose.pose.orientation.w = 0.985;
	} 
	else if(goal.goal.room == "121" || goal.goal.room == "114"){
		move_goal.target_pose.pose.position.x = -10.24;
		move_goal.target_pose.pose.position.y = -8.62;
		move_goal.target_pose.pose.position.z = 0.0;
		move_goal.target_pose.pose.orientation.x = 0.0;
		move_goal.target_pose.pose.orientation.y = 0.0;
		move_goal.target_pose.pose.orientation.z = 0.05;
		move_goal.target_pose.pose.orientation.w = 0.998;
	}
/*	else if(goal.goal.room == "114"){
		move_goal.target_pose.pose.position.x = -10.24;
		move_goal.target_pose.pose.position.y = -8.62;
		move_goal.target_pose.pose.position.z = 0.0;
		move_goal.target_pose.pose.orientation.x = 0.0;
		move_goal.target_pose.pose.orientation.y = 0.0;
		move_goal.target_pose.pose.orientation.z = 0.05;
		move_goal.target_pose.pose.orientation.w = 0.998;
	} */
	else if(goal.goal.room == "113"){
		move_goal.target_pose.pose.position.x = -10.29;
		move_goal.target_pose.pose.position.y = -6.23;
		move_goal.target_pose.pose.position.z = 0.0;
		move_goal.target_pose.pose.orientation.x = 0.0;
		move_goal.target_pose.pose.orientation.y = 0.0;
		move_goal.target_pose.pose.orientation.z = -0.676;
		move_goal.target_pose.pose.orientation.w = 0.736;
	}
	else if(goal.goal.room == "home"){
		move_goal.target_pose.pose.position.x = -10.01;
		move_goal.target_pose.pose.position.y = -2.59;
		move_goal.target_pose.pose.position.z = 0.0;
		move_goal.target_pose.pose.orientation.x = 0.0;
		move_goal.target_pose.pose.orientation.y = 0.0;
		move_goal.target_pose.pose.orientation.z = -0.74;
		move_goal.target_pose.pose.orientation.w = 0.667;
	}
	else if(goal.goal.room == "125" || goal.goal.room == "126"){
		move_goal.target_pose.pose.position.x = -9.82;
		move_goal.target_pose.pose.position.y = 4.02;
		move_goal.target_pose.pose.position.z = 0.0;
		move_goal.target_pose.pose.orientation.x = 0.0;
		move_goal.target_pose.pose.orientation.y = 0.0;
		move_goal.target_pose.pose.orientation.z = -0.676;
		move_goal.target_pose.pose.orientation.w = 0.736;
	}
/*	else if(goal.goal.room == "126"){
		move_goal.target_pose.pose.position.x = -9.82;
		move_goal.target_pose.pose.position.y = 4.02;
		move_goal.target_pose.pose.position.z = 0.0;
		move_goal.target_pose.pose.orientation.x = 0.0;
		move_goal.target_pose.pose.orientation.y = 0.0;
		move_goal.target_pose.pose.orientation.z = -0.676;
		move_goal.target_pose.pose.orientation.w = 0.736;
	}*/
	else if(goal.goal.room == "127"){
		move_goal.target_pose.pose.position.x = -9.82;
		move_goal.target_pose.pose.position.y = 4.02;
		move_goal.target_pose.pose.position.z = 0.0;
		move_goal.target_pose.pose.orientation.x = 0.0;
		move_goal.target_pose.pose.orientation.y = 0.0;
		move_goal.target_pose.pose.orientation.z = -0.676;
		move_goal.target_pose.pose.orientation.w = 0.736;
	}
	else if(goal.goal.room == "111"){
		move_goal.target_pose.pose.position.x = 9.80;
		move_goal.target_pose.pose.position.y = -4.53;
		move_goal.target_pose.pose.position.z = 0.0;
		move_goal.target_pose.pose.orientation.x = 0.0;
		move_goal.target_pose.pose.orientation.y = 0.0;
		move_goal.target_pose.pose.orientation.z = 0.736;
		move_goal.target_pose.pose.orientation.w = 0.676;
	}
	else {
		
	}
	feedback.feedback.feedback = "Be ready to send the navigation goal";
	as_movement->publishFeedback(feedback);
	ac_movement->sendGoal(move_goal);
	feedback.feedback.feedback = "Wait for the robot moving to the target position";
	as_movement->publishFeedback(feedback);
	if(goal.goal.room != "home"){
		ROS_INFO("Delivery starts");
	}
	feedback.feedback.feedback = "The robot is delivering the package";
	as_movement->publishFeedback(feedback);
	bool res = ac_movement->waitForResult();
	if(res){
		success = true;
	}
	/*while(!res){
		ROS_INFO_THROTTLE(5,"Wait for the robot moving to the target position");
	}*/

	if(ac_movement->getState() == actionlib::SimpleClientGoalState::ABORTED){
		result.result.result = "The robot got stuck";
		as_movement->setAborted(result);
		ROS_INFO("The robot got stuck");
	}

	if(ac_movement->getState() == actionlib::SimpleClientGoalState::SUCCEEDED && success){
		result.result.result = "Delivery is successful";
		as_movement->setSucceeded(result);
		if(goal.goal.room != "home"){
			ROS_INFO("Delivery is successful");
		}
	}
	
}

void server::goalCB_confirmation(){

	rsp_turtlebot_actions::rsp_turtlebot_confirmationGoal goal = *(as_confirmation->acceptNewGoal());
	rsp_turtlebot_actions::rsp_turtlebot_confirmationFeedback feedback;
	rsp_turtlebot_actions::rsp_turtlebot_confirmationResult result;
	desired_receiver_number = goal.goal.room;
	bool success;
	for(int i=0; i<300; i++){
		if (as_confirmation->isPreemptRequested() || !ros::ok()){
			as_confirmation->setPreempted();
			success = false;
			break;
		}
		feedback.feedback.feedback = "Waiting for the receiver to confirm";
		feedback.feedback.waiting_time = i;
		as_confirmation->publishFeedback(feedback);
		if(desired_receiver_number == receiver_number){
			success = true;
			break;
		}
		else{
			success = false;
		}
		ros::Duration(1).sleep();
	}
	if(success){
		result.result.result = "Package is received successfully";
		as_confirmation->setSucceeded(result);
	}	
}

void server::subCB_confirmation(const std_msgs::String& receiver_num){

	receiver_number = receiver_num.data;
}
