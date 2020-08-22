#ifndef _ROS_naoqi_bridge_msgs_SpeechWithFeedbackAction_h
#define _ROS_naoqi_bridge_msgs_SpeechWithFeedbackAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.hpp"
#include "naoqi_bridge_msgs/SpeechWithFeedbackActionGoal.hpp"
#include "naoqi_bridge_msgs/SpeechWithFeedbackActionResult.hpp"
#include "naoqi_bridge_msgs/SpeechWithFeedbackActionFeedback.hpp"

namespace naoqi_bridge_msgs
{

  class SpeechWithFeedbackAction : public ros::Msg
  {
    public:
      typedef naoqi_bridge_msgs::SpeechWithFeedbackActionGoal _action_goal_type;
      _action_goal_type action_goal;
      typedef naoqi_bridge_msgs::SpeechWithFeedbackActionResult _action_result_type;
      _action_result_type action_result;
      typedef naoqi_bridge_msgs::SpeechWithFeedbackActionFeedback _action_feedback_type;
      _action_feedback_type action_feedback;

    SpeechWithFeedbackAction():
      action_goal(),
      action_result(),
      action_feedback()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->action_goal.serialize(outbuffer + offset);
      offset += this->action_result.serialize(outbuffer + offset);
      offset += this->action_feedback.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->action_goal.deserialize(inbuffer + offset);
      offset += this->action_result.deserialize(inbuffer + offset);
      offset += this->action_feedback.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "naoqi_bridge_msgs/SpeechWithFeedbackAction"; };
    const char * getMD5(){ return "3a7530648ec5a63553b8765e8b88e951"; };

  };

}
#endif