#ifndef _ROS_naoqi_bridge_msgs_JointTrajectoryAction_h
#define _ROS_naoqi_bridge_msgs_JointTrajectoryAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.hpp"
#include "naoqi_bridge_msgs/JointTrajectoryActionGoal.hpp"
#include "naoqi_bridge_msgs/JointTrajectoryActionResult.hpp"
#include "naoqi_bridge_msgs/JointTrajectoryActionFeedback.hpp"

namespace naoqi_bridge_msgs
{

  class JointTrajectoryAction : public ros::Msg
  {
    public:
      typedef naoqi_bridge_msgs::JointTrajectoryActionGoal _action_goal_type;
      _action_goal_type action_goal;
      typedef naoqi_bridge_msgs::JointTrajectoryActionResult _action_result_type;
      _action_result_type action_result;
      typedef naoqi_bridge_msgs::JointTrajectoryActionFeedback _action_feedback_type;
      _action_feedback_type action_feedback;

    JointTrajectoryAction():
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

    const char * getType(){ return "naoqi_bridge_msgs/JointTrajectoryAction"; };
    const char * getMD5(){ return "a88e50dd366fa304954dd433b5706bd8"; };

  };

}
#endif
