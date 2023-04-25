#ifndef _ROS_strawberry_ros_msgs_ASRStatus_h
#define _ROS_strawberry_ros_msgs_ASRStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace strawberry_ros_msgs
{

  class ASRStatus : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef bool _speech_detected_type;
      _speech_detected_type speech_detected;
      typedef bool _speech_enabled_type;
      _speech_enabled_type speech_enabled;
      typedef int8_t _instance_id_type;
      _instance_id_type instance_id;

    ASRStatus():
      header(),
      speech_detected(0),
      speech_enabled(0),
      instance_id(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_speech_detected;
      u_speech_detected.real = this->speech_detected;
      *(outbuffer + offset + 0) = (u_speech_detected.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->speech_detected);
      union {
        bool real;
        uint8_t base;
      } u_speech_enabled;
      u_speech_enabled.real = this->speech_enabled;
      *(outbuffer + offset + 0) = (u_speech_enabled.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->speech_enabled);
      union {
        int8_t real;
        uint8_t base;
      } u_instance_id;
      u_instance_id.real = this->instance_id;
      *(outbuffer + offset + 0) = (u_instance_id.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->instance_id);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_speech_detected;
      u_speech_detected.base = 0;
      u_speech_detected.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->speech_detected = u_speech_detected.real;
      offset += sizeof(this->speech_detected);
      union {
        bool real;
        uint8_t base;
      } u_speech_enabled;
      u_speech_enabled.base = 0;
      u_speech_enabled.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->speech_enabled = u_speech_enabled.real;
      offset += sizeof(this->speech_enabled);
      union {
        int8_t real;
        uint8_t base;
      } u_instance_id;
      u_instance_id.base = 0;
      u_instance_id.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->instance_id = u_instance_id.real;
      offset += sizeof(this->instance_id);
     return offset;
    }

    virtual const char * getType() override { return "strawberry_ros_msgs/ASRStatus"; };
    virtual const char * getMD5() override { return "c8bc631a26205799e5c1d2184230794a"; };

  };

}
#endif
