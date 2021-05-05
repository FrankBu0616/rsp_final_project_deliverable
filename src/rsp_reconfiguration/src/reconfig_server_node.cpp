#include <rsp_reconfiguration/reconfig_server.hpp>

int main(int argc, char** argv){

	ros::init(argc, argv, "rsp_reconfig");
	ros::NodeHandle nh;
	server reconfig(nh);
	ros::spin();
	
	return 0;

}
