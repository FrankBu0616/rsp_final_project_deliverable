# rsp_final_project_deliverable
Boyang Xiao, Kaiwen Wang, Fanjun Bu


## Description
	We created a platform that used turtlebot to deliver packages on the first floor of Hackerman Hall. 

## Installation Instruction
The following packages are required to run our package.
#### Dependencies
- turtlebot
	- `sudo apt-get install ros-kinetic-turtlebot`
	-  `sudo apt-get install ros-kinetic-turtlebot-navigation`
	-  `sudo apt-get install ros-kinetic-navigation-stack`
-  Laser
	-  `sudo apt-get install ros-kinetic-urg-node`
	-  Add an ethernet connection as follows(for real robot only):
	-  ![Alt text](image1.png?raw=true "Ethernet Setup")
-  Camera
	-  `sudo apt-get install ros-kinetic-openni-launch`
	-  `sudo apt-get install ros-kinetic-aruco-ros`

## User Instruction
##### Before Everything
```
git clone https://github.com/FrankBu0616/rsp_final_project_deliverable.git 
cd rsp_final_project_seliverable
catkin build
source devel/setup.bash
```
##### Simulation
1. `roslaunch turtlebot_with_hokuyo_description turtlebot_word.launch`
2. Use Rviz to send a 2D pose estimate and move the robot to finish the localization.
3. Input the room number of the receiver at ‘sender_req’ in rqt_reconfigure gui and the robot would start to move to the assigned position.
4. As the robot gets to the desired position, input the room number at ‘receiver_conf’ in rqt_reconfigure gui for confirming the package is received. After the confirmation, the robot would get back to its home position and be ready for next delivery.

##### Real Robot
On the laptop connected to Turtlebot and hokuyo laser (if Running ROS across multiple machines), for the robot
`roslaunch  rsp_turtlebot_bringup minimal.launch`

For ROS master (on the main control laptop): `roslaunch turtlebot_with_hokuyo_description delivery.launch`
If running on multiple machines, follow [here](http://wiki.ros.org/ROS/Tutorials/MultipleMachines).

## Packages
**Aruco_description** AR tag description in gazebo simulation

**Aruco_sub** AR tag subscriber that monitors the distance between the robot and the tag. Publish to topic /aruco_result: 
- Topics:
	- /aruco_result: a topic that is being published when the turtlebot is less than 2 meters away from the aruco marker to indicate delivery approaching.

**Rsp_action_srv** 
- Usage: Action servers including sending goal position to the robot and confirming package received
- Node
 	- rsp_actionsrv: Create two action servers for moving robots with room number and confirmation. The action server for moving the robot is realized by hardcoding the position and orientation of each room and sending a navigation goal to move_base. 
- Topics
	- 	/action_server_confirmation/cancel
	- 	/action_server_confirmation/feedback
	- 	/action_server_confirmation/goal
	- 	/action_server_confirmation/result
	- 	/action_server_confirmation/status
	- 	/action_server_movement/cancel
	- 	/action_server_movement/feedback
	- 	/action_server_movement/goal
	- 	/action_server_movement/result
	- 	/action_server_movement/status
	- 	/receiver_confirmation: save receiver’s room number
 
**Rsp_gazebo_amcl** AMCL localization

**Rsp_gazebo_gmapping** gmapping for our turtlebot

**Rsp_reconfiguration** 
- Usage: Interface to enter room number and confirmation of delivery
- Node: 
-	 rsp_reconfig: Create a reconfigure server including two action clients for  action_server_confirmation and action_server_movement. 
- Parameter
	-  rsp_reconfig/receiver_conf: The room number of receiver for confirmation.
	- rsp_reconfig/sender_req: The room number for robot navigation goal.
	
**Rsp_turtlebot_actions** Actions for actionlib

**rsp_turtlebot_bringup** Launch the necessary nodes and topics for turtblebot movement and laser scan
	- Topic
		-  /scan: laser scan information. 
 
**Rsp_turtlebot_msgs** Messages for actionlib

**turtlebot_with_hokuyo_description** Description file of our turtlebot (also contains the launch file for gazebo simulation and main launch file)



## Progress
(Deliverables above the horizontal line is achieved.)

**Minimum**:
- Gazebo (Hackerman 1st floor) 
- Urdf robot description (sensor)
- Path planning (obstacle avoidance?)
- Localization 
- Sensing (Laser)
- Action packages
- Point to point movement
- Action Messages

**Expected**:
- AR tag recognition (camera)
- Parameter reconfiguration GUI
- Action packages
- Receive package confirmation (press a button)
* * *
AR tag alignment (door open: enter the room)


**Maximum**:
- Action packages
- Knocking doors (door closed)
- AR tag alignment (door open: enter the room)
- Phone app: https://github.com/ROS-Mobile/ROS-Mobile-Android

**Hardware Status**:
One of the turtlebot cannot move straight. 
