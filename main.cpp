#include <iostream>
#include <algorithm>
#include <librealsense2/rs.hpp> // Include RealSense Cross Platform API
#include "example.hpp"

#include <pcl/point_types.h>
#include <pcl/filters/passthrough.h>

int main()
{

    rs2::pipeline p;
    p.start();

    auto frames = p.wait_for_frames();
    auto depth = frames.get_depth_frame();

    float width = depth.get_width();
    float height = depth.get_height();

    // Query the distance from the camera to the object in the center of the image
    float dist_to_center = depth.get_distance(width / 2, height / 2);

    // Print the distance
    std::cout << "The camera is facing an object " << dist_to_center << " meters away \r";


    return 0;
}

