#include <aruco_sub/subscriber.hpp>
#include <std_msgs/String.h>
#include <std_msgs/Float64.h>

aruco::subscriber::subscriber( ros::NodeHandle& nh ): nh( nh ) {

    sub = nh.subscribe("/camera/aruco/position", 10, &subscriber::callback, this);
    pub = nh.advertise<std_msgs::String>("aruco_result", 10);

}

aruco::subscriber::~subscriber(){}

void aruco::subscriber::callback( const geometry_msgs::Vector3Stamped& position ) {
    // std::cout << "Distance: " << position.vector.z << std::endl;
    if (position.vector.z < 2) {
        std_msgs::String m;
        m.data = "Delivery Approaching";
        pub.publish(m);
    }
    
}