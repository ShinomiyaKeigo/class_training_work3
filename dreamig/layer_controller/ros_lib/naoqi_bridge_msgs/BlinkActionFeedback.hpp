#ifndef _ROS_naoqi_bridge_msgs_BlinkActionFeedback_h
#define _ROS_naoqi_bridge_msgs_BlinkActionFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.hpp"
#include "std_msgs/Header.hpp"
#include "actionlib_msgs/GoalStatus.hpp"
#include "naoqi_bridge_msgs/BlinkFeedback.hpp"

namespace naoqi_bridge_msgs
{

  class BlinkActionFeedback : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalStatus _status_type;
      _status_type status;
      typedef naoqi_bridge_msgs::BlinkFeedback _feedback_type;
      _feedback_type feedback;

    BlinkActionFeedback():
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

    const char * getType(){ return "naoqi_bridge_msgs/BlinkActionFeedback"; };
    const char * getMD5(){ return "b4761017d2f70a859c914a9306034255"; };

  };

}
#endif
