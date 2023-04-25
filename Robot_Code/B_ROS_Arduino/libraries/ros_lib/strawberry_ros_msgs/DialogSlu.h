#ifndef _ROS_strawberry_ros_msgs_DialogSlu_h
#define _ROS_strawberry_ros_msgs_DialogSlu_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace strawberry_ros_msgs
{

  class DialogSlu : public ros::Msg
  {
    public:
      typedef const char* _intent_type;
      _intent_type intent;
      typedef float _intent_conf_type;
      _intent_conf_type intent_conf;
      typedef float _intent_conf_avg_type;
      _intent_conf_avg_type intent_conf_avg;
      typedef bool _is_fallback_type;
      _is_fallback_type is_fallback;

    DialogSlu():
      intent(""),
      intent_conf(0),
      intent_conf_avg(0),
      is_fallback(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_intent = strlen(this->intent);
      varToArr(outbuffer + offset, length_intent);
      offset += 4;
      memcpy(outbuffer + offset, this->intent, length_intent);
      offset += length_intent;
      union {
        float real;
        uint32_t base;
      } u_intent_conf;
      u_intent_conf.real = this->intent_conf;
      *(outbuffer + offset + 0) = (u_intent_conf.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_intent_conf.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_intent_conf.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_intent_conf.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->intent_conf);
      union {
        float real;
        uint32_t base;
      } u_intent_conf_avg;
      u_intent_conf_avg.real = this->intent_conf_avg;
      *(outbuffer + offset + 0) = (u_intent_conf_avg.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_intent_conf_avg.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_intent_conf_avg.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_intent_conf_avg.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->intent_conf_avg);
      union {
        bool real;
        uint8_t base;
      } u_is_fallback;
      u_is_fallback.real = this->is_fallback;
      *(outbuffer + offset + 0) = (u_is_fallback.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_fallback);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_intent;
      arrToVar(length_intent, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_intent; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_intent-1]=0;
      this->intent = (char *)(inbuffer + offset-1);
      offset += length_intent;
      union {
        float real;
        uint32_t base;
      } u_intent_conf;
      u_intent_conf.base = 0;
      u_intent_conf.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_intent_conf.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_intent_conf.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_intent_conf.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->intent_conf = u_intent_conf.real;
      offset += sizeof(this->intent_conf);
      union {
        float real;
        uint32_t base;
      } u_intent_conf_avg;
      u_intent_conf_avg.base = 0;
      u_intent_conf_avg.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_intent_conf_avg.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_intent_conf_avg.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_intent_conf_avg.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->intent_conf_avg = u_intent_conf_avg.real;
      offset += sizeof(this->intent_conf_avg);
      union {
        bool real;
        uint8_t base;
      } u_is_fallback;
      u_is_fallback.base = 0;
      u_is_fallback.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_fallback = u_is_fallback.real;
      offset += sizeof(this->is_fallback);
     return offset;
    }

    virtual const char * getType() override { return "strawberry_ros_msgs/DialogSlu"; };
    virtual const char * getMD5() override { return "3d32dbe6c40979a5135d047cc64f1056"; };

  };

}
#endif
