#ifndef _ROS_haru_encouraging_mediator_msgs_UnityProjectorSetMiniCam_h
#define _ROS_haru_encouraging_mediator_msgs_UnityProjectorSetMiniCam_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace haru_encouraging_mediator_msgs
{

  class UnityProjectorSetMiniCam : public ros::Msg
  {
    public:
      typedef bool _activate_mini_cam_type;
      _activate_mini_cam_type activate_mini_cam;
      typedef bool _show_own_cam_type;
      _show_own_cam_type show_own_cam;

    UnityProjectorSetMiniCam():
      activate_mini_cam(0),
      show_own_cam(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_activate_mini_cam;
      u_activate_mini_cam.real = this->activate_mini_cam;
      *(outbuffer + offset + 0) = (u_activate_mini_cam.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->activate_mini_cam);
      union {
        bool real;
        uint8_t base;
      } u_show_own_cam;
      u_show_own_cam.real = this->show_own_cam;
      *(outbuffer + offset + 0) = (u_show_own_cam.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->show_own_cam);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_activate_mini_cam;
      u_activate_mini_cam.base = 0;
      u_activate_mini_cam.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->activate_mini_cam = u_activate_mini_cam.real;
      offset += sizeof(this->activate_mini_cam);
      union {
        bool real;
        uint8_t base;
      } u_show_own_cam;
      u_show_own_cam.base = 0;
      u_show_own_cam.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->show_own_cam = u_show_own_cam.real;
      offset += sizeof(this->show_own_cam);
     return offset;
    }

    virtual const char * getType() override { return "haru_encouraging_mediator_msgs/UnityProjectorSetMiniCam"; };
    virtual const char * getMD5() override { return "f31c3d10b8cabd3445b76a00f26ef7e8"; };

  };

}
#endif
