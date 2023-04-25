#ifndef _ROS_haru_encouraging_mediator_msgs_UnityProjectorWherebyMinicamShow_h
#define _ROS_haru_encouraging_mediator_msgs_UnityProjectorWherebyMinicamShow_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace haru_encouraging_mediator_msgs
{

  class UnityProjectorWherebyMinicamShow : public ros::Msg
  {
    public:
      typedef bool _show_mini_type;
      _show_mini_type show_mini;
      typedef int32_t _pose_mode_type;
      _pose_mode_type pose_mode;

    UnityProjectorWherebyMinicamShow():
      show_mini(0),
      pose_mode(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_show_mini;
      u_show_mini.real = this->show_mini;
      *(outbuffer + offset + 0) = (u_show_mini.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->show_mini);
      union {
        int32_t real;
        uint32_t base;
      } u_pose_mode;
      u_pose_mode.real = this->pose_mode;
      *(outbuffer + offset + 0) = (u_pose_mode.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pose_mode.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pose_mode.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pose_mode.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pose_mode);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_show_mini;
      u_show_mini.base = 0;
      u_show_mini.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->show_mini = u_show_mini.real;
      offset += sizeof(this->show_mini);
      union {
        int32_t real;
        uint32_t base;
      } u_pose_mode;
      u_pose_mode.base = 0;
      u_pose_mode.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pose_mode.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pose_mode.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pose_mode.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pose_mode = u_pose_mode.real;
      offset += sizeof(this->pose_mode);
     return offset;
    }

    virtual const char * getType() override { return "haru_encouraging_mediator_msgs/UnityProjectorWherebyMinicamShow"; };
    virtual const char * getMD5() override { return "1cb8f80110ab35e1c6dbddaf7fd0530b"; };

  };

}
#endif
