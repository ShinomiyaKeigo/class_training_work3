#ifndef _ROS_naoqi_bridge_msgs_SpeechWithFeedbackActionFeedback_h
#define _ROS_naoqi_bridge_msgs_SpeechWithFeedbackActionFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.hpp"
#include "std_msgs/Header.hpp"
#include "actionlib_msgs/GoalStatus.hpp"
#include "naoqi_bridge_msgs/SpeechWithFeedbackFeedback.hpp"

namespace naoqi_bridge_msgs
{

  class SpeechWithFeedbackActionFeedback : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalStatus _status_type;
      _status_type status;
      typedef naoqi_bridge_msgs::SpeechWithFeedbackFeedback _feedback_type;
      _feedback_type feedback;

    SpeechWithFeedbackActionFeedback():
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

    const char * getType(){ return "naoqi_bridge_msgs/SpeechWithFeedbackActionFeedback"; };
    const char * getMD5(){ return "aae20e09065c3809e8a8e87c4c8953fd"; };

  };

}
#endif
