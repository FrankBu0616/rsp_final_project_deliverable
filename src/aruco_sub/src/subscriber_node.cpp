#include <aruco_sub/subscriber.hpp>


int main(int argc, char** argv) {

    ros ::init( argc, argv, "posSub");
    ros::NodeHandle nh; 

    aruco::subscriber subscriber ( nh );
    ros::spin();
    return 0;
}