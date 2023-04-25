#ifndef _ROS_strawberry_ros_msgs_HandsVector_h
#define _ROS_strawberry_ros_msgs_HandsVector_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "strawberry_ros_msgs/Hands.h"

namespace strawberry_ros_msgs
{

  class HandsVector : public ros::Msg
  {
    public:
      uint32_t vector_of_hands_length;
      typedef strawberry_ros_msgs::Hands _vector_of_hands_type;
      _vector_of_hands_type st_vector_of_hands;
      _vector_of_hands_type * vector_of_hands;

    HandsVector():
      vector_of_hands_length(0), st_vector_of_hands(), vector_of_hands(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->vector_of_hands_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->vector_of_hands_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->vector_of_hands_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->vector_of_hands_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vector_of_hands_length);
      for( uint32_t i = 0; i < vector_of_hands_length; i++){
      offset += this->vector_of_hands[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t vector_of_hands_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      vector_of_hands_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      vector_of_hands_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      vector_of_hands_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->vector_of_hands_length);
      if(vector_of_hands_lengthT > vector_of_hands_length)
        this->vector_of_hands = (strawberry_ros_msgs::Hands*)realloc(this->vector_of_hands, vector_of_hands_lengthT * sizeof(strawberry_ros_msgs::Hands));
      vector_of_hands_length = vector_of_hands_lengthT;
      for( uint32_t i = 0; i < vector_of_hands_length; i++){
      offset += this->st_vector_of_hands.deserialize(inbuffer + offset);
        memcpy( &(this->vector_of_hands[i]), &(this->st_vector_of_hands), sizeof(strawberry_ros_msgs::Hands));
      }
     return offset;
    }

    virtual const char * getType() override { return "strawberry_ros_msgs/HandsVector"; };
    virtual const char * getMD5() override { return "4d82dfddbf437ef7f3c0e304895afe7d"; };

  };

}
#endif
