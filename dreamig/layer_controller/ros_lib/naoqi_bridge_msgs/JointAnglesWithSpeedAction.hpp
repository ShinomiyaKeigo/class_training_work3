#ifndef _ROS_naoqi_bridge_msgs_JointAnglesWithSpeedAction_h
#define _ROS_naoqi_bridge_msgs_JointAnglesWithSpeedAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.hpp"
#include "naoqi_bridge_msgs/JointAnglesWithSpeedActionGoal.hpp"
#include "naoqi_bridge_msgs/JointAnglesWithSpeedActionResult.hpp"
#include "naoqi_bridge_msgs/JointAnglesWithSpeedActionFeedback.hpp"

namespace naoqi_bridge_msgs
{

  class JointAnglesWithSpeedAction : public ros::Msg
  {
    public:
      typedef naoqi_bridge_msgs::JointAnglesWithSpeedActionGoal _action_goal_type;
      _action_goal_type action_goal;
      typedef naoqi_bridge_msgs::JointAnglesWithSpeedActionResult _action_result_type;
      _action_result_type action_result;
      typedef naoqi_bridge_msgs::JointAnglesWithSpeedActionFeedback _action_feedback_type;
      _action_feedback_type action_feedback;

    JointAnglesWithSpeedAction():
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

    const char * getType(){ return "naoqi_bridge_msgs/JointAnglesWithSpeedAction"; };
    const char * getMD5(){ return "efd2f7ac88847414fd26aacf32f993a5"; };

  };

}
#endif
