#ifndef _ROS_naoqi_bridge_msgs_BodyPoseAction_h
#define _ROS_naoqi_bridge_msgs_BodyPoseAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.hpp"
#include "naoqi_bridge_msgs/BodyPoseActionGoal.hpp"
#include "naoqi_bridge_msgs/BodyPoseActionResult.hpp"
#include "naoqi_bridge_msgs/BodyPoseActionFeedback.hpp"

namespace naoqi_bridge_msgs
{

  class BodyPoseAction : public ros::Msg
  {
    public:
      typedef naoqi_bridge_msgs::BodyPoseActionGoal _action_goal_type;
      _action_goal_type action_goal;
      typedef naoqi_bridge_msgs::BodyPoseActionResult _action_result_type;
      _action_result_type action_result;
      typedef naoqi_bridge_msgs::BodyPoseActionFeedback _action_feedback_type;
      _action_feedback_type action_feedback;

    BodyPoseAction():
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

    const char * getType(){ return "naoqi_bridge_msgs/BodyPoseAction"; };
    const char * getMD5(){ return "bc58fd1218bb64624b76dca7ad8a5a81"; };

  };

}
#endif
