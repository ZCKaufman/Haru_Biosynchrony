#ifndef _ROS_idmind_tabletop_msgs_MotorTemperature_h
#define _ROS_idmind_tabletop_msgs_MotorTemperature_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/Temperature.h"

namespace idmind_tabletop_msgs
{

  class MotorTemperature : public ros::Msg
  {
    public:
      uint32_t temperatures_length;
      typedef sensor_msgs::Temperature _temperatures_type;
      _temperatures_type st_temperatures;
      _temperatures_type * temperatures;
      enum { NUM_MOTORS =  5 };

    MotorTemperature():
      temperatures_length(0), st_temperatures(), temperatures(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->temperatures_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->temperatures_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->temperatures_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->temperatures_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->temperatures_length);
      for( uint32_t i = 0; i < temperatures_length; i++){
      offset += this->temperatures[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t temperatures_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      temperatures_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      temperatures_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      temperatures_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->temperatures_length);
      if(temperatures_lengthT > temperatures_length)
        this->temperatures = (sensor_msgs::Temperature*)realloc(this->temperatures, temperatures_lengthT * sizeof(sensor_msgs::Temperature));
      temperatures_length = temperatures_lengthT;
      for( uint32_t i = 0; i < temperatures_length; i++){
      offset += this->st_temperatures.deserialize(inbuffer + offset);
        memcpy( &(this->temperatures[i]), &(this->st_temperatures), sizeof(sensor_msgs::Temperature));
      }
     return offset;
    }

    virtual const char * getType() override { return "idmind_tabletop_msgs/MotorTemperature"; };
    virtual const char * getMD5() override { return "673425667e699603edbfa5675db59d44"; };

  };

}
#endif
