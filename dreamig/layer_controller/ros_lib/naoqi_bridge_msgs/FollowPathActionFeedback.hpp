#ifndef _ROS_naoqi_bridge_msgs_FollowPathActionFeedback_h
#define _ROS_naoqi_bridge_msgs_FollowPathActionFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.hpp"
#include "std_msgs/Header.hpp"
#include "actionlib_msgs/GoalStatus.hpp"
#include "naoqi_bridge_msgs/FollowPathFeedback.hpp"

namespace naoqi_bridge_msgs
{

  class FollowPathActionFeedback : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalStatus _status_type;
      _status_type status;
      typedef naoqi_bridge_msgs::FollowPathFeedback _feedback_type;
      _feedback_type feedback;

    FollowPathActionFeedback():
      header(),
      status(),
      feedback()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->status.serialize(outbuffer + offset);
      offset += this->feedback.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->status.deserialize(inbuffer + offset);
      offset += this->feedback.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "naoqi_bridge_msgs/FollowPathActionFeedback"; };
    const char * getMD5(){ return "dfaee912e03af794d99d2a72e37fc3e5"; };

  };

}
#endif
