#include <rsp_action_srv/rsp_actionserver.hpp>

int main(int argc, char** argv){
	
	ros::init(argc, argv, "rsp_action_srv");
	ros::NodeHandle nh;
	
	server server(nh);
	ros::spin();
	
	return 0;
}
