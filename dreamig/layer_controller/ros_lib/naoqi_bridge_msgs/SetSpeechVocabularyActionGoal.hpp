#ifndef _ROS_naoqi_bridge_msgs_SetSpeechVocabularyActionGoal_h
#define _ROS_naoqi_bridge_msgs_SetSpeechVocabularyActionGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.hpp"
#include "std_msgs/Header.hpp"
#include "actionlib_msgs/GoalID.hpp"
#include "naoqi_bridge_msgs/SetSpeechVocabularyGoal.hpp"

namespace naoqi_bridge_msgs
{

  class SetSpeechVocabularyActionGoal : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalID _goal_id_type;
      _goal_id_type goal_id;
      typedef naoqi_bridge_msgs::SetSpeechVocabularyGoal _goal_type;
      _goal_type goal;

    SetSpeechVocabularyActionGoal():
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

    const char * getType(){ return "naoqi_bridge_msgs/SetSpeechVocabularyActionGoal"; };
    const char * getMD5(){ return "f93300199bb500a3e511fde0b0394ddb"; };

  };

}
#endif
