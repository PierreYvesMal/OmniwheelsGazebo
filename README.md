## Clone
> **⚠️ Warning**  
> This should be cloned as a ros2 packages, usually under ros2_ws/src/  
```
cd ~/ros2_ws/src/
git clone git@github.com:PierreYvesMal/omniwheels_gazebo.git
```
## Build
> **⚠️ Warning**  
> Run this from the main ros2 workspace directory, not from the package itself.  
```
cd ~/ros2_ws/src/
colcon build --packages-select omniwheels_gazebo
```

## Launch
> **⚠️ Warning**  
> Run this in an actual terminal, it doesn't work in VSCode integrated terminal.  
```
source ~/ros2_ws/install/setup.bash
ros2 launch omniwheels_gazebo robot_state_publisher_launch.py