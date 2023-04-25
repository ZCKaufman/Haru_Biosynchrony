#ifndef _ROS_SERVICE_LookAt_h
#define _ROS_SERVICE_LookAt_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PointStamped.h"

namespace idmind_tabletop_msgs
{

static const char LOOKAT[] = "idmind_tabletop_msgs/LookAt";

  class LookAtRequest : public ros::Msg
  {
    public:
      typedef geometry_msgs::PointStamped _objective_type;
      _objective_type objective;
      typedef bool _disable_base_type;
      _disable_base_type disable_base;
      typedef bool _disable_neck_type;
      _disable_neck_type disable_neck;
      typedef bool _disable_head_type;
      _disable_head_type disable_head;
      typedef bool _disable_eyes_type;
      _disable_eyes_type disable_eyes;
      typedef bool _base_control_vel_type;
      _base_control_vel_type base_control_vel;

    LookAtRequest():
      objective(),
      disable_base(0),
      disable_neck(0),
      disable_head(0),
      disable_eyes(0),
      base_control_vel(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->objective.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_disable_base;
      u_disable_base.real = this->disable_base;
      *(outbuffer + offset + 0) = (u_disable_base.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->disable_base);
      union {
        bool real;
        uint8_t base;
      } u_disable_neck;
      u_disable_neck.real = this->disable_neck;
      *(outbuffer + offset + 0) = (u_disable_neck.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->disable_neck);
      union {
        bool real;
        uint8_t base;
      } u_disable_head;
      u_disable_head.real = this->disable_head;
      *(outbuffer + offset + 0) = (u_disable_head.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->disable_head);
      union {
        bool real;
        uint8_t base;
      } u_disable_eyes;
      u_disable_eyes.real = this->disable_eyes;
      *(outbuffer + offset + 0) = (u_disable_eyes.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->disable_eyes);
      union {
        bool real;
        uint8_t base;
      } u_base_control_vel;
      u_base_control_vel.real = this->base_control_vel;
      *(outbuffer + offset + 0) = (u_base_control_vel.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->base_control_vel);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->objective.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_disable_base;
      u_disable_base.base = 0;
      u_disable_base.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->disable_base = u_disable_base.real;
      offset += sizeof(this->disable_base);
      union {
        bool real;
        uint8_t base;
      } u_disable_neck;
      u_disable_neck.base = 0;
      u_disable_neck.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->disable_neck = u_disable_neck.real;
      offset += sizeof(this->disable_neck);
      union {
        bool real;
        uint8_t base;
      } u_disable_head;
      u_disable_head.base = 0;
      u_disable_head.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->disable_head = u_disable_head.real;
      offset += sizeof(this->disable_head);
      union {
        bool real;
        uint8_t base;
      } u_disable_eyes;
      u_disable_eyes.base = 0;
      u_disable_eyes.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->disable_eyes = u_disable_eyes.real;
      offset += sizeof(this->disable_eyes);
      union {
        bool real;
        uint8_t base;
      } u_base_control_vel;
      u_base_control_vel.base = 0;
      u_base_control_vel.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->base_control_vel = u_base_control_vel.real;
      offset += sizeof(this->base_control_vel);
     return offset;
    }

    virtual const char * getType() override { return LOOKAT; };
    virtual const char * getMD5() override { return "c7e54989a232799fd40bdc3af21607a5"; };

  };

  class LookAtResponse : public ros::Msg
  {
    public:

    LookAtResponse()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
     return offset;
    }

    virtual const char * getType() override { return LOOKAT; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class LookAt {
    public:
    typedef LookAtRequest Request;
    typedef LookAtResponse Response;
  };

}
#endif
