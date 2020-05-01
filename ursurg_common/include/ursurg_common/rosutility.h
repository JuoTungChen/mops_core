#pragma once

#include <ros/node_handle.h>

// Helper function to store a Callable in the subscription callback
// boost::function object
template<typename M, typename F>
ros::Subscriber mksub(ros::NodeHandle& nh,
                      const std::string& topic,
                      uint32_t queue_size,
                      F&& callback,
                      const ros::TransportHints& transport_hints = ros::TransportHints())
{
    return nh.subscribe<M>(topic,
                           queue_size,
                           boost::function<void(const M&)>(std::move(callback)),
                           ros::VoidConstPtr(),
                           transport_hints);
}