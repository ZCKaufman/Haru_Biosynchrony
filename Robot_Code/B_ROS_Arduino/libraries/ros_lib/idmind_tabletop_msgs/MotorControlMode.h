#ifndef _ROS_idmind_tabletop_msgs_MotorControlMode_h
#define _ROS_idmind_tabletop_msgs_MotorControlMode_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

  class MotorControlMode : public ros::Msg
  {
    public:
      uint32_t modes_length;
      typedef uint8_t _modes_type;
      _modes_type st_modes;
      _modes_type * modes;
      enum { POSITION_CONTROL =  0 };
      enum { VELOCITY_CONTROL =  1 };
      enum { NUM_MOTORS =  5 };

    MotorControlMode():
      modes_length(0), st_modes(), modes(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->modes_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->modes_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->modes_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->modes_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->modes_length);
      for( uint32_t i = 0; i < modes_length; i++){
      *(outbuffer + offset + 0) = (this->modes[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->modes[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t modes_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      modes_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      modes_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      modes_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->modes_length);
      if(modes_lengthT > modes_length)
        this->modes = (uint8_t*)realloc(this->modes, modes_lengthT * sizeof(uint8_t));
      modes_length = modes_lengthT;
      for( uint32_t i = 0; i < modes_length; i++){
      this->st_modes =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_modes);
        memcpy( &(this->modes[i]), &(this->st_modes), sizeof(uint8_t));
      }
     return offset;
    }

    virtual const char * getType() override { return "idmind_tabletop_msgs/MotorControlMode"; };
    virtual const char * getMD5() override { return "3f23be4bcc830e3d8c3ca08b652e8e4d"; };

  };

}
#endif
