#ifndef _ROS_naoqi_bridge_msgs_FollowPathFeedback_h
#define _ROS_naoqi_bridge_msgs_FollowPathFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.hpp"

namespace naoqi_bridge_msgs
{

  class FollowPathFeedback : public ros::Msg
  {
    public:
      typedef uint32_t _index_type;
      _index_type index;

    FollowPathFeedback():
      index(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->index >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->index >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->index >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->index >> (8 * 3)) & 0xFF;
      offset += sizeof(this->index);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->index =  ((uint32_t) (*(inbuffer + offset)));
      this->index |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->index |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->index |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->index);
     return offset;
    }

    const char * getType(){ return "naoqi_bridge_msgs/FollowPathFeedback"; };
    const char * getMD5(){ return "ad7b979103dbd563a352ef5270716728"; };

  };

}
#endif
