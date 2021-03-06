#ifndef _ROS_naoqi_bridge_msgs_SetSpeechVocabularyActionResult_h
#define _ROS_naoqi_bridge_msgs_SetSpeechVocabularyActionResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.hpp"
#include "std_msgs/Header.hpp"
#include "actionlib_msgs/GoalStatus.hpp"
#include "naoqi_bridge_msgs/SetSpeechVocabularyResult.hpp"

namespace naoqi_bridge_msgs
{

  class SetSpeechVocabularyActionResult : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalStatus _status_type;
      _status_type status;
      typedef naoqi_bridge_msgs::SetSpeechVocabularyResult _result_type;
      _result_type result;

    SetSpeechVocabularyActionResult():
      header(),
      status(),
      result()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->status.serialize(outbuffer + offset);
      offset += this->result.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->status.deserialize(inbuffer + offset);
      offset += this->result.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "naoqi_bridge_msgs/SetSpeechVocabularyActionResult"; };
    const char * getMD5(){ return "0698ce25b2d595b82357c010557e935f"; };

  };

}
#endif
