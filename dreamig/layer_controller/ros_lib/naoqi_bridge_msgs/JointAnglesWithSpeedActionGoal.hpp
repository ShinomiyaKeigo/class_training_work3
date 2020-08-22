#ifndef _ROS_naoqi_bridge_msgs_JointAnglesWithSpeedActionGoal_h
#define _ROS_naoqi_bridge_msgs_JointAnglesWithSpeedActionGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.hpp"
#include "std_msgs/Header.hpp"
#include "actionlib_msgs/GoalID.hpp"
#include "naoqi_bridge_msgs/JointAnglesWithSpeedGoal.hpp"

namespace naoqi_bridge_msgs
{

  class JointAnglesWithSpeedActionGoal : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalID _goal_id_type;
      _goal_id_type goal_id;
      typedef naoqi_bridge_msgs::JointAnglesWithSpeedGoal _goal_type;
      _goal_type goal;

    JointAnglesWithSpeedActionGoal():
      header(),
      goal_id(),
      goal()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->goal_id.serialize(outbuffer + offset);
      offset += this->goal.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->goal_id.deserialize(inbuffer + offset);
      offset += this->goal.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "naoqi_bridge_msgs/JointAnglesWithSpeedActionGoal"; };
    const char * getMD5(){ return "9b722e9749aa53fc0e8ca7aa12e95efb"; };

  };

}
#endif