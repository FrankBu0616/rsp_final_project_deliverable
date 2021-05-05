#include <ros/ros.h>
#include <geometry_msgs/Vector3Stamped.h>

namespace aruco {

	class subscriber {

	private:
		
		ros::NodeHandle nh;
		ros::Subscriber sub;
		ros::Publisher pub;

	public:

		subscriber( ros::NodeHandle& nh);
		~subscriber();

		void callback(const geometry_msgs::Vector3Stamped& position);


	};

}