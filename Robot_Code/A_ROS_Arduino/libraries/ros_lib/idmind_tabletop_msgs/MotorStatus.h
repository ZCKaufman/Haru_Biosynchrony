#ifndef _ROS_idmind_tabletop_msgs_MotorStatus_h
#define _ROS_idmind_tabletop_msgs_MotorStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

  class MotorStatus : public ros::Msg
  {
    public:
      uint32_t status_length;
      typedef uint8_t _status_type;
      _status_type st_status;
      _status_type * status;
      enum { STATUS_ERROR =  1 };
      enum { STATUS_INACTIVE =  2 };
      enum { STATUS_ACTIVE =  3 };
      enum { STATUS_MOVING =  4 };
      enum { STATUS_IN_POSITION =  5 };
      enum { BASE_ROLL =  0 };
      enum { NECK_TILT =  1 };
      enum { EYES_ROLL =  2 };
      enum { EYES_TILT =  3 };
      enum { EYES_STROKE =  4 };
      enum { NUM_MOTORS =  5 };

    MotorStatus():
      status_length(0), st_status(), status(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->status_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->status_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->status_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->status_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->status_length);
      for( uint32_t i = 0; i < status_length; i++){
      *(outbuffer + offset + 0) = (this->status[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->status[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t status_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      status_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      status_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      status_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->status_length);
      if(status_lengthT > status_length)
        this->status = (uint8_t*)realloc(this->status, status_lengthT * sizeof(uint8_t));
      status_length = status_lengthT;
      for( uint32_t i = 0; i < status_length; i++){
      this->st_status =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_status);
        memcpy( &(this->status[i]), &(this->st_status), sizeof(uint8_t));
      }
     return offset;
    }

    virtual const char * getType() override { return "idmind_tabletop_msgs/MotorStatus"; };
    virtual const char * getMD5() override { return "e80de99e5680dffe0d98de3eaf7523a3"; };

  };

}
#endif
