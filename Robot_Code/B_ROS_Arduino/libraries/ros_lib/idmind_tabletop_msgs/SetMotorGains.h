#ifndef _ROS_SERVICE_SetMotorGains_h
#define _ROS_SERVICE_SetMotorGains_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

static const char SETMOTORGAINS[] = "idmind_tabletop_msgs/SetMotorGains";

  class SetMotorGainsRequest : public ros::Msg
  {
    public:
      typedef uint8_t _motor_id_type;
      _motor_id_type motor_id;
      typedef int16_t _k_p_type;
      _k_p_type k_p;
      typedef int16_t _k_d_type;
      _k_d_type k_d;
      typedef int16_t _k_i_type;
      _k_i_type k_i;
      typedef int16_t _k_fd_type;
      _k_fd_type k_fd;
      typedef int16_t _k_fdd_type;
      _k_fdd_type k_fdd;

    SetMotorGainsRequest():
      motor_id(0),
      k_p(0),
      k_d(0),
      k_i(0),
      k_fd(0),
      k_fdd(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->motor_id >> (8 * 0)) & 0xFF;
      offset += sizeof(this->motor_id);
      union {
        int16_t real;
        uint16_t base;
      } u_k_p;
      u_k_p.real = this->k_p;
      *(outbuffer + offset + 0) = (u_k_p.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_k_p.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->k_p);
      union {
        int16_t real;
        uint16_t base;
      } u_k_d;
      u_k_d.real = this->k_d;
      *(outbuffer + offset + 0) = (u_k_d.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_k_d.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->k_d);
      union {
        int16_t real;
        uint16_t base;
      } u_k_i;
      u_k_i.real = this->k_i;
      *(outbuffer + offset + 0) = (u_k_i.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_k_i.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->k_i);
      union {
        int16_t real;
        uint16_t base;
      } u_k_fd;
      u_k_fd.real = this->k_fd;
      *(outbuffer + offset + 0) = (u_k_fd.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_k_fd.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->k_fd);
      union {
        int16_t real;
        uint16_t base;
      } u_k_fdd;
      u_k_fdd.real = this->k_fdd;
      *(outbuffer + offset + 0) = (u_k_fdd.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_k_fdd.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->k_fdd);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->motor_id =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->motor_id);
      union {
        int16_t real;
        uint16_t base;
      } u_k_p;
      u_k_p.base = 0;
      u_k_p.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_k_p.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->k_p = u_k_p.real;
      offset += sizeof(this->k_p);
      union {
        int16_t real;
        uint16_t base;
      } u_k_d;
      u_k_d.base = 0;
      u_k_d.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_k_d.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->k_d = u_k_d.real;
      offset += sizeof(this->k_d);
      union {
        int16_t real;
        uint16_t base;
      } u_k_i;
      u_k_i.base = 0;
      u_k_i.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_k_i.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->k_i = u_k_i.real;
      offset += sizeof(this->k_i);
      union {
        int16_t real;
        uint16_t base;
      } u_k_fd;
      u_k_fd.base = 0;
      u_k_fd.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_k_fd.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->k_fd = u_k_fd.real;
      offset += sizeof(this->k_fd);
      union {
        int16_t real;
        uint16_t base;
      } u_k_fdd;
      u_k_fdd.base = 0;
      u_k_fdd.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_k_fdd.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->k_fdd = u_k_fdd.real;
      offset += sizeof(this->k_fdd);
     return offset;
    }

    virtual const char * getType() override { return SETMOTORGAINS; };
    virtual const char * getMD5() override { return "3cb685edf0e15070487b5742faebd563"; };

  };

  class SetMotorGainsResponse : public ros::Msg
  {
    public:

    SetMotorGainsResponse()
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

    virtual const char * getType() override { return SETMOTORGAINS; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class SetMotorGains {
    public:
    typedef SetMotorGainsRequest Request;
    typedef SetMotorGainsResponse Response;
  };

}
#endif
